#ifndef AVATARSETTINGSEDITOR_H
#define AVATARSETTINGSEDITOR_H

#include "QMAvatar.h"
#include "ui_Avatar.h"
#include <QWidget>

class AvatarSettingsEditor : public QWidget
{
    Q_OBJECT

public:
    explicit AvatarSettingsEditor(QWidget *parent = 0);
    ~AvatarSettingsEditor();

protected slots:
    void setupForm();
    void updateWidget();
    void selectColor();

private:
    Ui::AvatarSettingsForm *const ui;
    QtMaterialAvatar       *const m_avatar;
};

#endif // AVATARSETTINGSEDITOR_H
