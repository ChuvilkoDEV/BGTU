#ifndef CODE_MATRIX_H
#define CODE_MATRIX_H

#include <iostream>
#include <utility>
#include <vector>
#include <iomanip>

#define EPS 0.001

using namespace std;
using matrixRow = vector<double>;
using matrix = vector<matrixRow>;

class Matrix {
  public:
  matrix data;
  int nRows;
  int nColumns;
  int nSwap;
  vector<int> basis;

  explicit Matrix(int nRows, int nColumns) {
    this->nRows = nRows;
    this->nColumns = nColumns;
    nSwap = 0;
    for (int i = 0; i < nColumns; i++) {
      matrixRow r(nRows);
      data.push_back(r);
    }
  }

  explicit Matrix(matrix &m) {
    this->nColumns = m[0].size();
    this->nRows = m.size();
    nSwap = 0;
    data = std::move(m);
  }

  void Output();
  void Input();

  static Matrix Multiplication(Matrix &m, double x);
  static Matrix Multiplication(Matrix &m1, Matrix &m2);
  static vector<double> Multiplication(Matrix &m1, vector<double> &m2);

  static Matrix division(Matrix &m, double x);

  static Matrix Addition(Matrix &m1, Matrix &m2);
  static Matrix Difference(Matrix &m1, Matrix &m2);

  static Matrix Transposition(Matrix &m);
  void Transposition();

  void forwardGauss();
  void reverseGauss();
  void deleteZeroRows();
  bool isFindZeroRow();

  void linearEquation();
  double determinant();
  void inverse();

  vector<vector<int>> generateCombinations();
  void deleteRow(int rowIndex);
  void reverseGauss(vector<int> &supports);
  bool CheckBasisMatrix(vector<int> &supports);
  void findAllBasis();
  bool isHaveSolution();

  bool isEnoughBasis();
  bool isAllElementZGreaterZero();
  void SimplexMethod();
};


#endif //CODE_MATRIX_H
