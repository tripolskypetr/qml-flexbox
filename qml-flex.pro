TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    third_party/yoga/log.cpp \
    third_party/yoga/Utils.cpp \
    third_party/yoga/YGConfig.cpp \
    third_party/yoga/YGEnums.cpp \
    third_party/yoga/YGLayout.cpp \
    third_party/yoga/YGMarker.cpp \
    third_party/yoga/YGNode.cpp \
    third_party/yoga/YGNodePrint.cpp \
    third_party/yoga/YGStyle.cpp \
    third_party/yoga/YGValue.cpp \
    third_party/yoga/Yoga.cpp \
    objects/flexbackend.cpp \
    objects/flex/flexnode.cpp \
    objects/flex/flexconfig.cpp

RESOURCES += \
    qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    third_party/yoga/CompactValue.h \
    third_party/yoga/instrumentation.h \
    third_party/yoga/log.h \
    third_party/yoga/Utils.h \
    third_party/yoga/YGConfig.h \
    third_party/yoga/YGEnums.h \
    third_party/yoga/YGFloatOptional.h \
    third_party/yoga/YGLayout.h \
    third_party/yoga/YGMacros.h \
    third_party/yoga/YGMarker.h \
    third_party/yoga/YGNode.h \
    third_party/yoga/YGNodePrint.h \
    third_party/yoga/YGStyle.h \
    third_party/yoga/YGValue.h \
    third_party/yoga/Yoga.h \
    third_party/yoga/Yoga-internal.h \
    objects/flexbackend.h \
    objects/flex/flexnode.h \
    objects/flex/flexconfig.h
