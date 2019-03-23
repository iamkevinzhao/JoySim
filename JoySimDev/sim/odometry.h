#ifndef SIM_ODOMETRY_H
#define SIM_ODOMETRY_H

#include <eigen3/Eigen/Geometry>

namespace sim {
using Cov6 = Eigen::Matrix<float, 6, 6>;
using Transform = Eigen::Affine3f;

struct Odometry
{
  Odometry();
  float x = 0.0f;
  float y = 0.0f;
  float z = 0.0f;
  float yaw = 0.0f;
  float pitch = 0.0f;
  float roll = 0.0f;
  float var_x = 0.0f;
  float var_y = 0.0f;
  float var_z = 0.0f;
  float var_yaw = 0.0f;
  float var_pitch = 0.0f;
  float var_roll = 0.0f;
  Cov6 CovMat();
  Transform TransMat();
};
}

#endif // SIM_ODOMETRY_H
