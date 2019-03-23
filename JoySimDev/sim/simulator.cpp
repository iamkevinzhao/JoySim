#include "simulator.h"
#include <viz/visualizer.h>
#include <viz/viz_config.h>
#include <cmath>
#include "engine.h"
#include "robot.h"
#include "odometer.h"
#include <config.h>

namespace sim {
Simulator::Simulator()
{
  robot_.reset(new Robot);
}

bool Simulator::Start() {
  auto beam_x = config_.playground_width / 2.0f;
  auto beam_y = config_.playground_height / 2.0f;
  auto beam_a = 0.0f;
  if (robot_) {
    robot_->Beam(wm::Pose(beam_x, beam_y, beam_a));
  }

  for (auto& odom : odoms_) {
    if (odom) {
      odom->SetPose(wm::Pose(beam_x, beam_y, beam_a));
    }
  }
  return true;
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
  for (auto& odom : odoms_) {
    if (odom) {
      odom->March(distance);
    }
  }
}

void Simulator::Rotate(const float &angle) {
  if (robot_) {
    robot_->Rotate(angle);
  }
  for (auto& odom : odoms_) {
    if (odom) {
      odom->Rotate(angle);
    }
  }
}

void Simulator::SetViz(std::shared_ptr<viz::Visualizer> vis) {
  viz_ = vis;
  if (robot_) {
    robot_->SetViz(viz_);
  }
  for (auto& odom : odoms_) {
    if (odom) {
      odom->SetViz(viz_);
    }
  }
}

void Simulator::AddOdometer(std::shared_ptr<Odometer> odom) {
  if (!odom) {
    return;
  }
  odom->SetTrajID(odoms_.size() + 2);
  odoms_.push_back(odom);

}

std::vector<std::shared_ptr<Odometer>> Simulator::GetOdometers() {
  return odoms_;
}

std::string Simulator::Version() {
  return JOYSIM_VERSION_STRING;
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
