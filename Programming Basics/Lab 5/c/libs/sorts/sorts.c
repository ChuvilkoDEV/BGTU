#include "sorts.h"

// Сортирует выбором массив a размера size по неубыванию
void selectionSort(int *a, size_t const size) {
  for (size_t i = 0; i < size - 1; i++) {
    swap(&a[i], &a[i + minIndex(&a[i], size - i)]);
  }
}

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

void countSort(int *a, const size_t size) {
  int min, max;
  getMinMax(a, size, &min, &max);
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
void mergeSort(const int *a, const int n,
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

typedef struct number {
  int number;
  int key;
} number;

#define BIT_STEP 8
#define NUMBER_STEP 255

void digitSort(int *a, size_t n) {
  number numbers[n];
  size_t countKeys[NUMBER_STEP + 1];
  for (int i = 0; i < NUMBER_STEP + 1; ++i)
    countKeys[i] = 0;

  for (int i = 0; i < sizeof(int) * 8; i += BIT_STEP) {
    int scanBits = NUMBER_STEP;
    for (int j = 0; j < n; ++j) {
      int key = (a[j] >> i) & scanBits;
      numbers[j].number = a[j];
      numbers[j].key = key;
      countKeys[key]++;
    }

    size_t keyIndex[NUMBER_STEP + 1];
    keyIndex[0] = 0;

    for (int j = 1; j < NUMBER_STEP + 1; ++j)
      keyIndex[j] = keyIndex[j - 1] + countKeys[j - 1];

    for (int j = 0; j < n; ++j) {
      size_t iWrite = keyIndex[numbers[j].key]++;
      a[iWrite] = numbers[j].number;
    }
//        outputArray_(a, n);

    for (int j = 0; j < NUMBER_STEP + 1; ++j)
      countKeys[j] = 0;
  }
}

void insertHeap(int *a, size_t *size, int x) {
  a[(*size)++] = x;
  size_t childIndex = *size - 1;
  size_t parentIndex = (childIndex - 1) / 2;
  while (a[childIndex] > a[parentIndex] && childIndex != 0) {
    swap(&a[childIndex], &a[parentIndex]);
    childIndex = parentIndex;
    parentIndex = (childIndex - 1) / 2;
  }
}

bool hasLeftChild(size_t parentIndex, size_t size) {
  return 2 * parentIndex + 1 < size;
}

bool hasRightChild(size_t parentIndex, size_t size) {
  return 2 * parentIndex + 2 < size;
}

size_t getLeftChildIndex(size_t parentIndex) {
  return 2 * parentIndex + 1;
}

size_t getMinChildIndex(const int *a, size_t size, size_t parentIndex) {
  size_t minChildIndex = getLeftChildIndex(parentIndex);
  size_t rightChildIndex = minChildIndex + 1;
  if (hasRightChild(parentIndex, size))
    if (a[rightChildIndex] > a[minChildIndex])
      minChildIndex = rightChildIndex;
  return minChildIndex;
}

void removeMinHeap(int *a, size_t *size) {
  *size -= 1;
  swap(&a[0], &a[*size]);
  size_t parentIndex = 0;
  while (hasLeftChild(parentIndex, *size)) {
    size_t minChildIndex = getMinChildIndex(a, *size, parentIndex);
    if (a[minChildIndex] > a[parentIndex]) {
      swap(&a[minChildIndex], &a[parentIndex]);
      parentIndex = minChildIndex;
    } else
      break;
  }
}

void heapSort(int *a, size_t size) {
  size_t heapSize = 0;
  while (heapSize != size)
    insertHeap(a, &heapSize, a[heapSize]);
  while (heapSize)
    removeMinHeap(a, &heapSize);
}