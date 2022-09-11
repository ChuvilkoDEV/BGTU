#include <stdio.h>

// Ввод массива a размера size
void inputArray(int *a, size_t const size) {
  for (size_t i = 0; i < size; i++)
    scanf("%d", &a[i]);
}

// Вывод массива a размера size
void outputArray(int *a, size_t const size) {
  for (size_t i = 0; i < size; i++)
    printf("%d ", a[i]);
}

// Возвращает позицию элемента со значением x. Поиск осуществляется в массиве a
// размера size, начиная с первого элемента. После нахождения первого
// подходящего элемента — поиск прекращается.
int linearSearch(int const *const a, size_t const size, int x) {
  for (int i = 0; i < size; i++)
    if (a[i] == x)
      return i;
  return -1;
}

// Обменивает значения двух переменных a и b типа int
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// Возвращает индекс минимального элемента в массиве a размера size
size_t minIndex(int const *const a, size_t const size) {
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

// Сортирует, в порядке неубывания, члены последовательности массива a размера
// size, идущие после первого вхождения числа x
void sortAfterX(int *a, size_t const size, int const x) {
  int indexX = linearSearch(a, size, x);
  if (indexX < size - 1 && indexX != -1)
    selectionSort(&a[indexX + 1], size - indexX - 1);
}


int main() {
  int x;
  size_t n;
  scanf("%d %llud", &x, &n);
  int a[n];
  inputArray(a, n);

  sortAfterX(a, n, x);

  outputArray(a, n);

  return 0;
}