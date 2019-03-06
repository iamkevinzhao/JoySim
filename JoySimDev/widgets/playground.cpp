#include "playground.h"

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

}
}
