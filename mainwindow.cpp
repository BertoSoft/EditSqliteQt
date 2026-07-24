#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "funciones.h"

#include <QTimer>
#include <QScreen>
#include <QDate>
#include <QTime>
#include <QStringList>
#include <QFileDialog>
#include <QKeyEvent>

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
    this->resize(1200, 600);
    initReloj();
    initUi();
}

MainWindow::~MainWindow(){

    delete ui;
}

//
// Funciones sobreescritas, protected
//
void MainWindow::keyPressEvent(QKeyEvent *ev){

    //
    // Si se pulsa ESC en MainWindow, Salimos
    //
    if(ev->key() == Qt::Key_Escape){
        salir();
    }

    QWidget::keyPressEvent(ev);
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
void MainWindow::abrirBaseDatos(){

    //
    // Iniciamos el dialogo de abrir archivo
    //
    QString strRutaFile = QFileDialog::getOpenFileName(
        this,
        Funciones().getAppName(),
        QDir::homePath(),
        "Archivos SQLite (*.db)(*.old) ;; Todos los Archivos (*.*)"
        );

    //
    // Comprobar que existe el archivo
    //
    if(strRutaFile.isEmpty()){

    }




}

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
    ui->sbPrincipal->setSizeGripEnabled(false);

    lblTexto->setStyleSheet("color: blue; background-color: lightgray; font-size: 11pt; font-weight: bold");
    lblFecha->setStyleSheet("color: blue; background-color: lightgray; font-size: 11pt; font-weight: bold");
    lblHora->setStyleSheet("color: blue; background-color: lightgray; font-size: 11pt; font-weight: bold");

    lblHora->setFrameShape(QFrame::Shape::WinPanel);
    lblFecha->setFrameShape(QFrame::Shape::WinPanel);
    lblTexto->setFrameShape(QFrame::Shape::WinPanel);

    lblHora->setFrameShadow(QFrame::Shadow::Sunken);
    lblFecha->setFrameShadow(QFrame::Shadow::Sunken);
    lblTexto->setFrameShadow(QFrame::Shadow::Sunken);

    ui->sbPrincipal->addPermanentWidget(lblFecha, 3);
    ui->sbPrincipal->addPermanentWidget(lblHora, 1);
    ui->sbPrincipal->addWidget(lblTexto, 15);

    lblTexto->setText(Funciones().getAppName());
    refrescaReloj();
}

void MainWindow::initArbolTablas(){

    //
    // Tres columnas
    //
    ui->arbolTablas->setColumnCount(3);
    ui->arbolTablas->setHeaderLabels(QStringList() << "Nombre" << "Tipo" << "Esquema");
    ui->arbolTablas->setColumnWidth(0, 250);
    ui->arbolTablas->setColumnWidth(1, 150);
    ui->arbolTablas->header()->setSectionResizeMode(2, QHeaderView::Stretch);


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
    exit(0);
}

//
// Funciones Actions
//
void MainWindow::on_actionAbrir_Archivo_triggered(){
    abrirBaseDatos();
}


void MainWindow::on_actionSAlir_triggered(){
    salir();
}

