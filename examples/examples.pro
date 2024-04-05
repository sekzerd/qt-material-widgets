QT += core gui widgets
TEMPLATE = app
CONFIG += c++11

SOURCES += \
    SettingsEditor/SEAppBar.cpp \
    SettingsEditor/SEAutoComplete.cpp \
    SettingsEditor/SEAvatar.cpp \
    SettingsEditor/SEBadge.cpp \
    SettingsEditor/SECheckBox.cpp \
    SettingsEditor/SECircularProgress.cpp \
    SettingsEditor/SEDialog.cpp \
    SettingsEditor/SEDivider.cpp \
    SettingsEditor/SEDrawer.cpp \
    SettingsEditor/SEFab.cpp \
    SettingsEditor/SEFlatButton.cpp \
    SettingsEditor/SEIconButton.cpp \
    SettingsEditor/SEMenu.cpp \
    SettingsEditor/SEProgress.cpp \
    SettingsEditor/SERadioButton.cpp \
    SettingsEditor/SERaisedButton.cpp \
    SettingsEditor/SEScrollBar.cpp \
    SettingsEditor/SESlider.cpp \
    SettingsEditor/SESnackBar.cpp \
    SettingsEditor/SETabs.cpp \
    MainWindow.cpp \
    SettingsEditor/SETextField.cpp \
    SettingsEditor/SEToggle.cpp \
    main.cpp

HEADERS += \
    SettingsEditor/SEAppBar.h \
    SettingsEditor/SEAutoComplete.h \
    SettingsEditor/SEAvatar.h \
    SettingsEditor/SEBadge.h \
    SettingsEditor/SECheckBox.h \
    SettingsEditor/SECircularProgress.h \
    SettingsEditor/SEDialog.h \
    SettingsEditor/SEDivider.h \
    SettingsEditor/SEDrawer.h \
    SettingsEditor/SEFab.h \
    SettingsEditor/SEFlatButton.h \
    SettingsEditor/SEIconButton.h \
    SettingsEditor/SEMenu.h \
    SettingsEditor/SEProgress.h \
    SettingsEditor/SERadioButton.h \
    SettingsEditor/SERaisedButton.h \
    SettingsEditor/SEScrollBar.h \
    SettingsEditor/SESlider.h \
    SettingsEditor/SESnackBar.h \
    SettingsEditor/SETabs.h \
    MainWindow.h \
    SettingsEditor/SETextField.h \
    SettingsEditor/SEToggle.h

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
    SettingsEditor/SEAppBar.ui \
    SettingsEditor/SEAvatar.ui \
    SettingsEditor/SEBadge.ui \
    SettingsEditor/SECheckBox.ui \
    SettingsEditor/SECircularProgress.ui \
    SettingsEditor/SEDialog.ui \
    SettingsEditor/SEDivider.ui \
    SettingsEditor/SEDrawer.ui \
    SettingsEditor/SEFab.ui \
    SettingsEditor/SEFlatButton.ui \
    SettingsEditor/SEIconButton.ui \
    SettingsEditor/SEProgress.ui \
    SettingsEditor/SERadioButton.ui \
    SettingsEditor/SEScrollBar.ui \
    SettingsEditor/SESlider.ui \
    SettingsEditor/SESnackBar.ui \
    SettingsEditor/SETabs.ui \
    SettingsEditor/SETextField.ui \
    SettingsEditor/SEToggle.ui
