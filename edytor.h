#ifndef EDYTOR_H
#define EDYTOR_H

#include <QDialog>
#include "pk_ppk.h"
#include "dyplomowy.h"
#include "student.h"
#include "bazadanych.h"

namespace Ui {
class edytor;
}

class edytor : public QDialog
{
    Q_OBJECT

public:
    explicit edytor(QWidget *parent = nullptr,bazaDanych*baza=nullptr);
    ~edytor();

private slots:
    void on_koniec_clicked();
/*
    void on_readPodsA_clicked();

    void on_readPodsB_clicked();

    void on_readPodsC_clicked();

    void on_readSred_clicked();

    void on_readTrud_clicked();

    void on_readDyplomA_clicked();

    void on_readDyplomB_clicked();

    void on_readDyplomC_clicked();

    void on_readDyplomD_clicked();*/

    void on_readStud_clicked();

    void on_readBaza_clicked();

    void on_readPlik_clicked();

    void on_readPK_clicked();
    void on_readPPK_clicked();
    void on_readDyplom_clicked();

    void on_back_clicked();

    void on_next_clicked();

private:
    Ui::edytor *ui;
    static bazaDanych* m_baza;
    //1 to pk, 2 to ppk, 3 to dyplom
    int przycisk=0;
    int pozycja=0;
};

#endif // EDYTOR_H
