#include "mainwindow.h"
#include "funciones.h"

#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //
    // Aqui empiezo yo
    //
    w.setWindowTitle(Funciones().getAppName());
    w.setWindowIcon(QIcon(":/icono.png"));
    w.show();

    return QApplication::exec();
}
