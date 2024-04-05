#include "SettingsEditor/SERaisedButton.h"
#include <QMRaisedButton.h>

RaisedButtonSettingsEditor::RaisedButtonSettingsEditor(QWidget *parent)
    : FlatButtonSettingsEditor(new QtMaterialRaisedButton("Rise up"), parent)
{
    ui->transparentCheckBox->setDisabled(true);
    ui->defaultPresetPushButton->setDisabled(true);
    ui->checkablePresetPushButton->setDisabled(true);
}

RaisedButtonSettingsEditor::~RaisedButtonSettingsEditor()
{
}
