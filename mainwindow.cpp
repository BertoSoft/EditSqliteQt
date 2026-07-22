#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "funciones.h"

#include <QTimer>

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

void MainWindow::refrescaReloj(){
}

void MainWindow::salir(){
}

