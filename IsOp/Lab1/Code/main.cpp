#include <iostream>
#include "Matrix/Matrix.h"

int main() {
  //matrix m = {{1, 1,2,3, 5}, {1, 4, 5, 6, 6}, {2, 7, 8, 9, 7}, {2, 4, 1, 4, 4}};
  //matrix m = {{3, -2, 2, 10}, {2, 1, -4, -7}, {2, 2, -6, -12}};
  //matrix m = {{3, 5, 1}, {1, 0, 2}, {2, 2, -1}};
  matrix m = {{3, 5, 1}, {3, 5, 1}, {3, 5, 1}};

  Matrix M1(m);

  M1.forwardGauss();
  M1.Output();

  return 0;
}
