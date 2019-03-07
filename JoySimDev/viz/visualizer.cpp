#include "visualizer.h"
#include <widgets/robot.h>
#include <widgets/playground.h>

namespace viz {
Visualizer::Visualizer()
{

}

Visualizer::~Visualizer() {
  if (playground_) {
    if (!playground_->parent()) {
      delete playground_;
      playground_ = nullptr;
    }
  }
}

void Visualizer::Configure(const VizConfig &config) {
  config_ = config;
}

VizConfig Visualizer::Config() {
  return config_;
}

void Visualizer::BeamRobot(
    const int &x, const int &y, const float &theta) {
  if (!playground_) {
    return;
  }
  if (robot_) {
    delete robot_;
  }
  robot_ = new widgets::Robot(theta, playground_);
  robot_->Move(x, y);
  robot_->show();
}

void Visualizer::MoveRobot(
    const int &delta_x, const int &delta_y, const float &delta_theta) {
  if (!playground_) {
    return;
  }
  auto theta = robot_->Heading();
  auto x = robot_->X();
  auto y = robot_->Y();
  if (robot_) {
    delete robot_;
  }
  robot_ = new widgets::Robot(theta + delta_theta, playground_);
  robot_->Move(x + delta_x, y + delta_y);
  robot_->show();
}

bool Visualizer::ConstructScene() {
  int width = config_.playground_width;
  int height = config_.playground_height;
  playground_ =
      new widgets::Playground(width, height);
  robot_ = new widgets::Robot(0.0f, playground_);
  robot_->Move(width / 2.0f, height / 2.0f);
  return true;
}

QWidget* Visualizer::PlaygroundWidget() {
  return playground_;
}
}
