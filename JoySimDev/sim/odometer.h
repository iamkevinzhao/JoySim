#ifndef SIM_ODOMETER_H
#define SIM_ODOMETER_H

#include "robot_base.h"

namespace sim {
class Odometer : public RobotBase {
public:
  Odometer();
  void SimMarch(
      const float& dist,
      float& sim_dist, float& sim_dev, float& sim_delta_ang) override;
  void SimRotate(const float& ang, float& sim_ang) override;
};
}

#endif // SIM_ODOMETER_H
