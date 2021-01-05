
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <stdio.h>
#include <string>
#include <qdebug.h>
#include <QFileDialog>
#include <QMessageBox>



using namespace std;

//deklaracje static
PK_PPK* MainWindow::egzamin=nullptr;
DYPLOMOWY* MainWindow::dyplom=new DYPLOMOWY("pytaniaDYPLOM.txt");
Student* MainWindow::student=new Student("studenci.txt");
PK_PPK* MainWindow::pk=new PK_PPK("pytaniaPK.txt");
PK_PPK* MainWindow::ppk=new PK_PPK("pytaniaPPK.txt");
bazaDanych* MainWindow::baza=new bazaDanych(student,pk,ppk,dyplom);



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->ImieStudenta->addItems(student->getLista());


//ustawienie aktualnego studenta

    //zwolnienie
if(ui->jakiEgzamin->currentIndex()!=2){
        if(student->getSrednia(0)>=5)
        {
            ui->Zwolnienie_z_podst->setText("   Zwolnienie z częsci podstawowej   ");
        }
        else{
            ui->Zwolnienie_z_podst->setText("Brak zwolnienia z części podstawowej");
        }
}
else
    ui->Zwolnienie_z_podst->setText("           EGZAMIN DYPLOMOWY         ");

         //liczba dodatkowych pytan
    ui->IleDodPyt->display(student->zwolnienie(0));

egzamin=pk;


    //SPRAWDZENIE POPRAWNOSCI ZCZYTANIA DANYCH
   if(egzamin->raportBladZczytywanie()==1)
       ui->pyt1->setText("BŁĄD PODCZAS ZCZYTYWANIA DANYCH Z PLIKU");
   if(egzamin->raportBrakNazwy()==1)
       ui->pyt2->setText("BRAK NAZWY PLIKU");
   if(egzamin->raportZlaNazwa()==1)
       ui->pyt3->setText("BLĘDNA NAZWA PLIKU");

//losowosc
    srand(time(0));

baza->stworzTabele();
baza->wypelnijTabelePytania();
baza->wypelnijTabeleStudenci();

m_okienko=new edytor(this,baza);
}


MainWindow::~MainWindow()
{
    delete dyplom;
    dyplom = nullptr;

    delete student;
    student = nullptr;

    delete pk;
    pk = nullptr;

    delete ppk;
    ppk = nullptr;

    delete baza;
    baza = nullptr;

    delete m_okienko;
    m_okienko=nullptr;

    delete ui;
}

//pole statyczne
edytor  *MainWindow::m_okienko;



   //rozpoczecie testu i potem losowanie dalszych pytan
void MainWindow::on_PoziomStart_clicked()
{



//zablokowanie przycisku start(zapewne tymczasowe)
ui->PoziomStart->setDisabled(1);

//odblokowanie nextLvl
ui->start->setEnabled(1);

//DYPLOM
if(ui->jakiEgzamin->currentIndex()==2){

        ui->pyt1->setFontWeight(99);
        ui->pyt2->setFontWeight(99);
        ui->pyt3->setFontWeight(99);
        ui->dodatkowe_pytania->setFontWeight(99);
        ui->pyt1->setText("Pytania ogólne - PytaniaAdministracja, sieci komputerowe i technologie internetowe:\n");
        ui->pyt2->setText("Pytania ogólne - Automatyka, elektrotechnika, elektronika i robotyka:\n");
        ui->pyt3->setText("Pytania ogólne - Programowanie, algorytmika i inżynieria oprogramowania:\n");
        ui->dodatkowe_pytania->setText("Pytania tylko dla spejaności Programowanie Komputerów:\n");
        ui->pyt1->setFontWeight(1);
        ui->pyt2->setFontWeight(1);
        ui->pyt3->setFontWeight(1);
        ui->dodatkowe_pytania->setFontWeight(1);

    ui->pyt1->append(dyplom->getDyplomA());
    ui->pyt2->append(dyplom->getDyplomB());
    ui->pyt3->append(dyplom->getDyplomC());
    ui->dodatkowe_pytania->append(dyplom->getDyplomD());
    ui->start->setText("RESET");


}else{

//losowanie dla podstawowych
if(ui->comboBox_3->currentIndex()==0){

ui->dodPytPodstA->setDisabled(1);
ui->dodPytPodstB->setDisabled(1);
ui->dodPytPodstC->setDisabled(1);
if(ui->jakiEgzamin->currentIndex()){
    ui->pyt1->setFontWeight(99);
    ui->pyt2->setFontWeight(99);
    ui->pyt3->setFontWeight(99);
    ui->pyt1->setText("Podstawy programowania i instrukcje sterujące\n");
    ui->pyt2->setText("Operacje tablicowe i wskaźnikowe i funkcje\n");
    ui->pyt3->setText("Debugowanie, testowanie kodu i obsługa wyjątków\n");
    ui->pyt1->setFontWeight(1);
    ui->pyt2->setFontWeight(1);
    ui->pyt3->setFontWeight(1);
}
else
{
    ui->pyt1->setFontWeight(99);
    ui->pyt2->setFontWeight(99);
    ui->pyt3->setFontWeight(99);
    ui->pyt1->setText("Programowanie proceduralne, obsługa plików, operacje bitowe i testowanie\n");
    ui->pyt2->setText("Złożone typy danych i podstawy programowania obiektowego\n");
    ui->pyt3->setText("Interakcje obiektowe, zarządzanie pamięcią w klasach, programowanie generyczne\n");
    ui->pyt1->setFontWeight(1);
    ui->pyt2->setFontWeight(1);
    ui->pyt3->setFontWeight(1);
}

     for(int ile=0;ile<=ui->dodPytPodstA->value();ile++){
         egzamin->losujPodstawoweA();
              ui->pyt1->append(egzamin->getWczytane_pytaniaPodstawowePKAIndeks(egzamin->get_wylosowane_podstawowePKaIndeks(ile)));
     }
     for(int ile=0;ile<=ui->dodPytPodstB->value();ile++){
         egzamin->losujPodstawoweB();
              ui->pyt2->append(egzamin->getWczytane_pytaniaPodstawowePKBIndeks(egzamin->get_wylosowane_podstawowePKbIndeks(ile)));
     }
     for(int ile=0;ile<=ui->dodPytPodstC->value();ile++){
         egzamin->losujPodstawoweC();
              ui->pyt3->append(egzamin->getWczytane_pytaniaPodstawowePKCIndeks(egzamin->get_wylosowane_podstawowePKcIndeks(ile)));
     }
}
else if(ui->comboBox_3->currentIndex()==1){
    ui->dodPytSred->setDisabled(1);
    ui->pyt1->clear();
    ui->pyt2->clear();
    ui->pyt3->clear();
    ui->dodatkowe_pytania->clear();

    for(int ile=0;ile<=ui->dodPytSred->value();ile++){
        egzamin->losujSrednie();
        ui->pyt1->append(egzamin->getWczytane_pytaniaSredniePKIndeks(egzamin->get_wylosowane_srednieIndeks(ile)));
    }


}else {
     ui->dodPytTrud->setDisabled(1);
    ui->pyt1->clear();
    ui->pyt2->clear();
    ui->pyt3->clear();
    ui->dodatkowe_pytania->clear();

    for(int ile=0;ile<=ui->dodPytTrud->value();ile++){
        egzamin->losujTrudne();

         ui->pyt1->append(egzamin->getWczytane_pytaniaTrudnePKIndeks(egzamin->get_wylosowane_trudneIndeks(ile)));
    }


}
}
}


void MainWindow::on_start_clicked()
{
    ui->pyt1->clear();
    ui->pyt2->clear();
    ui->pyt3->clear();
    ui->dodatkowe_pytania->clear();
    ui->ImieStudenta->setDisabled(1);
    ui->edycja->setDisabled(1);




    if(ui->start->text()=="RESET"){
        ui->edycja->setEnabled(1);
        ui->dodPytPodstA->setValue(0);
        ui->dodPytPodstB->setValue(0);
        ui->dodPytPodstC->setValue(0);
        ui->dodPytSred->setValue(0);
        ui->dodPytTrud->setValue(0);
        ui->ImieStudenta->setEnabled(1);
        ui->start->setText("Start test");
        ui->jakiEgzamin->setEnabled(1);
                ui->comboBox_3->setCurrentIndex(0);
                egzamin->resetDanych();
               //pamiecIleDodatkowych=student->zwolnienie(ui->ImieStudenta->currentIndex());
                ui->IleDodPyt->display(student->zwolnienie(ui->ImieStudenta->currentIndex()));

    }
    else{
    if(ui->start->text()=="Nastepny poziom"){

        if(ui->comboBox_3->currentIndex()==2){
            //reset
            ui->start->setDisabled(1);
        }else{
ui->comboBox_3->setCurrentIndex(ui->comboBox_3->currentIndex()+1);
ui->start->setDisabled(1);
}
        if(ui->comboBox_3->currentIndex()==2){
            ui->start->setText("RESET");
        }
    }else
    {
    //czas start ustawienia na starcie
    ////////////////////////////////

    //wyswietlenie liczby dodatkowych pytan

    pamiecIleDodatkowych=student->zwolnienie(ui->ImieStudenta->currentIndex());
        ui->IleDodPyt->display(pamiecIleDodatkowych);






//blokada 2 informacji podawanych na wstepie(listy rozwijane)
ui->jakiEgzamin->setDisabled(1);

//blokada start test
ui->start->setDisabled(1);
ui->start->setText("Nastepny poziom");


if(ui->Zwolnienie_z_podst->text()=="   Zwolnienie z częsci podstawowej   "){
    ui->comboBox_3->setCurrentIndex(1);
}
////////////////////////////////////
}
    //mozna losowac pytania
    ui->PoziomStart->setEnabled(1);

}
    if(ui->comboBox_3->currentIndex()==0){
        if(!ui->ImieStudenta->isEnabled()){
        if(ui->IleDodPyt->value()>0&&ui->jakiEgzamin->currentIndex()!=2){
        ui->dodPytPodstA->setEnabled(1);
        ui->dodPytPodstB->setEnabled(1);
        ui->dodPytPodstC->setEnabled(1);
        }
    }
    }else
    if(ui->comboBox_3->currentIndex()==1){
        if((ui->IleDodPyt->value()>0)){
          ui->dodPytSred->setEnabled(1);
    }
    }
    else{
        if((ui->IleDodPyt->value()>0)){
        ui->dodPytTrud->setEnabled(1);
    }
}


}

void MainWindow::on_ImieStudenta_activated(int index)
{
    //automatyczne zadanie liczby dodatkowych pytan oraz zwolnienia
int ilePytanZwolnienie=student->zwolnienie(index);

        //zwolnienie
if(ui->jakiEgzamin->currentIndex()!=2){
        if(student->getSrednia(index)>=5)
        {
            ui->Zwolnienie_z_podst->setText("   Zwolnienie z częsci podstawowej   ");
        }
        else{
            ui->Zwolnienie_z_podst->setText("Brak zwolnienia z części podstawowej");
        }
}
else
    ui->Zwolnienie_z_podst->setText("           EGZAMIN DYPLOMOWY         ");

         //liczba dodatkowych pytan
    ui->IleDodPyt->display(ilePytanZwolnienie);

}


void MainWindow::on_jakiEgzamin_activated(int index)
{
    bool problem =0;
    if(index==0){
        MainWindow::egzamin=MainWindow::pk;
        if(MainWindow::egzamin->raportBladZczytywanie()==1){
            problem=1;}
            ui->pyt1->setText("BŁĄD PODCZAS ZCZYTYWANIA DANYCH Z PLIKU");
        if(MainWindow::egzamin->raportBrakNazwy()==1){
            problem=1;}
            ui->pyt2->setText("BRAK NAZWY PLIKU");
        if(MainWindow::egzamin->raportZlaNazwa()==1){
            problem=1;}
            ui->pyt3->setText("BLĘDNA NAZWA PLIKU");
            if(ui->jakiEgzamin->currentIndex()!=2){
                    if(MainWindow::student->getSrednia(ui->ImieStudenta->currentIndex())>=5)
                    {
                        ui->Zwolnienie_z_podst->setText("   Zwolnienie z częsci podstawowej   ");
                    }
                    else{
                        ui->Zwolnienie_z_podst->setText("Brak zwolnienia z części podstawowej");
                    }
            }
    }else if(index==1){
        MainWindow::egzamin=MainWindow::ppk;
        if(MainWindow::egzamin->raportBladZczytywanie()==1){
            ui->pyt1->setText("BŁĄD PODCZAS ZCZYTYWANIA DANYCH Z PLIKU");
            problem=1;
        }
        if(MainWindow::egzamin->raportBrakNazwy()==1){
            ui->pyt2->setText("BRAK NAZWY PLIKU");
            problem=1;
        }
        if(MainWindow::egzamin->raportZlaNazwa()==1){
            ui->pyt3->setText("BLĘDNA NAZWA PLIKU");
            problem=1;
        }
        if(ui->jakiEgzamin->currentIndex()!=2){
                if(MainWindow::student->getSrednia(ui->ImieStudenta->currentIndex())>=5)
                {
                    ui->Zwolnienie_z_podst->setText("   Zwolnienie z częsci podstawowej   ");
                }
                else{
                    ui->Zwolnienie_z_podst->setText("Brak zwolnienia z części podstawowej");
                }
        }
    }else{
        if(MainWindow::dyplom->raportBladZczytywanie()==1){
            ui->pyt1->setText("BŁĄD PODCZAS ZCZYTYWANIA DANYCH Z PLIKU");
            problem=1;}
        if(MainWindow::dyplom->raportBrakNazwy()==1){
            problem=1;}
            ui->pyt2->setText("BRAK NAZWY PLIKU");
        if(MainWindow::dyplom->raportZlaNazwa()==1){
            problem=1;}
            ui->pyt3->setText("BLĘDNA NAZWA PLIKU");
            ui->Zwolnienie_z_podst->setText("           EGZAMIN DYPLOMOWY         ");
    }

if(problem)
            ui->start->setDisabled(1);
else
          {
    ui->start->setEnabled(1);
    ui->pyt1->setText("");
    ui->pyt2->setText("");
    ui->pyt3->setText("");
}
}

void MainWindow::on_dodPytPodstA_valueChanged(int arg1)
{
int czyJestJeszczePytanie=pamiecIleDodatkowych-pamiecPytanPodstB-pamiecPytanPodstC-arg1;

//w gore
if(arg1>pamiecPytanPodstA){
if(czyJestJeszczePytanie>=0){
    ui->IleDodPyt->display(ui->IleDodPyt->value()-(arg1-pamiecPytanPodstA));
    pamiecPytanPodstA=arg1;
}
else
{
    ui->dodPytPodstA->setValue(pamiecPytanPodstA);
}
}
//w dol
else{
    ui->IleDodPyt->display(ui->IleDodPyt->value()+(pamiecPytanPodstA-arg1));
     pamiecPytanPodstA=arg1;
}

sprawdzWyswietlacz();

}

void MainWindow::on_dodPytPodstB_valueChanged(int arg1)
{
    int czyJestJeszczePytanie=pamiecIleDodatkowych-pamiecPytanPodstA-pamiecPytanPodstC-arg1;


    //w gore
    if(arg1>pamiecPytanPodstB){
    if(czyJestJeszczePytanie>=0){
        ui->IleDodPyt->display(ui->IleDodPyt->value()-(arg1-pamiecPytanPodstB));
        pamiecPytanPodstB=arg1;
    }
    else
    {
        ui->dodPytPodstB->setValue(pamiecPytanPodstB);
    }
    }
    //w dol
    else{
        ui->IleDodPyt->display(ui->IleDodPyt->value()+(pamiecPytanPodstB-arg1));
        pamiecPytanPodstB=arg1;
    }
sprawdzWyswietlacz();

}

void MainWindow::on_dodPytPodstC_valueChanged(int arg1)
{
    int czyJestJeszczePytanie=pamiecIleDodatkowych-pamiecPytanPodstB-pamiecPytanPodstA-arg1;


    //w gore
    if(arg1>pamiecPytanPodstC){
    if(czyJestJeszczePytanie>=0){
        ui->IleDodPyt->display(ui->IleDodPyt->value()-(arg1-pamiecPytanPodstC));
        pamiecPytanPodstC=arg1;
    }
    else
    {
        ui->dodPytPodstC->setValue(pamiecPytanPodstC);
    }
    }
    //w dol
    else{
        ui->IleDodPyt->display(ui->IleDodPyt->value()+(pamiecPytanPodstC-arg1));
         pamiecPytanPodstC=arg1;
    }
sprawdzWyswietlacz();
}

void MainWindow::on_dodPytSred_valueChanged(int arg1)
{
    int czyJestJeszczePytanie=pamiecIleDodatkowych-pamiecPytanPodstB-pamiecPytanPodstA-pamiecPytanPodstC-arg1;

    //w gore
    if(arg1>pamiecPytanSrednich){
    if(czyJestJeszczePytanie>=0){
        ui->IleDodPyt->display(ui->IleDodPyt->value()-(arg1-pamiecPytanSrednich));
        pamiecPytanSrednich=arg1;
    }
    else
    {
        ui->dodPytSred->setValue(pamiecPytanSrednich);
    }
    }
    //w dol
    else{
        ui->IleDodPyt->display(ui->IleDodPyt->value()+(pamiecPytanSrednich-arg1));
         pamiecPytanSrednich=arg1;
    }


   sprawdzWyswietlacz();
}

void MainWindow::on_dodPytTrud_valueChanged(int arg1)
{
    int czyJestJeszczePytanie=pamiecIleDodatkowych-pamiecPytanPodstB-pamiecPytanPodstA-pamiecPytanPodstC-pamiecPytanSrednich-arg1;

    //w gore
    if(arg1>pamiecPytanTrudnych){
    if(czyJestJeszczePytanie>=0){
        ui->IleDodPyt->display(ui->IleDodPyt->value()-(arg1-pamiecPytanTrudnych));
        pamiecPytanTrudnych=arg1;
    }
    else
    {
        ui->dodPytTrud->setValue(pamiecPytanTrudnych);
    }
    }
    //w dol
    else{
        ui->IleDodPyt->display(ui->IleDodPyt->value()+(pamiecPytanTrudnych-arg1));
         pamiecPytanTrudnych=arg1;
    }

    sprawdzWyswietlacz();

}

void MainWindow::sprawdzWyswietlacz(){
    if(ui->IleDodPyt->value()<0)
        ui->IleDodPyt->display(0);
    if(ui->IleDodPyt->value()>pamiecIleDodatkowych)
        ui->IleDodPyt->display(pamiecIleDodatkowych);
}


void MainWindow::on_edycja_clicked()
{
    m_okienko->exec();
}
