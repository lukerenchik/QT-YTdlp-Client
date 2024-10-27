#include "Downloader.h"
#include <QDir>
#include <QRegularExpression>
#include <QDebug>

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
    QByteArray outputData = process->readAllStandardOutput();
    QString output = QString::fromLocal8Bit(outputData);

    QStringList lines = output.split('\n', Qt::SkipEmptyParts);

    for (const QString &line : lines) {
        parseOutputLine(line);
    }
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
