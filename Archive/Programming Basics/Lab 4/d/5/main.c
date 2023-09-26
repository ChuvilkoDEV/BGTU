#include <stdio.h>

void inputArray(int *const a, int const size) {
  for (int i = 0; i < size; i++)
    scanf("%d", &a[i]);
}

int isFindNumberX(int const *const a, int n, int const x) {
  n--;
  if (a[n] == x)
    return 1;
  else if (a[n] < x)
    return isFindNumberX(a, n, x);
  return 0;
}

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  int a[n];
  inputArray(a, n);

  printf("%d", isFindNumberX(a, n, x));

  return 0;
}
