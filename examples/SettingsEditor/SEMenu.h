#ifndef MENUSETTINGSEDITOR_H
#define MENUSETTINGSEDITOR_H

#include <QWidget>

#include "lib/QMOverlayWidget.h"

class QtMaterialMenu;

class MenuSettingsEditor : public QWidget
{
    Q_OBJECT

public:
    explicit MenuSettingsEditor(QWidget *parent = 0);
    ~MenuSettingsEditor();

protected slots:
    void setupForm();
    void updateWidget();
    void selectColor();

private:
    //Ui::MenuSettingsForm *const ui;
    QtMaterialMenu       *const m_menu;
};

#endif // MENUSETTINGSEDITOR_H
