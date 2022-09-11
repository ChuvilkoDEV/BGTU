#include <stdio.h>

void inputArray(int *const a, int const size) {
  for (int i = 0; i < size; i++)
    scanf("%d", &a[i]);
}

void outputArray(int *const a, int const size) {
  for (int i = 0; i < size; i++)
    printf("%d", a[i]);
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int min(int const *const a, int n, int *maxIndex) {
  n--;
  if (n < 0)
    return *maxIndex;
  if (a[n] > a[*maxIndex])
    *maxIndex = n;
  return min(a, n, maxIndex);
}

void selectionSort(int *const a, int n) {
  n--;
  if (n < 0)
    return;
  int maxIndex = n;
  swap(&a[min(a, n, &maxIndex)], &a[maxIndex]);
  selectionSort(a, n);
}

int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  inputArray(a, n);

  selectionSort(a, n);

  outputArray(a, n);

  return 0;
}
