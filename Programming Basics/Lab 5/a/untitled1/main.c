#include <stdio.h>

#define N 10

void inputArray_(int *const a, const size_t n) {
  for (size_t i = 0; i < n; i++)
    scanf("%d", &a[i]);
}

void outputArray_(const int *const a, const size_t n) {
  for (size_t i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}



int main() {
  int a[N], b[N], c[2 * N];
  size_t sizeA, sizeB, sizeC;



  return 0;
}
