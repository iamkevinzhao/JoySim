#include "odometer.h"
#include <iostream>

namespace sim {
Odometer::Odometer()
{
  SetTrajID(2);
}

void Odometer::Configure(const OdomConfig &config) {
  config_ = config;
}

void Odometer::SimMarch(
    const float& dist,
    float& sim_dist, float& sim_dev, float& sim_delta_ang) {
  SaveStateToPrev();

  auto d =
      NormRand(config_.dis_dev) -
      (Anomaly(config_.anomaly_precentage) ? config_.anomaly_degree : 0.0f);
  sim_dist = dist + d;
  auto dv =
      NormRand(config_.rot_dev) +
      (Anomaly(config_.anomaly_precentage) ? config_.anomaly_degree : 0.0f);
  sim_dev = dv;

  // update odom_prim_
  odom_prim_.d = sim_dist;
  odom_prim_.r = sim_dev;
  odom_prim_.dev_d = pow(config_.dis_dev, 2);
  odom_prim_.dev_r = pow(config_.rot_dev, 2);

  sim_delta_ang = 0.0f;
  auto previous = state;
  state.robot_pose.Trans(sim_dist, sim_dev, sim_delta_ang);
  AddTraj(previous.robot_pose, state.robot_pose);
}

void Odometer::SimRotate(const float& ang, float& sim_ang) {
  SaveStateToPrev();

  sim_ang = ang;
  state.robot_pose.a += sim_ang;
}

Odometry Odometer::GetOdometry() {
  Odometry odom;
#if 0
  odom.x = state.robot_pose.x - prev_state.robot_pose.x;
  odom.y = state.robot_pose.y - prev_state.robot_pose.y;
  odom.roll = state.robot_pose.a - prev_state.robot_pose.a;
  // TODO: variance decomposition
  odom.var_x = pow(config_.dis_dev, 2);
  odom.var_y = pow(config_.dis_dev, 2);
  odom.var_pitch = pow(config_.rot_dev, 2);
#endif
  return odom;
}

OdomPrimitive Odometer::GetOdomPrimitive() {
  return odom_prim_;
}

void Odometer::GetOdomPoses(wm::Pose &prev, wm::Pose &now) {
  now = state.robot_pose;
  prev = prev_state.robot_pose;
}
}
