#include "student.h"
#include <qdebug>
Student::Student(){

}
Student::Student(QString co_otwieramy)
{


        QFile file(co_otwieramy);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        while (!file.atEnd()) {
    QString student = file.readLine();
    QString imie;
    QString  nazwisko;
    int sekcja;
    double srednia=0;
    double mnoznik=1;
    int ileOcen=0;
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
            qInfo()<<ocenka;
            srednia+=(ocenka.digitValue()*mnoznik);
            mnoznik/=10.0;

        }
        else
        {
            if(srednia==0){
                QChar ocenka=student.at(i);
                qInfo()<<ocenka;
                srednia+=(ocenka.digitValue());
            }

        }
    }
    }
    }
        /*QChar ocenka=student.at(i);
        if(ocenka.isNumber())
        srednia*=ocenka.digitValue();

         if(i+2<student.size()){
        if(student.at(i+1)=="."){
            ocenka=student.at(i+2);
            if(ocenka.isNumber())
            srednia+=(ocenka.digitValue()*0.1);
        }

        //liczba po przecinku
        if(i+2<student.size()){
        if(student.at(i+1)=="."){
            QChar ss,ss1;
            ss=student.at(i);
            ss1=student.at(i+2);
            srednia+=(ss.digitValue()+(ss1.digitValue()*0.1));
            //qInfo()<<srednia;
            if(i+3<student.size())
            i+=2;
            ileOcen++;
            break;
        }
        }
    //zwykla calkowita liczba
        QChar o=student.at(i);
        if(o.isNumber()){
        srednia+=o.digitValue();
        ileOcen++;
        }
        break;

    }
    }
    }
    srednia=srednia/(ileOcen);
*/
    daneStudenta.push_back(imie+" "+nazwisko);
    imiona.push_back(imie);
    nazwiska.push_back(nazwisko);
    sekcje.push_back(sekcja);
    srednie.push_back(srednia);
    ile++;

    }
    }



