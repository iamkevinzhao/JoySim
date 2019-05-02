#ifndef SIM_ODOM_PRIMITIVE_H
#define SIM_ODOM_PRIMITIVE_H

#include <eigen3/Eigen/Core>
#include <JoySimDev/export.h>

namespace sim {
struct API OdomPrimitive
{
  OdomPrimitive();
  float d = 0.0f;
  float r = 0.0f;
  float dev_d = 0.0f;
  float dev_r = 0.0f;
  Eigen::Vector2f StateVec();
  Eigen::Matrix2f CovMat();
};
}

#endif // SIM_ODOM_PRIMITIVE_H
