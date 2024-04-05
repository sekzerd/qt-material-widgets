#ifndef SNACKBARSETTINGSEDITOR_H
#define SNACKBARSETTINGSEDITOR_H

#include "QMSnackBar.h"
#include "ui_SnackBar.h"
#include <QWidget>

class SnackbarSettingsEditor : public QWidget
{
    Q_OBJECT

public:
    explicit SnackbarSettingsEditor(QWidget *parent = 0);
    ~SnackbarSettingsEditor();

protected slots:
    void setupForm();
    void updateWidget();
    void showSnackbar();

  private:
    Ui::SnackbarSettingsForm *const ui;
    QtMaterialSnackbar *const m_snackbar;
};

#endif // SNACKBARSETTINGSEDITOR_H
