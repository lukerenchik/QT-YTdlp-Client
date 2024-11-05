/********************************************************************************
** Form generated from reading UI file 'downloadSettings.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOADSETTINGS_H
#define UI_DOWNLOADSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DownloadSettings
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpinBox *downloadRangeFromPlaylistStartSpinbox;
    QCheckBox *downloadThumbnailCheckbox;
    QCheckBox *limitNumVideosDownloadedFromPlaylistCheckbox;
    QCheckBox *normalizeFilenamesCheckbox;
    QCheckBox *downloadRangeFromPlaylistCheckbox;
    QLineEdit *maxFilenameLengthLineEdit;
    QCheckBox *limitFilenameLengthCheckbox;
    QCheckBox *windowsFilenamesCheckbox;
    QSpinBox *downloadIndexFromPlaylistStartSpinbox;
    QCheckBox *downloadPlaylistRandomOrderCheckbox;
    QCheckBox *downloadLinkedPlaylistCheckbox;
    QSpinBox *downloadIndexFromPlaylistEndSpinbox;

    void setupUi(QDialog *DownloadSettings)
    {
        if (DownloadSettings->objectName().isEmpty())
            DownloadSettings->setObjectName(QString::fromUtf8("DownloadSettings"));
        DownloadSettings->resize(751, 429);
        buttonBox = new QDialogButtonBox(DownloadSettings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(110, 350, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        gridLayoutWidget = new QWidget(DownloadSettings);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(80, 40, 576, 263));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        downloadRangeFromPlaylistStartSpinbox = new QSpinBox(gridLayoutWidget);
        downloadRangeFromPlaylistStartSpinbox->setObjectName(QString::fromUtf8("downloadRangeFromPlaylistStartSpinbox"));

        gridLayout->addWidget(downloadRangeFromPlaylistStartSpinbox, 3, 1, 1, 1);

        downloadThumbnailCheckbox = new QCheckBox(gridLayoutWidget);
        downloadThumbnailCheckbox->setObjectName(QString::fromUtf8("downloadThumbnailCheckbox"));

        gridLayout->addWidget(downloadThumbnailCheckbox, 7, 0, 1, 1);

        limitNumVideosDownloadedFromPlaylistCheckbox = new QCheckBox(gridLayoutWidget);
        limitNumVideosDownloadedFromPlaylistCheckbox->setObjectName(QString::fromUtf8("limitNumVideosDownloadedFromPlaylistCheckbox"));

        gridLayout->addWidget(limitNumVideosDownloadedFromPlaylistCheckbox, 1, 0, 1, 1);

        normalizeFilenamesCheckbox = new QCheckBox(gridLayoutWidget);
        normalizeFilenamesCheckbox->setObjectName(QString::fromUtf8("normalizeFilenamesCheckbox"));

        gridLayout->addWidget(normalizeFilenamesCheckbox, 4, 0, 1, 1);

        downloadRangeFromPlaylistCheckbox = new QCheckBox(gridLayoutWidget);
        downloadRangeFromPlaylistCheckbox->setObjectName(QString::fromUtf8("downloadRangeFromPlaylistCheckbox"));

        gridLayout->addWidget(downloadRangeFromPlaylistCheckbox, 3, 0, 1, 1);

        maxFilenameLengthLineEdit = new QLineEdit(gridLayoutWidget);
        maxFilenameLengthLineEdit->setObjectName(QString::fromUtf8("maxFilenameLengthLineEdit"));

        gridLayout->addWidget(maxFilenameLengthLineEdit, 6, 1, 1, 1);

        limitFilenameLengthCheckbox = new QCheckBox(gridLayoutWidget);
        limitFilenameLengthCheckbox->setObjectName(QString::fromUtf8("limitFilenameLengthCheckbox"));

        gridLayout->addWidget(limitFilenameLengthCheckbox, 6, 0, 1, 1);

        windowsFilenamesCheckbox = new QCheckBox(gridLayoutWidget);
        windowsFilenamesCheckbox->setObjectName(QString::fromUtf8("windowsFilenamesCheckbox"));

        gridLayout->addWidget(windowsFilenamesCheckbox, 5, 0, 1, 1);

        downloadIndexFromPlaylistStartSpinbox = new QSpinBox(gridLayoutWidget);
        downloadIndexFromPlaylistStartSpinbox->setObjectName(QString::fromUtf8("downloadIndexFromPlaylistStartSpinbox"));

        gridLayout->addWidget(downloadIndexFromPlaylistStartSpinbox, 1, 1, 1, 1);

        downloadPlaylistRandomOrderCheckbox = new QCheckBox(gridLayoutWidget);
        downloadPlaylistRandomOrderCheckbox->setObjectName(QString::fromUtf8("downloadPlaylistRandomOrderCheckbox"));

        gridLayout->addWidget(downloadPlaylistRandomOrderCheckbox, 2, 0, 1, 1);

        downloadLinkedPlaylistCheckbox = new QCheckBox(gridLayoutWidget);
        downloadLinkedPlaylistCheckbox->setObjectName(QString::fromUtf8("downloadLinkedPlaylistCheckbox"));

        gridLayout->addWidget(downloadLinkedPlaylistCheckbox, 0, 0, 1, 1);

        downloadIndexFromPlaylistEndSpinbox = new QSpinBox(gridLayoutWidget);
        downloadIndexFromPlaylistEndSpinbox->setObjectName(QString::fromUtf8("downloadIndexFromPlaylistEndSpinbox"));

        gridLayout->addWidget(downloadIndexFromPlaylistEndSpinbox, 3, 2, 1, 1);


        retranslateUi(DownloadSettings);
        QObject::connect(buttonBox, SIGNAL(accepted()), DownloadSettings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DownloadSettings, SLOT(reject()));

        QMetaObject::connectSlotsByName(DownloadSettings);
    } // setupUi

    void retranslateUi(QDialog *DownloadSettings)
    {
        DownloadSettings->setWindowTitle(QCoreApplication::translate("DownloadSettings", "Dialog", nullptr));
        downloadThumbnailCheckbox->setText(QCoreApplication::translate("DownloadSettings", "Download Thumbnail", nullptr));
        limitNumVideosDownloadedFromPlaylistCheckbox->setText(QCoreApplication::translate("DownloadSettings", "Limit Number of Videos Downloaded from Playlist", nullptr));
        normalizeFilenamesCheckbox->setText(QCoreApplication::translate("DownloadSettings", "Normalize Filenames", nullptr));
        downloadRangeFromPlaylistCheckbox->setText(QCoreApplication::translate("DownloadSettings", "Download Range from Playlist", nullptr));
        limitFilenameLengthCheckbox->setText(QCoreApplication::translate("DownloadSettings", "Limit Filename Length", nullptr));
        windowsFilenamesCheckbox->setText(QCoreApplication::translate("DownloadSettings", "Windows Filenames", nullptr));
        downloadPlaylistRandomOrderCheckbox->setText(QCoreApplication::translate("DownloadSettings", "Download Playlist Videos in a Random Order", nullptr));
        downloadLinkedPlaylistCheckbox->setText(QCoreApplication::translate("DownloadSettings", "If a Playlist is Linked, download the whole playlist", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DownloadSettings: public Ui_DownloadSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADSETTINGS_H
