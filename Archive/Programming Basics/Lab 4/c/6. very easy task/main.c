#include <stdio.h>

int min(int const a, int const b) {
  return a < b ? a : b;
}

int max(int const a, int const b) {
  return a < b ? a : b;
}

int minTime(int const n, int const firstPrinterTime,
            int const secondPrinterTime) {
  int left = 0;
  int right = (n - 1) * max(firstPrinterTime, secondPrinterTime);
  while (left + 1 < right) {
    int middle = left + (right - left) / 2;
    if ((middle / firstPrinterTime + middle / secondPrinterTime) < n - 1)
      left = middle;
    else
      right = middle;
  }
  return right + min(firstPrinterTime, secondPrinterTime);
}

int main() {
  int n, firstPrinterTime, secondPrinterTime;
  scanf("%d %d %d", &n, &firstPrinterTime, &secondPrinterTime);

  printf("%d", minTime(n, firstPrinterTime, secondPrinterTime));

  return 0;
}