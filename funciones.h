#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <QString>
#include <QRect>

class Funciones
{
public:
    Funciones();
    ~Funciones();

    //
    // Variables Globales
    //

    //
    // Estructuras
    //
    struct datTablas{
        QString strNombre;
        QString strSql;
    };

    struct datCampos{
        QString strNombre;
        QString strTipo;
        bool    noNulo;
        QString strValorDefecto;
        bool    isClavePrimaria;
    };

    //
    // Funciones
    //
    QString getAppName();

};

#endif // FUNCIONES_H
