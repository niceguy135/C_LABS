QT += widgets
requires(qtConfig(combobox))

HEADERS       = renderarea.h \
                circle.h \
                figures.h \
                rect.h \
                trig.h \
                window.h
SOURCES       = main.cpp \
                circle.cpp \
                figures.cpp \
                rect.cpp \
                renderarea.cpp \
                trig.cpp \
                window.cpp
RESOURCES     = basicdrawing.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

