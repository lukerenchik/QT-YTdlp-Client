#include "Downloader.h"
#include <QDir>
#include <QRegularExpression>
#include <QDebug>
#include <QCoreApplication>

Downloader::Downloader(QObject *parent)
    : QObject(parent)
    , process(nullptr)
{
}

Downloader::~Downloader()
{
    if (process) {
        process->kill();
        process->deleteLater();
    }
}

void Downloader::setOutputDir(const QString &dir)
{
    outputDir = dir;
}

void Downloader::download(const QString &url, const DownloadSettings::Options &options)
{
    if (url.isEmpty() || outputDir.isEmpty()) {
        emit downloadFinished(false, "URL or output directory is empty.");
        return;
    }

    QStringList arguments;

    if (options.downloadType == DownloadSettings::Options::Audio) {
        arguments << "-x"; // Extract audio
        if (!options.audioFormat.isEmpty()) {
            arguments << "--audio-format" << options.audioFormat;
        } else {
            arguments << "--audio-format" << "m4a";
        }
    } else if (options.downloadType == DownloadSettings::Options::Video) {
        if (!options.format.isEmpty()) {
            arguments << "-f" << options.format;
        } else {
            arguments << "-f" << "bestvideo+bestaudio"; // Default video format
        }
    }

    // Handle playlist range options
    if (options.downloadRangeFromPlaylist) {
        QString playlistItems;
        if (options.downloadIndexFromPlaylistStart > 0 && options.downloadIndexFromPlaylistEnd > 0) {
            playlistItems = QString("%1:%2").arg(options.downloadIndexFromPlaylistStart).arg(options.downloadIndexFromPlaylistEnd);
        } else if (options.downloadIndexFromPlaylistStart > 0) {
            playlistItems = QString("%1:").arg(options.downloadIndexFromPlaylistStart);
        } else if (options.downloadIndexFromPlaylistEnd > 0) {
            playlistItems = QString(":%1").arg(options.downloadIndexFromPlaylistEnd);
        }

        if (!playlistItems.isEmpty()) {
            arguments << "-I" << playlistItems;
        }
    }

    // Handle download limit
    if (options.limitNumVideosDownloadedFromPlaylist && options.downloadFromPlaylistLimit > 0) {
        arguments << "--max-downloads" << QString::number(options.downloadFromPlaylistLimit);
    }

    // Handle playlist options
    if (options.downloadLinkedPlaylist) {
        arguments << "--yes-playlist";
    } else {
        arguments << "--no-playlist";
    }

    if (options.downloadPlaylistRandomOrder) {
        arguments << "--playlist-random";
    }

    // Handle filename options
    if (options.normalizeFilenames) {
        arguments << "--restrict-filenames";
    }

    if (options.windowsFilenames) {
        arguments << "--windows-filenames";
    }

    if (options.limitFilenameLength && options.maxFilenameLength > 0) {
        arguments << "--trim-filenames" << QString::number(options.maxFilenameLength);
    }

    // Handle thumbnail option
    if (options.downloadThumbnail) {
        arguments << "--write-thumbnail";
    }

    // Add output template
    arguments << "-o" << QDir(outputDir).filePath("%(title)s.%(ext)s");

    // Add the URL
    arguments << url;

    process = new QProcess(this);

    connect(process, &QProcess::readyReadStandardOutput, this, &Downloader::onProcessOutput);
    connect(process, &QProcess::readyReadStandardError, this, &Downloader::onProcessErrorOutput);
    connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, &Downloader::onProcessFinished);

    // Determine the path to yt-dlp
    QString ytDlpPath = ytDlpExecutablePath;

    if (ytDlpPath.isEmpty()) {
        // Default to local app directory or system path
        QString appDirPath = QCoreApplication::applicationDirPath();

#ifdef Q_OS_WIN
        QString ytDlpFileName = "yt-dlp.exe";
#elif defined(Q_OS_MACOS)
        QString ytDlpFileName = "yt-dlp_macos";
#elif defined(Q_OS_LINUX)
        QString ytDlpFileName = "yt-dlp";
#endif

        QString ytDlpLocalPath = QDir(appDirPath).filePath(ytDlpFileName);
        ytDlpPath = QFile::exists(ytDlpLocalPath) ? ytDlpLocalPath : "yt-dlp";
    }

    qDebug() << "yt-dlp arguments:" << arguments;

    process->start(ytDlpPath, arguments);

    if (!process->waitForStarted()) {
        emit downloadFinished(false, "Failed to start yt-dlp process.");
        process->deleteLater();
        process = nullptr;
        return;
    }
}


void Downloader::onProcessOutput()
{
    QByteArray outputData = process->readAllStandardOutput();
    QString output = QString::fromLocal8Bit(outputData);

    QStringList lines = output.split('\n', Qt::SkipEmptyParts);

    for (const QString &line : lines) {
        parseOutputLine(line);
    }
}

void Downloader::setYtDlpExecutablePath(const QString &path)
{
    ytDlpExecutablePath = path;
}




void Downloader::onProcessErrorOutput()
{
    QByteArray errorData = process->readAllStandardError();
    QString errorOutput = QString::fromLocal8Bit(errorData);
    QStringList lines = errorOutput.split('\n', Qt::SkipEmptyParts);

    for (const QString &line : lines) {
        parseErrorLine(line);
    }
}

void Downloader::parseOutputLine(const QString &line)
{
    QRegularExpression progressRegex(R"(\[download\]\s+(\d+\.\d+)% of\s+([\d\.]+\w+)\s+at\s+([\d\.]+\w+/s)\s+ETA\s+([\d:]+))");
    QRegularExpression finishedRegex(R"(\[download\]\s+100%\s+of\s+([\d\.]+\w+)\s+in\s+([\d:]+)\s+at\s+([\d\.]+\w+/s))");
    QRegularExpressionMatch match = progressRegex.match(line);

    if (match.hasMatch()) {

        QString percentageStr = match.captured(1);
        QString totalSize = match.captured(2);
        QString speed = match.captured(3);
        QString eta = match.captured(4);

        double percentage = percentageStr.toDouble();

        emit progressUpdate(percentage, totalSize, speed, eta);
    } else if ((match = finishedRegex.match(line)).hasMatch()) {
        QString totalSize = match.captured(1);
        QString timeTaken = match.captured(2);
        QString averageSpeed = match.captured(3);

        emit progressUpdate(100.0, totalSize, averageSpeed, "0:00");

        emit infoMessage(line);


    }
    else {
        emit infoMessage(line);
    }

}

void Downloader::parseErrorLine(const QString &line)
{
    emit errorMessage(line);
}

void Downloader::onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    bool success = (exitStatus == QProcess::NormalExit && exitCode == 0);
    QString message = success ? "Download completed successfully." : "Download failed.";
    emit downloadFinished(success, message);

    process->deleteLater();
    process = nullptr;
}
