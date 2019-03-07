#include "simulator.h"
#include <viz/visualizer.h>
#include <viz/viz_config.h>

namespace sim {
Simulator::Simulator()
{

}

bool Simulator::Start() {
  state_.robot_x = config_.playground_width / 2.0f;
  state_.robot_y = config_.playground_height / 2.0f;
  state_.robot_a = 0.0f;
  if (viz_) {
    viz_->BeamRobot(state_.robot_x, state_.robot_y, state_.robot_a);
  }
}

void Simulator::Configure(const SimConfig &config) {
  config_ = config;

  if (config_.construct_viz) {
    viz_.reset(new viz::Visualizer);
  }
  if (viz_) {
    ConfigureVisualizer(viz_, config_);
    if (config_.construct_viz) {
      viz_->ConstructScene();
    }
  }
}

void Simulator::Command(
    const int &delta_x, const int &delta_y, const float &delta_theta) {
  int x = state_.robot_x + delta_x;
  int y = state_.robot_y + delta_y;
  int a = state_.robot_a + delta_theta;
  if (x >= 0 && x <= config_.playground_width) {
    if (y >= 0 && y <= config_.playground_height) {
      state_.robot_x = x;
      state_.robot_y = y;
    }
  }
  state_.robot_a = a;
  viz_->BeamRobot(state_.robot_x, state_.robot_y, state_.robot_a);
}

void Simulator::SetViz(std::shared_ptr<viz::Visualizer> vis) {
  viz_ = vis;
}

void Simulator::ConfigureVisualizer(
    std::shared_ptr<viz::Visualizer> vis, const SimConfig &config) {
  if (!vis) {
    return;
  }
  auto vconf = vis->Config();
  vconf.playground_width = config.playground_width;
  vconf.playground_height = config.playground_height;
  vis->Configure(vconf);
}
}
