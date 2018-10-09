/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionGreyscale;
    QAction *actionSave_as;
    QAction *actionColor;
    QAction *actionLamba;
    QAction *actionRevert_colors;
    QAction *actionPlot_grey_level;
    QAction *actionLaunch_magnifier;
    QAction *actionGama;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QPushButton *btnSaveAsInitialImage;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOpen;
    QMenu *menuLaunch_Smart_Dialog;
    QMenu *menuLaunch_Smart_Dialog_2;
    QMenu *menuTools;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(825, 490);
        actionGreyscale = new QAction(MainWindow);
        actionGreyscale->setObjectName(QStringLiteral("actionGreyscale"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionColor = new QAction(MainWindow);
        actionColor->setObjectName(QStringLiteral("actionColor"));
        actionLamba = new QAction(MainWindow);
        actionLamba->setObjectName(QStringLiteral("actionLamba"));
        actionRevert_colors = new QAction(MainWindow);
        actionRevert_colors->setObjectName(QStringLiteral("actionRevert_colors"));
        actionPlot_grey_level = new QAction(MainWindow);
        actionPlot_grey_level->setObjectName(QStringLiteral("actionPlot_grey_level"));
        actionLaunch_magnifier = new QAction(MainWindow);
        actionLaunch_magnifier->setObjectName(QStringLiteral("actionLaunch_magnifier"));
        actionGama = new QAction(MainWindow);
        actionGama->setObjectName(QStringLiteral("actionGama"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setEnabled(true);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName(QStringLiteral("scrollAreaWidgetContents_5"));
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 396, 366));
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents_5);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(scrollAreaWidgetContents_5);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 16777215));
        label->setAutoFillBackground(false);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_2->addWidget(label);

        scrollArea->setWidget(scrollAreaWidgetContents_5);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        scrollArea_2 = new QScrollArea(centralWidget);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setAcceptDrops(false);
        scrollArea_2->setAutoFillBackground(false);
        scrollArea_2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_6 = new QWidget();
        scrollAreaWidgetContents_6->setObjectName(QStringLiteral("scrollAreaWidgetContents_6"));
        scrollAreaWidgetContents_6->setGeometry(QRect(0, 0, 396, 366));
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents_6);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(scrollAreaWidgetContents_6);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(16777215, 16777215));
        label_2->setAutoFillBackground(false);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout->addWidget(label_2);

        scrollArea_2->setWidget(scrollAreaWidgetContents_6);

        gridLayout->addWidget(scrollArea_2, 0, 1, 1, 1);

        btnSaveAsInitialImage = new QPushButton(centralWidget);
        btnSaveAsInitialImage->setObjectName(QStringLiteral("btnSaveAsInitialImage"));

        gridLayout->addWidget(btnSaveAsInitialImage, 1, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 825, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuOpen = new QMenu(menuFile);
        menuOpen->setObjectName(QStringLiteral("menuOpen"));
        menuLaunch_Smart_Dialog = new QMenu(menuBar);
        menuLaunch_Smart_Dialog->setObjectName(QStringLiteral("menuLaunch_Smart_Dialog"));
        menuLaunch_Smart_Dialog_2 = new QMenu(menuLaunch_Smart_Dialog);
        menuLaunch_Smart_Dialog_2->setObjectName(QStringLiteral("menuLaunch_Smart_Dialog_2"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuLaunch_Smart_Dialog->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuFile->addAction(menuOpen->menuAction());
        menuFile->addAction(actionSave_as);
        menuOpen->addAction(actionGreyscale);
        menuOpen->addAction(actionColor);
        menuLaunch_Smart_Dialog->addAction(menuLaunch_Smart_Dialog_2->menuAction());
        menuLaunch_Smart_Dialog_2->addAction(actionLamba);
        menuLaunch_Smart_Dialog_2->addAction(actionGama);
        menuTools->addAction(actionRevert_colors);
        menuTools->addAction(actionPlot_grey_level);
        menuTools->addAction(actionLaunch_magnifier);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ImageProcessingTool", Q_NULLPTR));
        actionGreyscale->setText(QApplication::translate("MainWindow", "Greyscale", Q_NULLPTR));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as", Q_NULLPTR));
        actionColor->setText(QApplication::translate("MainWindow", "Color", Q_NULLPTR));
        actionLamba->setText(QApplication::translate("MainWindow", "Lambda", Q_NULLPTR));
        actionRevert_colors->setText(QApplication::translate("MainWindow", "Revert colors", Q_NULLPTR));
        actionPlot_grey_level->setText(QApplication::translate("MainWindow", "Plot grey level", Q_NULLPTR));
        actionLaunch_magnifier->setText(QApplication::translate("MainWindow", "Launch magnifier", Q_NULLPTR));
        actionGama->setText(QApplication::translate("MainWindow", "Gama", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QString());
        btnSaveAsInitialImage->setText(QApplication::translate("MainWindow", "Save as Initial Image", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuOpen->setTitle(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        menuLaunch_Smart_Dialog->setTitle(QApplication::translate("MainWindow", "Utils", Q_NULLPTR));
        menuLaunch_Smart_Dialog_2->setTitle(QApplication::translate("MainWindow", "Launch Smart Dialog", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
