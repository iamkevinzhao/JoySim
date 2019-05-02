#ifndef SIM_ROBOT_BASE_H
#define SIM_ROBOT_BASE_H

#include "engine.h"
#include "sim_state.h"
#include <JoySimDev/wm/pose.h>
#include <memory>
#include <JoySimDev/viz/visualizer.h>
#include <JoySimDev/export.h>

namespace sim {
class API RobotBase : public Engine
{
public:
  RobotBase();
  void SetViz(std::shared_ptr<viz::Visualizer> viz);
  void March(const float& dist);
  virtual void SimMarch(
      const float& dist, float& sim_dist, float& sim_dev, float& sim_delta_ang);
  void Rotate(const float& ang);
  virtual void SimRotate(const float& ang, float& sim_ang);
  void SetPose(const wm::Pose& pose);
  void SetTrajID(const int& id);
  int GetTrajID();
protected:
  void SaveStateToPrev();
  void AddTraj(const wm::Pose& prev, const wm::Pose& now);
  SimState state;
  SimState prev_state;
  std::shared_ptr<viz::Visualizer> viz;
  int traj_id_ = 0;
};
}

#endif // SIM_ROBOT_BASE_H
