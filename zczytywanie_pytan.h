#ifndef ZCZYTYWANIE_PYTAN_H
#define ZCZYTYWANIE_PYTAN_H
#include <fstream>
#include <QString>
#include <QStringList>
#include <QFile>
class zczytywanie_pytan
{
public:
    zczytywanie_pytan();


    int losujPytanie(int ileMaBazaPytan,int wylosowane[],int &ile_wylosowanych);


    //QFile
    void zczytywaniePytan1(QStringList &lista,int a,int b,QString co_otwieramy,int ktory_raz);


    int losujPytanie(int ileMaBazaPytan){
        return rand()%ileMaBazaPytan;
    }
};

#endif // ZCZYTYWANIE_PYTAN_H
