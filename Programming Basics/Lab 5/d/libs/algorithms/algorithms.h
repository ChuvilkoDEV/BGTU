#ifndef INC_5D_ALGORITHMS_H
#define INC_5D_ALGORITHMS_H

#include <stdbool.h>

void swap(int *a, int *b);

void swapF(float *a, float *b);

int min(int a, int b);

int max(int a, int b);

int getMax(int const *a, int n);

int getMin(int const *a, int n);

bool isUnique(long long const *a, int n);

long long getSum(int const *a, int n);

long long sumArray(int *a, int n);

int countNUnique(long long *a, int n);

#endif //INC_5D_ALGORITHMS_H
