#include "dyplomowy.h"

DYPLOMOWY::DYPLOMOWY()
{

}

DYPLOMOWY::DYPLOMOWY(QString nazwaPliku){
    m_nazwaPliku=nazwaPliku;
}

void DYPLOMOWY::wczytajPytaniaPlik(){
    if(!m_nazwaPliku.isEmpty()){
        zczytywaniePytan1(DyplomA,40,40,m_nazwaPliku,1);
        zczytywaniePytan1(DyplomB,40,40,m_nazwaPliku,2);
        zczytywaniePytan1(DyplomC,40,40,m_nazwaPliku,3);
        zczytywaniePytan1(DyplomD,40,40,m_nazwaPliku,4);
        ile_pytanA=DyplomA.size();
        ile_pytanB=DyplomB.size();
        ile_pytanC=DyplomC.size();
        ile_pytanD=DyplomD.size();
        if(ile_pytanA==0&&ile_pytanB==0&&ile_pytanC==0&&ile_pytanD==0)
            zlaNazwaPliku=1;
        else if(ile_pytanA==0||ile_pytanB==0||ile_pytanC==0||ile_pytanD==0)
            bladPodczasZczytywaniePytan=1;
        }
    else
            brakNazwyPliku=1;

}
void DYPLOMOWY::zaladujPonowniePlik(){
    DyplomA.clear();
    DyplomB.clear();
    DyplomC.clear();
    DyplomD.clear();
    ile_pytanA=0;
    ile_pytanB=0;
    ile_pytanC=0;
    ile_pytanD=0;
    wczytajPytaniaPlik();
}

void DYPLOMOWY::zaladujZbazy(QStringList a, QStringList b, QStringList c, QStringList d){
    ile_pytanA=a.size();
    ile_pytanB=b.size();
    ile_pytanC=c.size();
    ile_pytanD=d.size();
    DyplomA=a;
    DyplomB=b;
    DyplomC=c;
    DyplomD=d;
}
