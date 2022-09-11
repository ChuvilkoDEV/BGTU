#ifndef LIBS_SORTS_H
#define LIBS_SORTS_H

#include "../algorithms/algorithms.h"
#include "../array/array_.h"

// Сортирует выбором массив a размера size по неубыванию
void selectionSort(int *a, size_t size);

// Сортировка вставками
void insertionSort(int *a, int size);

// Обменная сортировка (пузырьковая)
void bubbleSort(int *a, size_t size);

// Сортировка расческой
void combsort(int *a, size_t size);

// Сортировка подсчетом
void countSort(int *a, size_t size);

// Сортировка Шелла
void shellSort(int *a, int n);

// Сортировка слиянием
void merge(const int *a, int n,
           const int *b, int m, int *c);

#endif //LIBS_SORTS_H
