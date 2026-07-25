#include "admindb.h"

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

AdminDb::AdminDb() {

}

AdminDb::~AdminDb(){

}

bool AdminDb::isSQLite(QString strRutaArchivo){
    QSqlDatabase    dbSql;
    QSqlQuery       sql;
    QString         strSql;

    if(strRutaArchivo.isEmpty()){
        return false;
    }
    dbSql = QSqlDatabase::addDatabase("QSQLITE", "con_1");
    dbSql.setDatabaseName(strRutaArchivo);
    if(dbSql.open()){

        dbSql.close();
        QSqlDatabase::removeDatabase("con_1");
        return true;
    }
    else{
        return false;
    }
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

QList<QString> AdminDb::getAllSentenciasSql(QString strRutaArchivo){
    QList<QString>  lista;
    QSqlDatabase    dbSql;
    QSqlQuery       sql;
    QString         strSql;

    dbSql = QSqlDatabase::addDatabase("QSQLITE", "con_3");
    dbSql.setDatabaseName(strRutaArchivo);

    if(dbSql.open()){
        sql     = QSqlQuery(dbSql);
        strSql  = "SELECT sql FROM sqlite_master WHERE type='table'";
        sql.exec(strSql);
    }
    sql.first();
    while (sql.isValid()) {
        lista.append(sql.value(0).toString());
        sql.next();
    }

    dbSql.close();
    QSqlDatabase::removeDatabase("con_3");











    return lista;
}