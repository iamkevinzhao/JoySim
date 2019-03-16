#include "pose.h"
#include <cmath>
#include <iostream>

namespace wm {
Pose::Pose() : Pose(0.0f, 0.0f, 0.0f) {

}

Pose::Pose(const float &x, const float &y, const float &a)
  : x(x), y(y), a(a) {

}

int Pose::ix() const {
  return round(x);
}

int Pose::iy() const {
  return round(y);
}

void Pose::Trans(
    const float &dist, const float &delta_dev, const float &delta_rot) {

  //  state_.robot_x
  //      -= sim_dist * sin(M_PI - (state_.robot_a + sim_dev) * M_PI / 180.0f);
  //  state_.robot_y
  //      -= sim_dist * cos(M_PI - (state_.robot_a + sim_dev) * M_PI / 180.0f);
  //  state_.robot_a += sim_delta_ang;

  float angle = M_PI - (this->a + delta_dev) * M_PI / 180.0f;
  this->x -= dist * sin(angle);
  this->y -= dist * cos(angle);
  this->a += delta_rot;
}

void Pose::Print() const {
  std::cout << "x: " << x << " y: " << y << " a: " << a << std::endl;
}
}
