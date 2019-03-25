#include "cpf_core.h"
#include <CPFDev/common/math.h>
#include <eigen3/Eigen/Dense>

namespace cpf {
CPFCore::CPFCore()
{

}

Result CPFCore::Fuse(const std::vector<Source> &sources) {
  Result result;
  Source fused;
  result.success = CPFCore::PureFuse(sources, fused);
  if (!result.success) {
    return result;
  }
  result.fused = fused;
  return result;
}

bool CPFCore::PureFuse(const std::vector<Source> &sources, Source &result) {
  std::vector<Eigen::MatrixXf> states;
  states.reserve(sources.size());
  std::vector<Eigen::MatrixXf> covars;
  covars.reserve(sources.size());
  for (auto& source : sources) {
    states.push_back(source.state);
    covars.push_back(source.covariance);
  }
  auto x_hat = SpliceMatVert(states);
  auto P = SpliceMatDiag(covars);
  auto M = GetM(sources);

  auto P_tilde =
      M * (M.transpose() * P.inverse() * M).inverse() * M.transpose();
  auto x_tilde = P_tilde * P.inverse() * x_hat;

  result.state = CutOffFromMatrix(x_tilde, sources[0].state.rows());
  result.covariance = CutOffFromMatrix(P_tilde, sources[0].covariance.rows());
  return true;
}

Eigen::MatrixXf CPFCore::GetM(const std::vector<Source>& sources) {
  Eigen::MatrixXf M =
      Eigen::MatrixXf::Identity(
          sources[0].state.rows(), sources[0].state.cols());
  std::vector<Eigen::MatrixXf> Ms;
  Ms.reserve(sources.size());
  for (auto& source : sources) {
    Ms.push_back(M);
  }
  return SpliceMatVert(Ms);
}
}
