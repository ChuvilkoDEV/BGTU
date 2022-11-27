#include <stdio.h>
#include "List7/List7.h"

void test1() {
  int a1[7] = {3, 5, 7, 1, 0, 5};
  List l1;
  InitList(&l1, 6);
  CopyFromArray(&l1, a1, 6);

  int a2[6] = {3, 5, 7, 1, 0, 5};
  List l2;
  InitList(&l2, 6);
  CopyFromArray(&l2, a2, 6);

  if (isEqual(&l1, &l2) == 1)
    printf("First test passed\n");
  else
    printf("First test failed\n");
}

void test2() {
  int a1[7] = {3, 5, 7, 1, 0, 5, 3};
  List l1;
  InitList(&l1, 7);
  CopyFromArray(&l1, a1, 7);

  int a2[6] = {3, 5, 7, 1, 0, 5};
  List l2;
  InitList(&l2, 6);
  CopyFromArray(&l2, a2, 6);

  if (isEqual(&l1, &l2) == 0)
    printf("Second test passed\n");
  else
    printf("Second test failed\n");
}

void test3() {
  int a1[6] = {3, 5, 7, 1, 1, 5};
  List l1;
  InitList(&l1, 6);
  CopyFromArray(&l1, a1, 6);

  int a2[6] = {3, 5, 7, 1, 0, 5};
  List l2;
  InitList(&l2, 6);
  CopyFromArray(&l2, a2, 6);

  if (isEqual(&l1, &l2) == 0)
    printf("Third test passed\n");
  else
    printf("Third test failed\n");
}

int main() {
  test1();
  test2();
  test3();

  return 0;
}
