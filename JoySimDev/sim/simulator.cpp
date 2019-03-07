#include "simulator.h"
#include <viz/visualizer.h>
#include <viz/viz_config.h>

namespace sim {
Simulator::Simulator()
{

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
  if (viz_) {
    viz_->MoveRobot(delta_x, delta_y, delta_theta);
  }
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
