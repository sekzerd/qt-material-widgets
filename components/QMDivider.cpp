#include "QMDivider.h"
#include "lib/QMTheme.h"
#include <QPainter>

Divider::Divider(QWidget *parent) : QWidget(parent) {
  _orientation = Orientation::HORIZONTAL;
  QtMaterialTheme theme;

  _color = theme.getColor("primary1");

  _thick = 1;
  _length = 100.0;
  _round = false;
}

Divider::~Divider() {}

void Divider::setColor(const QColor &color) {
  _color = color;
  update();
}

QColor Divider::color() const { return _color; }

void Divider::setThickness(const int &thick) {
  _thick = thick;
  update();
}

int Divider::thickness() const { return _thick; }

void Divider::setLength(const double len) {
  _length = len;
  update();
}

double Divider::length() const { return _length; }

void Divider::setOrientation(const Divider::Orientation orien) {
  _orientation = orien;
  update();
}

Divider::Orientation Divider::orient() const { return _orientation; }

void Divider::setRound(bool round) {
  _round = round;
  update();
}

bool Divider::round() const { return _round; }

void Divider::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);
  QPen pen(_color);
  pen.setWidth(_thick);
  if (_round) {
    pen.setCapStyle(Qt::RoundCap);
  }
  painter.setPen(pen);
  auto round_offset = _round ? _thick / 2 : 0;
  if (_orientation == Orientation::VERTICAL) {
    auto x = this->rect().x();
    auto y = this->rect().y();
    auto w = this->rect().width();
    auto h = this->rect().height();

    painter.drawLine(x + w / 2, y + round_offset, x + w / 2,
                     (y + h * _length / 100) - round_offset);
  }
  if (_orientation == Orientation::HORIZONTAL) {
    auto x = this->rect().x();
    auto y = this->rect().y();
    auto w = this->rect().width();
    auto h = this->rect().height();
    painter.drawLine(x + round_offset, y + h / 2,
                     (x + w * _length / 100) - round_offset, y + h / 2);
  }
}
