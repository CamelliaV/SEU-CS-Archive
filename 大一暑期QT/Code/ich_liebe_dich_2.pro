QT       += core gui
QT       += multimedia #enable QSound
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clerk.cpp \
    clerkinfo.cpp \
    depositor.cpp \
    dialog.cpp \
    dialoglist.cpp \
    dialoglosthandler.cpp \
    dialogwithdrawls.cpp \
    dialogwithdrawltotake.cpp \
    main.cpp \
    mainwindow.cpp \
    savings.cpp \
    withdrawls.cpp

HEADERS += \
    clerk.h \
    clerkinfo.h \
    depositor.h \
    dialog.h \
    dialoglist.h \
    dialoglosthandler.h \
    dialogwithdrawls.h \
    dialogwithdrawltotake.h \
    mainwindow.h \
    savings.h \
    withdrawls.h

FORMS += \
    dialog.ui \
    dialoglist.ui \
    dialoglosthandler.ui \
    dialogwithdrawls.ui \
    dialogwithdrawltotake.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES += \
    ich_liebe_dich_2.pro.user
