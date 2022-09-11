#ifndef LIBS_ALGORITHMS_H
#define LIBS_ALGORITHMS_H

#include <stdio.h>
#include <math.h>

#define EPS 0.00001

// Возвращает модуль вещественного числа типа double
double dabs(double a);

// Возвращает максимальное из двух чисел
int max2(int a, int b);

// Обменивает значения двух переменных a и b типа float
void swapF(float *a, float *b);

// Обменивает значения двух переменных a и b типа int
void swap(int *a, int *b);

#endif //LIBS_ALGORITHMS_H
