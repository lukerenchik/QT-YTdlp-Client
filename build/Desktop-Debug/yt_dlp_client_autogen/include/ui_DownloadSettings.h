/********************************************************************************
** Form generated from reading UI file 'DownloadSettings.ui'
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
    QSpinBox *spinBoxDownloadIndexStart;
    QCheckBox *checkBoxDownloadThumbnail;
    QCheckBox *checkBoxLimitNumVideosDownloadedFromPlaylist;
    QCheckBox *checkBoxNormalizeFilenames;
    QCheckBox *checkBoxDownloadRangeFromPlaylist;
    QLineEdit *lineEditMaxFilenameLength;
    QCheckBox *checkBoxLimitFilenameLength;
    QCheckBox *checkBoxWindowsFilenames;
    QSpinBox *spinBoxDownloadLimit;
    QCheckBox *checkBoxDownloadPlaylistRandomOrder;
    QCheckBox *checkBoxDownloadLinkedPlaylist;
    QSpinBox *spinBoxDownloadIndexEnd;

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
        spinBoxDownloadIndexStart = new QSpinBox(gridLayoutWidget);
        spinBoxDownloadIndexStart->setObjectName(QString::fromUtf8("spinBoxDownloadIndexStart"));

        gridLayout->addWidget(spinBoxDownloadIndexStart, 3, 1, 1, 1);

        checkBoxDownloadThumbnail = new QCheckBox(gridLayoutWidget);
        checkBoxDownloadThumbnail->setObjectName(QString::fromUtf8("checkBoxDownloadThumbnail"));

        gridLayout->addWidget(checkBoxDownloadThumbnail, 7, 0, 1, 1);

        checkBoxLimitNumVideosDownloadedFromPlaylist = new QCheckBox(gridLayoutWidget);
        checkBoxLimitNumVideosDownloadedFromPlaylist->setObjectName(QString::fromUtf8("checkBoxLimitNumVideosDownloadedFromPlaylist"));

        gridLayout->addWidget(checkBoxLimitNumVideosDownloadedFromPlaylist, 1, 0, 1, 1);

        checkBoxNormalizeFilenames = new QCheckBox(gridLayoutWidget);
        checkBoxNormalizeFilenames->setObjectName(QString::fromUtf8("checkBoxNormalizeFilenames"));

        gridLayout->addWidget(checkBoxNormalizeFilenames, 4, 0, 1, 1);

        checkBoxDownloadRangeFromPlaylist = new QCheckBox(gridLayoutWidget);
        checkBoxDownloadRangeFromPlaylist->setObjectName(QString::fromUtf8("checkBoxDownloadRangeFromPlaylist"));

        gridLayout->addWidget(checkBoxDownloadRangeFromPlaylist, 3, 0, 1, 1);

        lineEditMaxFilenameLength = new QLineEdit(gridLayoutWidget);
        lineEditMaxFilenameLength->setObjectName(QString::fromUtf8("lineEditMaxFilenameLength"));

        gridLayout->addWidget(lineEditMaxFilenameLength, 6, 1, 1, 1);

        checkBoxLimitFilenameLength = new QCheckBox(gridLayoutWidget);
        checkBoxLimitFilenameLength->setObjectName(QString::fromUtf8("checkBoxLimitFilenameLength"));

        gridLayout->addWidget(checkBoxLimitFilenameLength, 6, 0, 1, 1);

        checkBoxWindowsFilenames = new QCheckBox(gridLayoutWidget);
        checkBoxWindowsFilenames->setObjectName(QString::fromUtf8("checkBoxWindowsFilenames"));

        gridLayout->addWidget(checkBoxWindowsFilenames, 5, 0, 1, 1);

        spinBoxDownloadLimit = new QSpinBox(gridLayoutWidget);
        spinBoxDownloadLimit->setObjectName(QString::fromUtf8("spinBoxDownloadLimit"));

        gridLayout->addWidget(spinBoxDownloadLimit, 1, 1, 1, 1);

        checkBoxDownloadPlaylistRandomOrder = new QCheckBox(gridLayoutWidget);
        checkBoxDownloadPlaylistRandomOrder->setObjectName(QString::fromUtf8("checkBoxDownloadPlaylistRandomOrder"));

        gridLayout->addWidget(checkBoxDownloadPlaylistRandomOrder, 2, 0, 1, 1);

        checkBoxDownloadLinkedPlaylist = new QCheckBox(gridLayoutWidget);
        checkBoxDownloadLinkedPlaylist->setObjectName(QString::fromUtf8("checkBoxDownloadLinkedPlaylist"));

        gridLayout->addWidget(checkBoxDownloadLinkedPlaylist, 0, 0, 1, 1);

        spinBoxDownloadIndexEnd = new QSpinBox(gridLayoutWidget);
        spinBoxDownloadIndexEnd->setObjectName(QString::fromUtf8("spinBoxDownloadIndexEnd"));

        gridLayout->addWidget(spinBoxDownloadIndexEnd, 3, 2, 1, 1);


        retranslateUi(DownloadSettings);
        QObject::connect(buttonBox, SIGNAL(accepted()), DownloadSettings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DownloadSettings, SLOT(reject()));

        QMetaObject::connectSlotsByName(DownloadSettings);
    } // setupUi

    void retranslateUi(QDialog *DownloadSettings)
    {
        DownloadSettings->setWindowTitle(QCoreApplication::translate("DownloadSettings", "Dialog", nullptr));
        checkBoxDownloadThumbnail->setText(QCoreApplication::translate("DownloadSettings", "Download Thumbnail", nullptr));
        checkBoxLimitNumVideosDownloadedFromPlaylist->setText(QCoreApplication::translate("DownloadSettings", "Limit Number of Videos Downloaded from Playlist", nullptr));
        checkBoxNormalizeFilenames->setText(QCoreApplication::translate("DownloadSettings", "Normalize Filenames", nullptr));
        checkBoxDownloadRangeFromPlaylist->setText(QCoreApplication::translate("DownloadSettings", "Download Range from Playlist", nullptr));
        checkBoxLimitFilenameLength->setText(QCoreApplication::translate("DownloadSettings", "Limit Filename Length", nullptr));
        checkBoxWindowsFilenames->setText(QCoreApplication::translate("DownloadSettings", "Windows Filenames", nullptr));
        checkBoxDownloadPlaylistRandomOrder->setText(QCoreApplication::translate("DownloadSettings", "Download Playlist Videos in a Random Order", nullptr));
        checkBoxDownloadLinkedPlaylist->setText(QCoreApplication::translate("DownloadSettings", "If a Playlist is Linked, download the whole playlist", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DownloadSettings: public Ui_DownloadSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADSETTINGS_H
