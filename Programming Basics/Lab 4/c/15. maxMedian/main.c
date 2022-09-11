#include <stdio.h>
#include <stdlib.h>

void inputArray(int *const a, int const size) {
  for (int i = 0; i < size; i++)
    scanf("%d", &a[i]);
}

int compare_ints(const void *a, const void *b) {
  int arg1 = *(const int *) a;
  int arg2 = *(const int *) b;
  if (arg1 < arg2) return -1;
  if (arg1 > arg2) return 1;
  return 0;
}

int isMaxMedian(int const *const a, int const middle,
                int const n, int const k, int const median) {
  long long s = 0;
  for (int i = median; i < n; i++) {
    int si = middle - a[i];
    if (si < 0)
      si = 0;
    s += si;
  }
  if (s <= k)
    return 1;
  return 0;
}

long long binMaxMedian(int const *const a, int const n, int const k) {
  int median = (n - 1) / 2;
  int left = a[median] - 1;
  int right = a[median] + k + 1;

  while (left + 1 < right) {
    int middle = left + (right - left) / 2;
    int f = isMaxMedian(a, middle, n, k, median);
    if (f)
      left = middle;
    else
      right = middle;
  }
  return left;
}


int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int a[n];
  inputArray(a, n);

  qsort(a, n, sizeof(int), compare_ints);
  printf("%lld\n", binMaxMedian(a, n, k));

  return 0;
}