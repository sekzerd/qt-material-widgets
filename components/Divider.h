#ifndef DIVIDER_H
#define DIVIDER_H
#include <QtWidgets/QWidget>

class Divider : public QWidget {
  Q_OBJECT
public:
  enum class Orientation { HORIZONTAL, VERTICAL };

public:
  explicit Divider(QWidget *parent = 0);
  ~Divider();

public:
  void setColor(const QColor &color);
  QColor color() const;

  void setThickness(const int &width);
  int thickness() const;

  void setLength(const double len);
  float length() const;

  void setOrientation(const Orientation orien);
  Orientation orient() const;

protected:
  void paintEvent(QPaintEvent *event) override;

private:
  QColor _color;
  int _thick;
  double _length;
  Orientation _orientation;
};

#endif // DIVIDER_H
