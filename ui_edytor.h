/********************************************************************************
** Form generated from reading UI file 'edytor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDYTOR_H
#define UI_EDYTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_edytor
{
public:
    QGridLayout *gridLayout;
    QLabel *TYTUL;
    QPushButton *readPlik;
    QTextEdit *poleTekstowe;
    QPushButton *readBaza;
    QLabel *skadZczytane;
    QSpacerItem *verticalSpacer_2;
    QPushButton *readPK;
    QPushButton *readPPK;
    QPushButton *readDyplom;
    QPushButton *readStud;
    QSpacerItem *verticalSpacer;
    QPushButton *saveBase;
    QPushButton *savePlik;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *back;
    QPushButton *next;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *koniec;

    void setupUi(QDialog *edytor)
    {
        if (edytor->objectName().isEmpty())
            edytor->setObjectName(QString::fromUtf8("edytor"));
        edytor->resize(608, 440);
        gridLayout = new QGridLayout(edytor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        TYTUL = new QLabel(edytor);
        TYTUL->setObjectName(QString::fromUtf8("TYTUL"));
        TYTUL->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(TYTUL, 0, 0, 1, 1);

        readPlik = new QPushButton(edytor);
        readPlik->setObjectName(QString::fromUtf8("readPlik"));
        readPlik->setEnabled(false);

        gridLayout->addWidget(readPlik, 0, 1, 1, 1);

        poleTekstowe = new QTextEdit(edytor);
        poleTekstowe->setObjectName(QString::fromUtf8("poleTekstowe"));

        gridLayout->addWidget(poleTekstowe, 1, 0, 10, 1);

        readBaza = new QPushButton(edytor);
        readBaza->setObjectName(QString::fromUtf8("readBaza"));

        gridLayout->addWidget(readBaza, 1, 1, 1, 1);

        skadZczytane = new QLabel(edytor);
        skadZczytane->setObjectName(QString::fromUtf8("skadZczytane"));
        skadZczytane->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(skadZczytane, 2, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 72, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 1, 1, 1);

        readPK = new QPushButton(edytor);
        readPK->setObjectName(QString::fromUtf8("readPK"));

        gridLayout->addWidget(readPK, 4, 1, 1, 1);

        readPPK = new QPushButton(edytor);
        readPPK->setObjectName(QString::fromUtf8("readPPK"));

        gridLayout->addWidget(readPPK, 5, 1, 1, 1);

        readDyplom = new QPushButton(edytor);
        readDyplom->setObjectName(QString::fromUtf8("readDyplom"));

        gridLayout->addWidget(readDyplom, 6, 1, 1, 1);

        readStud = new QPushButton(edytor);
        readStud->setObjectName(QString::fromUtf8("readStud"));

        gridLayout->addWidget(readStud, 7, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 94, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 8, 1, 1, 1);

        saveBase = new QPushButton(edytor);
        saveBase->setObjectName(QString::fromUtf8("saveBase"));
        saveBase->setEnabled(false);

        gridLayout->addWidget(saveBase, 9, 1, 1, 1);

        savePlik = new QPushButton(edytor);
        savePlik->setObjectName(QString::fromUtf8("savePlik"));
        savePlik->setEnabled(false);

        gridLayout->addWidget(savePlik, 10, 1, 2, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(126, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        back = new QPushButton(edytor);
        back->setObjectName(QString::fromUtf8("back"));

        horizontalLayout->addWidget(back);

        next = new QPushButton(edytor);
        next->setObjectName(QString::fromUtf8("next"));

        horizontalLayout->addWidget(next);

        horizontalSpacer_2 = new QSpacerItem(158, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 11, 0, 2, 1);

        koniec = new QPushButton(edytor);
        koniec->setObjectName(QString::fromUtf8("koniec"));

        gridLayout->addWidget(koniec, 12, 1, 1, 1);


        retranslateUi(edytor);

        QMetaObject::connectSlotsByName(edytor);
    } // setupUi

    void retranslateUi(QDialog *edytor)
    {
        edytor->setWindowTitle(QCoreApplication::translate("edytor", "Dialog", nullptr));
        TYTUL->setText(QCoreApplication::translate("edytor", "TYTU\305\201", nullptr));
        readPlik->setText(QCoreApplication::translate("edytor", "Z PLIKU", nullptr));
        readBaza->setText(QCoreApplication::translate("edytor", "Z BAZY", nullptr));
        skadZczytane->setText(QCoreApplication::translate("edytor", "Zczytane z pliku", nullptr));
        readPK->setText(QCoreApplication::translate("edytor", "wczytaj PK", nullptr));
        readPPK->setText(QCoreApplication::translate("edytor", "wczytaj PPK", nullptr));
        readDyplom->setText(QCoreApplication::translate("edytor", "wczytaj DYPLOM", nullptr));
        readStud->setText(QCoreApplication::translate("edytor", "wczytaj studentow", nullptr));
        saveBase->setText(QCoreApplication::translate("edytor", "zapisz zmiany do bazy", nullptr));
        savePlik->setText(QCoreApplication::translate("edytor", "zapisz zmiany do pliku", nullptr));
        back->setText(QCoreApplication::translate("edytor", "BACK", nullptr));
        next->setText(QCoreApplication::translate("edytor", "NEXT", nullptr));
        koniec->setText(QCoreApplication::translate("edytor", "koniec", nullptr));
    } // retranslateUi

};

namespace Ui {
    class edytor: public Ui_edytor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDYTOR_H
