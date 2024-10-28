#ifndef YT_DLP_H
#define YT_DLP_H

#include <QMainWindow>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "Downloader.h"
#include "GifManager.h"

namespace Ui {
class yt_dlp;
}

class yt_dlp : public QMainWindow
{
    Q_OBJECT

public:
    explicit yt_dlp(QWidget *parent = nullptr);
    ~yt_dlp();

private slots:
    void on_saveButton_clicked();
    void on_dlButton_clicked();
    void onDownloadFinished(bool success, const QString &message);
    void onProgressUpdate(double percentage, const QString &totalSize, const QString &speed, const QString &eta);
    void onInfoMessage(const QString &message);
    void onErrorMessage(const QString &message);
    void on_actionInstallYtDlp_triggered();
    void onYtDlpDownloadFinished(QNetworkReply *reply);

private:
    Ui::yt_dlp *ui;
    QString outputDir;
    GifManager *gifManager;
    Downloader *downloader;
    QNetworkAccessManager *networkManager;
    void installYtDlp();
    bool isYtDlpInstalled();

};

#endif // YT_DLP_H
