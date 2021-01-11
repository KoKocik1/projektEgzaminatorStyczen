#ifndef BAZADANYCH_H
#define BAZADANYCH_H
#include "student.h"
#include "pk_ppk.h"
#include "dyplomowy.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSql>
#include <QtSql/QSqlRecord>

class bazaDanych
{
private:
    Student* m_student;
    PK_PPK* m_pk;
    PK_PPK* m_ppk;
    DYPLOMOWY* m_dyplomowy;
    QString m_nazwaBazy;
    QSqlDatabase m_db;
    QSqlQuery query;


public:
    bazaDanych(Student*,PK_PPK*,PK_PPK*,DYPLOMOWY*,QString);
    bazaDanych(QString);
    void stworzTabele();
    void wypelnijTabeleStudenci();
    void wypelnijTabelePytania();
    void zapisBazaDoPlik();
    QString selectPodstAPK();
    QString selectPodstBPK();
    QString selectPodstCPK();
    QString selectSredniePK();
    QString selectTrudnePK();
    QString selectPodstAPPK();
    QString selectPodstBPPK();
    QString selectPodstCPPK();
    QString selectSredniePPK();
    QString selectTrudnePPK();
    QString selectDyplomA();
    QString selectDyplomB();
    QString selectDyplomC();
    QString selectDyplomD();
    QString selectStudenci(int);
    QString select(QString);
    QString selectPK();
    QString selectPPK();
    QString selectDYPLOM();
    QString selectStudenci();
    void wypelnijTabelePytania(QStringList,int,int);
    void wypelnijStudenci(QStringList,QStringList,int,QList<double>);

};

#endif // BAZADANYCH_H
