#include <stdio.h>

void maxK(int const n, int *k) {
  int s = 1, i = 1;
  while (s < n) {
    i++;
    s += i;
  }
  *k = i;
}

int isFashionNumber(int const middle, int const n, int const border) {
  long long s = middle * (middle + 1) / 2 + border * (border + 1) / 2;
  if (s < n)
    return -1;
  else if (s > n)
    return 0;
  return 1;
}

int isBinFashionNumber(int const n, int const border) {
  int left = 0;
  int right = border + 1;
  while (left + 1 < right) {
    int middle = left + (right - left) / 2;
    int f = isFashionNumber(middle, n, border);
    if (f == -1)
      left = middle;
    else if (f == 0)
      right = middle;
    else
      return 1;
  }
  return 0;
}

int findFashionNumber(int const k, int const n) {
  for (int i = k; i > 0; i--) {
    if (isBinFashionNumber(n, i))
      return 1;
  }
  return 0;
}

int main() {
  int n, k;
  scanf("%d", &n);
  maxK(n, &k);

  if (findFashionNumber(k, n))
    printf("YES");
  else
    printf("NO");

  return 0;
}