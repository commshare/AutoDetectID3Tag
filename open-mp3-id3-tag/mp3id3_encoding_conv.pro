QT =  gui
TARGET = open_mp3_id3_tag
TEMPLATE = app

HEADERS += \
    src/uchardet/uchardet.h \
    src/taglib/tag.h \
    src/taglib/fileref.h \
    src/opencc/opencc.h \
    src/opencc/opencc_types.h \
    src/opencc/dictionary/text.h \
    src/opencc/dictionary/datrie.h \
    src/opencc/dictionary/abstract.h \
    src/opencc/utils.h \
    src/opencc/encoding.h \
    src/opencc/dictionary_set.h \
    src/opencc/converter.h \
    src/opencc/config_reader.h \
    src/opencc/dictionary_group.h \
    src/encoding_convertor.h \
    src/common.h \
    src/tag_convertor.h \
    src/main_window.h \
    src/chinese_convertor.h

SOURCES += \
    src/opencc/opencc.c \
    src/opencc/dictionary/text.c \
    src/opencc/dictionary/datrie.c \
    src/opencc/dictionary/abstract.c \
    src/opencc/utils.c \
    src/opencc/encoding.c \
    src/opencc/dictionary_set.c \
    src/opencc/converter.c \
    src/opencc/config_reader.c \
    src/opencc/dictionary_group.c \
    src/main.cpp \
    src/encoding_convertor.cpp \
    src/tag_convertor.cpp \
    src/main_window.cpp \
    src/chinese_convertor.cpp \
    src/common.c

FORMS +=

QT += widgets
QT += core #for QStandardPaths  //http://doc.qt.io/qt-5/qstandardpaths.html


#LIBS += -Llib -ltag -luchardet
LIBS += -L$$PWD/3rdparty -ltag -luchardet
LIBS += -Llib

RESOURCES = mp3id3_encoding_conv.qrc

TRANSLATIONS = ts/zhs.ts ts/zht.ts

CONFIG(debug, debug|release) {
    message(Debug build)
    DESTDIR = ./
    OBJECTS_DIR = debug/obj
} else {
    message(Release build)
    DESTDIR = ./
    OBJECTS_DIR = release/obj
}

win32 {
    RC_FILE = mp3id3_encoding_conv.rc
}

macx {
    ICON = icon.icns
    QTPLUGIN += qtwcodecs qcncodecs
}

linux-g++ {
    LIBS += -L/lib64 -lz
    QTPLUGIN += qtwcodecs qcncodecs
}
