#include <stdio.h>
#include <math.h>

#define EPS 0.00001

// Возвращает модуль вещественного числа a
double dabs(const double a) {
  return a >= 0 ? a : -a;
}

// Выводит корни квадратного уравнения, где a, b, c – коэффициенты.
void solveX2(const int a, const int b, const int c) {
  if (a == 0)
    printf("not quadratic");
  double D = pow(b, 2) - 4 * a * c;
  if (D < -EPS)
    printf("No solutions");
  else if (dabs(D) <= EPS)
    printf("x = %d", -b / (2 * a));
  else {
    double x1 = (-b + sqrt(D)) / (2 * a);
    double x2 = (-b - sqrt(D)) / (2 * a);
    printf("x1 = %lf\nx2 = %lf", x1, x2);
  }
}

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);

  solveX2(a, b, c);

  return 0;
}
