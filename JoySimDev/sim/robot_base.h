#ifndef SIM_ROBOT_BASE_H
#define SIM_ROBOT_BASE_H

#include "engine.h"
#include "sim_state.h"
#include "wm/pose.h"
#include <memory>
#include <viz/visualizer.h>

namespace sim {
class RobotBase : public Engine
{
public:
  RobotBase();
  void SetViz(std::shared_ptr<viz::Visualizer> viz);
  void March(const float& dist);
  virtual void SimMarch(
      const float& dist, float& sim_dist, float& sim_dev, float& sim_delta_ang);
  void Rotate(const float& ang);
  virtual void SimRotate(const float& ang, float& sim_ang);
protected:
  void AddTraj(const wm::Pose& prev, const wm::Pose& now);
  SimState state;
  std::shared_ptr<viz::Visualizer> viz;
};
}

#endif // SIM_ROBOT_BASE_H
