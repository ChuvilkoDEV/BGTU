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

void differenceArray(int const *const a, int const sizeA,
                     int const *const b, int const sizeB,
                     int *c, int *sizeC) {
  for (int i = 0; i < sizeA; i++) {
    bool flag = false;
    for (int j = 0; j < sizeB; j++)
      if (a[i] == b[j])
        flag = true;
    if (flag == false)
      c[(*sizeC)++] = a[i];
  }
}

int main() {
  int sizeA, sizeB, sizeC = 0;
  scanf("%d %d", &sizeA, &sizeB);
  int a[sizeA], b[sizeB], c[sizeA + sizeB];
  inputArray_(a, sizeA);
  inputArray_(b, sizeB);

  differenceArray(a, sizeA, b, sizeB, c, &sizeC);

  printf("%d", sizeC);

  return 0;
}