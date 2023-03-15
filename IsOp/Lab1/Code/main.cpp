#include <iostream>
#include "Matrix/Matrix.h"


void output(vector<int> &i) {
  for (auto j: i) {
    cout << 'x' << j << ' ';
  }
  cout << '\n';
}

int main() {
  cout << setprecision(3);
  //matrix m = {{1, 1,2,3, 5}, {1, 4, 5, 6, 6}, {2, 7, 8, 9, 7}, {2, 4, 1, 4, 4}};
  matrix m = {{8, 4, 3}, {4,5,4}, {1,1,1}};
  //matrix m = {{3, 5, 1}, {6, 10, 2}};
  //matrix m = {{2,  -1, 6, -1,  3,  12}, {3,  5,  1, -12, 2,  14}, {-3, 6,  8, 7,   -4, 18}};

  Matrix M1(m);
  M1.inverse();
  M1.Output();

  return 0;
}
