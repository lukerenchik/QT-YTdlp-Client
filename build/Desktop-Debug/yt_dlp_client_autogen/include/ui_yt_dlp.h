/********************************************************************************
** Form generated from reading UI file 'yt_dlp.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YT_DLP_H
#define UI_YT_DLP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_yt_dlp
{
public:
    QAction *actionHelp;
    QAction *actionAbout;
    QAction *actionSelectYtDlpInstallPath;
    QAction *actionDownload_Settings;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_6;
    QLabel *labelTotalSize;
    QHBoxLayout *horizontalLayout;
    QLabel *ytLink;
    QLineEdit *urlLineEdit;
    QPushButton *dlButton;
    QPushButton *saveButton;
    QLabel *labelSpeed;
    QProgressBar *progressBar;
    QGridLayout *gridLayout_5;
    QLabel *gifLabel;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *outputDirLabel;
    QLabel *labelETA;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButtonVideo;
    QRadioButton *radioButtonAudio;
    QMenuBar *menubar;
    QMenu *menuSettings;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *yt_dlp)
    {
        if (yt_dlp->objectName().isEmpty())
            yt_dlp->setObjectName(QString::fromUtf8("yt_dlp"));
        yt_dlp->resize(815, 587);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(yt_dlp->sizePolicy().hasHeightForWidth());
        yt_dlp->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        yt_dlp->setFont(font);
        actionHelp = new QAction(yt_dlp);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionAbout = new QAction(yt_dlp);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionSelectYtDlpInstallPath = new QAction(yt_dlp);
        actionSelectYtDlpInstallPath->setObjectName(QString::fromUtf8("actionSelectYtDlpInstallPath"));
        actionDownload_Settings = new QAction(yt_dlp);
        actionDownload_Settings->setObjectName(QString::fromUtf8("actionDownload_Settings"));
        centralwidget = new QWidget(yt_dlp);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget_3 = new QWidget(centralwidget);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(190, 20, 481, 491));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        labelTotalSize = new QLabel(gridLayoutWidget_3);
        labelTotalSize->setObjectName(QString::fromUtf8("labelTotalSize"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelTotalSize->sizePolicy().hasHeightForWidth());
        labelTotalSize->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(labelTotalSize, 6, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ytLink = new QLabel(gridLayoutWidget_3);
        ytLink->setObjectName(QString::fromUtf8("ytLink"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Latin Modern Mono"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        ytLink->setFont(font1);

        horizontalLayout->addWidget(ytLink);

        urlLineEdit = new QLineEdit(gridLayoutWidget_3);
        urlLineEdit->setObjectName(QString::fromUtf8("urlLineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(urlLineEdit->sizePolicy().hasHeightForWidth());
        urlLineEdit->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(urlLineEdit);


        gridLayout_6->addLayout(horizontalLayout, 2, 1, 1, 1);

        dlButton = new QPushButton(gridLayoutWidget_3);
        dlButton->setObjectName(QString::fromUtf8("dlButton"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(dlButton->sizePolicy().hasHeightForWidth());
        dlButton->setSizePolicy(sizePolicy3);

        gridLayout_6->addWidget(dlButton, 4, 1, 1, 1);

        saveButton = new QPushButton(gridLayoutWidget_3);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        sizePolicy3.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy3);

        gridLayout_6->addWidget(saveButton, 3, 1, 1, 1);

        labelSpeed = new QLabel(gridLayoutWidget_3);
        labelSpeed->setObjectName(QString::fromUtf8("labelSpeed"));
        sizePolicy1.setHeightForWidth(labelSpeed->sizePolicy().hasHeightForWidth());
        labelSpeed->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(labelSpeed, 7, 1, 1, 1);

        progressBar = new QProgressBar(gridLayoutWidget_3);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        sizePolicy2.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy2);
        progressBar->setValue(24);

        gridLayout_6->addWidget(progressBar, 5, 1, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gifLabel = new QLabel(gridLayoutWidget_3);
        gifLabel->setObjectName(QString::fromUtf8("gifLabel"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(gifLabel->sizePolicy().hasHeightForWidth());
        gifLabel->setSizePolicy(sizePolicy4);

        gridLayout_5->addWidget(gifLabel, 2, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));

        gridLayout_6->addLayout(gridLayout_2, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(gridLayoutWidget_3);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy5);

        horizontalLayout_2->addWidget(label);

        outputDirLabel = new QLabel(gridLayoutWidget_3);
        outputDirLabel->setObjectName(QString::fromUtf8("outputDirLabel"));

        horizontalLayout_2->addWidget(outputDirLabel);


        gridLayout_6->addLayout(horizontalLayout_2, 11, 1, 1, 1);

        labelETA = new QLabel(gridLayoutWidget_3);
        labelETA->setObjectName(QString::fromUtf8("labelETA"));
        sizePolicy1.setHeightForWidth(labelETA->sizePolicy().hasHeightForWidth());
        labelETA->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(labelETA, 8, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        radioButtonVideo = new QRadioButton(gridLayoutWidget_3);
        radioButtonVideo->setObjectName(QString::fromUtf8("radioButtonVideo"));

        horizontalLayout_3->addWidget(radioButtonVideo);

        radioButtonAudio = new QRadioButton(gridLayoutWidget_3);
        radioButtonAudio->setObjectName(QString::fromUtf8("radioButtonAudio"));

        horizontalLayout_3->addWidget(radioButtonAudio);


        gridLayout_6->addLayout(horizontalLayout_3, 1, 1, 1, 1);

        yt_dlp->setCentralWidget(centralwidget);
        menubar = new QMenuBar(yt_dlp);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 815, 21));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        yt_dlp->setMenuBar(menubar);
        statusbar = new QStatusBar(yt_dlp);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        yt_dlp->setStatusBar(statusbar);

        menubar->addAction(menuSettings->menuAction());
        menuSettings->addAction(actionHelp);
        menuSettings->addAction(actionAbout);
        menuSettings->addAction(actionDownload_Settings);
        menuSettings->addAction(actionSelectYtDlpInstallPath);

        retranslateUi(yt_dlp);

        QMetaObject::connectSlotsByName(yt_dlp);
    } // setupUi

    void retranslateUi(QMainWindow *yt_dlp)
    {
        yt_dlp->setWindowTitle(QCoreApplication::translate("yt_dlp", "yt-dlp client", nullptr));
        actionHelp->setText(QCoreApplication::translate("yt_dlp", "Help", nullptr));
        actionAbout->setText(QCoreApplication::translate("yt_dlp", "About", nullptr));
        actionSelectYtDlpInstallPath->setText(QCoreApplication::translate("yt_dlp", "Set YtDlp Path", nullptr));
        actionDownload_Settings->setText(QCoreApplication::translate("yt_dlp", "Download Settings", nullptr));
        labelTotalSize->setText(QCoreApplication::translate("yt_dlp", "Total Size:", nullptr));
        ytLink->setText(QCoreApplication::translate("yt_dlp", "Youtube Link", nullptr));
        dlButton->setText(QCoreApplication::translate("yt_dlp", "Download", nullptr));
        saveButton->setText(QCoreApplication::translate("yt_dlp", "Select Save Folder", nullptr));
        labelSpeed->setText(QCoreApplication::translate("yt_dlp", "Download Speed:", nullptr));
        gifLabel->setText(QString());
        label->setText(QCoreApplication::translate("yt_dlp", "Current Output Folder:", nullptr));
        outputDirLabel->setText(QString());
        labelETA->setText(QCoreApplication::translate("yt_dlp", "ETA: ", nullptr));
        radioButtonVideo->setText(QCoreApplication::translate("yt_dlp", "Video File", nullptr));
        radioButtonAudio->setText(QCoreApplication::translate("yt_dlp", "Audio File", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("yt_dlp", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class yt_dlp: public Ui_yt_dlp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YT_DLP_H
