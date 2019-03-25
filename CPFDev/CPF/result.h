#ifndef CPF_RESULT_H
#define CPF_RESULT_H

#include "source.h"
#include <vector>

namespace cpf {
struct Result
{
  Result();
  bool success = true;
  Source fused;
  bool outliers = false;
  struct Outlier {
    int id;
    float d;
  };
  std::vector<Outlier> outlier_info;
};
}

#endif // CPF_RESULT_H
