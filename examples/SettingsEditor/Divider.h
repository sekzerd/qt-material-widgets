#ifndef DIVIDER_SETTINGS_EDITOR_H
#define DIVIDER_SETTINGS_EDITOR_H

#include "ui_Divider.h"
#include <Divider.h>
#include <QWidget>

namespace Ui {
class DividerSettingsEditorForm;
}

class DividerSettingsEditor : public QWidget {
  Q_OBJECT

public:
  explicit DividerSettingsEditor(QWidget *parent = nullptr);
  ~DividerSettingsEditor();

private:
  void initConnect();

private:
  Ui::DividerSettingsEditorForm *ui;
  Divider *_divider;
};

#endif // DIVIDER_H
