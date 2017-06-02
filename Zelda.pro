#-------------------------------------------------
#
# Project created by QtCreator 2017-05-25T11:05:25
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Zelda
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    view.cpp \
    game.cpp \
    entity.cpp \
    tile.cpp \
    world.cpp \
    camera.cpp \
    aabb.cpp \
    watertile.cpp

HEADERS  += mainwindow.h \
    view.h \
    game.h \
    entity.h \
    tile.h \
    world.h \
    camera.h \
    aabb.h \
    watertile.h

FORMS    += mainwindow.ui
