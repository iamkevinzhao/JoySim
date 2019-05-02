#ifndef SIM_TRAJECTORY_ESTIMATE_H
#define SIM_TRAJECTORY_ESTIMATE_H

#include "robot_base.h"
#include <JoySimDev/export.h>

namespace sim {
class API TrajectoryEstimate : public RobotBase
{
public:
  TrajectoryEstimate();
  void Move(const float& dist, const float& rot);
  void SimRotate(const float& ang, float& sim_ang) override;
  void AddAnomalyTraj(const wm::Pose& prev, const wm::Pose& now);
};
}

#endif // SIM_TRAJECTORY_ESTIMATE_H
