#include "algorithms.h"

// Возвращает модуль вещественного числа типа double
double dabs(const double a) {
  return a >= 0 ? a : -a;
}

// Возвращает максимальное из двух чисел
int max2(const int a, const int b) {
  return a > b ? a : b;
}

// Обменивает значения двух переменных a и b типа float
void swapF(float *a, float *b) {
  float t = *a;
  *a = *b;
  *b = t;
}

// Обменивает значения двух переменных a и b типа float
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

