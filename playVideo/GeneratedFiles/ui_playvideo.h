/********************************************************************************
** Form generated from reading UI file 'playvideo.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYVIDEO_H
#define UI_PLAYVIDEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_playVideoClass
{
public:
    QWidget *centralWidget;
    QPushButton *selectButton;
    QLabel *outLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *playVideoClass)
    {
        if (playVideoClass->objectName().isEmpty())
            playVideoClass->setObjectName(QStringLiteral("playVideoClass"));
        playVideoClass->resize(747, 476);
        centralWidget = new QWidget(playVideoClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        selectButton = new QPushButton(centralWidget);
        selectButton->setObjectName(QStringLiteral("selectButton"));
        selectButton->setGeometry(QRect(360, 400, 75, 23));
        outLabel = new QLabel(centralWidget);
        outLabel->setObjectName(QStringLiteral("outLabel"));
        outLabel->setGeometry(QRect(9, 1, 731, 381));
        playVideoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(playVideoClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 747, 21));
        playVideoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(playVideoClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        playVideoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(playVideoClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        playVideoClass->setStatusBar(statusBar);

        retranslateUi(playVideoClass);

        QMetaObject::connectSlotsByName(playVideoClass);
    } // setupUi

    void retranslateUi(QMainWindow *playVideoClass)
    {
        playVideoClass->setWindowTitle(QApplication::translate("playVideoClass", "playVideo", 0));
        selectButton->setText(QApplication::translate("playVideoClass", "select", 0));
        outLabel->setText(QApplication::translate("playVideoClass", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class playVideoClass: public Ui_playVideoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYVIDEO_H
