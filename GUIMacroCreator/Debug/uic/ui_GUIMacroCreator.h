/********************************************************************************
** Form generated from reading UI file 'GUIMacroCreator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIMACROCREATOR_H
#define UI_GUIMACROCREATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUIMacroCreatorClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GUIMacroCreatorClass)
    {
        if (GUIMacroCreatorClass->objectName().isEmpty())
            GUIMacroCreatorClass->setObjectName(QString::fromUtf8("GUIMacroCreatorClass"));
        GUIMacroCreatorClass->resize(600, 400);
        menuBar = new QMenuBar(GUIMacroCreatorClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        GUIMacroCreatorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GUIMacroCreatorClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GUIMacroCreatorClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(GUIMacroCreatorClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        GUIMacroCreatorClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GUIMacroCreatorClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GUIMacroCreatorClass->setStatusBar(statusBar);

        retranslateUi(GUIMacroCreatorClass);

        QMetaObject::connectSlotsByName(GUIMacroCreatorClass);
    } // setupUi

    void retranslateUi(QMainWindow *GUIMacroCreatorClass)
    {
        GUIMacroCreatorClass->setWindowTitle(QApplication::translate("GUIMacroCreatorClass", "GUIMacroCreator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUIMacroCreatorClass: public Ui_GUIMacroCreatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIMACROCREATOR_H
