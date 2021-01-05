#include "dyplomowy.h"

DYPLOMOWY::DYPLOMOWY()
{

}

DYPLOMOWY::DYPLOMOWY(QString nazwaPliku){
if(!nazwaPliku.isEmpty()){
    zczytywaniePytan1(DyplomA,40,40,nazwaPliku,1);
    zczytywaniePytan1(DyplomB,40,40,nazwaPliku,2);
    zczytywaniePytan1(DyplomC,40,40,nazwaPliku,3);
    zczytywaniePytan1(DyplomD,40,40,nazwaPliku,4);
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
