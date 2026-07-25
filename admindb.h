#ifndef ADMINDB_H
#define ADMINDB_H

#include <QString>


class AdminDb
{
public:
    AdminDb();
    ~AdminDb();

    //
    // Funciones Publicas
    //
    bool            isSQLite(QString strRutaArchivo);
    QList<QString>  getAllTablas(QString strRutaArchivo);
    QList<QString>  getAllSentenciasSql(QString strRutaArchivo);


};

#endif // ADMINDB_H
