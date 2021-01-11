#include "edytor.h"
#include "ui_edytor.h"
#include "QTextCodec"
//deklaracje static
bazaDanych* edytor::m_baza=nullptr;

edytor::edytor(QString nazwaPlikuPK,QString nazwaPlikuPPK,QString nazwaPlikuDyplom,QString nazwaPlikuStudenci,QString nazwaBazy,QWidget *parent,bazaDanych* baza,Student* stud) :
    QDialog(parent),
    ui(new Ui::edytor)
{
    m_baza=baza;
    ui->setupUi(this);
    nazwaPlikuDyplomEdytor=nazwaPlikuDyplom;
    nazwaPlikuPKEdytor=nazwaPlikuPK;
    nazwaPlikuPPKEdytor=nazwaPlikuPPK;
    nazwaPlikuStudenciEdytor=nazwaPlikuStudenci;
    nazwaBazyEdytor=nazwaBazy;
    m_student=stud;
}

edytor::~edytor()
{
    delete ui;
}

void edytor::on_koniec_clicked()
{
    ui->poleTekstowe->setPlainText("");
    ui->saveBase->setEnabled(1);
    ui->savePlik->setEnabled(1);
     this->hide();
}

void edytor::on_readPK_clicked()
{
    przycisk=1;


    ui->saveBase->setEnabled(1);
    ui->savePlik->setEnabled(1);

  if(!ui->readBaza->isEnabled()){
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
  }else{
      QStringList zczytanePlikEdytor;
    zczytywanie_pytan edytorRead;
    QString wyswietl="";
     switch(pozycja){
    default:{
         ui->TYTUL->setText("PK    Programowanie proceduralne, obsługa plików, operacje bitowe i testowanie");
         edytorRead.zczytywaniePytan1(zczytanePlikEdytor,48,57,nazwaPlikuPKEdytor,1);
         for(int pozycja=0;pozycja<zczytanePlikEdytor.size();pozycja++)
         wyswietl+=zczytanePlikEdytor.at(pozycja);
         ui->poleTekstowe->setPlainText(wyswietl);
          break;
     }
     case 1:{
         ui->TYTUL->setText("PK    Złożone typy danych i podstawy programowania obiektowego");
         edytorRead.zczytywaniePytan1(zczytanePlikEdytor,48,57,nazwaPlikuPKEdytor,2);
         for(int pozycja=0;pozycja<zczytanePlikEdytor.size();pozycja++)
         wyswietl+=zczytanePlikEdytor.at(pozycja);
         ui->poleTekstowe->setPlainText(wyswietl);
         break;
     }
     case 2:{
         ui->TYTUL->setText("PK    Interakcje obiektowe, zarządzanie pamięcią w klasach, programowanie generyczne");
         edytorRead.zczytywaniePytan1(zczytanePlikEdytor,48,57,nazwaPlikuPKEdytor,3);
         for(int pozycja=0;pozycja<zczytanePlikEdytor.size();pozycja++)
         wyswietl+=zczytanePlikEdytor.at(pozycja);
         ui->poleTekstowe->setPlainText(wyswietl);
         break;
     }
     case 3:{
         ui->TYTUL->setText("PK    POZIOM ŚREDNI");
         edytorRead.zczytywaniePytan1(zczytanePlikEdytor,48,57,nazwaPlikuPKEdytor,4);
         for(int pozycja=0;pozycja<zczytanePlikEdytor.size();pozycja++)
         wyswietl+=zczytanePlikEdytor.at(pozycja);
         ui->poleTekstowe->setPlainText(wyswietl);
         break;
     }
     case 4:{
         ui->TYTUL->setText("PK    POZIOM TRUDNY");
         edytorRead.zczytywaniePytan1(zczytanePlikEdytor,48,57,nazwaPlikuPKEdytor,5);
         for(int pozycja=0;pozycja<zczytanePlikEdytor.size();pozycja++)
         wyswietl+=zczytanePlikEdytor.at(pozycja);
         ui->poleTekstowe->setPlainText(wyswietl);
         break;
     }
     }



  }
}

void edytor::on_readPPK_clicked()
{
    ui->saveBase->setEnabled(1);
    ui->savePlik->setEnabled(1);
    przycisk=2;
    if(!ui->readBaza->isEnabled()){
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
}else{
    QStringList zczytanePlikEdytor;
  zczytywanie_pytan edytorRead;
  QString wyswietl="";
   switch(pozycja){
  default:{
        ui->TYTUL->setText("PPK    Podstawy programowania i instrukcje sterujące");
       edytorRead.zczytywaniePytan1(zczytanePlikEdytor,48,57,nazwaPlikuPPKEdytor,1);
       for(int pozycja=0;pozycja<zczytanePlikEdytor.size();pozycja++)
       wyswietl+=zczytanePlikEdytor.at(pozycja);
       ui->poleTekstowe->setPlainText(wyswietl);
        break;
   }
   case 1:{
       ui->TYTUL->setText("PPK    Operacje tablicowe i wskaźnikowe i funkcje");
       edytorRead.zczytywaniePytan1(zczytanePlikEdytor,48,57,nazwaPlikuPPKEdytor,2);
       for(int pozycja=0;pozycja<zczytanePlikEdytor.size();pozycja++)
       wyswietl+=zczytanePlikEdytor.at(pozycja);
       ui->poleTekstowe->setPlainText(wyswietl);
       break;
   }
   case 2:{
      ui->TYTUL->setText("PPK    Debugowanie, testowanie kodu i obsługa wyjątków");
       edytorRead.zczytywaniePytan1(zczytanePlikEdytor,48,57,nazwaPlikuPPKEdytor,3);
       for(int pozycja=0;pozycja<zczytanePlikEdytor.size();pozycja++)
       wyswietl+=zczytanePlikEdytor.at(pozycja);
       ui->poleTekstowe->setPlainText(wyswietl);
       break;
   }
   case 3:{
       ui->TYTUL->setText("PPK    POZIOM ŚREDNI");
       edytorRead.zczytywaniePytan1(zczytanePlikEdytor,48,57,nazwaPlikuPPKEdytor,4);
       for(int pozycja=0;pozycja<zczytanePlikEdytor.size();pozycja++)
       wyswietl+=zczytanePlikEdytor.at(pozycja);
       ui->poleTekstowe->setPlainText(wyswietl);
       break;
   }
   case 4:{
       ui->TYTUL->setText("PPK    POZIOM TRUDNY");
       edytorRead.zczytywaniePytan1(zczytanePlikEdytor,48,57,nazwaPlikuPPKEdytor,5);
       for(int pozycja=0;pozycja<zczytanePlikEdytor.size();pozycja++)
       wyswietl+=zczytanePlikEdytor.at(pozycja);
       ui->poleTekstowe->setPlainText(wyswietl);
       break;
   }
   }



}
}

void edytor::on_readDyplom_clicked()
{
    ui->saveBase->setEnabled(1);
    ui->savePlik->setEnabled(1);
    if(pozycja==4)
        pozycja=0;

    przycisk=3;
    if(!ui->readBaza->isEnabled()){
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
}else{
  QStringList zczytanePlikEdytor;
  zczytywanie_pytan edytorRead;
  QString wyswietl="";
   switch(pozycja){
  default:{
       ui->TYTUL->setText("DYPLOM    Administracja, sieci komputerowe i technologie internetowe");
       edytorRead.zczytywaniePytan1(zczytanePlikEdytor,40,40,nazwaPlikuDyplomEdytor,1);
       for(int pozycja=0;pozycja<zczytanePlikEdytor.size();pozycja++)
       wyswietl+=zczytanePlikEdytor.at(pozycja);
       ui->poleTekstowe->setPlainText(wyswietl);
        break;
   }
   case 1:{
       ui->TYTUL->setText("DYPLOM    Automatyka, elektrotechnika, elektronika i robotyka");
       edytorRead.zczytywaniePytan1(zczytanePlikEdytor,40,40,nazwaPlikuDyplomEdytor,2);
       for(int pozycja=0;pozycja<zczytanePlikEdytor.size();pozycja++)
       wyswietl+=zczytanePlikEdytor.at(pozycja);
       ui->poleTekstowe->setPlainText(wyswietl);
       break;
   }
   case 2:{
       ui->TYTUL->setText("DYPLOM    Programowanie, algorytmika i inżynieria oprogramowania");
       edytorRead.zczytywaniePytan1(zczytanePlikEdytor,40,40,nazwaPlikuDyplomEdytor,3);
       for(int pozycja=0;pozycja<zczytanePlikEdytor.size();pozycja++)
       wyswietl+=zczytanePlikEdytor.at(pozycja);
       ui->poleTekstowe->setPlainText(wyswietl);
       break;
   }
   case 3:{
       ui->TYTUL->setText("DYPLOM    Pytania tylko dla spejaności Programowanie Komputerów:");
       edytorRead.zczytywaniePytan1(zczytanePlikEdytor,40,40,nazwaPlikuDyplomEdytor,4);
       for(int pozycja=0;pozycja<zczytanePlikEdytor.size();pozycja++)
       wyswietl+=zczytanePlikEdytor.at(pozycja);
       ui->poleTekstowe->setPlainText(wyswietl);
       break;
   }
   }



}
}
void edytor::on_readStud_clicked()
{
    ui->saveBase->setEnabled(1);
    ui->savePlik->setEnabled(1);
    przycisk=4;
    if(pozycja>m_student->ileSekcjijest()-1)
        pozycja=0;

QString zapyt="Studenci sekcja ";

    if(!ui->readBaza->isEnabled()){
        zapyt+=QString::number(pozycja+1);
        ui->TYTUL->setText(zapyt);
   ui->poleTekstowe->setPlainText(m_baza->selectStudenci(pozycja));
}
    else{
        ui->TYTUL->setText("Studenci sekcja "+QString::number(pozycja+1));
        QStringList zczytanePlikEdytor;
        zczytywanie_pytan edytorRead;
        QString wyswietl="";
        edytorRead.zczytywaniePytan1(zczytanePlikEdytor,65,122,nazwaPlikuStudenciEdytor,1);
        for(int pozycjaa=0;pozycjaa<zczytanePlikEdytor.size();pozycjaa++){
            int ileTb=0;
            QString linija=zczytanePlikEdytor.at(pozycjaa);
            for(int i=0;i<linija.size();i++){
                if(linija.at(i)=="\t")
                    ileTb++;
                if(ileTb==3){
                    if(QString::number(pozycja+1)==linija.at(i-1)){
                        wyswietl+=zczytanePlikEdytor.at(pozycjaa);
                    }
                    break;
                }
            }

        }
        ui->poleTekstowe->setPlainText(wyswietl);


    }


}
void edytor::on_readBaza_clicked()
{
    ui->skadZczytane->setText("Zczytane z Bazy");
    ui->readPlik->setEnabled(1);
    ui->readBaza->setDisabled(1);
    ui->poleTekstowe->setPlainText("");
    ui->saveBase->setDisabled(1);
    ui->savePlik->setDisabled(1);
}

void edytor::on_readPlik_clicked()
{
    ui->skadZczytane->setText("Zczytane z Pliku");
    ui->readPlik->setDisabled(1);
    ui->readBaza->setEnabled(1);
    ui->poleTekstowe->setPlainText("");
    ui->saveBase->setDisabled(1);
    ui->savePlik->setDisabled(1);
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
        if(pozycja!=m_student->ileSekcjijest()-1||!ui->readBaza->isEnabled()){
            pozycja++;
        on_readStud_clicked();
        }
        break;
    }
    default:
        break;
    }
}

void edytor::on_savePlik_clicked()
{
    QString text=ui->poleTekstowe->toPlainText();
    if(!text.isEmpty()){
        QString coZapisujemy;
        switch(przycisk){
        case 1:{
            PK_PPK edytorPytanka(nazwaPlikuPKEdytor);
            if(pozycja==0){
                coZapisujemy="POZIOM PODSTAWOWY\nProgramowanie proceduralne, obsługa plików, operacje bitowe i testowanie\n";
                coZapisujemy+=ui->poleTekstowe->toPlainText();

                coZapisujemy+="\nZłożone typy danych i podstawy programowania obiektowego\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanPodstawowychPKb();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaPodstawowePKBIndeks(i);
                }

                coZapisujemy+="\nInterakcje obiektowe, zarządzanie pamięcią w klasach, programowanie generyczne\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanPodstawowychPKc();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaPodstawowePKCIndeks(i);
                }

                coZapisujemy+="\nPOZIOM ŚREDNI:\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanSrednichPK();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaSredniePKIndeks(i);
                }

                coZapisujemy+="\nPOZIOM ZAAWANSOWANY:\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanTrudnychPk();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaTrudnePKIndeks(i);
                }

            }else if(pozycja==1){
                coZapisujemy="POZIOM PODSTAWOWY\nProgramowanie proceduralne, obsługa plików, operacje bitowe i testowanie\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanPodstawowychPKa();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaPodstawowePKAIndeks(i);
                }

                coZapisujemy+="\nZłożone typy danych i podstawy programowania obiektowego\n";
                coZapisujemy+=ui->poleTekstowe->toPlainText();

                coZapisujemy+="\nInterakcje obiektowe, zarządzanie pamięcią w klasach, programowanie generyczne\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanPodstawowychPKc();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaPodstawowePKCIndeks(i);
                }

                coZapisujemy+="\nPOZIOM ŚREDNI:\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanSrednichPK();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaSredniePKIndeks(i);
                }

                coZapisujemy+="\nPOZIOM ZAAWANSOWANY:\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanTrudnychPk();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaTrudnePKIndeks(i);
                }

            }else if(pozycja==2){
                coZapisujemy="POZIOM PODSTAWOWY\nProgramowanie proceduralne, obsługa plików, operacje bitowe i testowanie\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanPodstawowychPKa();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaPodstawowePKAIndeks(i);
                }

                coZapisujemy+="\nZłożone typy danych i podstawy programowania obiektowego\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanPodstawowychPKb();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaPodstawowePKBIndeks(i);
                }

                coZapisujemy+="\nInterakcje obiektowe, zarządzanie pamięcią w klasach, programowanie generyczne\n";
                coZapisujemy+=ui->poleTekstowe->toPlainText();

                coZapisujemy+="\nPOZIOM ŚREDNI:\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanSrednichPK();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaSredniePKIndeks(i);
                }

                coZapisujemy+="\nPOZIOM ZAAWANSOWANY:\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanTrudnychPk();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaTrudnePKIndeks(i);
                }

            }else if(pozycja==3){
                coZapisujemy="POZIOM PODSTAWOWY\nProgramowanie proceduralne, obsługa plików, operacje bitowe i testowanie\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanPodstawowychPKa();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaPodstawowePKAIndeks(i);
                }

                coZapisujemy+="\nZłożone typy danych i podstawy programowania obiektowego\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanPodstawowychPKb();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaPodstawowePKBIndeks(i);
                }

                coZapisujemy+="\nInterakcje obiektowe, zarządzanie pamięcią w klasach, programowanie generyczne\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanPodstawowychPKb();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaPodstawowePKBIndeks(i);
                }

                coZapisujemy+="\nPOZIOM ŚREDNI:\n";
                coZapisujemy+=ui->poleTekstowe->toPlainText();

                coZapisujemy+="\nPOZIOM ZAAWANSOWANY:\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanTrudnychPk();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaTrudnePKIndeks(i);
                }

            }else{
                coZapisujemy="POZIOM PODSTAWOWY\nProgramowanie proceduralne, obsługa plików, operacje bitowe i testowanie\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanPodstawowychPKa();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaPodstawowePKAIndeks(i);
                }

                coZapisujemy+="\nZłożone typy danych i podstawy programowania obiektowego\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanPodstawowychPKb();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaPodstawowePKBIndeks(i);
                }

                coZapisujemy+="\nInterakcje obiektowe, zarządzanie pamięcią w klasach, programowanie generyczne\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanPodstawowychPKc();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaPodstawowePKCIndeks(i);
                }

                coZapisujemy+="\nPOZIOM ŚREDNI:\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanSrednichPK();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaSredniePKIndeks(i);
                }

                coZapisujemy+="\nPOZIOM ZAAWANSOWANY:";
                coZapisujemy+=ui->poleTekstowe->toPlainText();

            }
            QFile file(nazwaPlikuPKEdytor);
            if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
                QTextStream out(&file);
                out.setCodec("UTF-8");
                out << coZapisujemy; // zapis danych do pliku
                file.close();
            }
            break;
        }
        case 2:{
            PK_PPK edytorPytanka(nazwaPlikuPPKEdytor);
            if(pozycja==0){
                coZapisujemy="POZIOM PODSTAWOWY\nPodstawy programowania i instrukcje sterujące\n";
                coZapisujemy+=ui->poleTekstowe->toPlainText();

                coZapisujemy+="\nOperacje tablicowe i wskaźnikowe i funkcje\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanPodstawowychPKb();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaPodstawowePKBIndeks(i);
                }

                coZapisujemy+="\nDebugowanie, testowanie kodu i obsługa wyjątków\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanPodstawowychPKc();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaPodstawowePKCIndeks(i);
                }

                coZapisujemy+="\nPOZIOM ŚREDNI:\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanSrednichPK();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaSredniePKIndeks(i);
                }

                coZapisujemy+="\nPOZIOM ZAAWANSOWANY:\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanTrudnychPk();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaTrudnePKIndeks(i);
                }

            }else if(pozycja==1){
                coZapisujemy="POZIOM PODSTAWOWY\nPodstawy programowania i instrukcje sterujące\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanPodstawowychPKa();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaPodstawowePKAIndeks(i);
                }

                coZapisujemy+="\nOperacje tablicowe i wskaźnikowe i funkcje\n";
                coZapisujemy+=ui->poleTekstowe->toPlainText();

                coZapisujemy+="\nDebugowanie, testowanie kodu i obsługa wyjątków\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanPodstawowychPKc();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaPodstawowePKCIndeks(i);
                }

                coZapisujemy+="\nPOZIOM ŚREDNI:\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanSrednichPK();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaSredniePKIndeks(i);
                }

                coZapisujemy+="\nPOZIOM ZAAWANSOWANY:\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanTrudnychPk();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaTrudnePKIndeks(i);
                }

            }else if(pozycja==2){
                coZapisujemy="POZIOM PODSTAWOWY\nPodstawy programowania i instrukcje sterujące\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanPodstawowychPKa();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaPodstawowePKAIndeks(i);
                }

                coZapisujemy+="\nOperacje tablicowe i wskaźnikowe i funkcje\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanPodstawowychPKb();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaPodstawowePKBIndeks(i);
                }

                coZapisujemy+="\nDebugowanie, testowanie kodu i obsługa wyjątków\n";
                coZapisujemy+=ui->poleTekstowe->toPlainText();

                coZapisujemy+="\nPOZIOM ŚREDNI:\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanSrednichPK();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaSredniePKIndeks(i);
                }

                coZapisujemy+="\nPOZIOM ZAAWANSOWANY:\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanTrudnychPk();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaTrudnePKIndeks(i);
                }

            }else if(pozycja==3){
                coZapisujemy="POZIOM PODSTAWOWY\nPodstawy programowania i instrukcje sterujące\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanPodstawowychPKa();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaPodstawowePKAIndeks(i);
                }

                coZapisujemy+="\nOperacje tablicowe i wskaźnikowe i funkcje\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanPodstawowychPKb();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaPodstawowePKBIndeks(i);
                }

                coZapisujemy+="\nDebugowanie, testowanie kodu i obsługa wyjątków\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanPodstawowychPKb();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaPodstawowePKBIndeks(i);
                }

                coZapisujemy+="\nPOZIOM ŚREDNI:\n";
                coZapisujemy+=ui->poleTekstowe->toPlainText();

                coZapisujemy+="\nPOZIOM ZAAWANSOWANY:\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanTrudnychPk();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaTrudnePKIndeks(i);
                }

            }else{
              coZapisujemy="POZIOM PODSTAWOWY\nPodstawy programowania i instrukcje sterujące\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanPodstawowychPKa();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaPodstawowePKAIndeks(i);
                }

                coZapisujemy+="\nOperacje tablicowe i wskaźnikowe i funkcje\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanPodstawowychPKb();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaPodstawowePKBIndeks(i);
                }

                coZapisujemy+="\nDebugowanie, testowanie kodu i obsługa wyjątków\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanPodstawowychPKc();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaPodstawowePKCIndeks(i);
                }

                coZapisujemy+="\nPOZIOM ŚREDNI:\n";
                for(int i=0;i<edytorPytanka.get_ile_pytanSrednichPK();i++){
                    coZapisujemy+=edytorPytanka.getWczytane_pytaniaSredniePKIndeks(i);
                }

                coZapisujemy+="\nPOZIOM ZAAWANSOWANY:";
                coZapisujemy+=ui->poleTekstowe->toPlainText();

            }
            QFile file(nazwaPlikuPPKEdytor);
            if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
                QTextStream out(&file);
                out.setCodec("UTF-8");
                out << coZapisujemy; // zapis danych do pliku
                file.close();
            }
            break;
        }
        case 3:{
            DYPLOMOWY edytorPytanka(nazwaPlikuDyplomEdytor);
            if(pozycja==0){
                coZapisujemy="Pytania ogólne - Administracja, sieci komputerowe i technologie internetowe:\n";
                coZapisujemy+=ui->poleTekstowe->toPlainText();

                coZapisujemy+="\nPytania ogólne - Automatyka, elektrotechnika, elektronika i robotyka:\n";
                for(int i=0;i<edytorPytanka.get_ilePytanDyplomB();i++){
                    coZapisujemy+=edytorPytanka.getDyplomBIndeks().at(i);
                }

                coZapisujemy+="\nPytania ogólne - Programowanie, algorytmika i inżynieria oprogramowania:\n";
                for(int i=0;i<edytorPytanka.get_ilePytanDyplomC();i++){
                    coZapisujemy+=edytorPytanka.getDyplomCIndeks().at(i);
                }

                coZapisujemy+="\nPytania tylko dla spejaności Programowanie Komputerów:\n";
                for(int i=0;i<edytorPytanka.get_ilePytanDyplomD();i++){
                    coZapisujemy+=edytorPytanka.getDyplomDIndeks().at(i);
                }



            }else if(pozycja==1){
                coZapisujemy="Pytania ogólne - Administracja, sieci komputerowe i technologie internetowe:\n";
                for(int i=0;i<edytorPytanka.get_ilePytanDyplomA();i++){
                    coZapisujemy+=edytorPytanka.getDyplomAIndeks().at(i);
                }

                coZapisujemy+="\nPytania ogólne - Automatyka, elektrotechnika, elektronika i robotyka:\n";
                coZapisujemy+=ui->poleTekstowe->toPlainText();

                coZapisujemy+="\nPytania ogólne - Programowanie, algorytmika i inżynieria oprogramowania:\n";
                for(int i=0;i<edytorPytanka.get_ilePytanDyplomC();i++){
                    coZapisujemy+=edytorPytanka.getDyplomCIndeks().at(i);
                }

                coZapisujemy+="\nPytania tylko dla spejaności Programowanie Komputerów:\n";
                for(int i=0;i<edytorPytanka.get_ilePytanDyplomD();i++){
                    coZapisujemy+=edytorPytanka.getDyplomDIndeks().at(i);
                }

            }else if(pozycja==2){
                coZapisujemy="Pytania ogólne - Administracja, sieci komputerowe i technologie internetowe:\n";
                for(int i=0;i<edytorPytanka.get_ilePytanDyplomA();i++){
                    coZapisujemy+=edytorPytanka.getDyplomAIndeks().at(i);
                }

                coZapisujemy+="\nPytania ogólne - Automatyka, elektrotechnika, elektronika i robotyka:\n";
                for(int i=0;i<edytorPytanka.get_ilePytanDyplomB();i++){
                    coZapisujemy+=edytorPytanka.getDyplomBIndeks().at(i);
                }

                coZapisujemy+="\nPytania ogólne - Programowanie, algorytmika i inżynieria oprogramowania:\n";
                coZapisujemy+=ui->poleTekstowe->toPlainText();

                coZapisujemy+="\nPytania tylko dla spejaności Programowanie Komputerów:\n";
                for(int i=0;i<edytorPytanka.get_ilePytanDyplomD();i++){
                    coZapisujemy+=edytorPytanka.getDyplomDIndeks().at(i);
                }

            }else if(pozycja==3){
                coZapisujemy="Pytania ogólne - Administracja, sieci komputerowe i technologie internetowe:\n";
                for(int i=0;i<edytorPytanka.get_ilePytanDyplomA();i++){
                    coZapisujemy+=edytorPytanka.getDyplomAIndeks().at(i);
                }

                coZapisujemy+="\nPytania ogólne - Automatyka, elektrotechnika, elektronika i robotyka:\n";
                for(int i=0;i<edytorPytanka.get_ilePytanDyplomB();i++){
                    coZapisujemy+=edytorPytanka.getDyplomBIndeks().at(i);
                }
                coZapisujemy+="\nPytania ogólne - Programowanie, algorytmika i inżynieria oprogramowania:\n";
                for(int i=0;i<edytorPytanka.get_ilePytanDyplomC();i++){
                    coZapisujemy+=edytorPytanka.getDyplomCIndeks().at(i);
                }

                coZapisujemy+="\nPytania tylko dla spejaności Programowanie Komputerów:\n";
                coZapisujemy+=ui->poleTekstowe->toPlainText();

            }

            QFile file(nazwaPlikuDyplomEdytor);
            if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
                QTextStream out(&file);
                out.setCodec("UTF-8");
                out << coZapisujemy; // zapis danych do pliku
                file.close();
            }
            break;
        }
        case 4:{

            QStringList zczytanePlikEdytor;
            zczytywanie_pytan edytorRead;
            QString wyswietl="";
            //wyswietl+="/n";
            edytorRead.zczytywaniePytan1(zczytanePlikEdytor,65,122,nazwaPlikuStudenciEdytor,1);
            wyswietl+=ui->poleTekstowe->toPlainText();
            QString nowyWyswietl;
            int ileUsunac=0;
            for(int i=wyswietl.size()-1;i>0;i--){
                if(wyswietl.at(i)=="\n"||wyswietl.at(i)=="\t")
                    ileUsunac++;
                else
                    break;
            }
            for(int i=0;i<wyswietl.size()-ileUsunac;i++)
                nowyWyswietl+=wyswietl.at(i);
            wyswietl=nowyWyswietl;
            wyswietl+="\n";

                for(int pozycjaa=0;pozycjaa<zczytanePlikEdytor.size();pozycjaa++){
                    int ileTb=0;
                    QString linija=zczytanePlikEdytor.at(pozycjaa);
                    for(int i=0;i<linija.size();i++){
                        if(linija.at(i)=="\t")
                            ileTb++;
                        if(ileTb==3){
                            if(QString::number(pozycja+1)!=linija.at(i-1)){
                                wyswietl+=zczytanePlikEdytor.at(pozycjaa);
                            }
                            break;
                        }
                    }
            }


                ui->poleTekstowe->setPlainText(wyswietl);


            QFile file(nazwaPlikuStudenciEdytor);
            if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
                QTextStream out(&file);
                out.setCodec("UTF-8");
                out<<ui->poleTekstowe->toPlainText();
                file.close();
            }
            on_readStud_clicked();
            break;
        }
        }
    }
    QMessageBox msgBox;
    msgBox.setText("Zapisano do pliku");
    msgBox.exec();
    ui->poleTekstowe->setPlainText("");
    ui->saveBase->setEnabled(1);
    ui->savePlik->setEnabled(1);
}

void edytor::on_saveBase_clicked()
{
    QString text=ui->poleTekstowe->toPlainText();
    if(!text.isEmpty()){
        bazaDanych edytorBaza(nazwaBazyEdytor);
        QString zczytaneDane=ui->poleTekstowe->toPlainText();
        QString modyfikacjaDanych;
        QString linia;
        QStringList edytorLista;

            if(przycisk==4){
                QStringList imie;
                QStringList nazwisko;
                QList<double> srednia;




                int ileOminac=0;
                for(int i=zczytaneDane.size()-1;i>0;i--){
                    if(zczytaneDane.at(i)=="\n"||zczytaneDane.at(i)=="\t")
                        ileOminac++;
                    else break;
                }

                for(int i=0;i<zczytaneDane.size()-ileOminac;i++){
                    modyfikacjaDanych+=zczytaneDane.at(i);
                    }

                modyfikacjaDanych+="\t";


                int ile_tab=0;
                for(int znak=0;znak<modyfikacjaDanych.size();znak++){

                    if(modyfikacjaDanych.at(znak)=="\t"){
                        ile_tab++;
                        if(ile_tab==1){
                            imie.push_back(linia);
                            linia.clear();

                        }else if(ile_tab==2){
                            nazwisko.push_back(linia);
                            linia.clear();

                        }else if(ile_tab==3){

                            linia.clear();

                        }else if(ile_tab==4){
                           // srednia.push_back(linia.toDouble());
                            linia.clear();
                        }



                    }
                    else{
                        if(modyfikacjaDanych.at(znak)=="\n"){
                            srednia.push_back(linia.toDouble());
                            ile_tab=0;
                            linia.clear();
                        }
                        else
                        linia+=modyfikacjaDanych.at(znak);
                    }
                }
                edytorBaza.wypelnijStudenci(imie,nazwisko,pozycja+1,srednia);
            }
            else
            {
            for(int znak=0;znak<zczytaneDane.size();znak++){

                if(zczytaneDane.at(znak)=="\n"){
                    linia+=zczytaneDane.at(znak);
                    edytorLista.push_back(linia);
                    linia.clear();
                }
                else
                    linia+=zczytaneDane.at(znak);
            }
            edytorBaza.wypelnijTabelePytania(edytorLista,przycisk,pozycja);
            }
    }
    QMessageBox msgBox;
    msgBox.setText("Zapisano do bazy");
    msgBox.exec();
    ui->poleTekstowe->setPlainText("");
    ui->saveBase->setEnabled(1);
    ui->savePlik->setEnabled(1);
}
