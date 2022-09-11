#include <stdio.h>

// Ввод массива a размера size
void inputArray(int *a, size_t const size) {
  for (size_t i = 0; i < size; i++)
    scanf("%d", &a[i]);
}

int closestLeftBinarySearch(const int *a, const int n, const int x) {
  int left = -1;
  int right = n;
  while (left + 1 < right) {
    int middle = (left + right) / 2;
    if (a[middle] <= x)
      left = middle;
    else
      right = middle;
  }
  return left;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int a[n], b[k];
  inputArray(a, n);
  inputArray(b, k);

  for (int i = 0; i < k; i++) {
    printf("%d\n", closestLeftBinarySearch(a, n, b[i]) + 1);
  }

  return 0;
}
