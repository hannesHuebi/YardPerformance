TEMPLATE = lib
TARGET = YardPerformacebackend
QT += qml quick
CONFIG += qt plugin

load(ubuntu-click)

TARGET = $$qtLibraryTarget($$TARGET)

# Input
SOURCES += \
    backend.cpp \
    mytype.cpp \
    parsecsv.cpp \
    expbuffer.cpp \
    explog.cpp \
    expvalue.cpp \
    udpport.cpp

HEADERS += \
    backend.h \
    mytype.h \
    parsecsv.h \
    csv.h \
    expbuffer.h \
    explog.h \
    expvalue.h \
    udpport.h

OTHER_FILES = qmldir

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
installPath = $${UBUNTU_CLICK_PLUGIN_PATH}/YardPerformace
qmldir.path = $$installPath
target.path = $$installPath
INSTALLS += target qmldir
QMAKE_CXXFLAGS += -std=c++0x
QMAKE_CXXFLAGS += -lpthread


