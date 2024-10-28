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

    QDir gifDir = QCoreApplication::applicationDirPath();
    gifDir.cdUp();
    gifDir.cdUp();
    QString gifDirectoryPath = gifDir.filePath("gifs");
    gifManager->setGifDirectory(gifDirectoryPath);
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
    QMessageBox::information(this, "Info", message);
}

void yt_dlp::onErrorMessage(const QString &message)
{
    QMessageBox::critical(this, "Error", message);
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

bool yt_dlp::isYtDlpInstalled()
{
    QProcess process;
    process.start("yt-dlp", QStringList() << "--version");
    if (!process.waitForStarted(3000)){
        process.kill();
        return false;
    }

    return (process.exitCode() == 0);
}

void yt_dlp::on_actionInstallYtDlp_triggered()
{
    installYtDlp();
}


void yt_dlp::installYtDlp()
{
    QString ytDlpUrl;
    QString ytDlpFileName;

#ifdef Q_OS_WIN
    ytDlpUrl = "https://github.com/yt-dlp/yt-dlp/releases/latest/download/yt-dlp.exe";
    ytDlpFileName = "yt-dlp.exe";
#elif defined(Q_OS_MACOS)
    ytDlpUrl = "https://github.com/yt-dlp/yt-dlp/releases/latest/download/yt-dlp_macos";
    ytDlpFileName = "yt-dlp_macos";
#elif defined(Q_OS_LINUX)
    ytDlpUrl = "https://github.com/yt-dlp/yt-dlp/releases/latest/download/yt-dlp";
    ytDlpFileName = "yt-dlp";
#else
    QMessageBox::warning(this, "Unsupported OS", "Your operating system is not supported.");
    return;
#endif

    QMessageBox::information(this, "Installing yt-dlp", "Downloading yt-dlp, Please wait...");
    QUrl url(ytDlpUrl);
    QNetworkRequest request(url);

    if (!networkManager) {
        networkManager = new QNetworkAccessManager(this);
    }

    QNetworkReply *reply = networkManager->get(request);
    connect(reply, &QNetworkReply::finished, this, &yt_dlp::onYtDlpDownloadFinished);

}

void yt_dlp::onYtDlpDownloadFinished(QNetworkReply *reply)
{
    reply->deleteLater();

    if (reply->error() != QNetworkReply::NoError) {
        QMessageBox::critical(this, "Download Failed", "Failed to download yt-dlp: " + reply->errorString());
        return;
    }

    QByteArray data = reply->readAll();

    QString ytDlpFileName;

#ifdef Q_OS_WIN
    ytDlpFileName = "yt-dlp.exe";
#elif defined(Q_OS_MACOS)
    ytDlpFileName = "yt-dlp_macos";
#elif defined(Q_OS_LINUX)
    ytDlpFileName = "yt-dlp";
#endif

    QString appDirPath = QCoreApplication::applicationDirPath();
    QString ytDlpFilePath = QDir(appDirPath).filePath(ytDlpFileName);

    QFile file(ytDlpFilePath);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, "Save Failed", "Failed to save yt-dlp executable.");
        return;
    }

    file.write(data);
    file.close();

#if defined(Q_OS_MACOS) || defined(Q_OS_LINUX)
    QFile::Permissions permissions = file.permissions();
    permissions |= QFile::ExeUser | QFile::ExeGroup | QFile::ExeOther;
    file.setPermissions(permissions);
#endif

    QMessageBox::information(this, "Installation Complete", "yt-dlp has been installed successfully.");
}
