#include "simulator.h"
#include <viz/visualizer.h>

namespace sim {
Simulator::Simulator()
{

}

void Simulator::Command(
    const int &delta_x, const int &delta_y, const float &delta_theta) {
  if (viz_) {
    viz_->MoveRobot(delta_x, delta_y, delta_theta);
  }
}

void Simulator::SetViz(std::shared_ptr<viz::Visualizer> viz) {
  viz_ = viz;
}
}
