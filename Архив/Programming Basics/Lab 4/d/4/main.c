#include <stdio.h>

void inputArray(int *const a, int const size) {
  for (int i = 0; i < size; i++)
    scanf("%d", &a[i]);
}

int isNonDecreasing(int const *a, int n) {
  n--;
  if (n == 1 && a[0] <= a[1])
    return 1;
  else if (a[n-1] <= a[n])
    return isNonDecreasing(a, n);
  return 0;
}

int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  inputArray(a, n);

  printf("%d", isNonDecreasing(a, n));

  return 0;
}