#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QProcess>

class Downloader : public QObject
{
    Q_OBJECT

public:
    explicit Downloader(QObject *parent = nullptr);
    ~Downloader();

    void setOutputDir(const QString &dir);
    void download(const QString &url);

signals:
    void downloadProgress(const QString &message);
    void downloadFinished(bool success, const QString &message);

private slots:
    void onProcessOutput();
    void onProcessErrorOutput();
    void onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus);

private:
    QString outputDir;
    QProcess *process;
};

#endif // DOWNLOADER_H
