#include "bazadanych.h"

bazaDanych::bazaDanych(Student*student,PK_PPK*pk,PK_PPK*ppk,DYPLOMOWY*dyplomowy,QString nazwaBazy)
{
    m_student=student;
    m_pk=pk;
    m_ppk=ppk;
    m_dyplomowy=dyplomowy;
    m_nazwaBazy=nazwaBazy;


}
bazaDanych::bazaDanych(QString nazwaBazy){
    m_nazwaBazy=nazwaBazy;
}
void bazaDanych::stworzTabele(){

    QSqlDatabase db ;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(m_nazwaBazy);
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

}
void bazaDanych::wypelnijTabelePytania(){


    PK_PPK* m_pk_ppk;
    QSqlDatabase db ;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(m_nazwaBazy);
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
//jaki Egzamin 1-PK,2-PPK,3-DYPLOM, 4- studenci
void bazaDanych::wypelnijTabelePytania(QStringList pytania,int jakiEgzamin,int ktoryDzial){

    if(!pytania.isEmpty()&&jakiEgzamin<4&&jakiEgzamin>0&&ktoryDzial>=0&&ktoryDzial<=4){
        QSqlDatabase db ;
        if(QSqlDatabase::contains("qt_sql_default_connection"))
          db = QSqlDatabase::database("qt_sql_default_connection");
        else
          db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(m_nazwaBazy);
        db.open();
        QSqlQuery query;

        switch(jakiEgzamin){
        case 1:{
            if(ktoryDzial==0){
                query.exec("DELETE FROM pytaniaPk WHERE poziom='podstawowyA'");

                for(int ileRazy=0;ileRazy<pytania.size();ileRazy++){
                    query.prepare("INSERT INTO pytaniaPk (poziom, pytanie) "
                                    "VALUES (:poziom, :pytanie)");
                    query.bindValue(":poziom","podstawowyA");
                      query.bindValue(":pytanie", pytania.at(ileRazy));
                      query.exec();
                }


            }else if(ktoryDzial==1){
                query.exec("DELETE FROM pytaniaPk WHERE poziom='podstawowyB'");
                query.exec();
                for(int ileRazy=0;ileRazy<pytania.size();ileRazy++){
                    query.prepare("INSERT INTO pytaniaPk (poziom, pytanie) "
                                    "VALUES (:poziom, :pytanie)");
                    query.bindValue(":poziom","podstawowyB");
                      query.bindValue(":pytanie", pytania.at(ileRazy));
                      query.exec();
                }

            }else if(ktoryDzial==2){
                query.exec("DELETE FROM pytaniaPk WHERE poziom='podstawowyC'");
                query.exec();
                for(int ileRazy=0;ileRazy<pytania.size();ileRazy++){
                    query.prepare("INSERT INTO pytaniaPk (poziom, pytanie) "
                                    "VALUES (:poziom, :pytanie)");
                    query.bindValue(":poziom","podstawowyC");
                      query.bindValue(":pytanie", pytania.at(ileRazy));
                      query.exec();
                }

            }else if(ktoryDzial==3){
                query.exec("DELETE FROM pytaniaPk WHERE poziom='sredni'");
                query.exec();
                for(int ileRazy=0;ileRazy<pytania.size();ileRazy++){
                    query.prepare("INSERT INTO pytaniaPk (poziom, pytanie) "
                                    "VALUES (:poziom, :pytanie)");
                    query.bindValue(":poziom","sredni");
                      query.bindValue(":pytanie", pytania.at(ileRazy));
                      query.exec();
                }

            }else{
                query.exec("DELETE FROM pytaniaPk WHERE poziom='trudny'");
                query.exec();
                for(int ileRazy=0;ileRazy<pytania.size();ileRazy++){
                    query.prepare("INSERT INTO pytaniaPk (poziom, pytanie) "
                                    "VALUES (:poziom, :pytanie)");
                    query.bindValue(":poziom","trudny");
                      query.bindValue(":pytanie", pytania.at(ileRazy));
                      query.exec();
                }

            }


            break;
        }
        case 2:{
            if(ktoryDzial==0){
                query.exec("DELETE FROM pytaniaPpk WHERE poziom='podstawowyA'");
                query.exec();
                for(int ileRazy=0;ileRazy<pytania.size();ileRazy++){
                    query.prepare("INSERT INTO pytaniaPpk (poziom, pytanie) "
                                    "VALUES (:poziom, :pytanie)");
                    query.bindValue(":poziom","podstawowyA");
                      query.bindValue(":pytanie", pytania.at(ileRazy));
                      query.exec();
                }

            }else if(ktoryDzial==1){
                query.exec("DELETE FROM pytaniaPpk WHERE poziom='podstawowyB'");
                query.exec();
                for(int ileRazy=0;ileRazy<pytania.size();ileRazy++){
                    query.prepare("INSERT INTO pytaniaPpk (poziom, pytanie) "
                                    "VALUES (:poziom, :pytanie)");
                    query.bindValue(":poziom","podstawowyB");
                      query.bindValue(":pytanie", pytania.at(ileRazy));
                      query.exec();
                }

            }else if(ktoryDzial==2){
                query.exec("DELETE FROM pytaniaPpk WHERE poziom='podstawowyC'");
                query.exec();
                for(int ileRazy=0;ileRazy<pytania.size();ileRazy++){
                    query.prepare("INSERT INTO pytaniaPpk (poziom, pytanie) "
                                    "VALUES (:poziom, :pytanie)");
                    query.bindValue(":poziom","podstawowyC");
                      query.bindValue(":pytanie", pytania.at(ileRazy));
                      query.exec();
                }

            }else if(ktoryDzial==3){
                query.exec("DELETE FROM pytaniaPpk WHERE poziom='sredni'");
                query.exec();
                for(int ileRazy=0;ileRazy<pytania.size();ileRazy++){
                    query.prepare("INSERT INTO pytaniaPpk (poziom, pytanie) "
                                    "VALUES (:poziom, :pytanie)");
                    query.bindValue(":poziom","sredni");
                      query.bindValue(":pytanie", pytania.at(ileRazy));
                      query.exec();
                }

            }else{
                query.exec("DELETE FROM pytaniaPpk WHERE poziom='trudny'");
                query.exec();
                for(int ileRazy=0;ileRazy<pytania.size();ileRazy++){
                    query.prepare("INSERT INTO pytaniaPpk (poziom, pytanie) "
                                    "VALUES (:poziom, :pytanie)");
                    query.bindValue(":poziom","trudny");
                      query.bindValue(":pytanie", pytania.at(ileRazy));
                      query.exec();
                }
               }

            break;
        }
        case 3:{
            if(ktoryDzial==0){
                query.exec("DELETE FROM pytaniaDyplomowe WHERE poziom='A'");
                query.exec();
                query.exec();
                for(int ileRazy=0;ileRazy<pytania.size();ileRazy++){
                    query.prepare("INSERT INTO pytaniaDyplomowe (poziom, pytanie) "
                                    "VALUES (:poziom, :pytanie)");
                    query.bindValue(":poziom","A");
                      query.bindValue(":pytanie", pytania.at(ileRazy));
                      query.exec();
                }

            }else if(ktoryDzial==1){
                query.exec("DELETE FROM pytaniaDyplomowe WHERE poziom='B'");
                query.exec();
                for(int ileRazy=0;ileRazy<pytania.size();ileRazy++){
                    query.prepare("INSERT INTO pytaniaDyplomowe (poziom, pytanie) "
                                    "VALUES (:poziom, :pytanie)");
                    query.bindValue(":poziom","B");
                      query.bindValue(":pytanie", pytania.at(ileRazy));
                      query.exec();
                }

            }else if(ktoryDzial==2){
                query.exec("DELETE FROM pytaniaDyplomowe WHERE poziom='C'");
                query.exec();
                for(int ileRazy=0;ileRazy<pytania.size();ileRazy++){
                    query.prepare("INSERT INTO pytaniaDyplomowe (poziom, pytanie) "
                                    "VALUES (:poziom, :pytanie)");
                    query.bindValue(":poziom","C");
                      query.bindValue(":pytanie", pytania.at(ileRazy));
                      query.exec();
                }

            }else{
                query.exec("DELETE FROM pytaniaDyplomowe WHERE poziom='D'");
                query.exec();
                for(int ileRazy=0;ileRazy<pytania.size();ileRazy++){
                    query.prepare("INSERT INTO pytaniaDyplomowe (poziom, pytanie) "
                                    "VALUES (:poziom, :pytanie)");
                    query.bindValue(":poziom","D");
                      query.bindValue(":pytanie", pytania.at(ileRazy));
                      query.exec();
                }
            }
            break;
               }
        }
        db.close();
        }
}
void bazaDanych::wypelnijStudenci(QStringList imie,QStringList nazwisko,int sekcja,QList<double> srednia){

    QSqlDatabase db ;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(m_nazwaBazy);
    db.open();
    QSqlQuery query;
    QString zapytanie;
    zapytanie="DELETE FROM studenci WHERE sekcja="+QString::number(sekcja);
    query.exec(zapytanie);


   for(int ileRazy=0;ileRazy<srednia.size();ileRazy++){    
       query.prepare("INSERT INTO studenci ( imie, nazwisko, sekcja, srednia) "
                       "VALUES (:imie, :nazwisko, :sekcja, :srednia)");
         query.bindValue(":imie", imie.at(ileRazy));
         query.bindValue(":nazwisko", nazwisko.at(ileRazy));
         query.bindValue(":sekcja", sekcja);
         if(srednia.at(ileRazy)<=6.0)
         query.bindValue(":srednia", srednia.at(ileRazy));
         else
         query.bindValue(":srednia", 6.0);
         query.exec();
}
}

void bazaDanych::wypelnijTabeleStudenci(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(m_nazwaBazy);
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

   QSqlDatabase db;
   if(QSqlDatabase::contains("qt_sql_default_connection"))
     db = QSqlDatabase::database("qt_sql_default_connection");
   else
     db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(m_nazwaBazy);
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

    QSqlDatabase db ;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(m_nazwaBazy);
    db.open();

    QSqlQuery query;
QString wynik;


query.prepare(
   "SELECT imie,nazwisko,sekcja,srednia FROM studenci WHERE sekcja=:numer");
query.bindValue(":numer", pozycja+1);
     query.exec();

     QSqlRecord rec = query.record();

        int cols = rec.count();
        for( int r=0; query.next(); r++ ){
          for( int c=0; c<cols; c++ ){
            wynik+=query.value(c).toString();
            if(c!=3)
            wynik+="\t";
          }
          wynik+="\n";
        }
return wynik;
}
QString bazaDanych::selectStudenci(){

    QSqlDatabase db ;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(m_nazwaBazy);
    db.open();

    QSqlQuery query;
QString wynik;


query.exec("SELECT imie,nazwisko,sekcja,srednia FROM studenci");


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

void bazaDanych::zapisBazaDoPlik(){
    QSqlDatabase db ;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(m_nazwaBazy);
    db.open();


QStringList Pa_pk;
QStringList Pb_pk;
QStringList Pc_pk;
QStringList Ps_pk;
QStringList Pt_pk;
QStringList Pa_ppk;
QStringList Pb_ppk;
QStringList Pc_ppk;
QStringList Ps_ppk;
QStringList Pt_ppk;
QStringList a_dyplom;
QStringList b_dyplom;
QStringList c_dyplom;
QStringList d_dyplom;

QString pytanieZczytanepka=selectPodstAPK();
QString pytanieZczytanepkb=selectPodstBPK();
QString pytanieZczytanepkc=selectPodstCPK();
QString pytanieZczytanepks=selectSredniePK();
QString pytanieZczytanepkt=selectTrudnePK();
QString pytanieZczytaneppka=selectPodstAPPK();
QString pytanieZczytaneppkb=selectPodstBPPK();
QString pytanieZczytaneppkc=selectPodstCPPK();
QString pytanieZczytaneppks=selectSredniePPK();
QString pytanieZczytaneppkt=selectTrudnePPK();
QString pytanieZczytaneda=selectDyplomA();
QString pytanieZczytanedb=selectDyplomB();
QString pytanieZczytanedc=selectDyplomC();
QString pytanieZczytanedd=selectDyplomD();

QList<int> rozmiar;

rozmiar.push_back(pytanieZczytanepka.size());
rozmiar.push_back(pytanieZczytanepkb.size());
rozmiar.push_back(pytanieZczytanepkc.size());
rozmiar.push_back(pytanieZczytanepks.size());
rozmiar.push_back(pytanieZczytanepkt.size());
rozmiar.push_back(pytanieZczytaneppka.size());
rozmiar.push_back(pytanieZczytaneppkb.size());
rozmiar.push_back(pytanieZczytaneppkc.size());
rozmiar.push_back(pytanieZczytaneppks.size());
rozmiar.push_back(pytanieZczytaneppkt.size());
rozmiar.push_back(pytanieZczytaneda.size());
rozmiar.push_back(pytanieZczytanedb.size());
rozmiar.push_back(pytanieZczytanedc.size());
rozmiar.push_back(pytanieZczytanedd.size());
std::sort(rozmiar.begin(),rozmiar.end());
QString pka,pkb,pkc,pks,pkt,ppka,ppkb,ppkc,ppks,ppkt,da,dbb,dc,dd;
for(int pozycja=0;pozycja<rozmiar.at(rozmiar.size()-1);pozycja++){

    //pk
    if(pozycja<pytanieZczytanepka.size()){
        pka+=pytanieZczytanepka.at(pozycja);
        if(pytanieZczytanepka.at(pozycja)=='\n'){
            Pa_pk.push_back(pka);
            pka="";
        }
    }
    if(pozycja<pytanieZczytanepkb.size()){
        pkb+=pytanieZczytanepkb.at(pozycja);
        if(pytanieZczytanepkb.at(pozycja)=='\n'){
            Pb_pk.push_back(pkb);
            pkb="";
        }
    }
    if(pozycja<pytanieZczytanepkc.size()){
        pkc+=pytanieZczytanepkc.at(pozycja);
        if(pytanieZczytanepkc.at(pozycja)=='\n'){
            Pc_pk.push_back(pkc);
            pkc="";
        }
    }
    if(pozycja<pytanieZczytanepks.size()){
        pks+=pytanieZczytanepks.at(pozycja);
        if(pytanieZczytanepks.at(pozycja)=='\n'){
            Ps_pk.push_back(pks);
            pks="";
        }
    }
    if(pozycja<pytanieZczytanepkt.size()){
        pkt+=pytanieZczytanepkt.at(pozycja);
        if(pytanieZczytanepkt.at(pozycja)=='\n'){
            Pt_pk.push_back(pkt);
            pkt="";
        }
    }

    //ppk
    if(pozycja<pytanieZczytaneppka.size()){
        ppka+=pytanieZczytaneppka.at(pozycja);
        if(pytanieZczytaneppka.at(pozycja)=='\n'){
            Pa_ppk.push_back(ppka);
            ppka="";
        }
    }
    if(pozycja<pytanieZczytaneppkb.size()){
        ppkb+=pytanieZczytaneppkb.at(pozycja);
        if(pytanieZczytaneppkb.at(pozycja)=='\n'){
            Pb_ppk.push_back(ppkb);
            ppkb="";
        }
    }
    if(pozycja<pytanieZczytaneppkc.size()){
        ppkc+=pytanieZczytaneppkc.at(pozycja);
        if(pytanieZczytaneppkc.at(pozycja)=='\n'){
            Pc_ppk.push_back(ppkc);
            ppkc="";
        }
    }
    if(pozycja<pytanieZczytaneppks.size()){
        ppks+=pytanieZczytaneppks.at(pozycja);
        if(pytanieZczytaneppks.at(pozycja)=='\n'){
            Ps_ppk.push_back(ppks);
            ppks="";
        }
    }
    if(pozycja<pytanieZczytaneppkt.size()){
        ppkt+=pytanieZczytaneppkt.at(pozycja);
        if(pytanieZczytaneppkt.at(pozycja)=='\n'){
            Pt_ppk.push_back(ppkt);
            ppkt="";
        }
    }

    if(pozycja<pytanieZczytaneda.size()){
            da+=pytanieZczytaneda.at(pozycja);
            if(pytanieZczytaneda.at(pozycja)=='\n'){
                a_dyplom.push_back(da);
                da="";
            }
    }
    if(pozycja<pytanieZczytanedb.size()){
            dbb+=pytanieZczytanedb.at(pozycja);
            if(pytanieZczytanedb.at(pozycja)=='\n'){
                b_dyplom.push_back(dbb);
                dbb="";
            }
    }
    if(pozycja<pytanieZczytanedc.size()){
            dc+=pytanieZczytanedc.at(pozycja);
            if(pytanieZczytanedc.at(pozycja)=='\n'){
                c_dyplom.push_back(dc);
                dc="";
            }
    }
    if(pozycja<pytanieZczytanedd.size()){
            dd+=pytanieZczytanedd.at(pozycja);
            if(pytanieZczytanedd.at(pozycja)=='\n'){
                d_dyplom.push_back(dd);
                dd="";
            }
    }

}


    m_pk->zaladujZbazy(Pa_pk,Pb_pk,Pc_pk,Ps_pk,Pt_pk);
    m_ppk->zaladujZbazy(Pa_ppk,Pb_ppk,Pc_ppk,Ps_ppk,Pt_ppk);
    m_dyplomowy->zaladujZbazy(a_dyplom,b_dyplom,c_dyplom,d_dyplom);
QStringList imieL;
QStringList nazwiskoL;
QList<int> sekcjeL;
QList<double> srednieL;
QStringList daneStudentaL;
QString linia="";

QString zczytaniStudenci=selectStudenci();
int ileOdjac=-1;
for(int i=zczytaniStudenci.size()-1;i>0;i--){
    if(zczytaniStudenci.at(i)=="\n"||zczytaniStudenci.at(i)=="\t")
        ileOdjac++;
    else
        break;
}
zczytaniStudenci.push_back("\n");

for(int i=0;i<zczytaniStudenci.size()-ileOdjac;i++){

    if(zczytaniStudenci.at(i)!="\n"){
        linia+=zczytaniStudenci.at(i);
    }else{

        QString student = linia;
        QString imie;
        QString  nazwisko;
        int sekcja;
        double srednia=0;
        double mnoznik=1;
        int ileTabowBylo=0;
        for(int i=0;i<student.size();i++){
            if(student.at(i)=="\t")
            {
                ileTabowBylo++;
             continue;
            }
        switch(ileTabowBylo){

        case 0:{
            imie+=student.at(i);
            break;}
        case 1:{
            nazwisko+=student.at(i);
            break;}
        case 2:{
            QChar s=student.at(i);
            sekcja=s.digitValue();
            break;}

        default:{
            if(i+1<student.size()){
                if(student.at(i)==".")
                continue;

                QChar ocenka=student.at(i);
                srednia+=(ocenka.digitValue()*mnoznik);
                mnoznik/=10.0;

            }
            else
            {
                if(srednia==0){
                    QChar ocenka=student.at(i);
                    srednia+=(ocenka.digitValue());
                }

            }
        }
        }
        }

        daneStudentaL.push_back(imie+" "+nazwisko);
        imieL.push_back(imie);
        nazwiskoL.push_back(nazwisko);
        sekcjeL.push_back(sekcja);
        srednieL.push_back(srednia);

        linia="";
        }


    }

m_student->zaladujBaze(imieL,nazwiskoL,sekcjeL,srednieL,daneStudentaL);
}




