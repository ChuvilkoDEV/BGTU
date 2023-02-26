#include "Matrix.h"

void Matrix::Output() {
  cout << setprecision(3);
  for (const auto &i: data) {
    for (auto j: i)
      cout << j << ",\t";
    cout << '\n';
  }
  cout << '\n';
}

void Matrix::Input() {
  for (int i = 0; i < nRows; i++) {
    for (int j = 0; j < nColumns; j++)
      cin >> this->data[i][j];
  }
}

Matrix Matrix::Multiplication(Matrix &m1, Matrix &m2) {
  if (m1.nColumns != m2.nRows) {
    cerr << "The number of columns of the first matrix is not equal "
            "to the number of rows of the second matrix";
    Matrix res(0, 0);
    return res;
  }

  Matrix res(m1.nRows, m2.nColumns);
  for (int i = 0; i < m1.nRows; i++) {
    for (int j = 0; j < m2.nColumns; j++) {
      res.data[i][j] = 0;
      for (int k = 0; k < m1.nColumns; ++k)
        res.data[i][j] += m1.data[i][k] * m2.data[k][j];
    }
  }
  return res;
}

Matrix Matrix::Multiplication(Matrix &m1, matrixRow &m2) {
  if (m1.nColumns != m2.size()) {
    cerr << "The number of columns of the first matrix is not equal "
            "to the number of rows of the second matrix";
    Matrix res(0, 0);
    return res;
  }

  Matrix res(m1.nRows, m1.nColumns);
  for (int i = 0; i < m1.nRows; i++) {
    for (int j = 0; j < m1.nColumns; j++) {
      res.data[i][j] = m1.data[i][j] * m2[j];
    }
  }
  return res;
}

Matrix Matrix::Multiplication(Matrix &m, double x) {
  Matrix res(m.nRows, m.nColumns);
  for (int i = 0; i < m.nRows; i++) {
    for (int j = 0; j < m.nColumns; j++) {
      res.data[i][j] = m.data[i][j] * x;
    }
  }
  return res;
}

Matrix Matrix::Addition(Matrix &m1, Matrix &m2) {
  if (m1.nRows != m2.nRows && m1.nColumns != m2.nColumns) {
    cerr << "Different number of rows or columns for matrices";
    Matrix res(0, 0);
    return res;
  }

  Matrix res(m1.nRows, m1.nColumns);
  for (int i = 0; i < m1.nColumns; i++)
    for (int j = 0; j < m1.nRows; j++)
      res.data[i][j] = m1.data[i][j] + m2.data[i][j];
  return res;
}

Matrix Matrix::Difference(Matrix &m1, Matrix &m2) {
  if (m1.nRows != m2.nRows && m1.nColumns != m2.nColumns) {
    cerr << "Different number of rows or columns for matrices";
    Matrix res(0, 0);
    return res;
  }

  Matrix res(m1.nRows, m1.nColumns);
  for (int i = 0; i < m1.nColumns; i++)
    for (int j = 0; j < m1.nRows; j++)
      res.data[i][j] = m1.data[i][j] - m2.data[i][j];
  return res;
}

Matrix Matrix::Transposition(Matrix &m) {
  Matrix res(m.nColumns, m.nRows);
  for (int i = 0; i < m.nRows; i++)
    for (int j = 0; j < m.nColumns; j++)
      res.data[j][i] = m.data[i][j];
  return res;
}


void Matrix::Transposition() {
  Matrix tmp(nRows, nColumns);
  for (int i = 0; i < this->nRows; i++)
    for (int j = 0; j < this->nColumns; j++)
      tmp.data[j][i] = this->data[i][j];
  this->data = tmp.data;
}

void Matrix::forwardGauss() {
  for (int i = 0; i < nRows - 1; i++) {
    for (int j = i + 1; j < nRows; j++)
      if (data[j][i] > data[i][i]) {
        swap(data[j], data[i]);
        nSwap++;
      }

    for (int j = i + 1; j < nRows; j++)
      if (abs(data[i][i]) >= EPS) {
        double dif = data[j][i] / data[i][i];
        for (int k = i; k < nColumns; k++)
          data[j][k] -= data[i][k] * dif;
      }
  }
}

void Matrix::reverseGauss() {
  for (int i = nRows - 1; i >= 0; i--) {
    if (abs(data[i][i]) >= EPS) {
      double dif = data[i][i];
      for (int j = i; j < nColumns; j++)
        data[i][j] /= dif;
    }

    for (int j = i - 1; j >= 0; j--) {
      for (int k = nRows; k < nColumns; k++)
        data[j][k] -= data[j][i] * data[i][k];
      data[j][i] = 0;
    }
  }
}


bool Matrix::isFindZeroRow() {
  for (int i = 0; i < nRows; i++) {
    bool allZero = true;
    for (int j = 0; j < nRows; j++)
      if (abs(data[i][j]) >= EPS) {
        allZero = false;
        break;
      }
    if (allZero)
      return true;
  }
  return false;
}

void Matrix::linearEquation() {
  this->forwardGauss();
  this->reverseGauss();
  if (isFindZeroRow()) {
    cerr << "No solution because null string was found";
    return;
  }

  for (int i = nRows - 1; i >= 0; i--) {
    cout << "x" << nRows - i << " = " << data[i][nColumns - 1] << ";\n";
  }
}

void Matrix::deleteZeroRows() {
  int n = nRows;
  for (int i = 0; i < n; i++) {
    bool allZero = true;
    for (int j = 0; j < n; j++) {
      if (abs(data[i][j]) > EPS) {
        allZero = false;
        break;
      }
    }
    if (allZero) {
      data[i].clear();
      data.erase(data.begin());
      nRows--;
    }
  }
}

double Matrix::determinant() {
  this->forwardGauss();
  this->deleteZeroRows();
  double det = data[0][0];
  for (int i = 1; i < nRows; i++) {
    det *= data[i][i];
  }
  if (nSwap % 2 == 1)
    det *= -1;
  return det;
}

void Matrix::inverse() {
  Matrix res(this->data);
  Matrix E(nRows, nColumns);
  for (int i = 0; i < nRows; i++)
    E.data[i][i] = 1;
  for (int i = 0; i < nRows; i++)
    for (auto j: E.data[i])
      res.data[i].push_back(j);
  res.nColumns *= 2;

  res.forwardGauss();
  res.reverseGauss();
  for (int i = 0; i < nRows; i++)
    for (int j = 0; j < nColumns; j++)
      data[i][j] = res.data[i][j + nColumns];
}

Matrix Matrix::division(Matrix &m, double x) {
  return Multiplication(m, 1/x);
}

void Matrix::deleteRow(int rowIndex) {
  if (rowIndex >= nRows || rowIndex < 0) {
    cerr << "Введенного индекса строки не существует";
    return;
  }

  data.erase(data.begin() + rowIndex);
  nRows--;
}





