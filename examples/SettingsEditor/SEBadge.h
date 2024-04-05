#ifndef BADGESETTINGSEDITOR_H
#define BADGESETTINGSEDITOR_H

#include "QMAvatar.h"
#include "QMBadge.h"
#include "ui_Badge.h"
#include <QWidget>

class BadgeSettingsEditor : public QWidget {
  Q_OBJECT

public:
    explicit BadgeSettingsEditor(QWidget *parent = 0);
    ~BadgeSettingsEditor();

protected slots:
    void setupForm();
    void updateWidget();
    void selectColor();

private:
    Ui::BadgeSettingsForm *const ui;
    QtMaterialAvatar      *const m_avatar;
    QtMaterialBadge       *const m_badge;
};

#endif // BADGESETTINGSEDITOR_H
