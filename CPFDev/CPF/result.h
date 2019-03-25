#ifndef CPF_RESULT_H
#define CPF_RESULT_H

#include "source.h"

namespace cpf {
struct Result
{
  Result();
  bool success;
  Source fused;
};
}

#endif // CPF_RESULT_H
