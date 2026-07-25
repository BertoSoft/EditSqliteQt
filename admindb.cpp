#include "admindb.h"

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlField>

AdminDb::AdminDb() {

}

AdminDb::~AdminDb(){

}

bool AdminDb::isSQLite(QString strRutaArchivo){
    QSqlDatabase    dbSql;
    QString         strSql;
    bool            exito = false;

    if(strRutaArchivo.isEmpty()){
        return false;
    }

    dbSql = QSqlDatabase::addDatabase("QSQLITE", "con_1");
    dbSql.setDatabaseName(strRutaArchivo);
    if(dbSql.open()){
        {
            QSqlQuery sql = QSqlQuery(dbSql);

            strSql = "PRAGMA table_info(";
            strSql.append("sqlite_sequence");
            strSql.append(")");

            if(sql.exec(strSql)){
                exito = true;
            }
        }
        dbSql.close();
    }

    dbSql = QSqlDatabase();

    QSqlDatabase::removeDatabase("con_1");
    return exito;
}

QList<QString> AdminDb::getAllTablas(QString strRutaArchivo){
    QList<QString>  listaTablas, listaTablasOrdenada;
    QSqlDatabase    dbSql;

    dbSql = QSqlDatabase::addDatabase("QSQLITE", "con_2");
    dbSql.setDatabaseName(strRutaArchivo);

    //
    // Obtenemos la lista
    //
    if(dbSql.open()){
        listaTablas = dbSql.tables(QSql::Tables);
        dbSql.close();
        dbSql = QSqlDatabase();
        QSqlDatabase::removeDatabase("con_2");
    }

    //
    // Ordenamos la Lista
    //
    int i = 0;
    while (i<listaTablas.count()) {
        if(listaTablas[i] != "android_metadata" && listaTablas[i] != "sqlite_sequence"){
            listaTablasOrdenada.append(listaTablas[i]);
        }
        i++;
    }
    listaTablasOrdenada.append("android_metadata");
    listaTablasOrdenada.append("sqlite_sequence");

    return listaTablasOrdenada;
}

QList<Funciones::datCampos> AdminDb::getAllCampos(QString strBd, QString strTabla){
    QList<Funciones::datCampos>     listaCampos;
    QSqlDatabase                    dbSql;
    QString                         strSql;
    QSqlQuery                       sql;

    dbSql = QSqlDatabase::addDatabase("QSQLITE", "con_3");
    dbSql.setDatabaseName(strBd);
    sql = QSqlQuery(dbSql);

    strSql = "PRAGMA table_info(";
    strSql.append(strTabla);
    strSql.append(")");

    if(dbSql.open()){
        sql.exec(strSql);
        sql.first();
        while (sql.isValid()) {
            Funciones::datCampos    dato;

            dato.strNombre          = sql.value("name").toString();
            dato.strTipo            = sql.value("type").toString();
            dato.noNulo             = sql.value("notnull").toBool();
            dato.strValorDefecto    = sql.value("dflt_value").toString();
            dato.isClavePrimaria    = sql.value("name").toBool();

            listaCampos.append(dato);
            sql.next();
        }
    }

    dbSql = QSqlDatabase();
    QSqlDatabase::removeDatabase("con_3");

    return listaCampos;
}

QList<Funciones::datTablas> AdminDb::getAllTablasAndSql(QString strRutaArchivo){
    QList<Funciones::datTablas>     listaTablasSql;
    QList<Funciones::datTablas>     listaTmp;
    QList<QString>                  listaTablas;
    QSqlDatabase                    dbSql;
    QSqlQuery                       sql;
    QString                         strSql;

    //
    // Obtengo una lista de tablas con QSQL::Tables
    //
    listaTablas = getAllTablas(strRutaArchivo);

    //
    // Obtengo los datos de la tabla sqlite_schema
    //
    dbSql = QSqlDatabase::addDatabase("QSQLITE", "con_4");
    dbSql.setDatabaseName(strRutaArchivo);

    if(dbSql.open()){
        sql     = QSqlQuery(dbSql);
        strSql  = "SELECT *FROM sqlite_master";
        sql.exec(strSql);
    }
    sql.first();
    while (sql.isValid()) {
        Funciones::datTablas    dato;

        dato.strNombre  = sql.value(1).toString();
        dato.strSql     = sql.value(4).toString().simplified();

        listaTmp.append(dato);

        sql.next();
    }

    //
    // Ordeno los datos de sqlite_schema con los de Qsql::Tables
    //
    int i = 0;
    int j = 0;
    while (i < listaTablas.count()) {
        j = 0;
        while (j < listaTmp.count()) {
            if(listaTablas[i] == listaTmp[j].strNombre){
                Funciones::datTablas dato;

                dato.strNombre  = listaTablas[i];
                dato.strSql     = listaTmp[j].strSql;
                listaTablasSql.append(dato);
            }
            j++;
        }
        i++;
    }

    dbSql = QSqlDatabase();
    QSqlDatabase::removeDatabase("con_4");

    return listaTablasSql;
}

