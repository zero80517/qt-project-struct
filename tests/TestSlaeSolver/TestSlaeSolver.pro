QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_testslaesolver.cpp

include( ../../common.pri )
include( ../../app.pri )

LIBS += -lSlaeSolver$${LIB_SUFFIX}
