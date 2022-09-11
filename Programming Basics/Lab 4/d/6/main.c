#include <stdio.h>

void inputArray(int *const a, int const size) {
  for (int i = 0; i < size; i++)
    scanf("%d", &a[i]);
}

void updateIndexMin(int const *const a, int n, int *minIndex, int *min) {
  if (a[n] < *min) {
    *min = a[n];
    *minIndex = n;
    return;
  }
}

void indexMin_(int const *const a, int n, int *minIndex, int *min) {
  n--;
  if (n < 0)
    return;
  updateIndexMin(a, n, minIndex, min);
  indexMin_(a, n, minIndex, min);
}

int indexMin(int const *const a, int const n) {
  int min = a[n - 1], minIndex = n - 1;
  indexMin_(a, n, &minIndex, &min);
  return minIndex;
}

int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  inputArray(a, n);

  printf("%d", indexMin(a, n));

  return 0;
}