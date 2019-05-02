#ifndef CPF_CPF_CORE_H
#define CPF_CPF_CORE_H

#include <vector>
#include "source.h"
#include "result.h"
#include <CPFDev/export.h>

namespace cpf {
class API CPFCore
{
public:
  CPFCore();
  Result Fuse(const std::vector<Source>& sources);
  bool PureFuse(
      const std::vector<Source>& sources, Source& fused);
protected:
  bool PureFuse(
      const std::vector<Source>& sources, Source& fused,
      Eigen::MatrixXf& x_hat, Eigen::MatrixXf& P,
      Eigen::MatrixXf& x_tilde, Eigen::MatrixXf& P_tilde);
  bool DetectOutliers(
      Eigen::MatrixXf& x_hat, Eigen::MatrixXf& P,
      Eigen::MatrixXf& x_tilde, Result& result);
  bool PurgeOutliers(
      const Eigen::MatrixXf& fused,
      const std::vector<Source>& sources_in,
      std::vector<Source>& sources_out,
      Result& result);
  virtual Eigen::MatrixXf GetM(const std::vector<Source>& sources);
private:
};
}
#endif // CPF_CPF_CORE_H
