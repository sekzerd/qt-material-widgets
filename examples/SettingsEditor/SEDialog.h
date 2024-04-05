#ifndef DIALOGSETTINGSEDITOR_H
#define DIALOGSETTINGSEDITOR_H

#include "QMDialog.h"
#include "ui_Dialog.h"
#include <QWidget>

class DialogSettingsEditor : public QWidget
{
    Q_OBJECT

public:
    explicit DialogSettingsEditor(QWidget *parent = 0);
    ~DialogSettingsEditor();

protected slots:
    void setupForm();
    void updateWidget();

private:
    Ui::DialogSettingsForm *const ui;
    QtMaterialDialog       *const m_dialog;
};

#endif // DIALOGSETTINGSEDITOR_H
