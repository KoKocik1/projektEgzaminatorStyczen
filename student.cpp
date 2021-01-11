#include "student.h"

Student::Student(){

}
Student::Student(QString co_otwieramy)
{
plik_studenci=co_otwieramy;
zaladujStudentow();
}

void Student::zaladujStudentow(){
    QFile file(plik_studenci);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
//if(file.readAll().isEmpty()){


    while (!file.atEnd()) {
QString student = file.readLine();
if(!student.isEmpty()){
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
if(srednia>6.0)
    srednia=6.0;

daneStudenta.push_back(imie+" "+nazwisko);
imiona.push_back(imie);
nazwiska.push_back(nazwisko);
sekcje.push_back(sekcja);
srednie.push_back(srednia);



ile_studentow++;
}
}
    ileJestSekcji();
}
void Student::ileJestSekcji(){
    int ileSek=0;
    if(ile_studentow!=0){

    for(int i=0;i<sekcje.size();i++){
        if(ileSek<sekcje.at(i))
            ileSek=sekcje.at(i);
    }
    ileSekcji=ileSek;
    }
    else
        ileSekcji=0;
}

void Student::zaladujPonownieStudentow(){
    ile_studentow=0;
    imiona.clear();
    nazwiska.clear();
    sekcje.clear();
    srednie.clear();
    daneStudenta.clear();
    ileSekcji=0;
    zaladujStudentow();
}
void Student::zaladujBaze(QStringList im,QStringList na,QList<int> se,QList<double> sr,QStringList daneStud){
    imiona=im;
    nazwiska=na;
    sekcje=se;
    srednie=sr;
    ile_studentow=imiona.size();
    daneStudenta=daneStud;
    ileSekcji=0;
    ileJestSekcji();
}

