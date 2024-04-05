#ifndef TABSSETTINGSEDITOR_H
#define TABSSETTINGSEDITOR_H

#include "QMTabs.h"
#include "ui_Tabs.h"
#include <QWidget>

class TabsSettingsEditor : public QWidget
{
    Q_OBJECT

public:
    explicit TabsSettingsEditor(QWidget *parent = 0);
    ~TabsSettingsEditor();

protected slots:
    void setupForm();
    void updateWidget();

private:
    Ui::TabsSettingsForm *const ui;
    QtMaterialTabs       *const m_tabs;
};

#endif // TABSSETTINGSEDITOR_H
