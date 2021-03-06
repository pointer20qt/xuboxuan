#-------------------------------------------------
#
# Project created by QtCreator 2020-02-06T16:44:54
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SignSystem
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    person.cpp \
    login.cpp \
    register.cpp

HEADERS  += widget.h \
    person.h \
    login.h \
    register.h

FORMS    += widget.ui \
    person.ui \
    login.ui \
    register.ui

RC_ICONS =app.ico

RESOURCES += \
    sign_picture/icon.qrc

