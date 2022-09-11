#include <stdio.h>

void floatAverage_(double last) {
  double a;
  scanf("%lf", &a);
  if (a < 0)
    return;
  floatAverage_(a);
  printf("%lf ", (last + a) / 2);
}

void floatAverage() {
  double a;
  scanf("%lf", &a);
  floatAverage_(a);
}

int main() {
  floatAverage();

  return 0;
}