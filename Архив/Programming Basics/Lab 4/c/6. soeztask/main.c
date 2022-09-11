#include <stdio.h>

#define EPS 0.000001

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int min(int const a, int const b) {
  return a < b ? a : b;
}

int max(int const a, int const b) {
  return a > b ? a : b;
}

int isHaveTime(int n, int const firstPrinterTime,
               int const secondPrinterTime, int const hypotheticallyTime) {
  int time = firstPrinterTime;
  n--;
  time += (firstPrinterTime * secondPrinterTime) *
          (n / (firstPrinterTime + secondPrinterTime));
  n %= firstPrinterTime + secondPrinterTime;
  int firstPrinter = 0, secondPrinter = 0;
  for (n; n > 0; n--) {
    if (firstPrinter <= secondPrinter)
      firstPrinter += firstPrinterTime;
    else
      secondPrinter += secondPrinterTime;
  }
  if (hypotheticallyTime < (time + max(firstPrinter, secondPrinter)))
    return 0;
  return 1;
}

int minTime(int const n, int const firstPrinterTime,
            int const secondPrinterTime) {
  int left = 1;
  int right = (int) 1e9;
  while (left + 1 < right) {
    int middle = (left + right) / 2;
    if (isHaveTime(n, firstPrinterTime, secondPrinterTime, middle))
      right = middle;
    else
      left = middle;
  }
  return right;
}

int main() {
  int n, firstPrinter, secondPrinter;
  scanf("%d %d %d", &n, &firstPrinter, &secondPrinter);

  if (secondPrinter < firstPrinter)
    swap(&secondPrinter, &firstPrinter);

  printf("%d", minTime(n, firstPrinter, secondPrinter));

  return 0;
}