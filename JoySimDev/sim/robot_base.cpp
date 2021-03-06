#include "robot_base.h"
#include <iostream>

namespace sim {
RobotBase::RobotBase()
{
  SaveStateToPrev();
}

void RobotBase::SetViz(std::shared_ptr<viz::Visualizer> viz) {
  this->viz = viz;
}

void RobotBase::AddTraj(const wm::Pose &prev, const wm::Pose &now) {
  if (viz) {
    viz->AddRobotTraj(
        prev.ix(), prev.iy(), prev.a,
        now.ix(), now.iy(), now.a, traj_id_);
  }
}

void RobotBase::SimMarch(
    const float& dist, float& sim_dist, float& sim_dev, float& sim_delta_ang) {
  sim_dist = dist;
  sim_dev = 0.0f;
  sim_delta_ang = 0.0f;
}

void RobotBase::March(const float &dist) {
  float a, b, c;
  SimMarch(dist, a, b, c);
}

void RobotBase::SimRotate(const float& ang, float& sim_ang) {
  sim_ang = ang;
}

void RobotBase::Rotate(const float &ang) {
  float a;
  SimRotate(ang, a);
}

void RobotBase::SetTrajID(const int &id) {
  traj_id_ = id;
}

int RobotBase::GetTrajID() {
  return traj_id_;
}

void RobotBase::SetPose(const wm::Pose &pose) {
  state.robot_pose = pose;
}

void RobotBase::SaveStateToPrev() {
  prev_state = state;
}
}
