#include "odom_fusion.h"
#include <iostream>
#include <CPFDev/common/math.h>
#include <eigen3/Eigen/Eigenvalues>
#include <eigen3/Eigen/Dense>

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
  if (sources_.empty()) {
    return false;
  }

  std::vector<Eigen::VectorXf> vectors;
  for (auto& source : sources_) {
    vectors.push_back(SpliceVectors({source.measurement}));
  }
  Eigen::VectorXf x_hat = SpliceVectors(vectors);

  std::vector<Eigen::MatrixXf> matrices;
  for (auto& source : sources_) {
    matrices.push_back(SpliceMatDiag({source.covariance}));
  }
  Eigen::MatrixXf P = SpliceMatDiag(matrices);

  matrices.clear();
  for (auto& source : sources_) {
    auto dim = source.measurement.rows();
    matrices.push_back(Eigen::MatrixXf::Identity(dim, dim));
  }
  Eigen::MatrixXf M = SpliceMatVert(matrices);

  Eigen::MatrixXf P_tilde =
      M * (M.transpose() * P.inverse() * M).inverse() * M.transpose();
  Eigen::VectorXf x_tilde = P_tilde * P.inverse() * x_hat;

  measurement = CutOffFromVector(x_tilde, sources_[0].measurement.rows());
  covariance = CutOffFromMatrix(P_tilde, sources_[0].covariance.rows());
  return true;
}
}
