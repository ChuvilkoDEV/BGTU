#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
using MatrixRow = vector<int>;
using Matrix = vector<MatrixRow>;

int N = 5;

void getMatrixRow(string &s, MatrixRow &row) {
  int sum = 0;
  for (char const &c: s) {
    if (c == ' ') {
      row.push_back(sum);
      sum = 0;
    } else {
      sum = sum * 10 + c - '0';
    }
  }
  row.push_back(sum);
}

void getMatrix(Matrix &matrix) {
  std::string line;
  std::ifstream in("..\\hello.txt"); // окрываем файл для чтения
  if (in.is_open()) {
    for (int i = 0; i < N; i++) {
      getline(in, line);
      getMatrixRow(line, matrix[i]);
    }
  }
  in.close();     // закрываем файл
}

void outputMatrix(Matrix &matrix) {
  for (auto &i: matrix) {
    for (int j: i)
      cout << j << ' ';
    cout << '\n';
  }
}

void deleteFirstElements(Matrix &matrix) {
  matrix.erase(matrix.begin());
  for (auto &i : matrix)
    i.erase(i.begin());
}

int main() {
  Matrix matrix(N);
  getMatrix(matrix);

  cout << "before:" << endl;
  outputMatrix(matrix);

  cout << endl << "after:" << endl;
  deleteFirstElements(matrix);
  outputMatrix(matrix);

  return 0;
}
