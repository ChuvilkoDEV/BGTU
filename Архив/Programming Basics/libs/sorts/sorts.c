#include "sorts.h"

// Сортирует выбором массив a размера size по неубыванию
void selectionSort(int *a, size_t const size) {
  for (size_t i = 0; i < size - 1; i++)
    swap(&a[i], &a[i + minIndex_(&a[i], size - i)]);
}

// Сортировка вставками
void insertionSort(int *a, const int size) {
  for (int i = 1; i < size; i++) {
    int t = a[i];
    int j = i;
    while (j > 0 && a[j - 1] > t) {
      a[j] = a[j - 1];
      j--;
    }
    a[j] = t;
  }
}

// Обменная сортировка (пузырьковая)
void bubbleSort(int *a, size_t size) {
  for (size_t i = 0; i < size - 1; i++)
    for (size_t j = size - 1; j > i; j--)
      if (a[j - 1] > a[j])
        swap(&a[j - 1], &a[j]);
}

// Сортировка расческой
void combsort(int *a, const size_t size) {
  size_t step = size;
  int swapped = 1;
  while (step > 1 || swapped) {
    if (step > 1)
      step /= 1.24733;
    swapped = 0;
    for (size_t i = 0, j = i + step; j < size; ++i, ++j)
      if (a[i] > a[j]) {
        swap(&a[i], &a[j]);
        swapped = 1;
      }
  }
}

// Сортировка подсчетом
void countSort(int *a, const size_t size) {
  int min, max;
  getMinMax_(a, size, &min, &max);
  int k = max - min + 1;
  int *b = (int *) calloc(k, sizeof(int));

  for (int i = 0; i < size; i++)
    b[a[i] - min]++;

  int ind = 0;
  for (int i = 0; i < k; i++) {
    int x = b[i];
    for (int j = 0; j < x; j++)
      a[ind++] = min + i;
  }

  free(b);
}

// Сортировка Шелла
void shellSort(int *a, int n) {
  for (int i = n / 2; i > 0; i /= 2)
    for (int j = i; j < n; ++j)
      for (int k = j - i; k >= 0 && a[k] > a[k + i]; k -= i) {
        int t = a[k];
        a[k] = a[k + i];
        a[k + i] = t;
      }
}

// Сортировка слиянием
void merge(const int *a, const int n,
           const int *b, const int m, int *c) {
  int i = 0, j = 0;
  while (i < n || j < m) {
    if (j == m || i < n && a[i] < b[j]) {
      c[i + j] = a[i];
      i++;
    } else {
      c[i + j] = b[j];
      j++;
    }
  }
}