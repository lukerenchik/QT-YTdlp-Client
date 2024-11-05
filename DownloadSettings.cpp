#include "DownloadSettings.h"
#include "ui_DownloadSettings.h"

DownloadSettings::DownloadSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DownloadSettings)
{
    ui->setupUi(this);

    // Connect signals and slots if needed
    // For example, to enable/disable maxFilenameLength based on limitFilenameLength
    connect(ui->checkBoxLimitFilenameLength, &QCheckBox::toggled, this, [this](bool checked){
        ui->lineEditMaxFilenameLength->setEnabled(checked);
    });
}

DownloadSettings::~DownloadSettings()
{
    delete ui;
}

void DownloadSettings::on_buttonBox_accepted()
{
    // Collect data from UI elements
    options.downloadIndexFromPlaylistStart = ui->spinBoxDownloadIndexStart->value();
    options.downloadIndexFromPlaylistEnd = ui->spinBoxDownloadIndexEnd->value();
    options.downloadFromPlaylistLimit = ui->spinBoxDownloadLimit->value();
    options.downloadLinkedPlaylist = ui->checkBoxDownloadLinkedPlaylist->isChecked();
    options.downloadPlaylistRandomOrder = ui->checkBoxDownloadPlaylistRandomOrder->isChecked();
    options.downloadRangeFromPlaylist = ui->checkBoxDownloadRangeFromPlaylist->isChecked();
    options.downloadThumbnail = ui->checkBoxDownloadThumbnail->isChecked();
    options.limitFilenameLength = ui->checkBoxLimitFilenameLength->isChecked();
    options.maxFilenameLength = ui->lineEditMaxFilenameLength->text().toInt();
    options.limitNumVideosDownloadedFromPlaylist = ui->checkBoxLimitNumVideosDownloadedFromPlaylist->isChecked();
    options.normalizeFilenames = ui->checkBoxNormalizeFilenames->isChecked();
    options.windowsFilenames = ui->checkBoxWindowsFilenames->isChecked();

    accept();
}

void DownloadSettings::on_buttonBox_rejected()
{
    reject();
}

DownloadSettings::Options DownloadSettings::getOptions() const
{
    return options;
}

void DownloadSettings::setOptions(const Options &opts)
{
    options = opts;

    // Set UI elements based on options
    ui->spinBoxDownloadIndexStart->setValue(options.downloadIndexFromPlaylistStart);
    ui->spinBoxDownloadIndexEnd->setValue(options.downloadIndexFromPlaylistEnd);
    ui->spinBoxDownloadLimit->setValue(options.downloadFromPlaylistLimit);
    ui->checkBoxDownloadLinkedPlaylist->setChecked(options.downloadLinkedPlaylist);
    ui->checkBoxDownloadPlaylistRandomOrder->setChecked(options.downloadPlaylistRandomOrder);
    ui->checkBoxDownloadRangeFromPlaylist->setChecked(options.downloadRangeFromPlaylist);
    ui->checkBoxDownloadThumbnail->setChecked(options.downloadThumbnail);
    ui->checkBoxLimitFilenameLength->setChecked(options.limitFilenameLength);
    ui->lineEditMaxFilenameLength->setText(QString::number(options.maxFilenameLength));
    ui->lineEditMaxFilenameLength->setEnabled(options.limitFilenameLength);
    ui->checkBoxLimitNumVideosDownloadedFromPlaylist->setChecked(options.limitNumVideosDownloadedFromPlaylist);
    ui->checkBoxNormalizeFilenames->setChecked(options.normalizeFilenames);
    ui->checkBoxWindowsFilenames->setChecked(options.windowsFilenames);
}
