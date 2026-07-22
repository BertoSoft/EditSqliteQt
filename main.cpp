#include "mainwindow.h"
#include "funciones.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //
    // Aqui empiezo yo
    //
    w.resize(640,480);

    QPoint xyCentroPantalla = Funciones().getxyCentroPantalla();
    int x = (xyCentroPantalla.x() - (w.width() / 2));
    int y = (xyCentroPantalla.y() - (w.height() / 2));
    w.move(x, y);

    w.setWindowTitle(Funciones().getAppName());
    w.setWindowIcon(QIcon(":/icono.png"));
    w.move(x, y);

    w.show();
    return QApplication::exec();
}
