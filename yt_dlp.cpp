#include "yt_dlp.h"
#include "./ui_yt_dlp.h"
#include "Downloader.h"
#include <QFileDialog>
#include <QStandardPaths>
#include <QMessageBox>
#include <QSettings>

yt_dlp::yt_dlp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::yt_dlp)
    , downloader(new Downloader(this))

{
    ui->setupUi(this);

    gifManager = new GifManager(ui->gifLabel, this);

    // Set default output directory
    outputDir = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
    ui->outputDirLabel->setText(outputDir);
    downloader->setOutputDir(outputDir);

    // Connect downloader signals to slots
    connect(downloader, &Downloader::downloadFinished, this, &yt_dlp::onDownloadFinished);
    connect(downloader, &Downloader::progressUpdate, this, &yt_dlp::onProgressUpdate);
    connect(downloader, &Downloader::infoMessage, this, &yt_dlp::onInfoMessage);
    connect(downloader, &Downloader::errorMessage, this, &yt_dlp::onErrorMessage);

    // Saving / Loading Stored Path
    QSettings settings("yt_dlp", "client");
    ytDlpExecutablePath = settings.value("ytDlpExecutablePath").toString();

    if (!ytDlpExecutablePath.isEmpty()) {
        downloader->setYtDlpExecutablePath(ytDlpExecutablePath);
    }



    // Initialize GifManager
    QDir gifDir = QCoreApplication::applicationDirPath();
    gifDir.cdUp();
    gifDir.cdUp();
    QString gifDirectoryPath = gifDir.filePath("gifs");
    gifManager->setGifDirectory(gifDirectoryPath);
    gifManager->displayRandomGif();
}

yt_dlp::~yt_dlp()
{
    delete gifManager;
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
    //QMessageBox::information(this, "Info", message);
    return;
}

void yt_dlp::onErrorMessage(const QString &message)
{
    //QMessageBox::critical(this, "Error", message);
    return;
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

void yt_dlp::on_actionSelectYtDlpInstallPath_triggered()
{
    QString filter;

#ifdef Q_OS_WIN
    filter = "Executable Files (*.exe);;All Files (*)";
#elif defined(Q_OS_MACOS) || defined(Q_OS_LINUX)
    filter = "All Files (*)";
#endif

    QString defaultPath = QDir::homePath();

    QString filePath = QFileDialog::getOpenFileName(this, tr("Select yt-dlp Executable"), defaultPath, filter);

    if (!filePath.isEmpty()) {
        // Store the selected path and update the application
        setYtDlpExecutablePath(filePath);
    }
}

void yt_dlp::setYtDlpExecutablePath(const QString &path)
{
    ytDlpExecutablePath = path;
    downloader->setYtDlpExecutablePath(ytDlpExecutablePath);

    QSettings settings("yt_dlp", "client");
    settings.setValue("ytDlpExecutablePath", ytDlpExecutablePath);

    QMessageBox::information(this, "yt-dlp Path Set", "yt-dlp executable path has been updated.");
}

void yt_dlp::on_actionAbout_triggered()
{
    QString aboutText = QString(
                            "<h2>yt_dlp client</h2>"
                            "<p>Version: 1</p>"
                            "<p>Developed by Luke Renchik.</p>"
                            );

    QMessageBox::about(
        this, "About", aboutText);
}

void yt_dlp::on_actionHelp_triggered()
{
    QString helpText = QString(
        "<h2>Help.</h2>"
        "<p>Instructions:</p>"
        "<ol>"
        "<li>Ensure <a href ='https://github.com/yt-dlp'>yt_dlp</a> is installed</li>"
        "<li>Enter the URL of the content you wish to download.</li>"
        "<li>Click on the 'Download' button.</li>"

        "</ol>"
        );

    QMessageBox::about(
        this, "Help", helpText);
}


