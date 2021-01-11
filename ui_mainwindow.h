/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QComboBox *jakiEgzamin;
    QLabel *label;
    QComboBox *ImieStudenta;
    QLabel *label_2;
    QPushButton *wczytajBaze;
    QPushButton *wczytajPlik;
    QVBoxLayout *verticalLayout_3;
    QLabel *Zwolnienie_z_podst;
    QComboBox *comboBox_3;
    QLabel *coWczytane;
    QSpacerItem *verticalSpacer;
    QLabel *label_5;
    QLCDNumber *IleDodPyt;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpinBox *dodPytPodstA;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_9;
    QSpinBox *dodPytPodstB;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_10;
    QSpinBox *dodPytPodstC;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QSpinBox *dodPytSred;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QSpinBox *dodPytTrud;
    QSpacerItem *verticalSpacer_2;
    QPushButton *edycja;
    QPushButton *PoziomStart;
    QPushButton *start;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *pyt1;
    QTextEdit *pyt2;
    QTextEdit *pyt3;
    QTextEdit *dodatkowe_pytania;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(644, 468);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        MainWindow->setPalette(palette);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        jakiEgzamin = new QComboBox(centralwidget);
        jakiEgzamin->addItem(QString());
        jakiEgzamin->addItem(QString());
        jakiEgzamin->addItem(QString());
        jakiEgzamin->setObjectName(QString::fromUtf8("jakiEgzamin"));

        gridLayout->addWidget(jakiEgzamin, 1, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        ImieStudenta = new QComboBox(centralwidget);
        ImieStudenta->setObjectName(QString::fromUtf8("ImieStudenta"));

        gridLayout->addWidget(ImieStudenta, 1, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        wczytajBaze = new QPushButton(centralwidget);
        wczytajBaze->setObjectName(QString::fromUtf8("wczytajBaze"));

        gridLayout->addWidget(wczytajBaze, 1, 2, 1, 1);

        wczytajPlik = new QPushButton(centralwidget);
        wczytajPlik->setObjectName(QString::fromUtf8("wczytajPlik"));

        gridLayout->addWidget(wczytajPlik, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        Zwolnienie_z_podst = new QLabel(centralwidget);
        Zwolnienie_z_podst->setObjectName(QString::fromUtf8("Zwolnienie_z_podst"));
        Zwolnienie_z_podst->setFrameShape(QFrame::Box);

        verticalLayout_3->addWidget(Zwolnienie_z_podst);

        comboBox_3 = new QComboBox(centralwidget);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setEnabled(false);

        verticalLayout_3->addWidget(comboBox_3);

        coWczytane = new QLabel(centralwidget);
        coWczytane->setObjectName(QString::fromUtf8("coWczytane"));
        coWczytane->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(coWczytane);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);

        IleDodPyt = new QLCDNumber(centralwidget);
        IleDodPyt->setObjectName(QString::fromUtf8("IleDodPyt"));
        QFont font;
        font.setFamily(QString::fromUtf8("Mongolian Baiti"));
        font.setPointSize(10);
        IleDodPyt->setFont(font);
        IleDodPyt->setFrameShadow(QFrame::Plain);
        IleDodPyt->setSegmentStyle(QLCDNumber::Flat);

        verticalLayout_3->addWidget(IleDodPyt);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        dodPytPodstA = new QSpinBox(centralwidget);
        dodPytPodstA->setObjectName(QString::fromUtf8("dodPytPodstA"));
        dodPytPodstA->setEnabled(false);
        dodPytPodstA->setMaximum(6);

        horizontalLayout->addWidget(dodPytPodstA);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_6->addWidget(label_9);

        dodPytPodstB = new QSpinBox(centralwidget);
        dodPytPodstB->setObjectName(QString::fromUtf8("dodPytPodstB"));
        dodPytPodstB->setEnabled(false);
        dodPytPodstB->setMaximum(6);

        horizontalLayout_6->addWidget(dodPytPodstB);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_7->addWidget(label_10);

        dodPytPodstC = new QSpinBox(centralwidget);
        dodPytPodstC->setObjectName(QString::fromUtf8("dodPytPodstC"));
        dodPytPodstC->setEnabled(false);
        dodPytPodstC->setMaximum(6);

        horizontalLayout_7->addWidget(dodPytPodstC);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        dodPytSred = new QSpinBox(centralwidget);
        dodPytSred->setObjectName(QString::fromUtf8("dodPytSred"));
        dodPytSred->setEnabled(false);
        dodPytSred->setMaximum(6);

        horizontalLayout_2->addWidget(dodPytSred);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);

        dodPytTrud = new QSpinBox(centralwidget);
        dodPytTrud->setObjectName(QString::fromUtf8("dodPytTrud"));
        dodPytTrud->setEnabled(false);
        dodPytTrud->setMaximum(6);

        horizontalLayout_3->addWidget(dodPytTrud);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        edycja = new QPushButton(centralwidget);
        edycja->setObjectName(QString::fromUtf8("edycja"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        edycja->setPalette(palette1);

        verticalLayout_3->addWidget(edycja);

        PoziomStart = new QPushButton(centralwidget);
        PoziomStart->setObjectName(QString::fromUtf8("PoziomStart"));
        PoziomStart->setEnabled(false);

        verticalLayout_3->addWidget(PoziomStart);

        start = new QPushButton(centralwidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setEnabled(true);

        verticalLayout_3->addWidget(start);


        gridLayout_2->addLayout(verticalLayout_3, 0, 1, 2, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pyt1 = new QTextEdit(centralwidget);
        pyt1->setObjectName(QString::fromUtf8("pyt1"));
        pyt1->setFrameShape(QFrame::Box);
        pyt1->setReadOnly(true);

        verticalLayout_2->addWidget(pyt1);

        pyt2 = new QTextEdit(centralwidget);
        pyt2->setObjectName(QString::fromUtf8("pyt2"));
        pyt2->setFrameShape(QFrame::Box);
        pyt2->setReadOnly(true);

        verticalLayout_2->addWidget(pyt2);

        pyt3 = new QTextEdit(centralwidget);
        pyt3->setObjectName(QString::fromUtf8("pyt3"));
        pyt3->setFrameShape(QFrame::Box);
        pyt3->setReadOnly(true);

        verticalLayout_2->addWidget(pyt3);

        dodatkowe_pytania = new QTextEdit(centralwidget);
        dodatkowe_pytania->setObjectName(QString::fromUtf8("dodatkowe_pytania"));
        dodatkowe_pytania->setFrameShape(QFrame::Box);
        dodatkowe_pytania->setReadOnly(true);

        verticalLayout_2->addWidget(dodatkowe_pytania);


        gridLayout_2->addLayout(verticalLayout_2, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 644, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        jakiEgzamin->setItemText(0, QCoreApplication::translate("MainWindow", "PK", nullptr));
        jakiEgzamin->setItemText(1, QCoreApplication::translate("MainWindow", "PPK", nullptr));
        jakiEgzamin->setItemText(2, QCoreApplication::translate("MainWindow", "DYPLOMOWY", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "Jaki student:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Jaki to egzamin", nullptr));
        wczytajBaze->setText(QCoreApplication::translate("MainWindow", "Wczytaj pytania z bazy", nullptr));
        wczytajPlik->setText(QCoreApplication::translate("MainWindow", "Wczytaj pytania z pliku", nullptr));
        Zwolnienie_z_podst->setText(QString());
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "Poziom podstawowy", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "Poziom \305\233redni", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainWindow", "Poziom trudny", nullptr));

        coWczytane->setText(QCoreApplication::translate("MainWindow", "pytania z pliku", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Liczba dodatkowych pyta\305\204", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Podstawa blok A", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Podstawa blok B", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Podstawa blok C", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Srednie", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Trudne", nullptr));
        edycja->setText(QCoreApplication::translate("MainWindow", "edytor", nullptr));
        PoziomStart->setText(QCoreApplication::translate("MainWindow", "Losowanie pytania", nullptr));
        start->setText(QCoreApplication::translate("MainWindow", "Test start", nullptr));
        pyt1->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.1pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pyt2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.1pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pyt3->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.1pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        dodatkowe_pytania->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.1pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
