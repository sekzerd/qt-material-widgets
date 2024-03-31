QT += core gui widgets
TEMPLATE = app
CONFIG += c++11

SOURCES += \
    SettingsEditor/AppBar.cpp \
    SettingsEditor/AutoComplete.cpp \
    SettingsEditor/Avatar.cpp \
    SettingsEditor/Badge.cpp \
    SettingsEditor/CheckBox.cpp \
    SettingsEditor/CircularProgress.cpp \
    SettingsEditor/Dialog.cpp \
    SettingsEditor/Drawer.cpp \
    SettingsEditor/Fab.cpp \
    SettingsEditor/FlatButton.cpp \
    SettingsEditor/IconButton.cpp \
    SettingsEditor/Menu.cpp \
    SettingsEditor/Progress.cpp \
    SettingsEditor/RadioButton.cpp \
    SettingsEditor/RaisedButton.cpp \
    SettingsEditor/ScrollBar.cpp \
    SettingsEditor/Slider.cpp \
    SettingsEditor/SnackBar.cpp \
    MainWindow.cpp \
    SettingsEditor/Tabs.cpp \
    SettingsEditor/TextField.cpp \
    SettingsEditor/Toggle.cpp \
    main.cpp

HEADERS += \
    SettingsEditor/AppBar.h \
    SettingsEditor/AutoComplete.h \
    SettingsEditor/Avatar.h \
    SettingsEditor/Badge.h \
    SettingsEditor/CheckBox.h \
    SettingsEditor/CircularProgress.h \
    SettingsEditor/Dialog.h \
    SettingsEditor/Drawer.h \
    SettingsEditor/Fab.h \
    SettingsEditor/FlatButton.h \
    SettingsEditor/IconButton.h \
    SettingsEditor/Menu.h \
    SettingsEditor/Progress.h \
    SettingsEditor/RadioButton.h \
    SettingsEditor/RaisedButton.h \
    SettingsEditor/ScrollBar.h \
    SettingsEditor/Slider.h \
    SettingsEditor/SnackBar.h \
    MainWindow.h \
    SettingsEditor/Tabs.h \
    SettingsEditor/TextField.h \
    SettingsEditor/Toggle.h

HEADERS += SettingEditor.h

INCLUDEPATH += $$top_srcdir/components/
TARGET = examples-exe

win32{
    LIBS += $$top_builddir/components/$(OBJECTS_DIR)/components.lib
    PRE_TARGETDEPS += $$top_builddir/components/$(OBJECTS_DIR)/components.lib
}
else{
    LIBS += $$top_builddir/components/$(OBJECTS_DIR)/libcomponents.a
    PRE_TARGETDEPS += $$top_builddir/components/$(OBJECTS_DIR)/libcomponents.a
}

RESOURCES += \
    examples.qrc

FORMS += \
    SettingsEditor/AppBar.ui \
    SettingsEditor/Avatar.ui \
    SettingsEditor/Badge.ui \
    SettingsEditor/CheckBox.ui \
    SettingsEditor/CircularProgress.ui \
    SettingsEditor/Dialog.ui \
    SettingsEditor/Drawer.ui \
    SettingsEditor/Fab.ui \
    SettingsEditor/FlatButton.ui \
    SettingsEditor/IconButton.ui \
    SettingsEditor/Progress.ui \
    SettingsEditor/RadioButton.ui \
    SettingsEditor/ScrollBar.ui \
    SettingsEditor/Slider.ui \
    SettingsEditor/SnackBar.ui \
    SettingsEditor/Tabs.ui \
    SettingsEditor/TextField.ui \
    SettingsEditor/Toggle.ui
