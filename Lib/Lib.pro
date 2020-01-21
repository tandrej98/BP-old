QT += gui

TEMPLATE = lib
DEFINES += ORIENTATIONMAP_LIBRARY

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    orientationmap.cpp

HEADERS += \
    OrientationMap_global.h \
    helper.h \
    orientationmap.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

unix:!macx|win32: LIBS += -L$$PWD/arrayfire/lib/ -lafcuda
unix:!macx|win32: LIBS += -L$$PWD/arrayfire/lib/ -laf

INCLUDEPATH += $$PWD/arrayfire/headers
DEPENDPATH += $$PWD/arrayfire/headers

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/opencv/lib/release/ -lopencv_world420
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/opencv/lib/debug/ -lopencv_world420d
else:unix:!macx: LIBS += -L$$PWD/opencv/lib/ -lopencv_world420d

INCLUDEPATH += $$PWD/opencv/headers
DEPENDPATH += $$PWD/opencv/headers
