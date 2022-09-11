#include <stdio.h>

void inputArray(int *const a, int const size) {
  for (int i = 0; i < size; i++)
    scanf("%d", &a[i]);
}

long long maxSum(int const *const a, int n) {
  long long s = 0;
  for (int i = 0; i < n; i++)
    s += a[i];
  return s;
}

long long max2(long long const a, long long const b) {
  return a > b ? a : b;
}

int maxInArray(int const *const a, int n) {
  int max = a[0];
  for (int i = 1; i < n; i++)
    if (a[i] > max)
      max = a[i];
  return max;
}

int isMaxMinSum(int const *const a, int const n, int const k,
                long long const middle) {
  long long localS = 0, maxS = 0;
  int countSubarray = 0;
  for (int i = 0; i < n; i++) {
    long long tmpLocalS = localS + a[i];
    if (tmpLocalS > middle) {
      countSubarray++;
      maxS = max2(localS, maxS);
      localS = a[i];
    } else if (tmpLocalS == middle) {
      localS = 0;
      countSubarray++;
      maxS = max2(tmpLocalS, maxS);
    } else {
      localS = tmpLocalS;
    }
  }
  if (localS != 0)
    countSubarray++;
  if (countSubarray == k)
    return 1;
  else if (countSubarray < k)
    return 0;
  else
    return -1;
}

long long binMaxMedian(int const *const a, int const n, int const k,
                       long long const maxS, int const max) {
  long long left = max - 1;
  long long right = maxS + 1;
  while (left + 1 < right) {
    long long middle = left + (right - left) / 2;
    int f = isMaxMinSum(a, n, k, middle);
    if (f != -1)
      right = middle;
    else
      left = middle;
  }
  return right;
}


int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int a[n];
  inputArray(a, n);

  long long maxS = maxSum(a, n);
  int max = maxInArray(a, n);

  printf("%lld\n", binMaxMedian(a, n, k, maxS, max));

  return 0;
}