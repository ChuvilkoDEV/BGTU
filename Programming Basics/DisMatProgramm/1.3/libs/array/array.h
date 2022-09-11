#ifndef INC_1_3_ARRAY_H
#define INC_1_3_ARRAY_H

#include <iostream>
#include <cassert>

int compare_ints(const void *a, const void *b);

void inputArray_(int *a, size_t n);

void outputArray_(int *a, size_t n);

void append_(int *a, size_t *n, int value);

void insert_(int *a, size_t *n, size_t pos, int value);

void deleteByPosSaveOrder_(int *a, size_t *n, size_t pos);

void deleteByPosUnsaveOrder_(int *a, size_t *n, size_t pos);

size_t linearSearch_(const int *a, size_t n, int x);

int any_(const int *a, size_t n, int (*predicate)(int));

int all_(const int *a, size_t n, int (*predicate)(int));

int countIf_(int *a, size_t n, int (*predicate)(int));

void deleteIf_(int *a, size_t *n, int (*deletePredicate)(int));

void forEach_(int *source, int *dest,
              size_t n, int (*predicate)(int));

size_t binarySearch_(const int *a, size_t n, int x);

size_t binarySearchMoreOrEqual_(const int *a, size_t n, int x);


#endif //INC_1_3_ARRAY_H
