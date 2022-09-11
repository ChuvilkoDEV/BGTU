#include <stdio.h>

int nGeomProgression_(int const q, int a, int const n, int i) {
  i++;
  if (i == n)
    return a;
  else if (i < n)
    return nGeomProgression_(q, a * q, n, i);
}

int nGeomProgression(int const q, int a, int const n) {
  return nGeomProgression_(q, a, n, 0);
}

int main() {
  int q, a, n;
  scanf("%d %d %d", &q, &a, &n);

  printf("%d", nGeomProgression(q, a, n));

  return 0;
}
