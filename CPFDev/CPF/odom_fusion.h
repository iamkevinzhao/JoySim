#ifndef CPF_ODOM_FUSION_H
#define CPF_ODOM_FUSION_H

#include <eigen3/Eigen/Core>
#include <vector>
#include "cpf_core.h"
#include <CPFDev/export.h>

namespace cpf {
class API OdomFusion : public CPFCore
{
public:
  OdomFusion();
  void Reset();
  void AddOdom(Eigen::Vector2f measurement, Eigen::Matrix2f covariance);
  bool Fuse(Eigen::Vector2f& measurement, Eigen::Matrix2f& covariance);
  bool Fuse(
      Eigen::Vector2f& measurement, Eigen::Matrix2f& covariance,
      Result& result);
private:
//  struct Source {
//    Eigen::Vector2f measurement;
//    Eigen::Matrix2f covariance;
//  };
  std::vector<Source> sources_;
};
}

#endif // CPF_ODOM_FUSION_H
