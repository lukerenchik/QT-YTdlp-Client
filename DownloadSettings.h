#ifndef DOWNLOADSETTINGS_H
#define DOWNLOADSETTINGS_H

#include <QDialog>

namespace Ui {
class DownloadSettings;
}

class DownloadSettings : public QDialog
{
    Q_OBJECT

public:
    explicit DownloadSettings(QWidget *parent = nullptr);
    ~DownloadSettings();

    // Struct to hold the download options
    struct Options {
        int downloadIndexFromPlaylistEnd;
        int downloadIndexFromPlaylistStart;
        int downloadFromPlaylistLimit;
        bool downloadLinkedPlaylist;
        bool downloadPlaylistRandomOrder;
        bool downloadRangeFromPlaylist;
        bool downloadThumbnail;
        bool limitFilenameLength;
        bool limitNumVideosDownloadedFromPlaylist;
        int maxFilenameLength;
        bool normalizeFilenames;
        bool windowsFilenames;
        enum DownloadType {
            Video,
            Audio
        };

        DownloadType downloadType;

        QString audioFormat;
        QString format;

    };


    Options getOptions() const;
    void setOptions(const Options &options);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::DownloadSettings *ui;
    Options options;
};

#endif // DOWNLOADSETTINGS_H
