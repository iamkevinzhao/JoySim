#ifndef COMMON_MATH_H
#define COMMON_MATH_H

#include <eigen3/Eigen/Core>
#include <vector>

Eigen::VectorXf SpliceVectors(const std::vector<Eigen::VectorXf>& vectors);

Eigen::MatrixXf SpliceMatDiag(const std::vector<Eigen::MatrixXf>& mats);

Eigen::MatrixXf SpliceMatVert(const std::vector<Eigen::MatrixXf>& mats);

Eigen::VectorXf CutOffFromVector(
    const Eigen::VectorXf& vector, const int& size);

Eigen::MatrixXf CutOffFromMatrix(
    const Eigen::MatrixXf& matrix, const int& size);

Eigen::MatrixXf CutOffFromMatrix(
    const Eigen::MatrixXf& matrix, const int& row, const int& col);

#endif // COMMON_MATH_H
