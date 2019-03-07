#include "simulator.h"
#include <viz/visualizer.h>
#include <viz/viz_config.h>
#include <cmath>

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

void Simulator::March(const float &distance) {
  state_.robot_x =
      state_.robot_x - distance * sin(M_PI - state_.robot_a * M_PI / 180.0f);
  state_.robot_y =
      state_.robot_y - distance * cos(M_PI - state_.robot_a * M_PI / 180.0f);
  viz_->BeamRobot(state_.robot_x, state_.robot_y, state_.robot_a);
}

void Simulator::Rotate(const float &angle) {
  state_.robot_a += angle;
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
