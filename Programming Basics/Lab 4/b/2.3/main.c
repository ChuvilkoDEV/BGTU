#include <stdio.h>

// Ввод массива a размера size
void inputArray(int *a, const size_t size) {
  for (size_t i = 0; i < size; i++)
    scanf("%d", &a[i]);
}

// Вывод массива a размера size
void outputArray(int *a, const size_t size) {
  for (size_t i = 0; i < size; i++)
    printf("%d ", a[i]);
}

// Обменивает значения двух переменных a и b типа int
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// Обменивает значения двух переменных a и b типа size_t
void swapIndex(size_t *a, size_t *b) {
  size_t t = *a;
  *a = *b;
  *b = t;
}

// Возвращает индекс минимального элемента в массиве a размера size
size_t minIndex(int const *a, size_t const size) {
  size_t minIndex = 0;
  for (size_t i = 0; i < size; i++)
    if (a[i] < a[minIndex])
      minIndex = i;
  return minIndex;
}

// Сортирует выбором массив a размера size по неубыванию
void selectionSort(int *a, size_t const size) {
  for (size_t i = 0; i < size - 1; i++) {
    swap(&a[i], &a[i + minIndex(&a[i], size - i)]);
  }
}

// Осуществляет поиск минимального и максимального значения в массиве a размера
// size. В случае, если такие значения удалось найти - изменяет значение
// minIndex на порядковый номер последнего минимального значения, а maxIndex
// на порядковый номер максимального значения, иначе оставляет без изменения.
void findMinMaxIndex(int const *const a, size_t size, size_t *minIndex,
                     size_t *maxIndex) {
  for (size_t i = 1; i < size; i++) {
    if (a[i] <= a[*minIndex])
      *minIndex = i;
    else if (a[i] > a[*maxIndex])
      *maxIndex = i;
  }
}

// Сортирует числа массива a размера size, находящиеся между первым вхождением
// максимального значения и последним вхождением минимального.
void sortDescendingBetweenMinMax(int *a, size_t size) {
  size_t minIndex = 0, maxIndex = 0;
  findMinMaxIndex(a, size, &minIndex, &maxIndex);
  if (minIndex < maxIndex)
    swapIndex(&minIndex, &maxIndex);
  selectionSort(&a[maxIndex + 1], minIndex - 1);
}


int main() {
  size_t n;
  scanf("%llud", &n);
  int a[n];
  inputArray(a, n);

  sortDescendingBetweenMinMax(a, n);

  outputArray(a, n);

  return 0;
}