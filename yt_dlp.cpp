#include "yt_dlp.h"
#include "./ui_yt_dlp.h"
#include "Downloader.h"
#include <QFileDialog>
#include <QStandardPaths>
#include <QMessageBox>

yt_dlp::yt_dlp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::yt_dlp)
    , downloader(new Downloader(this))
    , gifManager(nullptr)
{
    ui->setupUi(this);

    // Set default output directory
    outputDir = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
    ui->outputDirLabel->setText(outputDir);
    downloader->setOutputDir(outputDir);

    // Connect downloader signals to slots
    connect(downloader, &Downloader::downloadFinished, this, &yt_dlp::onDownloadFinished);
    connect(downloader, &Downloader::progressUpdate, this, &yt_dlp::onProgressUpdate);
    connect(downloader, &Downloader::infoMessage, this, &yt_dlp::onInfoMessage);
    connect(downloader, &Downloader::errorMessage, this, &yt_dlp::onErrorMessage);

    // Initialize GifManager
    gifManager = new GifManager(ui->gifLabel, this);
    gifManager->setGifDirectory("/home/luke/yt_dlp_client/gifs");
    gifManager->displayRandomGif();
}

yt_dlp::~yt_dlp()
{
    delete ui;
}


void yt_dlp::on_saveButton_clicked()
{
    QString directory = QFileDialog::getExistingDirectory(this, tr("Select Destination Folder"), QDir::homePath());
    if (!directory.isEmpty()) {
        outputDir = directory;
        downloader->setOutputDir(outputDir);
        ui->outputDirLabel->setText(outputDir);
    }
}


void yt_dlp::on_dlButton_clicked()
{
    QString url = ui->urlLineEdit->text().trimmed();

    if (url.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a URL.");
        return;
    }

    if (outputDir.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please select an output directory.");
        return;
    }

    ui->dlButton->setEnabled(false);

    // Reset progress bar and labels
    ui->progressBar->setValue(0);
    ui->labelTotalSize->clear();
    ui->labelSpeed->clear();
    ui->labelETA->clear();

    downloader->download(url);
}

void yt_dlp::onProgressUpdate(double percentage, const QString &totalSize, const QString &speed, const QString &eta)
{
    ui->progressBar->setValue(static_cast<int>(percentage));

    if (!totalSize.isEmpty())
        ui->labelTotalSize->setText("Total Size: " + totalSize);

    if (!speed.isEmpty())
        ui->labelSpeed->setText("Speed: " + speed);

    if (!eta.isEmpty())
        ui->labelETA->setText("ETA: " + eta);
}


void yt_dlp::onInfoMessage(const QString &message)
{
    ui->outputTextEdit->append(message);
}

void yt_dlp::onErrorMessage(const QString &message)
{
    ui->outputTextEdit->append("<span style='color:red;'>" + message + "</span>");
}

void yt_dlp::onDownloadFinished(bool success, const QString &message)
{
    ui->dlButton->setEnabled(true);

    if (success) {
        QMessageBox::information(this, "Success", message);

        // Display a new random GIF upon successful download
        gifManager->displayRandomGif();
    } else {
        QMessageBox::critical(this, "Error", message);
    }
}

