#include <stdio.h>

void inputArray(int *const a, int const size) {
  for (int i = 0; i < size; i++)
    scanf("%d", &a[i]);
}

int isNegative(int const a) {
  return a < 0 ? 1 : 0;
}

int any(int const *const a, int const n, int (*f)(int)) {
  if (n && f(a[n - 1]))
    return any(a, n - 1, *f);
  return n != 0;
}

int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  inputArray(a, n);

  printf("%d", any(a, n, isNegative));

  return 0;
}