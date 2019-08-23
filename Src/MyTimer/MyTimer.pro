QT += widgets gui
CONFIG += C++11

INCLUDEPATH += E:/lua/lua53dll
LIBS += E:/lua/lua53dll/QtLua53.dll

HEADERS += \
    mytimer-src/MyTimerWidget.h \
    lualib-src/lua-animation.h \
    lualib-src/lua-button.h \
    lualib-src/lua-mytimer.h \
    lualib-src/lua-label.h \
    lualib-src/lua-widget.h \
    lualib-src/lua-qt.h \
    mytimer-src/MyLabel.h

SOURCES += \
    mytimer-src/main.cpp \
    mytimer-src/MyTimerWidget.cpp \
    lualib-src/lua-mytimer.cpp \
    lualib-src/lua-animation.cpp \
    lualib-src/lua-button.cpp \
    lualib-src/lua-label.cpp \
    lualib-src/lua-widget.cpp \
    lualib-src/lua-qt.cpp \
    mytimer-src/MyLabel.cpp
