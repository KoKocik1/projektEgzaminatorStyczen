#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pk_ppk.h"
#include "student.h"
#include "dyplomowy.h"
#include "bazadanych.h"
#include "edytor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_PoziomStart_clicked();
    void on_start_clicked();
    void on_ImieStudenta_activated(int index);
    void on_jakiEgzamin_activated(int index);




    void on_dodPytPodstA_valueChanged(int arg1);
    void on_dodPytPodstB_valueChanged(int arg1);
    void on_dodPytPodstC_valueChanged(int arg1);
    void on_dodPytSred_valueChanged(int arg1);
    void on_dodPytTrud_valueChanged(int arg1);

    void on_edycja_clicked();

    void sprawdzWyswietlacz();

    void on_wczytajPlik_clicked();

    void on_wczytajBaze_clicked();

private:
    Ui::MainWindow *ui;
    static edytor  *m_okienko;

    static PK_PPK* egzamin;
    static DYPLOMOWY* dyplom;
    static Student* student;
    static PK_PPK*  pk;
    static PK_PPK* ppk;
    static bazaDanych* baza;
    int pamiecPytanPodstA=0;
    int pamiecPytanPodstB=0;
    int pamiecPytanPodstC=0;
    int pamiecPytanSrednich=0;
    int pamiecPytanTrudnych=0;
    int pamiecIleDodatkowych=0;

    static QString nazwaPlikuDyplom;
    static QString nazwaPlikuStudenci;
    static QString nazwaPlikuPK;
    static QString nazwaPlikuPPK;
    static QString nazwaBazy;

    int h1;



    //wskaznik na pk albo ppk

};
#endif // MAINWINDOW_H
