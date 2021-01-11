#include "pk_ppk.h"
#include<QDebug>
PK_PPK::PK_PPK(QString plikPytania)
{
  m_plik_pytania=plikPytania;
  wczytajPlik();
}
void PK_PPK::wczytajPlik(){
    if(!m_plik_pytania.isEmpty()){

    zczytywaniePytan1(wczytane_pytaniaPodstawowePKA,48,57,m_plik_pytania,1);
    zczytywaniePytan1(wczytane_pytaniaPodstawowePKB,48,57,m_plik_pytania,2);
    zczytywaniePytan1(wczytane_pytaniaPodstawowePKC,48,57,m_plik_pytania,3);
    zczytywaniePytan1(wczytane_pytaniaSredniePK,48,57,m_plik_pytania,4);
    zczytywaniePytan1(wczytane_pytaniaTrudnePK,48,57,m_plik_pytania,5);
    ile_pytanPodstawowychPKa=wczytane_pytaniaPodstawowePKA.size();
    ile_pytanPodstawowychPKb=wczytane_pytaniaPodstawowePKB.size();
    ile_pytanPodstawowychPKc=wczytane_pytaniaPodstawowePKC.size();
    ile_pytanSrednichPK=wczytane_pytaniaSredniePK.size();
    ile_pytanTrudnychPk=wczytane_pytaniaTrudnePK.size();
    if(ile_pytanPodstawowychPKa==0&&ile_pytanPodstawowychPKb==0&&ile_pytanPodstawowychPKc==0&&ile_pytanSrednichPK==0&&ile_pytanTrudnychPk==0)
        zlaNazwaPliku=1;
    else if(ile_pytanPodstawowychPKa==0||ile_pytanPodstawowychPKb==0||ile_pytanPodstawowychPKc==0||ile_pytanSrednichPK==0||ile_pytanTrudnychPk==0)
        bladPodczasZczytywaniePytan=1;
    }
else
        brakNazwyPliku=1;
}
void PK_PPK::resetDanychListy(){
        wczytane_pytaniaPodstawowePKA.clear();
        wczytane_pytaniaPodstawowePKB.clear();
        wczytane_pytaniaPodstawowePKC.clear();
        wczytane_pytaniaSredniePK.clear();
        wczytane_pytaniaTrudnePK.clear();
       resetDanych();

}
void PK_PPK::zaladujPonowniePlik(){
    resetDanychListy();
    wczytajPlik();
}
void PK_PPK::resetDanych(){
    ile_wylosowanychPodstawowePKa=0;
    ile_wylosowanychPodstawowePKb=0;
    ile_wylosowanychPodstawowePKc=0;
    ile_wylosowanychSrednich=0;
    ile_wylosowanychTrudnych=0;

}

void PK_PPK::zaladujZbazy(
    QStringList Bwczytane_pytaniaPodstawowePKA,
    QStringList  Bwczytane_pytaniaPodstawowePKB,
    QStringList Bwczytane_pytaniaPodstawowePKC,
    QStringList  Bwczytane_pytaniaSredniePK,
    QStringList  Bwczytane_pytaniaTrudnePK){

    wczytane_pytaniaPodstawowePKA=Bwczytane_pytaniaPodstawowePKA;
    wczytane_pytaniaPodstawowePKB=Bwczytane_pytaniaPodstawowePKB;
    wczytane_pytaniaPodstawowePKC=Bwczytane_pytaniaPodstawowePKC;
    wczytane_pytaniaSredniePK=Bwczytane_pytaniaSredniePK;
    wczytane_pytaniaTrudnePK=Bwczytane_pytaniaTrudnePK;
    ile_pytanPodstawowychPKa=wczytane_pytaniaPodstawowePKA.size();
    ile_pytanPodstawowychPKb=wczytane_pytaniaPodstawowePKB.size();
    ile_pytanPodstawowychPKc=wczytane_pytaniaPodstawowePKC.size();
    ile_pytanSrednichPK=wczytane_pytaniaSredniePK.size();
    ile_pytanTrudnychPk= wczytane_pytaniaTrudnePK.size();


}

