#include "edytor.h"
#include "ui_edytor.h"

//deklaracje static
bazaDanych* edytor::m_baza=nullptr;

edytor::edytor(QWidget *parent,bazaDanych* baza) :
    QDialog(parent),
    ui(new Ui::edytor)
{
    m_baza=baza;
    ui->setupUi(this);
}

edytor::~edytor()
{
    delete ui;
}

void edytor::on_koniec_clicked()
{
    ui->poleTekstowe->setPlainText("");
     this->hide();
}

void edytor::on_readPK_clicked()
{
  // ui->poleTekstowe->setPlainText(m_baza->selectPK());
    przycisk=1;
   switch(pozycja){
  default:{
       ui->TYTUL->setText("PK    Programowanie proceduralne, obsługa plików, operacje bitowe i testowanie");
        ui->poleTekstowe->setPlainText(m_baza->selectPodstAPK());
        break;
   }
   case 1:{
       ui->TYTUL->setText("PK    Złożone typy danych i podstawy programowania obiektowego");
       ui->poleTekstowe->setPlainText(m_baza->selectPodstBPK());
       break;
   }
   case 2:{
       ui->TYTUL->setText("PK    Interakcje obiektowe, zarządzanie pamięcią w klasach, programowanie generyczne");
       ui->poleTekstowe->setPlainText(m_baza->selectPodstCPK());
       break;
   }
   case 3:{
       ui->TYTUL->setText("PK    POZIOM ŚREDNI");
       ui->poleTekstowe->setPlainText(m_baza->selectSredniePK());
       break;
   }
   case 4:{
       ui->TYTUL->setText("PK    POZIOM TRUDNY");
       ui->poleTekstowe->setPlainText(m_baza->selectTrudnePK());
       break;
   }
   }
}

void edytor::on_readPPK_clicked()
{
    przycisk=2;
    switch(pozycja){
    default:{
        ui->TYTUL->setText("PPK    Podstawy programowania i instrukcje sterujące");
         ui->poleTekstowe->setPlainText(m_baza->selectPodstAPPK());
         break;
    }
    case 1:{
        ui->TYTUL->setText("PPK    Operacje tablicowe i wskaźnikowe i funkcje");
        ui->poleTekstowe->setPlainText(m_baza->selectPodstBPPK());
        break;
    }
    case 2:{
        ui->TYTUL->setText("PPK    Debugowanie, testowanie kodu i obsługa wyjątków");
        ui->poleTekstowe->setPlainText(m_baza->selectPodstCPPK());
        break;
    }
    case 3:{
        ui->TYTUL->setText("PPK    POZIOM ŚREDNI");
        ui->poleTekstowe->setPlainText(m_baza->selectSredniePPK());
        break;
    }
    case 4:{
        ui->TYTUL->setText("PPK    POZIOM TRUDNY");
        ui->poleTekstowe->setPlainText(m_baza->selectTrudnePPK());
        break;
    }
    }
}

void edytor::on_readDyplom_clicked()
{
    if(pozycja==4)
        pozycja=0;

    przycisk=3;
    switch(pozycja){
    default:{
        ui->TYTUL->setText("DYPLOM    Administracja, sieci komputerowe i technologie internetowe");
         ui->poleTekstowe->setPlainText(m_baza->selectDyplomA());
         break;
    }
    case 1:{
        ui->TYTUL->setText("DYPLOM    Automatyka, elektrotechnika, elektronika i robotyka");
        ui->poleTekstowe->setPlainText(m_baza->selectDyplomB());
        break;
    }
    case 2:{
        ui->TYTUL->setText("DYPLOM    Programowanie, algorytmika i inżynieria oprogramowania");
        ui->poleTekstowe->setPlainText(m_baza->selectDyplomC());
        break;
    }
    case 3:{
        ui->TYTUL->setText("DYPLOM    Pytania tylko dla spejaności Programowanie Komputerów:");
        ui->poleTekstowe->setPlainText(m_baza->selectDyplomD());
        break;
    }
    }
}
/*
void edytor::on_readPodsA_clicked()
{
    if(ui->ktory->currentIndex())
   ui->poleTekstowe->setPlainText(m_baza->selectPodstAPK());
    else
      ui->poleTekstowe->setPlainText(m_baza->selectPodstAPPK());
}

void edytor::on_readPodsB_clicked()
{
    if(ui->ktory->currentIndex())
       ui->poleTekstowe->setPlainText(m_baza->selectPodstBPK());
       else
        ui->poleTekstowe->setPlainText(m_baza->selectPodstBPPK());
}

void edytor::on_readPodsC_clicked()
{
    if(ui->ktory->currentIndex())
       ui->poleTekstowe->setPlainText(m_baza->selectPodstCPK());
    else
     ui->poleTekstowe->setPlainText(m_baza->selectPodstCPPK());
}

void edytor::on_readSred_clicked()
{
    if(ui->ktory->currentIndex())
       ui->poleTekstowe->setPlainText(m_baza->selectSredniePK());
    else
     ui->poleTekstowe->setPlainText(m_baza->selectSredniePPK());
}

void edytor::on_readTrud_clicked()
{
    if(ui->ktory->currentIndex())
       ui->poleTekstowe->setPlainText(m_baza->selectTrudnePK());
    else
     ui->poleTekstowe->setPlainText(m_baza->selectTrudnePPK());
}

void edytor::on_readDyplomA_clicked()
{
       ui->poleTekstowe->setPlainText(m_baza->selectDyplomA());
}
void edytor::on_readDyplomB_clicked()
{
       ui->poleTekstowe->setPlainText(m_baza->selectDyplomB());
}
void edytor::on_readDyplomC_clicked()
{
       ui->poleTekstowe->setPlainText(m_baza->selectDyplomC());
}
void edytor::on_readDyplomD_clicked()
{
       ui->poleTekstowe->setPlainText(m_baza->selectDyplomD());
}
*/
void edytor::on_readStud_clicked()
{
    przycisk=4;
    if(pozycja>1)
        pozycja=0;

    if(pozycja)
        ui->TYTUL->setText("Studenci sekcja 2");
        else
    ui->TYTUL->setText("Studenci sekcja 1");


   ui->poleTekstowe->setPlainText(m_baza->selectStudenci(pozycja));


}

void edytor::on_readBaza_clicked()
{
    ui->readPlik->setEnabled(1);
    ui->readBaza->setDisabled(1);
}

void edytor::on_readPlik_clicked()
{
    ui->readPlik->setDisabled(1);
    ui->readBaza->setEnabled(1);
}



void edytor::on_back_clicked()
{
    if(pozycja!=0){
        pozycja--;

    switch(przycisk){
    case 1:{
       on_readPK_clicked();
       break;
    }
    case 2:{
        on_readPPK_clicked();
        break;
    }
    case 3:{
        on_readDyplom_clicked();
        break;
    }
    case 4:{
        on_readStud_clicked();
        break;
    }
    }
    }
}

void edytor::on_next_clicked()
{
    switch(przycisk){
    case 1:{
        if(pozycja!=4){
            pozycja++;
       on_readPK_clicked();
        }
       break;
    }
    case 2:{
        if(pozycja!=4){
            pozycja++;
        on_readPPK_clicked();
        }
        break;
    }
    case 3:{
        if(pozycja!=3){
            pozycja++;
        on_readDyplom_clicked();
        }
        break;
    }
    case 4:{
        if(pozycja!=1){
            pozycja++;
        on_readStud_clicked();
        }
        break;
    }
    default:
        break;
    }
}
