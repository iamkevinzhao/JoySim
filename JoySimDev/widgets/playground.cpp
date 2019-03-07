#include "playground.h"
#include <QPainter>

namespace widgets {
Playground::Playground(const int width, const int height, QWidget *parent) :
  WidgetBase(parent), kWidth(width), kHeight(height)
{
  this->setFixedSize(kWidth, kHeight);
}

Playground::~Playground()
{
}

void Playground::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setPen(QPen(Qt::green, 1));
  painter.drawRect(0, 0, kWidth - 1, kHeight - 1);
}
}
