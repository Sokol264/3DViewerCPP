QT       += core gui openglwidgets opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controller/controller.cpp \
    command.cpp \
    drawer.cpp \
    facade.cpp \
    figure.cpp \
    filemanager.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Controller/controller.h \
    command.h \
    drawer.h \
    facade.h \
    figure.h \
    filemanager.h \
    mainwindow.h \
    vertex.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    shaders.qrc \
    textures.qrc
