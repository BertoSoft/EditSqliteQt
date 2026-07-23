#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "funciones.h"

#include <QTimer>
#include <QScreen>
#include <QDate>
#include <QTime>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){

    ui->setupUi(this);

    //
    // Instalamos los filtros de eventos
    //
    qApp->installEventFilter(this);
    this->installEventFilter(this);

    //
    // Desarrollamos la App
    //
    this->resize(800, 400);
    initReloj();
    initUi();

}

MainWindow::~MainWindow(){

    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *ev){

    //
    // Si se pulsa la x de salir , Salimos
    //
    if(obj == this && ev->type() == QEvent::Close){
        salir();
    }


    //
    // Devolvemos obj, y ev para que sean procesados por Qt
    //

    return QObject::eventFilter(obj, ev);
}

//
// Funciones de MainWindow
//
void MainWindow::initUi(){

    centrarApp();
    initBarraEstado();
    initArbolTablas();

}

void MainWindow::initReloj(void){

    //
    // Hacemos que cada segundo refresque la hora
    //
    QTimer *reloj = new QTimer();


    //
    // reloj                        = puntero al objeto QTimer
    // timeout                      = señal que se emite cuando pasa el tiempo de reloj
    // [this](){refrescaReloj();}   = es la funcion lambda que se envia, el this es para acceder a los metodos de MainWindow
    //

    connect(reloj, &QTimer::timeout, [this](){refrescaReloj();});
    reloj->start(1000);
}

void MainWindow::initBarraEstado(){


    //
    // Establezco la barra de estado
    //
    ui->bePrincipal->setSizeGripEnabled(false);

    lblTexto->setStyleSheet("color: blue; background-color: lightgray; font-size: 11pt; font-weight: bold");
    lblFecha->setStyleSheet("color: blue; background-color: lightgray; font-size: 11pt; font-weight: bold");
    lblHora->setStyleSheet("color: blue; background-color: lightgray; font-size: 11pt; font-weight: bold");

    lblHora->setFrameShape(QFrame::Shape::WinPanel);
    lblFecha->setFrameShape(QFrame::Shape::WinPanel);
    lblTexto->setFrameShape(QFrame::Shape::WinPanel);

    lblHora->setFrameShadow(QFrame::Shadow::Sunken);
    lblFecha->setFrameShadow(QFrame::Shadow::Sunken);
    lblTexto->setFrameShadow(QFrame::Shadow::Sunken);

    ui->bePrincipal->addPermanentWidget(lblFecha, 3);
    ui->bePrincipal->addPermanentWidget(lblHora, 1);
    ui->bePrincipal->addWidget(lblTexto, 15);

    lblTexto->setText(Funciones().getAppName());
    refrescaReloj();

}

void MainWindow::initArbolTablas(){

    //
    // Tres columnas
    //
    ui->arbolTablas->setColumnCount(3);
    ui->arbolTablas->setHeaderLabels(QStringList() << "Nombre" << "Tipo" << "Esquema");


}

void MainWindow::refrescaReloj(){
    QLocale locale;
    QDate   fecha   = QDate::currentDate();
    QTime   hora    = QTime::currentTime();

    //
    // Rellenamos fecha y hora
    //
    lblFecha->setText(locale.toString(fecha, "dddd ',' dd 'de' MMMM 'de' yyyy"));
    lblHora->setText(hora.toString("hh:mm:ss"));
}

void MainWindow::centrarApp(){
    QScreen *pantalla = QGuiApplication::primaryScreen();
    QRect   geometriaPantalla = pantalla->availableGeometry();

    int x = (geometriaPantalla.width()/2) - (this->width()/2);
    int y = (geometriaPantalla.height()/2) - (this->height()/2);

    this->move(x, y);
}

void MainWindow::salir(){
}

