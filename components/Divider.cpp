#include "Divider.h"
#include <QPainter>

Divider::Divider(QWidget *parent) : QWidget(parent) {
  _orientation = Orientation::HORIZONTAL;
  _color = QColor(255, 255, 255, 100);

  _thick = 1;
  _length = 100.0;
}

Divider::~Divider() {}

void Divider::setColor(const QColor &color) { _color = color; }

QColor Divider::color() const { return _color; }

void Divider::setThickness(const int &thick) { _thick = thick; }

int Divider::thickness() const { return _thick; }

void Divider::setLength(const double len) { _length = len; }

float Divider::length() const { return _length; }

void Divider::setOrientation(const Divider::Orientation orien) {
  _orientation = orien;
}

Divider::Orientation Divider::orient() const { return _orientation; }

void Divider::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  QPen pen(_color);
  pen.setWidth(_thick);
  pen.setCapStyle(Qt::RoundCap);

  painter.setPen(pen);
  if (_orientation == Orientation::VERTICAL) {
    auto x = this->rect().x();
    auto y = this->rect().y();
    auto w = this->rect().width();
    auto h = this->rect().height();
    painter.drawLine(x + w / 2, y, x + w / 2, y + h * _length / 100);
  }
  if (_orientation == Orientation::HORIZONTAL) {
    auto x = this->rect().x();
    auto y = this->rect().y();
    auto w = this->rect().width();
    auto h = this->rect().height();
    painter.drawLine(x, y + h / 2, x + w * _length / 100, y + h / 2);
  }
}
