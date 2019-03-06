#include "robot.h"
#include <QPainter>

namespace widgets {
Robot::Robot(const float& heading, QWidget* parent)
  : WidgetBase(parent), kHeading(heading),
    kMargin(kBeacon - kRadius + kWeight),
    kCenter(kMargin + kRadius)
{
  constexpr int kEmpirical = 5;
  const int kLen = kBeacon + kRadius + kEmpirical*kWeight;
  this->setFixedSize(kLen, kLen);
}

void Robot::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  int diam = 2*kRadius;
  QRect rect(kMargin, kMargin, diam, diam);
  painter.setPen(QPen(Qt::blue, kWeight));
  painter.drawEllipse(rect);
  painter.drawLine(
      kCenter, kCenter,
      kCenter + kBeacon * sin(M_PI - kHeading * M_PI / 180),
      kCenter + kBeacon * cos(M_PI - kHeading * M_PI / 180));
}

void Robot::Move(const int &x, const int &y) {
  this->move(x - kCenter, y - kCenter);
}
}
