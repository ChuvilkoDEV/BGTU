#include "Matrix.h"
#include <iostream>
#include <vector>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);
  int numberOfRows = 3, numberOfCols = 7;
  cout << "Функция Z:" << "\n";
  vector<double> zFunction(numberOfCols - 1);
  zFunction = {0, 6, 0, 8, 0, 3};
  //вывод функции Z
  cout << "Z = ";
  for (int i = 0; i < numberOfCols - 1; i++) {
    cout << zFunction[i] << "x[" << i + 1 << "] ";
  }
  //СЛАУ
  cout << "\n" << "Изначальная систему СЛАУ:" << "\n";
  matrix m({{1, -4, 0, -5, 0, -3, 9},
            {0, 7, 1, 5, 0, 4, 26},
            {0, 3, 0, -5, 1, -4, 10}});
  Matrix M(m);
  vector<double> index;
  M.indexes(index);
  M.newIndex(index);
  M.Output();
  cout << "Проверка на кол-во базисов: " << M.isEnoughBasis();
  cout << "\n" << "Изначальная таблица Симплекс метода:" << "\n";
  //первая таблица Симплекс метода
  Matrix FirstSimplexMatrix(numberOfRows + 1, numberOfCols);
  for (int i = 0; i < M.nRows; i++)
    for (int j = 0; j < M.nColumns; j++)
      FirstSimplexMatrix.data[i][j] = M.data[i][j];

  for (int i = 0; i < numberOfCols; i++) {
    if (zFunction[i] != 0) {
      FirstSimplexMatrix.data[numberOfRows][i] = -zFunction[i];
    } else {
      FirstSimplexMatrix.data[numberOfRows][i] = zFunction[i];
    }
  }
  FirstSimplexMatrix.data[numberOfRows][numberOfCols - 1] = 0;
  FirstSimplexMatrix.Output();
  int k = 1;
  while (!FirstSimplexMatrix.isAllElementZGreaterZero()) {
    FirstSimplexMatrix.SimplexMethod();
    cout << "-------------------------------------------------------" << "\n";
    cout << k << " таблица Симплекс метода" << "\n";
    FirstSimplexMatrix.Output();
    k++;
  }
  //вывод Zmax и иксов
  for (int i = 0; i < index.size(); i++) {
    cout << "x[" << index[i] << "]= " <<
         FirstSimplexMatrix.data[i][numberOfCols - 1] << "\n";
  }
  cout << "Zmax= " << FirstSimplexMatrix.data[numberOfRows][numberOfCols - 1];
  return 0;
}