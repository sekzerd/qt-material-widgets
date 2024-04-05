#ifndef QTMATERIALTABS_H
#define QTMATERIALTABS_H

#include "QMTabsInternal.h"
#include "QMTabsPrivate.h"
#include "lib/QMTheme.h"
#include <QIcon>
#include <QtWidgets/QAbstractScrollArea>
#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QWidget>

// class QtMaterialTabsPrivate;
// class QtMaterialTab;

class QtMaterialTabs : public QWidget {
  Q_OBJECT

public:
    explicit QtMaterialTabs(QWidget *parent = 0);
    ~QtMaterialTabs();

    void setUseThemeColors(bool value);
    bool useThemeColors() const;

    void setHaloVisible(bool value);
    bool isHaloVisible() const;

    void setRippleStyle(Material::RippleStyle style);
    Material::RippleStyle rippleStyle() const;

    void setInkColor(const QColor &color);
    QColor inkColor() const;

    void setBackgroundColor(const QColor &color);
    QColor backgroundColor() const;

    void setTextColor(const QColor &color);
    QColor textColor() const;

    void addTab(const QString &text, const QIcon &icon = QIcon());

    void setCurrentTab(QtMaterialTab *tab);
    void setCurrentTab(int index);

    int currentIndex() const;

    void setDirection(QBoxLayout::Direction direction);
    QBoxLayout::Direction direction() const;
    void setInkBarPosition(QtMaterialTabsInkBar::InkBarPosition pos);

  signals:
    void currentChanged(int);

  protected:
    void setTabActive(int index, bool active = true);
    void updateTabs();

    const QScopedPointer<QtMaterialTabsPrivate> d_ptr;

  private:
    QBoxLayout::Direction _direction;
    QtMaterialTabsInkBar::InkBarPosition _inkBarPosition;

  private:
    Q_DISABLE_COPY(QtMaterialTabs)
    Q_DECLARE_PRIVATE(QtMaterialTabs)
};

#endif // QTMATERIALTABS_H
