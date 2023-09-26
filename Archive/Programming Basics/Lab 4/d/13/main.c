#include <stdio.h>

void inputArray(int *const a, int const size) {
  for (int i = 0; i < size; i++)
    scanf("%d", &a[i]);
}

int binSearch_(int const *const a, int const x, int left, int right) {
  if (left + 1 >= right)
    return left;
  int middle = left + (right - left) / 2;
  if (a[middle] > x)
    right = middle;
  else
    left = middle;
  return binSearch_(a, x, left, right);
}

int binSearch(int const *const a, int n, int const x) {
  return binSearch_(a, x, -1, n);
}

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  int a[n];
  inputArray(a, n);

  int index = binSearch(a, n, x);
  printf("%d", index);
  if (index == -1 || index == n || a[index] != x)
    printf("x does not belong to set a");
  else
    printf("The x value is the %dth element in array a", index);

  return 0;
}