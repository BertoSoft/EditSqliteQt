/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
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
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *spTablas;
    QToolButton *btnRefrescar;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *tabTabla;
    QFrame *frame;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblCampo2;
    QLabel *lblCampo2_3;
    QLabel *lblCampo;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblReg;
    QLabel *lblId;
    QLineEdit *txtCampo;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLabel *label_2;
    QToolButton *btnModificar;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QMenu *menuArchivo;
    QMenu *menuEdicion;
    QStatusBar *sbPrincipal;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(776, 611);
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
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setObjectName("gridLayout_4");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(tab_2);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        spTablas = new QComboBox(tab_2);
        spTablas->setObjectName("spTablas");

        horizontalLayout->addWidget(spTablas);

        btnRefrescar = new QToolButton(tab_2);
        btnRefrescar->setObjectName("btnRefrescar");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/refrescar.jpeg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnRefrescar->setIcon(icon3);
        btnRefrescar->setIconSize(QSize(24, 24));
        btnRefrescar->setAutoRaise(true);

        horizontalLayout->addWidget(btnRefrescar);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 10);

        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        tabTabla = new QTableWidget(tab_2);
        tabTabla->setObjectName("tabTabla");
        tabTabla->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tabTabla->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tabTabla->setGridStyle(Qt::PenStyle::SolidLine);
        tabTabla->verticalHeader()->setVisible(true);
        tabTabla->verticalHeader()->setProperty("showSortIndicator", QVariant(false));

        horizontalLayout_4->addWidget(tabTabla);

        frame = new QFrame(tab_2);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 310, 391));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lblCampo2 = new QLabel(layoutWidget);
        lblCampo2->setObjectName("lblCampo2");

        horizontalLayout_2->addWidget(lblCampo2);

        lblCampo2_3 = new QLabel(layoutWidget);
        lblCampo2_3->setObjectName("lblCampo2_3");

        horizontalLayout_2->addWidget(lblCampo2_3);

        lblCampo = new QLabel(layoutWidget);
        lblCampo->setObjectName("lblCampo");

        horizontalLayout_2->addWidget(lblCampo);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lblReg = new QLabel(layoutWidget);
        lblReg->setObjectName("lblReg");
        lblReg->setFrameShape(QFrame::Shape::Panel);
        lblReg->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_3->addWidget(lblReg);

        lblId = new QLabel(layoutWidget);
        lblId->setObjectName("lblId");
        lblId->setFrameShape(QFrame::Shape::Panel);
        lblId->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_3->addWidget(lblId);

        txtCampo = new QLineEdit(layoutWidget);
        txtCampo->setObjectName("txtCampo");

        horizontalLayout_3->addWidget(txtCampo);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(170, 142, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_5->addWidget(label_3);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_5->addWidget(label_2);

        btnModificar = new QToolButton(layoutWidget);
        btnModificar->setObjectName("btnModificar");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnModificar->setIcon(icon4);
        btnModificar->setIconSize(QSize(24, 24));
        btnModificar->setPopupMode(QToolButton::ToolButtonPopupMode::DelayedPopup);
        btnModificar->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        btnModificar->setAutoRaise(true);

        horizontalLayout_5->addWidget(btnModificar);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 142, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 20);

        horizontalLayout_4->addWidget(frame);

        horizontalLayout_4->setStretch(0, 10);
        horizontalLayout_4->setStretch(1, 6);

        verticalLayout_2->addLayout(horizontalLayout_4);


        gridLayout_4->addLayout(verticalLayout_2, 0, 0, 1, 1);

        tabPrincipal->addTab(tab_2, QString());

        gridLayout->addWidget(tabPrincipal, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 776, 23));
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

        tabPrincipal->setCurrentIndex(1);


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
        label->setText(QCoreApplication::translate("MainWindow", "Tabla", nullptr));
        btnRefrescar->setText(QString());
        lblCampo2->setText(QCoreApplication::translate("MainWindow", "N\302\272 Reg.", nullptr));
        lblCampo2_3->setText(QCoreApplication::translate("MainWindow", "_id ", nullptr));
        lblCampo->setText(QCoreApplication::translate("MainWindow", "Fecha 1", nullptr));
        lblReg->setText(QString());
        lblId->setText(QString());
        label_3->setText(QString());
        label_2->setText(QString());
        btnModificar->setText(QCoreApplication::translate("MainWindow", " Modificar Valor", nullptr));
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
