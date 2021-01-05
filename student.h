#ifndef STUDENT_H
#define STUDENT_H
#include "zczytywanie_pytan.h"

class Student
{
private:
     QString plik_studenci="studenci.txt";

     int ile=0;

     //sekcja dla studentow
     int ile_studentow=0;
     QStringList imiona;
     QStringList nazwiska;
     QList<int> sekcje;
     QList<double> srednie;

     QStringList daneStudenta;
public:
     Student();
    Student(QString);

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
};

#endif // STUDENT_H
