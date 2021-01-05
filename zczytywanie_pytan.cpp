#include "zczytywanie_pytan.h"
zczytywanie_pytan::zczytywanie_pytan()
{

}
int zczytywanie_pytan::losujPytanie(int ileMaBazaPytan,int wylosowane[],int &ile_wylosowanych){

    //czy jest
    bool ok;
    int wylosowana;
    do
    {
        //losowanie z bazy pytan
        wylosowana = rand()%ileMaBazaPytan;
        ok = true;

        //sprawdzenie czy jest niepowtarzalne
        for (int i = 0; i < ile_wylosowanych; i++)
        {
            if (wylosowana == wylosowane[i]) ok = false;
        }
} while (!ok);

    //zwiekszenie liczby wylosowanych
    ile_wylosowanych+=+1;
return wylosowana;
}



void zczytywanie_pytan::zczytywaniePytan1(QStringList &lista,int a,int b,QString co_otwieramy,int ktory_raz){

int ktory_raz_ten_program=0;

bool byly_pytania=0;



    QFile file(co_otwieramy);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    while (!file.atEnd()) {
        QString pytania = file.readLine();


        //nie liczba
        if(pytania[0]<a||pytania[0]>b){
            if(byly_pytania)
               { ktory_raz_ten_program++;
                byly_pytania=false;}

                   if(ktory_raz_ten_program==ktory_raz){
                         break;
                    }
        }
        //liczba
         else
        {
            byly_pytania=true;
            if(ktory_raz_ten_program+1==ktory_raz)
                    {
                lista.push_back(pytania);
                    }

        }


}
}

