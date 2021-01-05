#ifndef DYPLOMOWY_H
#define DYPLOMOWY_H
#include "zczytywanie_pytan.h"

class DYPLOMOWY: public zczytywanie_pytan
{
private:

    int ile_pytanA=0;
    int ile_pytanB=0;
    int ile_pytanC=0;
    int ile_pytanD=0;

    QStringList DyplomA;
    QStringList DyplomB;
    QStringList DyplomC;
    QStringList DyplomD;

    int brakNazwyPliku=0;
    int zlaNazwaPliku=0;
    int bladPodczasZczytywaniePytan=0;

public:
    DYPLOMOWY();
    DYPLOMOWY(QString);

    //bledy
    int raportBrakNazwy(){
        return brakNazwyPliku;
    }
    int raportZlaNazwa(){
        return zlaNazwaPliku;
    }
    int raportBladZczytywanie(){
        return bladPodczasZczytywaniePytan;
    }

    //QStringList
    QString getDyplomA(){
        return DyplomA.at(losujPytanie(ile_pytanA));
    }
    QString getDyplomB(){
        return DyplomB.at(losujPytanie(ile_pytanB));
    }
    QString getDyplomC(){
        return DyplomC.at(losujPytanie(ile_pytanC));
    }
    QString getDyplomD(){
        return DyplomD.at(losujPytanie(ile_pytanD));
    }

    //QStringList.at
    QStringList getDyplomAIndeks(){
        return DyplomA;
    }
    QStringList getDyplomBIndeks(){
        return DyplomB;
    }
    QStringList getDyplomCIndeks(){
        return DyplomC;
    }
    QStringList getDyplomDIndeks(){
        return DyplomD;
    }


    //ile pytan dyplom
    int get_ilePytanDyplomA(){
        return ile_pytanA;
    }
    int get_ilePytanDyplomB(){
        return ile_pytanB;
    }
    int get_ilePytanDyplomC(){
        return ile_pytanC;
    }
    int get_ilePytanDyplomD(){
        return ile_pytanD;
    }
};

#endif // DYPLOMOWY_H
