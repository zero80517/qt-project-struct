include( ../../common.pri )
include( ../../lib.pri )

TARGET = SlaeSolver$${LIB_SUFFIX}
TEMPLATE = lib

DEFINES += SLAESOLVER_LIBRARY

SOURCES += \
    lu_decomposition.cpp \
    slaesolver.cpp

HEADERS += \
    ../../export/SlaeSolver_global.h \
    ../../export/slaesolver.h \
    ../include/SlaeSolver/lu_decomposition.h
