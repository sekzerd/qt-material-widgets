#ifndef FABSETTINGSEDITOR_H
#define FABSETTINGSEDITOR_H

#include "QMFab.h"
#include "ui_Fab.h"
#include <QWidget>

class FloatingActionButtonSettingsEditor : public QWidget
{
    Q_OBJECT

public:
    explicit FloatingActionButtonSettingsEditor(QWidget *parent = 0);
    ~FloatingActionButtonSettingsEditor();

protected slots:
    void setupForm();
    void updateWidget();
    void selectColor();

private:
    Ui::FloatingActionButtonSettingsForm *const ui;
    QtMaterialFloatingActionButton       *const m_fab;
};

#endif // FABSETTINGSEDITOR_H
