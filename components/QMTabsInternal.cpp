#include "QMTabsInternal.h"
#include "QMTabs.h"
#include <QDebug>
#include <QEvent>
#include <QPainter>
#include <QPropertyAnimation>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLayoutItem>

/*!
 *  \class QtMaterialTabsInkBar
 *  \internal
 */

QtMaterialTabsInkBar::QtMaterialTabsInkBar(QtMaterialTabs *parent)
    : QtMaterialOverlayWidget(parent), m_tabs(parent),
      m_animation(new QPropertyAnimation(parent)), m_tween(0) {
  Q_ASSERT(parent);
  m_inkBarPosition = InkBarPosition::BOTTOM;
  m_animation->setPropertyName("tweenValue");
  m_animation->setEasingCurve(QEasingCurve::OutCirc);
  m_animation->setTargetObject(this);
  m_animation->setDuration(700);

  m_tabs->installEventFilter(this);
  m_thickness = 4;
  setAttribute(Qt::WA_TransparentForMouseEvents);
  setAttribute(Qt::WA_NoSystemBackground);
}

QtMaterialTabsInkBar::~QtMaterialTabsInkBar()
{
}

void QtMaterialTabsInkBar::refreshGeometry() {
  QLayoutItem *item = m_tabs->layout()->itemAt(m_tabs->currentIndex());
  if (!item) {
    return;
  }

  const QRect r(item->geometry());
  const qreal s = 1 - m_tween;

  if (QAbstractAnimation::Running != m_animation->state()) {
    switch (m_inkBarPosition) {
    case InkBarPosition::TOP: {
      m_geometry = QRect(r.left(), r.top(), r.width(), m_thickness);
      break;
    }
    case InkBarPosition::BOTTOM: {
      m_geometry = QRect(r.left(), r.bottom(), r.width(), m_thickness);
      break;
    }
    case InkBarPosition::LEFT: {
      m_geometry = QRect(r.left(), r.top(), m_thickness, r.height());
      break;
    }
    case InkBarPosition::RIGHT: {
      m_geometry =
          QRect(r.right() - m_thickness, r.top(), m_thickness, r.height());
      break;
    }
    default: {
      break;
    }
    }
  } else {

    // animation here

    const qreal left = m_previousGeometry.left() * s + r.left() * m_tween;
    const qreal width = m_previousGeometry.width() * s + r.width() * m_tween;
    auto top = m_previousGeometry.top() * s + r.top() * m_tween;
    switch (m_inkBarPosition) {
    case InkBarPosition::TOP: {
      m_geometry = QRect(left, r.top(), width, m_thickness);
      break;
    }
    case InkBarPosition::BOTTOM: {
      m_geometry = QRect(left, r.bottom(), width, m_thickness);

      break;
    }
    case InkBarPosition::LEFT: {
      m_geometry = QRect(r.left(), top, m_thickness, r.height());

      break;
    }
    case InkBarPosition::RIGHT: {
      m_geometry = QRect(r.right() - m_thickness, top, m_thickness, r.height());

      break;
    }
    default: {
      break;
    }
    }
  }
  m_tabs->update();
}

void QtMaterialTabsInkBar::animate()
{
    raise();

    m_previousGeometry = m_geometry;

    m_animation->stop();
    m_animation->setStartValue(0);
    m_animation->setEndValue(1);
    m_animation->start();
}

void QtMaterialTabsInkBar::setInkBarPosition(
    QtMaterialTabsInkBar::InkBarPosition pos) {
  m_inkBarPosition = pos;
  update();
}

QtMaterialTabsInkBar::InkBarPosition
QtMaterialTabsInkBar::inkBarPosition() const {
  return m_inkBarPosition;
}

void QtMaterialTabsInkBar::setThickness(uint thickness) {
  m_thickness = thickness;
  update();
}

uint QtMaterialTabsInkBar::thickness(uint thickness) const {
  return m_thickness;
}

bool QtMaterialTabsInkBar::eventFilter(QObject *obj, QEvent *event)
{
    switch (event->type())
    {
    case QEvent::Move:
    case QEvent::Resize:
    {
        refreshGeometry();
        break;
    }
    default:
        break;
    }
    return QtMaterialOverlayWidget::eventFilter(obj, event);
}

void QtMaterialTabsInkBar::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);

    painter.setOpacity(1);
    painter.fillRect(m_geometry, m_tabs->inkColor());
}

/*!
 *  \class QtMaterialTab
 *  \internal
 */

QtMaterialTab::QtMaterialTab(QtMaterialTabs *parent)
    : QtMaterialFlatButton(parent),
      m_tabs(parent),
      m_active(false)
{
    Q_ASSERT(parent);

    setMinimumHeight(50);

    QFont f(font());
    f.setStyleName("Normal");
    setFont(f);

    setCornerRadius(0);
    setRole(Material::Primary);
    setBackgroundMode(Qt::OpaqueMode);
    setBaseOpacity(0.25);

    connect(this, SIGNAL(clicked(bool)), this, SLOT(activateTab()));
}

QtMaterialTab::~QtMaterialTab()
{
}

QSize QtMaterialTab::sizeHint() const
{
    if (icon().isNull()) {
        return QtMaterialFlatButton::sizeHint();
    } else {
        return QSize(40, iconSize().height()+46);
    }
}

void QtMaterialTab::activateTab()
{
    m_tabs->setCurrentTab(this);
}

void QtMaterialTab::paintForeground(QPainter *painter)
{
    painter->setPen(foregroundColor());

    if (!icon().isNull()) {
        painter->translate(0, 12);
    }

    QSize textSize(fontMetrics().size(Qt::TextSingleLine, text()));
    QSize base(size()-textSize);

    QRect textGeometry(QPoint(base.width(), base.height())/2, textSize);

    painter->drawText(textGeometry, Qt::AlignCenter, text());

    if (!icon().isNull())
    {
        const QSize &size = iconSize();
        QRect iconRect(QPoint((width()-size.width())/2, 0), size);

        QPixmap pixmap = icon().pixmap(iconSize());
        QPainter icon(&pixmap);
        icon.setCompositionMode(QPainter::CompositionMode_SourceIn);
        icon.fillRect(pixmap.rect(), painter->pen().color());
        painter->drawPixmap(iconRect, pixmap);
    }

    if (!m_active)
    {
        if (!icon().isNull()) {
            painter->translate(0, -12);
        }
        QBrush overlay;
        overlay.setStyle(Qt::SolidPattern);
        overlay.setColor(backgroundColor());
        painter->setOpacity(0.36);
        painter->fillRect(rect(), overlay);
    }
}
