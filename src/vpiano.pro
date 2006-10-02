TEMPLATE = app
TARGET = vpiano

CONFIG += release \
          warn_on \
          qt \
          thread \
          exceptions

SOURCES = main.cpp mainwindow.cpp keyboardwidget.cpp
HEADERS = mainwindow.h keyboardwidget.h
RESOURCES = vpiano.qrc
