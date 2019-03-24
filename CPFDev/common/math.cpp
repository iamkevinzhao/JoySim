#include "math.h"

Eigen::VectorXf SpliceVectors(const std::vector<Eigen::VectorXf>& vectors) {
  int num = 0;
  for (auto& vec : vectors) {
    num += vec.rows();
  }
  Eigen::VectorXf vector = Eigen::VectorXf::Zero(num);
  int index = 0;
  for (auto& vec : vectors) {
    for (int i = 0; i < vec.rows(); ++i) {
      vector(index++) = vec(i);
    }
  }
  return vector;
}

Eigen::MatrixXf SpliceMatDiag(const std::vector<Eigen::MatrixXf>& mats) {
  int num = 0;
  for (auto& mat : mats) {
    num += mat.rows();
  }
  Eigen::MatrixXf matrix = Eigen::MatrixXf::Zero(num, num);
  int index = 0;
  for (auto& mat : mats) {
    for (int i = 0; i < mat.rows(); ++i) {
      for (int j = 0; j < mat.cols(); ++j) {
        matrix(index + i, index + j) = mat(i, j);
      }
    }
    index += mat.rows();
  }
  return matrix;
}

Eigen::MatrixXf SpliceMatVert(const std::vector<Eigen::MatrixXf>& mats) {
  int cols = 0;
  int rows = 0;
  for (auto& mat : mats) {
    rows += mat.rows();
    if (mat.cols() > cols) {
      cols = mat.cols();
    }
  }
  Eigen::MatrixXf matrix = Eigen::MatrixXf(rows, cols);
  int index = 0;
  for (auto& mat : mats) {
    for (int i = 0; i < mat.rows(); ++i) {
      for (int j = 0; j < mat.cols(); ++j) {
        matrix(index + i, j) = mat(i, j);
      }
    }
    index += mat.rows();
  }
  return matrix;
}
