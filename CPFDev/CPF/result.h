#ifndef CPF_RESULT_H
#define CPF_RESULT_H

#include "source.h"
#include <vector>
#include <CPFDev/export.h>

namespace cpf {
struct API Result
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
