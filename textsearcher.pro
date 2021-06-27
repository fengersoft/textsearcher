QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/api/file/fileseacher.cpp \
    src/api/file/ioutils.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/objects/keywordhighlight.cpp \
    src/windows/showfilewindow.cpp

HEADERS += \
    src/api/file/fileseacher.h \
    src/api/file/ioutils.h \
    src/mainwindow.h \
    src/objects/keywordhighlight.h \
    src/windows/showfilewindow.h

FORMS += \
    src/mainwindow.ui \
    src/windows/showfilewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
DLLDESTDIR=$$PWD/bin/
RC_ICONS=app.ico

RESOURCES += \
    app.qrc
