#-------------------------------------------------
#
# Project created by QtCreator 2015-10-07T16:35:45
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = TreeMerge
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    treeiterator.cpp

HEADERS += \
    node.h \
    tree.h \
    treeiterator.h

QMAKE_CXXFLAGS += -std=c++11

