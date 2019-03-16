#ifndef SIM_ROBOT_H
#define SIM_ROBOT_H

#include "robot_base.h"

namespace sim {
class Robot : public RobotBase
{
public:
  Robot();
  void SimMarch(
      const float& dist,
      float& sim_dist, float& sim_dev, float& sim_delta_ang) override;
  void SimRotate(const float& ang, float& sim_ang) override;
  void Beam(const wm::Pose& pose);
private:
  void UpdatePoseViz();
};
}

#endif // SIM_ROBOT_H
