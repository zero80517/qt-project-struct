QT += core
QT -= gui

TARGET = App
TEMPLATE = app

SOURCES += \
        main.cpp

include( ../../common.pri )
include( ../../app.pri )

LIBS += -lSlaeSolver$${LIB_SUFFIX}
