#include "bazadanych.h"

bazaDanych::bazaDanych(Student*student,PK_PPK*pk,PK_PPK*ppk,DYPLOMOWY*dyplomowy)
{
    m_student=student;
    m_pk=pk;
    m_ppk=ppk;
    m_dyplomowy=dyplomowy;


}
void bazaDanych::stworzTabele(){

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mydb.db");
    db.open();

    QSqlQuery query;

    query.exec("create table pytaniaPk"
               "(id integer primary key, "
               "poziom varchar(15),"
               "pytanie varchar(1000))");

    query.exec("create table pytaniaPpk"
               "(id integer primary key, "
               "poziom varchar(15),"
               "pytanie varchar(1000))");

    query.exec("create table pytaniaDyplomowe"
               "(id integer primary key, "
               "poziom varchar(15),"
               "pytanie varchar(1000))");

    query.exec("create table studenci "
              "(id integer primary key, "
              "imie varchar(20), "
              "nazwisko varchar(30), "
              "sekcja integer, "
               "srednia double)");
    db.close();
    //QSqlDatabase::removeDatabase("PK");
}
void bazaDanych::wypelnijTabelePytania(){

    PK_PPK* m_pk_ppk;
    //QSqlDatabase db= QSqlDatabase::database("QSQLITE");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mydb.db");
    db.open();

    QSqlQuery query;
    query.exec("DELETE FROM pytaniaPk WHERE id>0");
    query.exec("DELETE FROM pytaniaPpk WHERE id>0");
    query.exec("DELETE FROM pytaniaDyplomowe WHERE id>0");

    QString nazwaBazy="INSERT INTO pytaniaPk (poziom, pytanie) ";
    m_pk_ppk=m_pk;
    for(int dwaRazy=0;dwaRazy<2;dwaRazy++){
    for(int i=0;i<m_pk_ppk->get_ile_pytanPodstawowychPKa();i++){
        query.prepare(nazwaBazy+
                        "VALUES (:poziom, :pytanie)");
        query.bindValue(":poziom","podstawowyA");
          query.bindValue(":pytanie", m_pk_ppk->getWczytane_pytaniaPodstawowePKAIndeks(i));
          query.exec();
    }
    for(int i=0;i<m_pk_ppk->get_ile_pytanPodstawowychPKb();i++){
        query.prepare(nazwaBazy+
                        "VALUES (:poziom, :pytanie)");
        query.bindValue(":poziom","podstawowyB");
          query.bindValue(":pytanie", m_pk_ppk->getWczytane_pytaniaPodstawowePKBIndeks(i));
          query.exec();
    }
    for(int i=0;i<m_pk_ppk->get_ile_pytanPodstawowychPKc();i++){
        query.prepare(nazwaBazy+
                        "VALUES (:poziom, :pytanie)");
        query.bindValue(":poziom","podstawowyC");
          query.bindValue(":pytanie", m_pk_ppk->getWczytane_pytaniaPodstawowePKCIndeks(i));
          query.exec();
    }
    for(int i=0;i<m_pk_ppk->get_ile_pytanSrednichPK();i++){
        query.prepare(nazwaBazy+
                        "VALUES (:poziom, :pytanie)");
        query.bindValue(":poziom","sredni");
          query.bindValue(":pytanie", m_pk_ppk->getWczytane_pytaniaSredniePKIndeks(i));
          query.exec();
    }
    for(int i=0;i<m_pk_ppk->get_ile_pytanTrudnychPk();i++){
        query.prepare(nazwaBazy+
                        "VALUES (:poziom, :pytanie)");
        query.bindValue(":poziom","trudny");
          query.bindValue(":pytanie", m_pk_ppk->getWczytane_pytaniaTrudnePKIndeks(i));
          query.exec();
    }
    m_pk_ppk=m_ppk;
    nazwaBazy="INSERT INTO pytaniaPpk (poziom, pytanie) ";
    }



    for(int i=0;i<m_dyplomowy->get_ilePytanDyplomA();i++){
        query.prepare("INSERT INTO pytaniaDyplomowe (poziom, pytanie) "
                        "VALUES (:poziom, :pytanie)");
        query.bindValue(":poziom","A");
          query.bindValue(":pytanie", m_dyplomowy->getDyplomAIndeks().at(i));
          query.exec();
    }
    for(int i=0;i<m_dyplomowy->get_ilePytanDyplomB();i++){
        query.prepare("INSERT INTO pytaniaDyplomowe (poziom, pytanie) "
                        "VALUES (:poziom, :pytanie)");
        query.bindValue(":poziom","B");
          query.bindValue(":pytanie", m_dyplomowy->getDyplomBIndeks().at(i));
          query.exec();
    }
    for(int i=0;i<m_dyplomowy->get_ilePytanDyplomC();i++){
        query.prepare("INSERT INTO pytaniaDyplomowe (poziom, pytanie) "
                        "VALUES (:poziom, :pytanie)");
        query.bindValue(":poziom","C");
          query.bindValue(":pytanie", m_dyplomowy->getDyplomCIndeks().at(i));
          query.exec();
    }
    for(int i=0;i<m_dyplomowy->get_ilePytanDyplomD();i++){
        query.prepare("INSERT INTO pytaniaDyplomowe (poziom, pytanie) "
                        "VALUES (:poziom, :pytanie)");
        query.bindValue(":poziom","D");
          query.bindValue(":pytanie", m_dyplomowy->getDyplomDIndeks().at(i));
          query.exec();
    }

db.close();


}
void bazaDanych::wypelnijTabeleStudenci(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mydb.db");
    db.open();

    QSqlQuery query;


     query.exec("DELETE FROM studenci WHERE id>0");

    for(int i=0;i<m_student->getLista().size();i++){
        query.prepare("INSERT INTO studenci ( imie, nazwisko, sekcja, srednia) "
                        "VALUES (:imie, :nazwisko, :sekcja, :srednia)");
          query.bindValue(":imie", m_student->getImie(i));
          query.bindValue(":nazwisko", m_student->getNazwisko(i));
          query.bindValue(":sekcja", m_student->getSekcja(i));
          query.bindValue(":srednia", m_student->getSrednia(i));
          query.exec();
    }
    db.close();

}
QString bazaDanych::select(QString zapytanie){
   // QSqlQuery query(QSqlDatabase::database("projektPK"));
   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mydb.db");
    db.open();

   QSqlQuery query;
QString wynik;

     query.exec(zapytanie);
     QSqlRecord rec = query.record();

        int cols = rec.count();
        for( int r=0; query.next(); r++ )
          for( int c=0; c<cols; c++ )
            wynik+=query.value(c).toString();

      // db.close();
return wynik;

}
QString bazaDanych::selectPK(){
return select("select pytanie from pytaniaPk");
}

QString bazaDanych::selectPPK(){
return select("select pytanie from pytaniaPpk");
}
QString bazaDanych::selectDYPLOM(){
return select("select pytanie from pytaniaDyplomowe");
}


QString bazaDanych::selectPodstAPK(){
return select("select pytanie from pytaniaPk where poziom='podstawowyA'");
}
QString bazaDanych::selectPodstBPK(){
return select("select pytanie from pytaniaPk where poziom='podstawowyB'");
}
QString bazaDanych::selectPodstCPK(){
return select("select pytanie from pytaniaPk where poziom='podstawowyC'");
}
QString bazaDanych::selectSredniePK(){
return select("select pytanie from pytaniaPk where poziom='sredni'");
}
QString bazaDanych::selectTrudnePK(){
return select("select pytanie from pytaniaPk where poziom='trudny'");
}
QString bazaDanych::selectPodstAPPK(){
return select("select pytanie from pytaniaPpk where poziom='podstawowyA'");
}
QString bazaDanych::selectPodstBPPK(){
return select("select pytanie from pytaniaPpk where poziom='podstawowyB'");
}
QString bazaDanych::selectPodstCPPK(){
return select("select pytanie from pytaniaPpk where poziom='podstawowyC'");
}
QString bazaDanych::selectSredniePPK(){
return select("select pytanie from pytaniaPpk where poziom='sredni'");
}
QString bazaDanych::selectTrudnePPK(){
return select("select pytanie from pytaniaPpk where poziom='trudny'");
}
QString bazaDanych::selectStudenci(int pozycja){

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mydb.db");
    db.open();

    QSqlQuery query;
QString wynik;

//QString zapytanie="select imie,nazwisko,sekcja,srednia from studenci where sekcja=1";
qInfo()<<pozycja+1;
query.prepare(
   "SELECT imie,nazwisko,sekcja,srednia FROM studenci WHERE sekcja=:numer");
query.bindValue(":numer", pozycja+1);
     query.exec();

     QSqlRecord rec = query.record();

        int cols = rec.count();
        for( int r=0; query.next(); r++ ){
          for( int c=0; c<cols; c++ ){
            wynik+=query.value(c).toString();
            wynik+="\t";
          }
          wynik+="\n";
        }
return wynik;
}
QString bazaDanych::selectDyplomA(){
return select("select pytanie from pytaniaDyplomowe where poziom='A'");
}
QString bazaDanych::selectDyplomB(){
return select("select pytanie from pytaniaDyplomowe where poziom='B'");
}
QString bazaDanych::selectDyplomC(){
return select("select pytanie from pytaniaDyplomowe where poziom='C'");
}
QString bazaDanych::selectDyplomD(){
return select("select pytanie from pytaniaDyplomowe where poziom='D'");
}

