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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_yt_dlp
{
public:
    QAction *actionHelp;
    QAction *actionAbout;
    QAction *actionEtc;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_6;
    QLineEdit *urlLineEdit;
    QGridLayout *gridLayout_2;
    QLabel *ytLink;
    QGridLayout *gridLayout_5;
    QLabel *gifLabel;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_7;
    QPushButton *saveButton;
    QPushButton *dlButton;
    QTextEdit *outputTextEdit;
    QLabel *outputDirLabel;
    QProgressBar *progressBar;
    QLabel *labelTotalSize;
    QLabel *labelSpeed;
    QLabel *labelETA;
    QMenuBar *menubar;
    QMenu *menuSettings;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *yt_dlp)
    {
        if (yt_dlp->objectName().isEmpty())
            yt_dlp->setObjectName(QString::fromUtf8("yt_dlp"));
        yt_dlp->resize(815, 587);
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        yt_dlp->setFont(font);
        actionHelp = new QAction(yt_dlp);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionAbout = new QAction(yt_dlp);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionEtc = new QAction(yt_dlp);
        actionEtc->setObjectName(QString::fromUtf8("actionEtc"));
        centralwidget = new QWidget(yt_dlp);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget_3 = new QWidget(centralwidget);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(140, 30, 481, 351));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        urlLineEdit = new QLineEdit(gridLayoutWidget_3);
        urlLineEdit->setObjectName(QString::fromUtf8("urlLineEdit"));

        gridLayout_6->addWidget(urlLineEdit, 1, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        ytLink = new QLabel(gridLayoutWidget_3);
        ytLink->setObjectName(QString::fromUtf8("ytLink"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Serif"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        ytLink->setFont(font1);

        gridLayout_2->addWidget(ytLink, 0, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_2, 1, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gifLabel = new QLabel(gridLayoutWidget_3);
        gifLabel->setObjectName(QString::fromUtf8("gifLabel"));

        gridLayout_5->addWidget(gifLabel, 0, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 1, 1, 1);

        gridLayoutWidget_4 = new QWidget(centralwidget);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(20, 380, 231, 132));
        gridLayout_7 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        saveButton = new QPushButton(gridLayoutWidget_4);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        gridLayout_7->addWidget(saveButton, 1, 0, 1, 1);

        dlButton = new QPushButton(gridLayoutWidget_4);
        dlButton->setObjectName(QString::fromUtf8("dlButton"));

        gridLayout_7->addWidget(dlButton, 2, 0, 1, 1);

        outputTextEdit = new QTextEdit(gridLayoutWidget_4);
        outputTextEdit->setObjectName(QString::fromUtf8("outputTextEdit"));

        gridLayout_7->addWidget(outputTextEdit, 0, 0, 1, 1);

        outputDirLabel = new QLabel(centralwidget);
        outputDirLabel->setObjectName(QString::fromUtf8("outputDirLabel"));
        outputDirLabel->setGeometry(QRect(10, 520, 531, 16));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(280, 410, 118, 23));
        progressBar->setValue(24);
        labelTotalSize = new QLabel(centralwidget);
        labelTotalSize->setObjectName(QString::fromUtf8("labelTotalSize"));
        labelTotalSize->setGeometry(QRect(280, 450, 241, 16));
        labelSpeed = new QLabel(centralwidget);
        labelSpeed->setObjectName(QString::fromUtf8("labelSpeed"));
        labelSpeed->setGeometry(QRect(280, 480, 291, 16));
        labelETA = new QLabel(centralwidget);
        labelETA->setObjectName(QString::fromUtf8("labelETA"));
        labelETA->setGeometry(QRect(280, 510, 151, 16));
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
        menuSettings->addAction(actionEtc);

        retranslateUi(yt_dlp);

        QMetaObject::connectSlotsByName(yt_dlp);
    } // setupUi

    void retranslateUi(QMainWindow *yt_dlp)
    {
        yt_dlp->setWindowTitle(QCoreApplication::translate("yt_dlp", "yt-dlp client", nullptr));
        actionHelp->setText(QCoreApplication::translate("yt_dlp", "Help", nullptr));
        actionAbout->setText(QCoreApplication::translate("yt_dlp", "About", nullptr));
        actionEtc->setText(QCoreApplication::translate("yt_dlp", "Etc", nullptr));
        ytLink->setText(QCoreApplication::translate("yt_dlp", "Youtube Link", nullptr));
        gifLabel->setText(QString());
        saveButton->setText(QCoreApplication::translate("yt_dlp", "Select Save Folder", nullptr));
        dlButton->setText(QCoreApplication::translate("yt_dlp", "Download", nullptr));
        outputDirLabel->setText(QString());
        labelTotalSize->setText(QCoreApplication::translate("yt_dlp", "TextLabel", nullptr));
        labelSpeed->setText(QCoreApplication::translate("yt_dlp", "TextLabel", nullptr));
        labelETA->setText(QCoreApplication::translate("yt_dlp", "TextLabel", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("yt_dlp", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class yt_dlp: public Ui_yt_dlp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YT_DLP_H
