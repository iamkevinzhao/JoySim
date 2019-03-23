#include "odom_primitive.h"

namespace sim {
OdomPrimitive::OdomPrimitive()
{

}

Eigen::Vector2f OdomPrimitive::StateVec() {
  Eigen::Vector2f vec = Eigen::Vector2f::Identity();
  vec(0, 0) = d;
  vec(1, 0) = r;
  return vec;
}

Eigen::Matrix2f OdomPrimitive::CovMat() {
  Eigen::Matrix2f mat = Eigen::Matrix2f::Identity();
  mat(0, 0) = dev_d;
  mat(1, 1) = dev_r;
  return mat;
}
}
