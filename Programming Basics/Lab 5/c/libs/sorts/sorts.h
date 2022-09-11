#ifndef LAB_5C_SORTS_H
#define LAB_5C_SORTS_H

#include "../algorithms/algorithms.h"
#include "../array/array_.h"

// Сортирует выбором массив a размера size по неубыванию
void selectionSort(int *a, size_t size);

void insertionSort(int *a, int size);

// Обменная сортировка (пузырьковая)
void bubbleSort(int *a, size_t size);

// Сортировка расческой
void combsort(int *a, size_t size);

void countSort(int *a, size_t size);

void shellSort(int *a, int n);

void mergeSort(const int *a, int n,
           const int *b, int m, int *c);

void digitSort(int *a, size_t n);

void heapSort(int *a, size_t size);

#endif //LAB_5C_SORTS_H
