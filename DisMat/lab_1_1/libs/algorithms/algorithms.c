#include "algorithms.h"

// Обменивает значения двух переменных a и b типа float
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// Возвращает максимальное из двух чисел
int max2_int(const int a, const int b) {
  return a > b ? a : b;
}

// Возвращает максимальное из двух чисел
size_t max2_size_t(const size_t a, const size_t b) {
  return a > b ? a : b;
}