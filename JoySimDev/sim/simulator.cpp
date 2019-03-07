#include "simulator.h"
#include <viz/visualizer.h>
#include <viz/viz_config.h>
#include <cmath>
#include "engine.h"

namespace sim {
Simulator::Simulator()
{
  engine_.reset(new Engine);
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
  auto prev_state = state_;
  float sim_dist, sim_dev, sim_delta_ang;
  engine_->March(distance, sim_dist, sim_dev, sim_delta_ang);
  state_.robot_x
      -= sim_dist * sin(M_PI - (state_.robot_a + sim_dev) * M_PI / 180.0f);
  state_.robot_y
      -= sim_dist * cos(M_PI - (state_.robot_a + sim_dev) * M_PI / 180.0f);
  state_.robot_a += sim_delta_ang;
  if (viz_) {
    viz_->BeamRobot(state_.robot_x, state_.robot_y, state_.robot_a);
    viz_->AddRobotTraj(
        prev_state.robot_x, prev_state.robot_y, prev_state.robot_a,
        state_.robot_x, state_.robot_y, state_.robot_a);
  }
}

void Simulator::Rotate(const float &angle) {
  float sim_ang;
  engine_->Rotate(angle, sim_ang);
  state_.robot_a += sim_ang;
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
