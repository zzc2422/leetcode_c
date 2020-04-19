TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    intersection-lcci.c \
    main.c \

HEADERS += \
	include/list.h \
	include/tree.h \
	include_all.h \