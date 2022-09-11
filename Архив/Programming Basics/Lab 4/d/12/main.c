#include <stdio.h>

void inputArray(int *const a, int const size) {
  for (int i = 0; i < size; i++)
    scanf("%d", &a[i]);
}

int isNegative(int const a) {
  return a < 0 ? 1 : 0;
}

int all(int const *const a, int const n, int (*f)(int)) {
  if (n && f(a[n - 1]))
    return all(a, n - 1, *f);
  return n == 0;
}

int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  inputArray(a, n);

  printf("%d", all(a, n));

  return 0;
}