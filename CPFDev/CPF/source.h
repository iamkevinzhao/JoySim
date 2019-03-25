#ifndef CPF_SOURCE_H
#define CPF_SOURCE_H

#include <eigen3/Eigen/Core>

namespace cpf {
struct Source {
  Source();
  int id = 0;
  Eigen::MatrixXf state;
  Eigen::MatrixXf covariance;
};
}
#endif // CPF_SOURCE_H
