#ifndef STUDENT_H
#define STUDENT_H
#include "zczytywanie_pytan.h"

class Student
{
private:
     QString plik_studenci;

     //sekcja dla studentow
     int ile_studentow=0;
     QStringList imiona;
     QStringList nazwiska;
     QList<int> sekcje;
     QList<double> srednie;

     QStringList daneStudenta;
     int ileSekcji;
public:
     Student();
    Student(QString);

    int ileSekcjijest(){
        return ileSekcji;
    }
    void ileJestSekcji();
    void zaladujStudentow();
    void zaladujPonownieStudentow();
    void zaladujBaze(QStringList,QStringList,QList<int>,QList<double>,QStringList);

    QStringList getLista(){
        return daneStudenta;
    }
    double getSrednia(int indeks){
        return srednie.at(indeks);
    }
    QString getImie(int indeks){
        return imiona.at(indeks);
    }
    QString getNazwisko(int indeks){
        return nazwiska.at(indeks);
    }
    int getSekcja(int indeks){
        return sekcje.at(indeks);
    }
    int zwolnienie(int indeks){
        if(srednie.at(indeks)>=3.5){
            return floor(2.0*(srednie.at(indeks)-3.0));
        }
        else
            return 0;
    }
    int getIleStudentow(){
        return ile_studentow;
    }


};

#endif // STUDENT_H
