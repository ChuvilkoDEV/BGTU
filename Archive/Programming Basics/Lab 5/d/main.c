#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"
#include "libs/algorithms/algorithms.h"

void test_transposeSquareMatrix() {
  matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                            4, 5, 6,
                                            7, 8, 9}, 3, 3);
  transposeSquareMatrix(&m);
  matrix res = createMatrixFromArray((int[]) {1, 4, 7,
                                              2, 5, 8,
                                              3, 6, 9}, 3, 3);

  assert(twoMatricesEqual(m, res));
  freeMemMatrix(m);
  freeMemMatrix(res);
}

void test_exchangeMaxAndMinRow() {
  matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                            4, 5, 6,
                                            7, 8, 9}, 3, 3);
  exchangeMaxAndMinRow(&m);
  matrix res = createMatrixFromArray((int[]) {7, 8, 9,
                                              4, 5, 6,
                                              1, 2, 3}, 3, 3);

  assert(twoMatricesEqual(m, res));
  freeMemMatrix(m);
  freeMemMatrix(res);
}

void test_sortRowsByMinElement() {
  matrix m = createMatrixFromArray((int[]) {7, 1, 2,
                                            1, 8, 1,
                                            3, 2, 3}, 3, 3);
  sortRowsByMaxElement(&m);
  matrix res = createMatrixFromArray((int[]) {7, 1, 2,
                                              3, 2, 3,
                                              1, 8, 1}, 3, 3);

  assert(twoMatricesEqual(m, res));
  freeMemMatrix(m);
  freeMemMatrix(res);
}

void test_sortColsByMinElement() {
  matrix m = createMatrixFromArray((int[]) {7, 5, 3,
                                            9, 2, 3,
                                            3, 6, 3}, 3, 3);
  sortColsByMinElement(&m);
  matrix res = createMatrixFromArray((int[]) {7, 3, 5,
                                              9, 3, 2,
                                              3, 3, 6}, 3, 3);

  assert(twoMatricesEqual(m, res));
  freeMemMatrix(m);
  freeMemMatrix(res);
}

void test_mulMatrices() {
  matrix m1 = createMatrixFromArray((int[]) {1, 2, 3, 4,
                                             5, 6, 7, 8,
                                             9, 10, 11, 12}, 3, 4);
  matrix m2 = createMatrixFromArray((int[]) {1, 2, 3, 4,
                                             5, 6, 7, 8,
                                             9, 10, 11, 12}, 4, 3);
  matrix res = mulMatrices(m1, m2);
  matrix test = createMatrixFromArray(
    (int[]) {70, 80, 90, 158, 184, 210, 246, 288, 330}, 3, 3);

  assert(twoMatricesEqual(res, test));
  freeMemMatrix(m1);
  freeMemMatrix(m2);
  freeMemMatrix(res);
  freeMemMatrix(test);
}

void test_getSquareOfMatrixIfSymmetric() {
  matrix m = createMatrixFromArray((int[]) {1, 1, 2,
                                            1, 2, 3,
                                            2, 3, 3}, 3, 3);
  getSquareOfMatrixIfSymmetric(&m);
  matrix res = createMatrixFromArray((int[]) {6, 9, 11,
                                              9, 14, 17,
                                              11, 17, 22}, 3, 3);

  assert(twoMatricesEqual(m, res));
  freeMemMatrix(m);
  freeMemMatrix(res);
}

void test_transposeIfMatrixHasNotEqualSumOfRows() {
  matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                            4, 5, 6,
                                            7, 8, 9}, 3, 3);
  transposeSquareMatrix(&m);
  matrix res = createMatrixFromArray((int[]) {1, 4, 7,
                                              2, 5, 8,
                                              3, 6, 9}, 3, 3);

  assert(twoMatricesEqual(m, res));
  freeMemMatrix(m);
  freeMemMatrix(res);
}

void test_isMutuallyInverseMatrices() {
  matrix m1 = createMatrixFromArray((int[]) {3, -5,
                                             1, -2}, 2, 2);
  matrix m2 = createMatrixFromArray((int[]) {2, -5,
                                             1, -3}, 2, 2);

  assert(isMutuallyInverseMatrices(m1, m2));
  freeMemMatrix(m1);
  freeMemMatrix(m2);
}

void test_getMinInArea_zoneDoesNotGoBeyond() {
  matrix m = createMatrixFromArray((int[]) {3, 2, 3,
                                            4, 10, 6,
                                            7, 8, 9}, 3, 3);

  assert(getMinInArea(m) == 2);
  freeMemMatrix(m);
}

void test_getMinInArea_zoneOverflowsOnTheLeft() {
  matrix m = createMatrixFromArray((int[]) {3, 2, 3,
                                            10, 1, 6,
                                            7, 8, 9}, 3, 3);

  assert(getMinInArea(m) == 2);
  freeMemMatrix(m);
}

void test_getMinInArea_zoneOverflowsOnTheRight() {
  matrix m = createMatrixFromArray((int[]) {9, 8, 9,
                                            1, 1, 10,
                                            7, 8, 9}, 3, 3);

  assert(getMinInArea(m) == 8);
  freeMemMatrix(m);
}

void test_getMinInArea_zoneIsOutOfBounds() {
  matrix m = createMatrixFromArray((int[]) {9, 8, 9,
                                            10, 1, -10,
                                            7, 81, 9}, 3, 3);

  assert(getMinInArea(m) == -10);
  freeMemMatrix(m);
}

void test_getMinInArea() {
  test_getMinInArea_zoneDoesNotGoBeyond();
  test_getMinInArea_zoneOverflowsOnTheLeft();
  test_getMinInArea_zoneOverflowsOnTheRight();
  test_getMinInArea_zoneIsOutOfBounds();
}

void test_sortByDistances() {
  matrix m = createMatrixFromArray((int[]) {3, -5, 2,
                                            4, 6, -3,
                                            1, 3, 0}, 3, 3);
  sortByDistances(&m);
  matrix res = createMatrixFromArray((int[]) {1, 3, 0,
                                              3, -5, 2,
                                              4, 6, -3}, 3, 3);

  assert(twoMatricesEqual(m, res));
  freeMemMatrix(m);
  freeMemMatrix(res);
}

void test_getNSpecialElement() {
  matrix m = createMatrixFromArray((int[]) {3, 5, 5, 4,
                                            2, 3, 6, 7,
                                            12, 2, 1, 2}, 3, 4);

  assert(getNSpecialElement(m) == 2);
  freeMemMatrix(m);

}

void test_swapPenultimateRow() {
  matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                            4, 5, 6,
                                            7, 8, 1}, 3, 3);
  swapPenultimateRow(&m, m.nCols);
  matrix res = createMatrixFromArray((int[]) {1, 2, 3,
                                              1, 4, 7,
                                              7, 8, 1}, 3, 3);

  assert(twoMatricesEqual(m, res));
  freeMemMatrix(m);
  freeMemMatrix(res);
}

void test() {
  test_transposeSquareMatrix();
  test_exchangeMaxAndMinRow();
  test_sortRowsByMinElement();
  test_sortColsByMinElement();
  test_mulMatrices();
  test_getSquareOfMatrixIfSymmetric();
  test_transposeIfMatrixHasNotEqualSumOfRows();
  test_isMutuallyInverseMatrices();
  test_getMinInArea();
  test_sortByDistances();
  test_getNSpecialElement();
  test_swapPenultimateRow();
}

int main() {
  test();

  return 0;
}
