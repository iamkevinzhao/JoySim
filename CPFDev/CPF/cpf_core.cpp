#include "cpf_core.h"
#include <CPFDev/common/math.h>
#include <eigen3/Eigen/Dense>
#include <CPFDev/common/chi_square_table.h>
#include <iostream>

namespace cpf {
CPFCore::CPFCore()
{

}

Result CPFCore::Fuse(const std::vector<Source> &sources) {
  Result result;
  Source fused;
  Eigen::MatrixXf x_hat, P, x_tilde, P_tilde;
  if (!CPFCore::PureFuse(sources, fused, x_hat, P, x_tilde, P_tilde)) {
    result.success = false;
    return result;
  }

  if (!DetectOutliers(x_hat, P, x_tilde, result)) {
    result.success = false;
    return result;
  }

  if (result.outliers) {
    std::vector<Source> good_sources;
    if (result.outliers) {
      if (!PurgeOutliers(fused.state, sources, good_sources, result)) {
        result.success = false;
        return result;
      }
    }

    if (!good_sources.empty()) {
      if (!CPFCore::PureFuse(good_sources, fused)) {
        result.success = false;
        return result;
      }
    } else {
      result.success = false;
      return result;
    }
  }

  result.fused = fused;
  return result;
}

bool CPFCore::PureFuse(const std::vector<Source> &sources, Source &fused) {
  Eigen::MatrixXf x_hat, P, x_tilde, P_tilde;
  return PureFuse(sources, fused, x_hat, P, x_tilde, P_tilde);
}

bool CPFCore::PureFuse(
    const std::vector<Source> &sources, Source &result,
    Eigen::MatrixXf& x_hat, Eigen::MatrixXf& P,
    Eigen::MatrixXf& x_tilde, Eigen::MatrixXf& P_tilde) {
  std::vector<Eigen::MatrixXf> states;
  states.reserve(sources.size());
  std::vector<Eigen::MatrixXf> covars;
  covars.reserve(sources.size());
  for (auto& source : sources) {
    states.push_back(source.state);
    covars.push_back(source.covariance);
  }
  x_hat = SpliceMatVert(states);
  P = SpliceMatDiag(covars);
  auto M = GetM(sources);

  P_tilde =
      M * (M.transpose() * P.inverse() * M).inverse() * M.transpose();
  x_tilde = P_tilde * P.inverse() * x_hat;

  result.state = CutOffFromMatrix(x_tilde, sources[0].state.rows());
  result.covariance = CutOffFromMatrix(P_tilde, sources[0].covariance.rows());
  return true;
}

bool CPFCore::DetectOutliers(
    Eigen::MatrixXf& x_hat, Eigen::MatrixXf& P,
    Eigen::MatrixXf& x_tilde, Result &result) {
  double chi_sqr;
  if (!ChiSquareTable::LookUp(
          ChiSquareTable::Alpha::a0_05, x_hat.rows(), chi_sqr)) {
    return false;
  }
  auto d = (x_hat - x_tilde).transpose() * P.inverse() * (x_hat - x_tilde);
  double dd = d(0, 0);
  if (dd > chi_sqr) {
    result.outliers = true;
  }
  return true;
}

bool CPFCore::PurgeOutliers(
    const Eigen::MatrixXf &fused,
    const std::vector<Source> &sources_in,
    std::vector<Source> &sources_out,
    Result &result) {
  double chi_sqr;
  if (!ChiSquareTable::LookUp(
          ChiSquareTable::Alpha::a0_05, fused.rows(), chi_sqr)) {
    return false;
  }
  for (auto& source : sources_in) {
    auto d =
        (source.state - fused).transpose() *
        source.covariance.inverse() *
        (source.state - fused);
    double dd = d(0, 0);
    if (dd > chi_sqr) {
      result.outlier_info.push_back(Result::Outlier{source.id, (float)dd});
    } else {
      sources_out.push_back(source);
    }
  }
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
