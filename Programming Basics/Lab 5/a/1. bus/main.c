#include <stdio.h>

void inputArray_(int *const a, const size_t n) {
  for (size_t i = 0; i < n; i++)
    scanf("%d", &a[i]);
}

size_t linearSearch_(const int *a, const size_t n, int x) {
  for (size_t i = 0; i < n; i++)
    if (a[i] == x)
      return i;
  return n;
}

int isUniqueNumber(int const *const a, size_t const size, int const value) {
  for (size_t i = 0; i < size; i++)
    if (a[i] == value)
      return 0;
  return 1;
}

void deleteUnequalBusRace(int *a, size_t *n1, int *b, size_t n2) {
  for (size_t i = 0; i < *n1; i++) {
    size_t index = linearSearch_(a, *n1, b[i]);
    if (index == *n1)

  }
}

int main() {
  size_t t;
  scanf("%zd", &t);

  size_t n1;
  scanf("%zd", &n1);
  int a[n1];
  inputArray_(a, n1);

  for (int t1 = 0; t1 < t - 1; t1++) {
    size_t n2;
    scanf("%zd", &n2);
    int b[n2];
    inputArray_(b, n2);

    deleteUnequalBusRace(a, &n1, b, n2);
  }

  return 0;
}
