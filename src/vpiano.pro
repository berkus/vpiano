TEMPLATE = app
TARGET = vpiano

CONFIG += release \
          warn_on \
          qt \
          thread \
          exceptions

SOURCES = main.cpp mainwindow.cpp keyboardwidget.cpp octaverangewidget.cpp
HEADERS = mainwindow.h keyboardwidget.h octaverangewidget.h
RESOURCES = vpiano.qrc
