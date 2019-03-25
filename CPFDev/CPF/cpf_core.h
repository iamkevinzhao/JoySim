#ifndef CPF_CPF_CORE_H
#define CPF_CPF_CORE_H

#include <vector>
#include "source.h"
#include "result.h"

namespace cpf {
class CPFCore
{
public:
  CPFCore();
  Result Fuse(const std::vector<Source>& sources);
  bool PureFuse(const std::vector<Source>& sources, Source& result);
protected:
  virtual Eigen::MatrixXf GetM(const std::vector<Source>& sources);
private:
};
}
#endif // CPF_CPF_CORE_H
