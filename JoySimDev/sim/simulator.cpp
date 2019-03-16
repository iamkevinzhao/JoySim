#include "simulator.h"
#include <viz/visualizer.h>
#include <viz/viz_config.h>
#include <cmath>
#include "engine.h"
#include "robot.h"
#include "odometer.h"

namespace sim {
Simulator::Simulator()
{
  robot_.reset(new Robot);
  odom_.reset(new Odometer);
}

bool Simulator::Start() {
  if (robot_) {
    robot_->Beam(
        wm::Pose(
            config_.playground_width / 2.0f,
            config_.playground_height / 2.0f,
            0.0f));
  }

  if (odom_) {
    odom_->SetPose(
        wm::Pose(
            config_.playground_width / 2.0f,
            config_.playground_height / 2.0f,
            0.0f));
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
  if (robot_) {
    robot_->March(distance);
  }
  if (odom_) {
    odom_->March(distance);
  }
}

void Simulator::Rotate(const float &angle) {
  if (robot_) {
    robot_->Rotate(angle);
  }
  if (odom_) {
    odom_->Rotate(angle);
  }
}

void Simulator::SetViz(std::shared_ptr<viz::Visualizer> vis) {
  viz_ = vis;
  if (robot_) {
    robot_->SetViz(viz_);
  }
  if (odom_) {
    odom_->SetViz(viz_);
  }
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
