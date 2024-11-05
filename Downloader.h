#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QProcess>
#include "DownloadSettings.h"

class Downloader : public QObject
{
    Q_OBJECT

public:
    explicit Downloader(QObject *parent = nullptr);
    ~Downloader();

    void setOutputDir(const QString &dir);
    void download(const QString &url, const DownloadSettings::Options &options);
    void setYtDlpExecutablePath(const QString &path);

signals:
    void progressUpdate(double percentage, const QString &totalSize, const QString &speed, const QString &eta);
    void infoMessage(const QString &message);
    void errorMessage(const QString &message);
    void downloadFinished(bool success, const QString &message);

private slots:
    void onProcessOutput();
    void onProcessErrorOutput();
    void onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus);

private:
    QString outputDir;
    QProcess *process;
    QString ytDlpExecutablePath;

    void parseOutputLine(const QString &line);
    void parseErrorLine(const QString &line);
};

#endif // DOWNLOADER_H
