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

// Обменивает значения двух переменных a и b типа int
void swap(int *a, int *b) {
  int t = *a;
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

// Возвращает 1 (Истина), если число x не встречается в массиве a,
// в ином случае 0 (Ложь).
int isUniqueNumber(int const *const a, size_t const size, int const x) {
  for (size_t i = 0; i < size; i++)
    if (a[i] == x)
      return 0;
  return 1;
}

// Возвращает 1 (Истина), если все значения в массиве а размера size -
// уникальны, в ином случае 0 (Ложь)
int isUniqueNumbers(int const *a, size_t const size) {
  if (size == 1)
    return 0;
  for (size_t i = 0; i < size - 1; i++)
    if (isUniqueNumber(&a[i] + 1, size - i, a[i]))
      return 0;
  return 1;
}

// Упорядочивает массив a размера size по убыванию, если упорядочить по
// убыванию невозможно (есть элементы, значения которых равны), то оставляет
// массив без изменения
void sortDescending(int *a, size_t const size) {
  if (isUniqueNumbers(a, size)) {
    selectionSort(a, size);
  }
}

int main() {
  size_t size;
  scanf("%llud", &size);
  int a[size];
  inputArray(a, size);

  sortDescending(a, size);

  outputArray(a, size);

  return 0;
}
