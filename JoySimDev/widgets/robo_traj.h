#ifndef WIDGETS_ROBO_TRAJ_H
#define WIDGETS_ROBO_TRAJ_H

#include "widget_base.h"
#include <wm/pose.h>

namespace widgets {
class RoboTraj : public WidgetBase
{
public:
  RoboTraj(const wm::Pose& from, const wm::Pose& to, QWidget* parent);
protected:
  void paintEvent(QPaintEvent* event);
private:
  wm::Pose from_;
  wm::Pose to_;
  float radius_;
};
}

#endif // ROBO_TRAJ_H
