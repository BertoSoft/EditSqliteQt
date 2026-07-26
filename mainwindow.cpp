#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "admindb.h"
#include "funciones.h"

#include <QTimer>
#include <QScreen>
#include <QDate>
#include <QTime>
#include <QStringList>
#include <QFileDialog>
#include <QKeyEvent>
#include <QMessageBox>
#include <QTableWidgetItem>

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
void MainWindow::resizeEvent(QResizeEvent *ev){
    QSize newTamano = ev->size();
    QSize oldTamano = ev->oldSize();

    //
    // Por aqui pasa cada vez que cambia tamaño de la ventana
    //




    QMainWindow::resizeEvent(ev);
}

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
        "Archivos SQLite (*.db *.old) ;; Todos los Archivos (*.*)"
        );

    //
    // Si no esta vacio
    //
    if(!strRutaFile.isEmpty()){

        //
        // Si es SQLite
        //
        if(AdminDb().isSQLite(strRutaFile)){

            //
            // Todo Ok , Abrimos el archivo
            //
            ui->arbolTablas->clear();
            lblTexto->setText(strRutaFile);
            refrescaArbolTablas();
            initSp();
            refrescaTabla();
        }

        //
        // No es SQLite
        //
        else{
            QMessageBox::information(
                this,
                Funciones().getAppName(),
                "No se reconoce este formato de Archivo...");
        }
    }




}

void MainWindow::initUi(){

    centrarApp();
    initBarraEstado();
    initArbolTablas();
    initSp();
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

    lblTexto->setStyleSheet("color: black; background-color: lightgray; font-size: 11pt; font-weight: bold");
    lblFecha->setStyleSheet("color: black; background-color: lightgray; font-size: 11pt; font-weight: bold");
    lblHora->setStyleSheet("color: black; background-color: lightgray; font-size: 11pt; font-weight: bold");

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

    //ui->arbolTablas->header()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->arbolTablas->setColumnWidth(0, 200);
    //ui->arbolTablas->header()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->arbolTablas->setColumnWidth(1, 125);

    //
    // 1. Permitir que el contenido defina el ancho real de las columnas
    //
    ui->arbolTablas->header()->setSectionResizeMode(2, QHeaderView::ResizeToContents);

    //
    // 2. Desactivar el estiramiento obligatorio de la última columna
    //
    ui->arbolTablas->header()->setStretchLastSection(false);


}

void MainWindow::initSp(){
    QList<QString>  listaTablas;


    ui->spTablas->clear();
    if(lblTexto->text() != Funciones().getAppName()){
        listaTablas = AdminDb().getAllTablas(lblTexto->text());
        ui->spTablas->addItems(listaTablas);
    }
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

void MainWindow::refrescaArbolTablas(){
    QList<Funciones::datTablas>     listaTablasSql;
    QString                         str;
    int                             i = 0;
    int                             j = 0;

    //
    // Obtenemos el listado de tablas y sql
    //
    listaTablasSql = AdminDb().getAllTablasAndSql(lblTexto->text());


    //
    // Creamos la primera rama de tablas(n), con itemInicial
    //
    QTreeWidgetItem *itemInicial = new QTreeWidgetItem(ui->arbolTablas);

    str = "Tablas(";
    str.append(QString::number(listaTablasSql.count()));
    str.append(")");

    itemInicial->setText(0, str);

    //
    // Creamos la primera rama con los nombres de las tablas, en item0
    //
    i = 0;
    while (i<listaTablasSql.count()) {
        j = 0;
        QTreeWidgetItem *item0 = new QTreeWidgetItem(itemInicial);
        item0->setText(0, listaTablasSql[i].strNombre);
        item0->setText(2, listaTablasSql[i].strSql);

        //
        // Por cada tabla creamos una subrama con los campos, item1
        //
        QList<Funciones::datCampos> listaCampos = AdminDb().getAllCampos(
            lblTexto->text(),
            listaTablasSql[i].strNombre
            );

        while (j < listaCampos.count()) {
            QTreeWidgetItem *item1 = new QTreeWidgetItem(item0);

            str = listaCampos[j].strNombre;
            str.prepend("\"");
            str.append("\"  ");
            str.append(listaCampos[j].strTipo);


            item1->setText(0, listaCampos[j].strNombre);
            item1->setText(1, listaCampos[j].strTipo);
            item1->setText(2, str);
            j++;
        }

        i++;
    }



}

void MainWindow::refrescaTabla(){
    QList<Funciones::datCampos> listaCampos;
    QList<QVariantMap>          listaDatosVariant;
    QList<QString>              listaHeaders;
    int i, j;

    listaCampos = AdminDb().getAllCampos(lblTexto->text(), ui->spTablas->currentText());

    //
    // Numero de columnas = al numero de campos
    //
    ui->tabTabla->setColumnCount(listaCampos.count());
    i = 0;
    while (i < listaCampos.count()) {
        listaHeaders.append(listaCampos[i].strNombre);
        i++;
    }
    ui->tabTabla->setHorizontalHeaderLabels(listaHeaders);


    listaDatosVariant = AdminDb().getAllDatosTabla(lblTexto->text(), ui->spTablas->currentText());

    //
    // Ahora Rellenamos la tabla
    //
    i = 0;
    j = 0;
    while (i < listaDatosVariant.count()) {
        ui->tabTabla->setRowCount(i + 1);
        QVariantMap dato = listaDatosVariant[i];

        while (j < listaCampos.count()) {
            QTableWidgetItem *item = new QTableWidgetItem(dato[listaCampos[j].strNombre].toString());
            ui->tabTabla->setItem(i, j, item);
            j++;
        }
        i++;
        j = 0;
    }
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


void MainWindow::on_spTablas_activated(int index){
    ui->tabTabla->clear();
    refrescaTabla();
}

