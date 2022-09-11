#include "algorithms.h"

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void swapF(float *a, float *b) {
  float t = *a;
  *a = *b;
  *b = t;
}

int min(int a, int b) {
  return a < b ? a : b;
}

int max(int a, int b) {
  return a > b ? a : b;
}

int getMax(int const *a, int n) {
  int m = a[0];
  for (int i = 1; i < n; i++)
    m = max(m, a[i]);
  return m;
}

int getMin(int const *a, int n) {
  int m = a[0];
  for (int i = 1; i < n; i++)
    m = min(m, a[i]);
  return m;
}

bool isUnique(long long const *const a, int const n) {
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (a[i] == a[j])
        return false;
  return true;
}

long long getSum(int const *const a, int const n) {
  long long s = 0;
  for (int i = 0; i < n; i++)
    s += a[i];
  return s;
}

long long sumArray(int *a, int n) {
  long long s = 0;
  for (int i = 0; i < n; i++)
    s += a[i];
  return s;
}

int countNUnique(long long *a, int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    bool flag = false;
    for (int j = n - 1; j > i; j--)
      if (a[i] == a[j])
        flag = true;
    if (flag == false)
      count++;
  }
  return count;
}

