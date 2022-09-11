#include <stdio.h>
#include <stdlib.h>

void inputArray(int *a, size_t const size) {
  for (size_t i = 0; i < size; i++)
    scanf("%d", &a[i]);
}

int compare_ints(const void *a, const void *b) {
  int arg1 = *(const int *) a;
  int arg2 = *(const int *) b;
  if (arg1 < arg2) return -1;
  if (arg1 > arg2) return 1;
  return 0;
}

int closestLeftBinarySearch(const int *a, const int n, const int x) {
  int left = 0;
  int right = n - 1;
  while (left + 1 < right) {
    int middle = (left + right) / 2;
    if (a[middle] < x)
      left = middle;
    else
      right = middle;
  }
  if (a[left] < x)
    left++;
  return left;
}

int closestRightBinarySearch(const int *a, const int n, const int x) {
  int left = -1;
  int right = n - 1;
  while (left + 1 < right) {
    int middle = left + (right - left) / 2;
    if (a[middle] <= x)
      left = middle;
    else
      right = middle;
  }
  if (a[right] > x)
    right--;
  return right;
}

int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  inputArray(a, n);

  qsort(a, n, sizeof(int), compare_ints);

  int k;
  scanf("%d", &k);

  for (int i = 0; i < k; i++) {
    int leftBorder, rightBorder;
    scanf("%d %d", &leftBorder, &rightBorder);

    printf("%d ", closestRightBinarySearch(a, n, rightBorder) -
                  closestLeftBinarySearch(a, n, leftBorder) + 1);
  }

  return 0;
}