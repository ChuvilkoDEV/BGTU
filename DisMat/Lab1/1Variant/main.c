#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define N 10

void inputArray_(int *const a, const int n) {
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
}

void outputArray_(const int *const a, const int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}

void unionArray(int const *const a, int sizeA,
                int const *const b, int sizeB,
                int *c, int *sizeC) {
  for (int i = 0; i < sizeA; i++) {
    bool flag = false;
    for (int j = 0; j < *sizeC; j++)
      if (c[j] == a[i])
        flag = true;
    if (flag == false)
      c[*sizeC++] = a[i];
  }
  for (int i = 0; i < sizeB; i++) {
    bool flag = false;
    for (int j = 0; j < *sizeC; j++)
      if (c[j] == b[i])
        flag = true;
    if (flag == false)
      c[*sizeC++] = b[i];
  }
}

bool isEqualArray(int const *const a, int sizeA,
                  int const *const b, int sizeB) {
  if (sizeA != sizeB)
    return false;
  for (int i = 0; i < sizeA; i++)
    if (a[i] != b[i])
      return false;
  return true;
}

void test1() {
  int a[5] = {3, 4, 2, 5, 1}, b[5] = {6, 4, 8, 1, 9}, c[10];
  int sizeA = 5, sizeB = 5, sizeC = 0;
  int res[8] = {1, 2, 3, 4, 5, 6, 8, 9};
  int sizeRes = 8;

  unionArray(a, sizeA, b, sizeB, c, &sizeC);

  assert(isEqualArray(c, sizeC, res, sizeRes));
}

void test() {
  test1();
}

int main() {
  test();
}
