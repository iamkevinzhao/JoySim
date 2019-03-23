#include "robot.h"

namespace sim {
Robot::Robot()
{

}

void Robot::SimMarch(
    const float &dist, float &sim_dist, float &sim_dev, float &sim_delta_ang) {
  SaveStateToPrev();

  sim_dist = dist;
  sim_dev = 0.0f;
  sim_delta_ang = 0.0f;
  auto previous = state;
  state.robot_pose.Trans(sim_dist, sim_dev, sim_delta_ang);
  UpdatePoseViz();
  AddTraj(previous.robot_pose, state.robot_pose);
}

void Robot::SimRotate(const float &ang, float &sim_ang) {
  SaveStateToPrev();

  sim_ang = ang;
  state.robot_pose.a += sim_ang;
  UpdatePoseViz();
}

void Robot::Beam(const wm::Pose &pose) {
  state.robot_pose = pose;
  UpdatePoseViz();
}

void Robot::UpdatePoseViz() {
  if (viz) {
    viz->BeamRobot(state.robot_pose.ix(), state.robot_pose.iy(), state.robot_pose.a);
  }
}
}
