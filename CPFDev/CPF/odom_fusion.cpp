#include "odom_fusion.h"
#include <iostream>

namespace cpf {
OdomFusion::OdomFusion()
{

}

void OdomFusion::Reset() {
  sources_.clear();
}

void OdomFusion::AddOdom(
    Eigen::Vector2f measurement, Eigen::Matrix2f covariance) {
  sources_.push_back({measurement, covariance});
}

bool OdomFusion::Fuse(
    Eigen::Vector2f &measurement, Eigen::Matrix2f &covariance) {

  return true;
}
}
