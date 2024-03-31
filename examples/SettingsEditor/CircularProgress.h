#ifndef CIRCULARPROGRESSSETTINGSEDITOR_H
#define CIRCULARPROGRESSSETTINGSEDITOR_H

#include "ui_CircularProgress.h"
#include <QWidget>

class QtMaterialCircularProgress;

class CircularProgressSettingsEditor : public QWidget
{
    Q_OBJECT

public:
    explicit CircularProgressSettingsEditor(QWidget *parent = 0);
    ~CircularProgressSettingsEditor();

protected slots:
    void setupForm();
    void updateWidget();
    void selectColor();

private:
    Ui::CircularProgressSettingsForm *const ui;
    QtMaterialCircularProgress       *const m_progress;
};

#endif // CIRCULARPROGRESSSETTINGSEDITOR_H
