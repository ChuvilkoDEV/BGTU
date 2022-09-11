#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/voidVector.h"
#include "libs/array/array.h"

void test_createVector_emptyVector() {
  vector v = createVector(0);

  assert(v.size == 0);
  assert(v.capacity == 0);

  deleteVector(&v);
}

void test_createVector_notEmptyVector() {
  vector v = createVector(5);

  assert(v.size == 0);
  assert(v.capacity == 5);

  deleteVector(&v);
}

void test_createVector() {
  test_createVector_emptyVector();
  test_createVector_notEmptyVector();
}

void test_reserve_newCapacityZero() {
  vector v = createVector(5);

  reserve(&v, 0);

  assert(v.data == 0);
  assert(v.size == 0);
  assert(v.capacity == 0);
  deleteVector(&v);
}

void test_reserve_newCapacitySmallerSize() {
  vector v = createVector(5);

  pushBack(&v, 0);
  pushBack(&v, 1);
  pushBack(&v, 2);
  pushBack(&v, 3);
  reserve(&v, 3);

  int resArray[] = {0, 1, 2};

  assert(isEqualArray(v.data, v.size, resArray, 3));
  assert(v.size == 3);
  assert(v.capacity == 3);
  deleteVector(&v);
}

void test_reserve_newCapacityBiggerSize() {
  vector v = createVector(5);

  pushBack(&v, 0);
  pushBack(&v, 1);
  pushBack(&v, 2);
  pushBack(&v, 3);
  reserve(&v, 8);

  int resArray[] = {0, 1, 2, 3};

  assert(isEqualArray(v.data, v.size, resArray, 4));
  assert(v.size == 4);
  assert(v.capacity == 8);
  deleteVector(&v);
}

void test_reserve() {
  test_reserve_newCapacityZero();
  test_reserve_newCapacitySmallerSize();
  test_reserve_newCapacityBiggerSize();
}

void test_shrinkToFit() {
  vector v = createVector(6);

  pushBack(&v, 0);
  pushBack(&v, 1);
  pushBack(&v, 2);
  pushBack(&v, 3);
  shrinkToFit(&v);

  int resArray[] = {0, 1, 2, 3};

  assert(isEqualArray(v.data, v.size, resArray, 4));
  assert(v.size == 4);
  assert(v.capacity == 4);
  deleteVector(&v);
}

void test_pushBack_emptyVector1() {
  vector v = createVector(2);
  pushBack(&v, 1);

  assert(v.data[0] == 1);
  assert(v.capacity == 2);
  deleteVector(&v);
}

void test_pushBack_emptyVector2() {
  vector v = createVector(0);
  pushBack(&v, 1);

  assert(v.data[0] == 1);
  assert(v.capacity == 1);
  deleteVector(&v);
}

void test_pushBack_emptyVector() {
  test_pushBack_emptyVector1();
  test_pushBack_emptyVector2();
}

void test_pushBack_fullVector() {
  vector v = createVector(2);
  pushBack(&v, 1);
  pushBack(&v, 2);
  pushBack(&v, 3);
  assert(v.data[2] == 3);

  deleteVector(&v);
}

void test_popBack_notEmptyVector() {
  vector v = createVector(0);
  pushBack(&v, 10);

  assert (v.size == 1);
  popBack(&v);
  assert (v.size == 0);
  assert (v.capacity == 1);

  deleteVector(&v);
}

void test_atVector_notEmptyVector() {
  vector v = createVector(2);
  pushBack(&v, 1);
  pushBack(&v, 2);

  assert(atVector(&v, 0) == &v.data[0]);

  deleteVector(&v);
}

void test_atVector_requestToLastElement() {
  vector v = createVector(2);
  pushBack(&v, 1);
  pushBack(&v, 2);

  assert(atVector(&v, 1) == &v.data[1]);

  deleteVector(&v);
}

void test_back_oneElementInVector() {
  vector v = createVector(3);
  pushBack(&v, 1);
  pushBack(&v, 2);

  assert(back(&v) == &v.data[1]);

  deleteVector(&v);
}

void test_front_oneElementInVector() {
  vector v = createVector(3);
  pushBack(&v, 1);
  pushBack(&v, 2);

  assert(front(&v) == &v.data[0]);

  deleteVector(&v);
}

void test_indexVector() {
  test_atVector_notEmptyVector();
  test_atVector_requestToLastElement();
  test_back_oneElementInVector();
  test_front_oneElementInVector();
}

void test_getVectorValueV() {
  vectorVoid v = createVectorV(5, sizeof(int));
  int source[] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++)
    setVectorValueV(&v, i, &source[i]);

  assert(isEqualArray(v.data, v.size, source, 5));
  deleteVectorV(&v);
}

void test_setVectorValueV() {
  vectorVoid v = createVectorV(5, sizeof(int));
  int source[] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++)
    setVectorValueV(&v, i, &source[i]);

  assert(isEqualArray(v.data, v.size, source, 5));
  deleteVectorV(&v);
}

void test_pushBack_fromManual1() {
  size_t n;
  scanf("%zd", &n);

  vectorVoid v = createVectorV(0, sizeof(int));
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);

    pushBackV(&v, &x);
  }

  for (int i = 0; i < n; i++) {
    int x;
    getVectorValueV(&v, i, &x);

    printf("%d ", x);
  }
}

void test_pushBack_fromManual2() {
  size_t n;
  scanf("%zd", &n);

  vectorVoid v = createVectorV(0, sizeof(float));
  for (int i = 0; i < n; i++) {
    float x;
    scanf("%f", &x);

    pushBackV(&v, &x);
  }

  for (int i = 0; i < n; i++) {
    float x;
    getVectorValueV(&v, i, &x);

    printf("%f ", x);
  }
}


void tests() {
  test_createVector();
  test_reserve();
  test_shrinkToFit();
  test_pushBack_emptyVector();
  test_pushBack_fullVector();
  test_popBack_notEmptyVector();
  test_indexVector();

  test_getVectorValueV();
  test_setVectorValueV();
}

int main() {
  tests();

  return 0;
}
