#ifndef WIDGETS_ROBO_TRAJ_H
#define WIDGETS_ROBO_TRAJ_H

#include "widget_base.h"
#include <wm/pose.h>

namespace widgets {
class RoboTraj : public WidgetBase
{
public:
  RoboTraj(
    const wm::Pose& from, const wm::Pose& to, QWidget* parent, const int& id);
  RoboTraj(
    const wm::Pose& from, const wm::Pose& to, QWidget* parent,
    const Qt::GlobalColor& dot_color = Qt::red,
    const Qt::GlobalColor& line_color = Qt::green);
  static Qt::GlobalColor DotColorByID(const int& id);
  static Qt::GlobalColor LineColorByID(const int& id);
protected:
  void paintEvent(QPaintEvent* event);
private:
  const wm::Pose kFrom;
  const wm::Pose kTo;
  float radius_;
  const Qt::GlobalColor kLineColor;
  const Qt::GlobalColor kDotColor;
};
}

#endif // ROBO_TRAJ_H
