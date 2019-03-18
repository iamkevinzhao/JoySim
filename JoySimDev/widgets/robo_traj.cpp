#include "robo_traj.h"
#include <QPainter>
#include <QDebug>
#include <cmath>

namespace widgets {
RoboTraj::RoboTraj(
    const wm::Pose& from, const wm::Pose& to, QWidget* parent,
    const Qt::GlobalColor& dot_color,
    const Qt::GlobalColor& line_color)
  : WidgetBase(parent), kFrom(from), kTo(to),
    kLineColor(line_color), kDotColor(dot_color)
{
  radius_ = sqrt(pow(kTo.x - kFrom.x, 2) + pow(kTo.y - kFrom.y, 2));
}

Qt::GlobalColor RoboTraj::DotColorByID(const int& id) {
  switch (id) {
  case 0: return Qt::red;
  case 1: return Qt::blue;
  default: return Qt::white;
  }
}

Qt::GlobalColor RoboTraj::LineColorByID(const int& id) {
  switch (id) {
  case 0: return Qt::green;
  case 1: return Qt::magenta;
  default: return Qt::gray;
  }
}

void RoboTraj::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setPen(QPen(kLineColor, 1));
  painter.drawLine(
      radius_, radius_, radius_ + kTo.x - kFrom.x, radius_ + kTo.y - kFrom.y);
  painter.setPen(QPen(kDotColor, 3));
  painter.drawPoint(radius_, radius_);
  this->move(kFrom.x - radius_, kFrom.y - radius_);
}
}
