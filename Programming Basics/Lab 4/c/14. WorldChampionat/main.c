#include <stdio.h>
#include <stdlib.h>

void inputArray(int *const a, int const size) {
  for (int i = 0; i < size; i++)
    scanf("%d", &a[i]);
}

int nEntrance(int const *const a, int const n, int const cycle) {
  for (int i = 0; i < n; i++) {
    if (a[i] - cycle * n - i <= 0)
      return i + 1;
  }
  return nEntrance(a, n, cycle - 1);
}

int isFindZero(int const *const a, int const n, int const middle) {
  for (int i = 0; i < n; i++)
    if (a[i] - middle * n - i <= 0)
      return 1;
  return 0;
}

long long binEntrance(int const *const a, int const n) {
  int left = -1;
  int right = (int) 1e9 / n + 1;
  while (left + 1 < right) {
    int middle = left + (right - left) / 2;
    int f = isFindZero(a, n, middle);
    if (f)
      right = middle;
    else
      left = middle;
  }
  return nEntrance(a, n, right);
}


int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  inputArray(a, n);

  printf("%lld\n", binEntrance(a, n));

  return 0;
}