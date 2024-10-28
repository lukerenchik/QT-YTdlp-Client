#include "yt_dlp.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QApplication a(argc, argv);
    yt_dlp w;
    w.show();
    return a.exec();
}
