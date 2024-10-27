#include "GifManager.h"
#include <QDir>
#include <QFileInfoList>
#include <QRandomGenerator>
#include <QDebug>

GifManager::GifManager(QLabel *label, QObject *parent)
    : QObject(parent)
    , gifLabel(label)
    , gifMovie(nullptr)
{
}

GifManager::~GifManager()
{
    if (gifMovie) {
        gifMovie->stop();
        delete gifMovie;
    }
}

void GifManager::setGifDirectory(const QString &directory)
{
    gifDirectoryPath = directory;
    loadGifFiles();
}

void GifManager::loadGifFiles()
{
    QDir gifDir(gifDirectoryPath);

    QStringList filters;
    filters << "*.gif";
    gifDir.setNameFilters(filters);

    QFileInfoList gifFiles = gifDir.entryInfoList(QDir::Files);

    gifFilePaths.clear();
    for (const QFileInfo &fileInfo : gifFiles) {
        gifFilePaths.append(fileInfo.absoluteFilePath());
    }

    if (gifFilePaths.isEmpty()) {
        qWarning() << "No GIFs found in the directory:" << gifDirectoryPath;
    }
}

void GifManager::displayRandomGif()
{
    if (gifFilePaths.isEmpty()) {
        qWarning() << "No GIFs available to display.";
        return;
    }

    int randomIndex = QRandomGenerator::global()->bounded(gifFilePaths.size());
    QString selectedGifPath = gifFilePaths.at(randomIndex);

    if (gifMovie) {
        gifMovie->stop();
        delete gifMovie;
    }

    gifMovie = new QMovie(selectedGifPath);
    if (!gifMovie->isValid()) {
        qWarning() << "Failed to load GIF:" << selectedGifPath;
        delete gifMovie;
        gifMovie = nullptr;
        return;
    }

    gifLabel->setMovie(gifMovie);
    gifMovie->start();

    qDebug() << "Displaying GIF:" << selectedGifPath;
}
