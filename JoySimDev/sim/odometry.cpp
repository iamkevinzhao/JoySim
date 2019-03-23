#include "odometry.h"
#include <iostream>

namespace sim {
Odometry::Odometry()
{
}

Cov6 Odometry::CovMat() {
  Cov6 cov = Cov6::Zero();
  cov(0, 0) = var_x;
  cov(1, 1) = var_y;
  cov(2, 2) = var_z;
  cov(3, 3) = var_pitch;
  cov(4, 4) = var_yaw;
  cov(5, 5) = var_roll;
  return cov;
}

Transform Odometry::TransMat() {
  Eigen::AngleAxisf roll(
      this->roll * M_PI / 180.0f, Eigen::Vector3f::UnitZ());
  Eigen::AngleAxisf pitch(
      this->pitch * M_PI / 180.0f, Eigen::Vector3f::UnitY());
  Eigen::AngleAxisf yaw(
      this->yaw * M_PI / 180.0f, Eigen::Vector3f::UnitX());

  Transform trans = Transform::Identity();
  trans.rotate(roll * pitch * yaw);

  Eigen::Vector3f t(x, y, z);
  trans.translate(t);
  return trans;
}
}
