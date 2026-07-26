#ifndef ADMINDB_H
#define ADMINDB_H

#include "funciones.h"

#include <QString>


class AdminDb
{
public:
    AdminDb();
    ~AdminDb();

    //
    // Funciones Publicas
    //
    bool                            isSQLite(QString strRutaArchivo);
    QList<QString>                  getAllTablas(QString strRutaArchivo);
    QList<Funciones::datTablas>     getAllTablasAndSql(QString strRutaArchivo);
    QList<Funciones::datCampos>     getAllCampos(QString strBd, QString strTabla);
    QList<QVariantMap>              getAllDatosTabla(QString strBd, QString strTabla);

};

#endif // ADMINDB_H
