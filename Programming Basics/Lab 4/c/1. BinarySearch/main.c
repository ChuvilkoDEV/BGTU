#include <stdio.h>

// Ввод массива a размера size
void inputArray(int *a, size_t const size) {
  for (size_t i = 0; i < size; i++)
    scanf("%d", &a[i]);
}

int binarySearch(const int *a, const int n, const int x) {
  int left = -1;
  int right = n;
  while (left + 1 < right) {
    int middle = left + (right - left) / 2;
    if (a[middle] > x)
      right = middle;
    else if (a[middle] < x) // если ’истина’, искомый элемент лежит левее
      left = middle;
    else
      return middle;
  }
  return -1;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int a[n], b[k];
  inputArray(a, n);
  inputArray(b, k);

  for (int i = 0; i < k; i++) {
    if (binarySearch(a, n, b[i]) == -1)
      printf("NO\n");
    else
      printf("YES\n");
  }

  return 0;
}
