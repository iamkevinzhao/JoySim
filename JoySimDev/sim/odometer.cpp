#include "odometer.h"
#include <iostream>

namespace sim {
Odometer::Odometer()
{
  SetTrajID(2);
}

void Odometer::SimMarch(
    const float& dist,
    float& sim_dist, float& sim_dev, float& sim_delta_ang) {
  auto d = NormRand(1.0f);
  sim_dist = dist + d;
  auto dv = NormRand(10.0f);
  sim_dev = dv;
  std::cout << d << " " << dv << std::endl;
  sim_delta_ang = 0.0f;
  auto previous = state;
  state.robot_pose.Trans(sim_dist, sim_dev, sim_delta_ang);
  AddTraj(previous.robot_pose, state.robot_pose);
}

void Odometer::SimRotate(const float& ang, float& sim_ang) {
  sim_ang = ang;
  state.robot_pose.a += sim_ang;
}
}
