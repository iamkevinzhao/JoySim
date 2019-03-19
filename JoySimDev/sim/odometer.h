#ifndef SIM_ODOMETER_H
#define SIM_ODOMETER_H

#include <JoySimDev/sim/robot_base.h>
#include "odom_config.h"
#include <JoySimDev/export.h>

namespace sim {
class API Odometer : public RobotBase {
public:
  Odometer();
  void Configure(const OdomConfig& config);
  void SimMarch(
      const float& dist,
      float& sim_dist, float& sim_dev, float& sim_delta_ang) override;
  void SimRotate(const float& ang, float& sim_ang) override;
private:
  OdomConfig config_;
};
}

#endif // SIM_ODOMETER_H
