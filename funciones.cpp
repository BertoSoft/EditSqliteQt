#include "funciones.h"

#include <QString>
#include <QScreen>
#include <QGuiApplication>


Funciones::Funciones(){

}

Funciones::~Funciones(){

}

QString Funciones::getAppName(){

    return "EditSqlliteQt 1.0";
}

QPoint Funciones::getxyCentroPantalla(){

    QRect   xyPantalla;
    QScreen *pantalla = QGuiApplication::primaryScreen();

    if(pantalla){
        xyPantalla = pantalla->availableGeometry();
        int x = (xyPantalla.width() / 2);
        int y = (xyPantalla.height() / 2);

        return QPoint(x, y);
    }

    return QPoint();
}