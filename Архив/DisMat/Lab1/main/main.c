#include <stdio.h>
#include <assert.h>
#include "implementation.h"

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


int main() {
  printf("Hello, World!\n");
  return 0;
}