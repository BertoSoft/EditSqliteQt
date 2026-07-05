#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    //
    // Comprobar commit portatil
    //



    return QApplication::exec();
}
