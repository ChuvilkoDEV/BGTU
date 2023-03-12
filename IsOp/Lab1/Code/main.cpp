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
  //matrix m = {{3, -2, 2, 10}, {2, 1, -4, -7}, {2, 2, -6, -12}};
  matrix m = {{3, 5, 1}, {3, 5, 2}};
  //matrix m = {{2,  -1, 6, -1,  3,  12}, {3,  5,  1, -12, 2,  14}, {-3, 6,  8, 7,   -4, 18}};

  Matrix M1(m);
  M1.Output();
  M1.forwardGauss();
  M1.findAllBasis();

  return 0;
}
