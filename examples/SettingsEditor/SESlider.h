#ifndef SLIDERSETTINGSEDITOR_H
#define SLIDERSETTINGSEDITOR_H

#include "QMSlider.h"
#include "ui_Slider.h"
#include <QWidget>

class SliderSettingsEditor : public QWidget
{
    Q_OBJECT

public:
    explicit SliderSettingsEditor(QWidget *parent = 0);
    ~SliderSettingsEditor();

protected slots:
    void setupForm();
    void updateWidget();

private:
    Ui::SliderSettingsForm *const ui;
    QtMaterialSlider       *const m_slider;
};

#endif // SLIDERSETTINGSEDITOR_H
