#include <stdio.h>

// Возвращает модуль вещественного числа a
double abs(const double a) {
  return a >= 0 ? a : -a;
}

int main() {
  double a;
  scanf("%lf", &a);

  printf("%lf", abs(a));

  return 0;
}

