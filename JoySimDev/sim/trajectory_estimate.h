#ifndef SIM_TRAJECTORY_ESTIMATE_H
#define SIM_TRAJECTORY_ESTIMATE_H

#include "robot_base.h"

namespace sim {
class TrajectoryEstimate : public RobotBase
{
public:
  TrajectoryEstimate();
  void Move(const float& dist, const float& rot);
  void SimRotate(const float& ang, float& sim_ang) override;
};
}

#endif // SIM_TRAJECTORY_ESTIMATE_H
