#ifndef AUTOCOMPLETESETTINGSEDITOR_H
#define AUTOCOMPLETESETTINGSEDITOR_H

#include "QMAutoComplete.h"
#include "lib/QMOverlayWidget.h"
#include <QWidget>

class AutoCompleteSettingsEditor : public QWidget
{
    Q_OBJECT

public:
    explicit AutoCompleteSettingsEditor(QWidget *parent = 0);
    ~AutoCompleteSettingsEditor();

protected slots:
    void setupForm();
    void updateWidget();
    void selectColor();

  private:
    QtMaterialAutoComplete *const m_autocomplete;
};

#endif // AUTOCOMPLETESETTINGSEDITOR_H
