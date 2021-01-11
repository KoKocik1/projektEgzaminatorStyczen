#ifndef PK_PPK_H
#define PK_PPK_H
#include "zczytywanie_pytan.h"
#include <QDebug>

class PK_PPK :public zczytywanie_pytan
{
private:
    //Nazwy plikow
    QString m_plik_pytania;




    //zczytane pytania
    QStringList wczytane_pytaniaPodstawowePKA;
    QStringList  wczytane_pytaniaPodstawowePKB;
    QStringList wczytane_pytaniaPodstawowePKC;
    QStringList  wczytane_pytaniaSredniePK;
    QStringList  wczytane_pytaniaTrudnePK;

    //ile jest pytan
    int ile_pytanPodstawowychPKa=0;
    int ile_pytanPodstawowychPKb=0;
    int ile_pytanPodstawowychPKc=0;
    int ile_pytanSrednichPK=0;
    int ile_pytanTrudnychPk=0;

    //jakie wylosowano podstawowe
    int wylosowane_podstawowePKa[7];
    int wylosowane_podstawowePKb[7];
    int wylosowane_podstawowePKc[7];
    int wylosowane_srednie[7];
    int wylosowane_trudne[7];

    //ile aktualnie wylosowanych
    int ile_wylosowanychPodstawowePKa=0;
    int ile_wylosowanychPodstawowePKb=0;
    int ile_wylosowanychPodstawowePKc=0;
    int ile_wylosowanychSrednich=0;
    int ile_wylosowanychTrudnych=0;

    int brakNazwyPliku=0;
    int zlaNazwaPliku=0;
    int bladPodczasZczytywaniePytan=0;

public:
    PK_PPK();
    PK_PPK(QString);

    void zaladujZbazy(QStringList,QStringList,QStringList,QStringList,QStringList);
    void resetDanychListy();
    void wczytajPlik();
    void zaladujPonowniePlik();
    void zaladujZbazy(QString);

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

    //void setPytaniaPlik(QString plik);
void losujPodstawoweA(){
   // wylosowane_podstawowePKa[ile_wylosowanychPodstawowePKa]=1;
    wylosowane_podstawowePKa[ile_wylosowanychPodstawowePKa-1]=losujPytanie(ile_pytanPodstawowychPKa,wylosowane_podstawowePKa,ile_wylosowanychPodstawowePKa);
}
void losujPodstawoweB(){
    wylosowane_podstawowePKb[ile_wylosowanychPodstawowePKb-1]=losujPytanie(ile_pytanPodstawowychPKb,wylosowane_podstawowePKb,ile_wylosowanychPodstawowePKb);
}
void losujPodstawoweC(){
    wylosowane_podstawowePKc[ile_wylosowanychPodstawowePKc-1]=losujPytanie(ile_pytanPodstawowychPKc,wylosowane_podstawowePKc,ile_wylosowanychPodstawowePKc);
}
void losujSrednie(){
    wylosowane_srednie[ile_wylosowanychSrednich-1]=losujPytanie(ile_pytanSrednichPK,wylosowane_srednie,ile_wylosowanychSrednich);

}
void losujTrudne(){
    wylosowane_trudne[ile_wylosowanychTrudnych-1]=losujPytanie(ile_pytanTrudnychPk,wylosowane_trudne,ile_wylosowanychTrudnych);

}

void resetDanych();

    //get QStringList cala lista
    QStringList getWczytane_pytaniaPodstawowePKA(){
        return wczytane_pytaniaPodstawowePKA;
    }
    QStringList getWczytane_pytaniaPodstawowePKB(){
        return wczytane_pytaniaPodstawowePKB;
    }
    QStringList getWczytane_pytaniaPodstawowePKC(){
        return wczytane_pytaniaPodstawowePKC;
    }
    QStringList getWczytane_pytaniaSredniePK(){
        return wczytane_pytaniaSredniePK;
    }
    QStringList getWczytane_pytaniaTrudnePK(){
        return wczytane_pytaniaTrudnePK;
    }


    //get QStringList.at()
    QString getWczytane_pytaniaPodstawowePKAIndeks(int indeks){
        return wczytane_pytaniaPodstawowePKA.at(indeks);
    }
    QString getWczytane_pytaniaPodstawowePKBIndeks(int indeks){
        return wczytane_pytaniaPodstawowePKB.at(indeks);
    }
    QString getWczytane_pytaniaPodstawowePKCIndeks(int indeks){
        return wczytane_pytaniaPodstawowePKC.at(indeks);
    }
    QString getWczytane_pytaniaSredniePKIndeks(int indeks){
        return wczytane_pytaniaSredniePK.at(indeks);
    }
    QString getWczytane_pytaniaTrudnePKIndeks(int indeks){
        return wczytane_pytaniaTrudnePK.at(indeks);
    }

    //get Ile Pytan
    int get_ile_pytanPodstawowychPKa(){
        return ile_pytanPodstawowychPKa;
    }
    int get_ile_pytanPodstawowychPKb(){
        return ile_pytanPodstawowychPKb;
    }
    int get_ile_pytanPodstawowychPKc(){
        return ile_pytanPodstawowychPKc;
    }
    int get_ile_pytanSrednichPK(){
        return ile_pytanSrednichPK;
    }
    int get_ile_pytanTrudnychPk(){
        return ile_pytanTrudnychPk;
    }

    //get wylosowane cale
    int* get_wylosowane_podstawowePKa(){
        return wylosowane_podstawowePKa;
    }
    int * get_wylosowane_podstawowePKb(){
        return wylosowane_podstawowePKb;
    }
    int*  get_wylosowane_podstawowePKc(){
        return wylosowane_podstawowePKc;
    }
    int * get_wylosowane_srednie(){
        return wylosowane_srednie;
    }
    int*  get_wylosowane_trudne(){
        return wylosowane_trudne;
    }


    //get wylosowane[at]
    int get_wylosowane_podstawowePKaIndeks(int indeks){
        return wylosowane_podstawowePKa[indeks];
    }
    int  get_wylosowane_podstawowePKbIndeks(int indeks){
        return wylosowane_podstawowePKb[indeks];
    }
    int  get_wylosowane_podstawowePKcIndeks(int indeks){
        return wylosowane_podstawowePKc[indeks];
    }
    int  get_wylosowane_srednieIndeks(int indeks){
        return wylosowane_srednie[indeks];
    }
    int  get_wylosowane_trudneIndeks(int indeks){
        return wylosowane_trudne[indeks];
    }



    int get_ile_wylosowanychPodstawowePKa(){
        return ile_wylosowanychPodstawowePKa;
    }
    int get_ile_wylosowanychPodstawowePKb(){
        return ile_wylosowanychPodstawowePKb;
    }
    int get_ile_wylosowanychPodstawowePKc(){
        return ile_wylosowanychPodstawowePKc;
    }
    int get_ile_wylosowanychSrednich(){
        return ile_wylosowanychSrednich;
    }
    int get_ile_wylosowanychTrudnych(){
        return ile_wylosowanychTrudnych;
    }



//set wylosowane
void set_wylosowane_podstawowePKa(int wartosc){
     wylosowane_podstawowePKa[ile_wylosowanychPodstawowePKa]=wartosc;
}
void set_wylosowane_podstawowePKb(int wartosc){
    wylosowane_podstawowePKb[ile_wylosowanychPodstawowePKb]=wartosc;
}
void  set_wylosowane_podstawowePKc(int wartosc){
    wylosowane_podstawowePKc[ile_wylosowanychPodstawowePKc]=wartosc;
}
void set_wylosowane_srednie(int wartosc){
    wylosowane_srednie[ile_wylosowanychSrednich]=wartosc;
}
void  set_wylosowane_trudne(int wartosc){
     wylosowane_trudne[ile_wylosowanychTrudnych]=wartosc;
}


void set_ile_wylosowanychPodstawowePKa(){
    ile_wylosowanychPodstawowePKa++;
}
void set_ile_wylosowanychPodstawowePKb(){
    ile_wylosowanychPodstawowePKb++;
}
void set_ile_wylosowanychPodstawowePKc(){
     ile_wylosowanychPodstawowePKc++;
}
void set_ile_wylosowanychSrednich(){
    ile_wylosowanychSrednich++;
}
void set_ile_wylosowanychTrudnych(){
     ile_wylosowanychTrudnych++;
}

};

#endif // PK_PPK_H
