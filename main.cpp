#include "yt_dlp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //These two are so I could get my application to scale on high DPI displays. Unsure if they affect other displays.
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QApplication a(argc, argv);
    yt_dlp w;
    w.show();
    return a.exec();
}
