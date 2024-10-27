#ifndef YT_DLP_H
#define YT_DLP_H

#include <QMainWindow>
#include <QLabel>
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

    void onDownloadProgress(const QString &message);
    void onDownloadFinished(bool success, const QString &message);

private:
    Ui::yt_dlp *ui;
    QString outputDir;
    GifManager *gifManager;
    Downloader *downloader; // Add this line
};

#endif // YT_DLP_H
