#include "trajectory_estimate.h"
#include <iostream>

namespace sim {
TrajectoryEstimate::TrajectoryEstimate()
{
  SetTrajID(1);
}

void TrajectoryEstimate::Move(const float &dist, const float &rot) {
  auto previous = state;
  state.robot_pose.Trans(dist, rot, 0.0f);
  AddTraj(previous.robot_pose, state.robot_pose);
}

void TrajectoryEstimate::SimRotate(const float& ang, float& sim_ang) {
  sim_ang = ang;
  state.robot_pose.a += sim_ang;
}

void TrajectoryEstimate::AddAnomalyTraj(const wm::Pose& prev, const wm::Pose& now) {
  if (viz) {
    viz->AddRobotTraj(
        prev.ix(), prev.iy(), prev.a,
        now.ix(), now.iy(), now.a, 101);
  }
}
}
