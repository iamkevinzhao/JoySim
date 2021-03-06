#include "chi_square_table.h"

const std::unordered_map<
    ChiSquareTable::Alpha,
    std::vector<double>,
    EnumClassHash> ChiSquareTable::table_{
//  {ChiSquareTable::Alpha::a0_05,
//   std::vector<double>{
//      0.0039, 0.103, 0.352, 0.711, 1.15, 1.64, 2.17, 2.73, 3.33, 3.94, 4.57,
//      5.23, 5.89, 6.57, 7.26, 7.96, 8.67, 9.39, 10.1, 10.9, 11.6, 12.3, 13.1,
//      13.8, 14.6, 15.4, 16.2, 16.9, 17.7, 18.5, 19.3, 20.1, 20.9, 21.7, 22.5,
//      23.3, 24.1, 24.9, 25.7, 26.5, 27.3, 28.1, 29.0, 29.8, 30.6}},
//  {ChiSquareTable::Alpha::a0_5,
//   std::vector<double>{
//      0.455, 1.39, 2.37, 3.36, 4.35, 5.35, 6.35, 7.34, 8.34, 9.34, 10.3, 11.3,
//      12.3, 13.3, 14.3, 15.3, 16.3, 17.3, 18.3, 19.3, 20.3, 21.3, 22.3, 23.3,
//      24.3, 25.3, 26.3, 27.3, 28.3, 29.3, 30.3, 31.3, 32.3, 33.3, 34.3, 35.3,
//      36.3, 37.3, 38.3, 39.3, 40.3, 41.3, 42.3, 43.3, 44.3}}
  {ChiSquareTable::Alpha::a0_05,
   std::vector<double>{
       3.84, 5.99, 7.81, 9.49, 11.1, 12.6, 14.1, 15.5, 16.9, 18.3, 19.7, 21.0,
       22.4, 23.7, 25.0, 26.3, 27.6, 28.9, 30.1, 31.4, 32.7, 33.9, 35.2, 36.4,
       37.7, 38.9, 40.1, 41.3, 42.6, 43.8, 45.0, 46.2, 47.4, 48.6, 49.8, 51.0,
       52.2, 53.4, 54.6, 55.8, 56.9, 58.1, 59.3, 60.5, 61.7}},
  {ChiSquareTable::Alpha::a0_25,
   std::vector<double>{
       1.32, 2.77, 4.11, 5.39, 6.63, 7.84, 9.04, 10.2, 11.4, 12.5, 13.7, 14.8,
       16.0, 17.1, 18.2, 19.4, 20.5, 21.6, 22.7, 23.8, 24.9, 26.0, 27.1, 28.2,
       29.3, 30.4, 31.5, 32.6, 33.7, 34.8, 35.9, 37.0, 38.1, 39.1, 40.2, 41.3,
       42.4, 43.5, 44.5, 45.6, 46.7, 47.8, 48.8, 49.9, 51.0}},
};

ChiSquareTable::ChiSquareTable()
{
  // table_[Alpha::a0_05] = std::vector<double>{1.0};
}

bool ChiSquareTable::LookUp(const Alpha &alpha, const int &dof, double &chi_sqr) {
  chi_sqr = 0.0;
  if (!table_.count(alpha)) {
    return false;
  }
  if (dof <= 0 || dof > table_.at(alpha).size()) {
    return false;
  }
  chi_sqr = table_.at(alpha)[dof - 1];
  return true;
}
