#include <stdio.h>
#include <stdlib.h>

void inputArray(int *const a, int const size) {
  for (int i = 0; i < size; i++)
    scanf("%d", &a[i]);
}

void copyArray(int const *const a, int *const b, int const size) {
  for (int i = 0; i < size; i++)
    b[i] = a[i];
}

int compare_ints(const void *a, const void *b) {
  int arg1 = *(const int *) a;
  int arg2 = *(const int *) b;
  if (arg1 < arg2) return 1;
  if (arg1 > arg2) return -1;
  return 0;
}

int isFit_(int const *const b, int const middle, int const heightFridge) {
  int s = 0;
  for (int i = 0; i < middle; i += 2) {
    s += b[i];
    if (s > heightFridge)
      return 0;
  }
  return 1;
}

int isFit(int const *const a, int *const b,
           int const middle, int const heightFridge) {
  copyArray(a, b, middle);
  qsort(b, middle, sizeof(int), compare_ints);
  return isFit_(b, middle, heightFridge);
}

int binFridge(int const *const a, int *const b,
              int const nBottle, int const heightFridge) {
  int left = -1;
  int right = nBottle;
  while (left + 1 < right) {
    int middle = left + (right - left) / 2;
    int f = isFit(a, b, middle + 1, heightFridge);
    if (f)
      left = middle;
    else
      right = middle;
  }
  return right;
}


int main() {
  int nBottle, heightFridge;
  scanf("%d %d", &nBottle, &heightFridge);
  int a[nBottle], b[nBottle];
  inputArray(a, nBottle);

  printf("%d\n", binFridge(a, b, nBottle, heightFridge));

  return 0;
}