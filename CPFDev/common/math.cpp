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
  Eigen::MatrixXf matrix = Eigen::MatrixXf::Zero(rows, cols);
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

Eigen::VectorXf CutOffFromVector(const Eigen::VectorXf& vector, const int& size) {
  Eigen::VectorXf result = Eigen::VectorXf::Zero(size);
  for (int i = 0; i < size; ++i) {
    result(i) = vector(i);
  }
  return result;
}

Eigen::MatrixXf CutOffFromMatrix(
    const Eigen::MatrixXf& matrix, const int& size) {
  return CutOffFromMatrix(matrix, size, size);
}

Eigen::MatrixXf CutOffFromMatrix(
    const Eigen::MatrixXf& matrix, const int& row, const int& col) {
  Eigen::MatrixXf result = Eigen::MatrixXf::Zero(row, col);
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      result(i, j) = matrix(i, j);
    }
  }
  return result;
}
