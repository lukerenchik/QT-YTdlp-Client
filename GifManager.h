#ifndef GIFMANAGER_H
#define GIFMANAGER_H

#include <QObject>
#include <QLabel>
#include <QMovie>

class GifManager : public QObject
{
    Q_OBJECT

public:
    explicit GifManager(QLabel *label, QObject *parent = nullptr);
    ~GifManager();

    void setGifDirectory(const QString &directory);
    void displayRandomGif();

private:
    QLabel *gifLabel;
    QMovie *gifMovie;
    QString gifDirectoryPath;

    void loadGifFiles();
    QStringList gifFilePaths;

};

#endif // GIFMANAGER_H
