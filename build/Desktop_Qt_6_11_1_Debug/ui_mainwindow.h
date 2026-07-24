/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbrir_Archivo;
    QAction *actionSAlir;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabPrincipal;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QTreeWidget *arbolTablas;
    QWidget *tab_2;
    QMenuBar *menubar;
    QMenu *menuArchivo;
    QMenu *menuEdicion;
    QStatusBar *sbPrincipal;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(934, 611);
        MainWindow->setMaximumSize(QSize(991, 611));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icono.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        actionAbrir_Archivo = new QAction(MainWindow);
        actionAbrir_Archivo->setObjectName("actionAbrir_Archivo");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/abrir.jpeg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionAbrir_Archivo->setIcon(icon1);
        actionSAlir = new QAction(MainWindow);
        actionSAlir->setObjectName("actionSAlir");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/salir.jpeg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSAlir->setIcon(icon2);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        tabPrincipal = new QTabWidget(centralwidget);
        tabPrincipal->setObjectName("tabPrincipal");
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName("gridLayout_2");
        arbolTablas = new QTreeWidget(tab);
        arbolTablas->setObjectName("arbolTablas");

        gridLayout_2->addWidget(arbolTablas, 0, 0, 1, 1);

        tabPrincipal->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabPrincipal->addTab(tab_2, QString());

        gridLayout->addWidget(tabPrincipal, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 934, 23));
        menuArchivo = new QMenu(menubar);
        menuArchivo->setObjectName("menuArchivo");
        menuEdicion = new QMenu(menubar);
        menuEdicion->setObjectName("menuEdicion");
        MainWindow->setMenuBar(menubar);
        sbPrincipal = new QStatusBar(MainWindow);
        sbPrincipal->setObjectName("sbPrincipal");
        MainWindow->setStatusBar(sbPrincipal);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menuArchivo->menuAction());
        menubar->addAction(menuEdicion->menuAction());
        menuArchivo->addAction(actionAbrir_Archivo);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionSAlir);
        toolBar->addAction(actionAbrir_Archivo);

        retranslateUi(MainWindow);

        tabPrincipal->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAbrir_Archivo->setText(QCoreApplication::translate("MainWindow", "Abrir Base de Datos", nullptr));
        actionSAlir->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = arbolTablas->headerItem();
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("MainWindow", "Esquema", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "Tipo", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "Nombre", nullptr));
        tabPrincipal->setTabText(tabPrincipal->indexOf(tab), QCoreApplication::translate("MainWindow", "Estructura", nullptr));
        tabPrincipal->setTabText(tabPrincipal->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Hoja de datos", nullptr));
        menuArchivo->setTitle(QCoreApplication::translate("MainWindow", "Archivo", nullptr));
        menuEdicion->setTitle(QCoreApplication::translate("MainWindow", "Edicion", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
