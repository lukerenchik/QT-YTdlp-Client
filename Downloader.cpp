#include "Downloader.h"
#include <QDir>

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

void Downloader::download(const QString &url)
{
    if (url.isEmpty() || outputDir.isEmpty()) {
        emit downloadFinished(false, "URL or output directory is empty.");
        return;
    }

    QStringList arguments;
    arguments << "-f" << "bestaudio";
    arguments << "--extract-audio";
    arguments << "--audio-format" << "m4a";
    arguments << "--output" << QDir(outputDir).filePath("%(title)s.%(ext)s");
    arguments << url;

    process = new QProcess(this);

    connect(process, &QProcess::readyReadStandardOutput, this, &Downloader::onProcessOutput);
    connect(process, &QProcess::readyReadStandardError, this, &Downloader::onProcessErrorOutput);
    connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, &Downloader::onProcessFinished);

    process->start("yt-dlp", arguments);

    if (!process->waitForStarted()) {
        emit downloadFinished(false, "Failed to start yt-dlp process.");
        process->deleteLater();
        process = nullptr;
        return;
    }
}

void Downloader::onProcessOutput()
{
    QByteArray output = process->readAllStandardOutput();
    QString text = QString::fromLocal8Bit(output);
    emit downloadProgress(text);
}

void Downloader::onProcessErrorOutput()
{
    QByteArray errorOutput = process->readAllStandardError();
    QString text = QString::fromLocal8Bit(errorOutput);
    emit downloadProgress(text); // You might want to separate errors
}

void Downloader::onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    bool success = (exitStatus == QProcess::NormalExit && exitCode == 0);
    QString message = success ? "Download completed successfully." : "Download failed.";
    emit downloadFinished(success, message);

    process->deleteLater();
    process = nullptr;
}
