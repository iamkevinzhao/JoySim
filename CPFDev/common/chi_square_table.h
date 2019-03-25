#ifndef COMMON_CHI_SQUARE_TABLE_H
#define CHI_SQUARE_TABLE_H

#include <unordered_map>
#include <vector>
#include "utils.h"

class ChiSquareTable
{
public:
  enum class Alpha {a0_05, a0_25};
  ChiSquareTable();
  static bool LookUp(const Alpha& alpha, const int& dof, double& chi_sqr);
private:
  static const std::unordered_map<Alpha, std::vector<double>, EnumClassHash> table_;
};

#endif // COMMON_CHI_SQUARE_TABLE_H
