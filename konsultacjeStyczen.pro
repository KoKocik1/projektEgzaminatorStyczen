QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bazadanych.cpp \
    dyplomowy.cpp \
    edytor.cpp \
    main.cpp \
    mainwindow.cpp \
    pk_ppk.cpp \
    student.cpp \
    zczytywanie_pytan.cpp

HEADERS += \
    bazadanych.h \
    dyplomowy.h \
    edytor.h \
    mainwindow.h \
    pk_ppk.h \
    student.h \
    zczytywanie_pytan.h

FORMS += \
    edytor.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    pytaniaDYPLOM.txt \
    pytaniaPK.txt \
    pytaniaPPK.txt \
    studenci.txt
