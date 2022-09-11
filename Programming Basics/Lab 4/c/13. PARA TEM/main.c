#include <stdio.h>
#include <stdlib.h>

void inputArray(int *const a, int const size) {
  for (int i = 0; i < size; i++)
    scanf("%d", &a[i]);
}

void getInterest(int const *const a, int const  *const b,
                 int *const c, int const size) {
  for (int i = 0; i < size; i++)
    c[i] = a[i] - b[i];
}

int compare_ints(const void *a, const void *b) {
  int arg1 = *(const int *) a;
  int arg2 = *(const int *) b;
  if (arg1 < arg2) return 1;
  if (arg1 > arg2) return -1;
  return 0;
}

int isInterest(int const *const c, int const middle, int const i) {
  if (c[i] + c[middle] <= 0)
    return 0;
  return 1;
}

int binInterest_(int const *const c, int const n, int const i) {
  int left = i;
  int right = n;
  while (left + 1 < right) {
    int middle = left + (right - left) / 2;
    int f = isInterest(c, middle, i);
    if (f)
      left = middle;
    else
      right = middle;
  }
  return left - i;
}

long long binInterest(int const * const c, int const n) {
  long long s = 0;
  for (int i = 0; i < n - 1; i++) {
    int interest = binInterest_(c, n, i);
    if (interest == 0)
      return s;
    s += interest;
  }
  return s;
}


int main() {
  int n;
  scanf("%d", &n);
  int a[n], b[n], c[n];
  inputArray(a, n);
  inputArray(b, n);

  getInterest(a, b, c, n);
  qsort(c, n, sizeof(int), compare_ints);
  printf("%lld\n", binInterest(c, n));

  return 0;
}