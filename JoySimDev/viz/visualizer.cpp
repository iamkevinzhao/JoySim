#include "visualizer.h"
#include <widgets/robot.h>
#include <widgets/playground.h>

namespace viz {
Visualizer::Visualizer()
{

}

void Visualizer::MoveRobot(
    const int &delta_x, const int &delta_y, const float &delta_theta) {
  auto theta = robot_->Heading();
  auto x = robot_->X();
  auto y = robot_->Y();
  delete robot_;
  robot_ = new widgets::Robot(theta + delta_theta, playground_);
  robot_->Move(x + delta_x, y + delta_y);
  robot_->show();
}

bool Visualizer::ConstructScene() {
  playground_ = new widgets::Playground(400, 400);
  robot_ = new widgets::Robot(0.0f, playground_);
  robot_->Move(200, 200);
  return true;
}

QWidget* Visualizer::PlaygroundWidget() {
  return playground_;
}
}
