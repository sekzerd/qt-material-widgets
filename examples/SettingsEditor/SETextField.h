#ifndef TEXTFIELDSETTINGSEDITOR_H
#define TEXTFIELDSETTINGSEDITOR_H

#include "QMTextField.h"
#include "ui_TextField.h"
#include <QWidget>

class TextFieldSettingsEditor : public QWidget
{
    Q_OBJECT

public:
    explicit TextFieldSettingsEditor(QWidget *parent = 0);
    ~TextFieldSettingsEditor();

protected slots:
    void setupForm();
    void updateWidget();
    void selectColor();
    void setShowInputLine();

private:
    Ui::TextFieldSettingsForm *const ui;
    QtMaterialTextField       *const m_textField;
};

#endif // TEXTFIELDSETTINGSEDITOR_H
