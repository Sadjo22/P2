#-------------------------------------------------
#
# Project created by QtCreator 2019-01-30T12:59:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Progetto_Engineering
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    container.cpp \
    engineering.cpp \
    mechanical_engineering.cpp \
    aeronautic.cpp \
    computer_engineering.cpp \
    model.cpp \
    view1.cpp \
    items_window.cpp \
    modeladapter.cpp \
    xmlio.cpp \
    dialog1.cpp \
    dialog2.cpp \
    login.cpp \
    mainwindowlogin.cpp \
    dialog3.cpp

HEADERS += \
        mainwindow.h \
    container.h \
    engineering.h \
    mechanical_engineering.h \
    aeronautic.h \
    computer_engineering.h \
    model.h \
    view1.h \
    items_window.h \
    modeladapter.h \
    xmlio.h \
    dialog1.h \
    dialog2.h \
    login.h \
    mainwindowlogin.h \
    dialog3.h

FORMS += \
        mainwindow.ui \
    mainwindowlogin.ui

RESOURCES += \
    foto.qrc

DISTFILES += \
    images/logo.jpeg
