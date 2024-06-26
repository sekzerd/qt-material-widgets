#include "SEDivider.h"
#include "ui_Divider.h"
#include <QDoubleSpinBox>
#include <QVBoxLayout>
#include <QtDebug>

DividerSettingsEditor::DividerSettingsEditor(QWidget *parent)
    : QWidget(parent), ui(new Ui::DividerSettingsEditorForm) {
  //  ui->setupUi(this);

  QVBoxLayout *layout = new QVBoxLayout;
  setLayout(layout);

  QWidget *widget = new QWidget;
  layout->addWidget(widget);

  QWidget *canvas = new QWidget;
  canvas->setStyleSheet("QWidget { background: white; }");

  _divider = new Divider(canvas);
  QColor color(_divider->color());

  _divider->setOrientation(Divider::Orientation::HORIZONTAL);
  //  _divider->setColor(color);
  _divider->setThickness(10);
  _divider->setLength(100.0);
  layout->addWidget(_divider);

  ui->setupUi(widget);
  connect(ui->btn_round, &QRadioButton::toggled, this,
          [=](bool round) { _divider->setRound(round); });
  connect(ui->orientation, &QComboBox::currentTextChanged, this,
          [=](QString str) {
            if (str == "VERTICAL") {
              _divider->setOrientation(Divider::Orientation::VERTICAL);
            }
            if (str == "HORIZONTAL") {
              _divider->setOrientation(Divider::Orientation::HORIZONTAL);
            }
          });
  connect(ui->length, &QDoubleSpinBox::textChanged, this, [=](QString str) {
    _divider->setLength(str.toDouble());
  });
  connect(ui->thickness, &QSpinBox::textChanged, this, [=](QString str) {
    _divider->setThickness(str.toInt());
  });
  connect(ui->color, &QLineEdit::textChanged, this, [=](QString str) {
    _divider->setColor(QColor(str));
  });
  ui->thickness->setValue(10);
  ui->color->setText(color.name());

  ui->orientation->addItem("HORIZONTAL");
  ui->orientation->addItem("VERTICAL");
  ui->length->setValue(100.0);
}

DividerSettingsEditor::~DividerSettingsEditor() { delete ui; }

void DividerSettingsEditor::initConnect() {}
