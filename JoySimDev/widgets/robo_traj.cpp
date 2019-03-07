#include "robo_traj.h"
#include <QPainter>
#include <QDebug>
#include <cmath>

namespace widgets {
RoboTraj::RoboTraj(
    const wm::Pose& from, const wm::Pose& to, QWidget* parent)
  : WidgetBase(parent), from_(from), to_(to)
{
  radius_ = sqrt(pow(to_.x - from_.x, 2) + pow(to_.y - from_.y, 2));
}

void RoboTraj::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setPen(QPen(Qt::green, 1));
  painter.drawLine(
      radius_, radius_, radius_ + to_.x - from_.x, radius_ + to_.y - from_.y);
  painter.setPen(QPen(Qt::red, 3));
  painter.drawPoint(radius_, radius_);
  this->move(from_.x - radius_, from_.y - radius_);
}
}
