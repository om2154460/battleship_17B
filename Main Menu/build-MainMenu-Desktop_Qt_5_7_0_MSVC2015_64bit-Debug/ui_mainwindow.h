/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Game;
    QAction *actionLoad_Game;
    QAction *actionDatabase;
    QAction *actionInstructions;
    QAction *actionAbout;
    QAction *actionExit_Program;
    QAction *actionSave_Game;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuMain_Menu;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(578, 575);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionNew_Game = new QAction(MainWindow);
        actionNew_Game->setObjectName(QStringLiteral("actionNew_Game"));
        actionLoad_Game = new QAction(MainWindow);
        actionLoad_Game->setObjectName(QStringLiteral("actionLoad_Game"));
        actionDatabase = new QAction(MainWindow);
        actionDatabase->setObjectName(QStringLiteral("actionDatabase"));
        actionInstructions = new QAction(MainWindow);
        actionInstructions->setObjectName(QStringLiteral("actionInstructions"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionExit_Program = new QAction(MainWindow);
        actionExit_Program->setObjectName(QStringLiteral("actionExit_Program"));
        actionSave_Game = new QAction(MainWindow);
        actionSave_Game->setObjectName(QStringLiteral("actionSave_Game"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 578, 21));
        menuMain_Menu = new QMenu(menuBar);
        menuMain_Menu->setObjectName(QStringLiteral("menuMain_Menu"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMain_Menu->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuMain_Menu->addAction(actionNew_Game);
        menuMain_Menu->addAction(actionSave_Game);
        menuMain_Menu->addAction(actionLoad_Game);
        menuMain_Menu->addAction(actionExit_Program);
        menuEdit->addAction(actionDatabase);
        menuHelp->addAction(actionInstructions);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);
        QObject::connect(actionExit_Program, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Battleship", 0));
        actionNew_Game->setText(QApplication::translate("MainWindow", "New Game", 0));
        actionLoad_Game->setText(QApplication::translate("MainWindow", "Load Game", 0));
        actionDatabase->setText(QApplication::translate("MainWindow", "Database", 0));
        actionInstructions->setText(QApplication::translate("MainWindow", "Instructions", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionExit_Program->setText(QApplication::translate("MainWindow", "Exit Program", 0));
        actionSave_Game->setText(QApplication::translate("MainWindow", "Save Game", 0));
        menuMain_Menu->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
