#include <stdio.h>
#include <math.h>

// Ввод массива a размера size
void inputArray(int *a, size_t const size) {
  for (size_t i = 0; i < size; i++)
    scanf("%d", &a[i]);
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

// Возвращает количество отрицательных элементов в массиве а рамера size.
int countNegativeElement(int const *a, size_t const size) {
  int countNegativeElement = 0;
  for (size_t i = 0; i < size; i++)
    if (a[i] < 0)
      countNegativeElement++;
  return countNegativeElement;
}

// Применяет функцию f() к элементам массива a размера size
void absForEach(int *a, size_t const size) {
  for (size_t i = 0; i < size; i++)
    a[i] = abs(a[i]);
}

// Возвращает знаменатель геометрической прогрессии, где a и b соседние числа
// последовательности. Если целочисленный знаменатель найти
// не получается — возвращает 0.
int denominatorGeomProgression(int const a, int const b) {
  if (b != 0 && a != 0 && a % b == 0)
    return a / b;
  return 0;
}

// Возвращает 1, если элементы отсортированного массива представляют собой
// геометрическую прогрессию.
int isGeomProgression_(int const *a, size_t const size) {
  int q = denominatorGeomProgression(a[1], a[0]);
  for (size_t i = 1; i < size - 1 && q != 0; i++)
    if (q != denominatorGeomProgression(a[i + 1], a[i]))
      return 0;
  return q != 0;
}

// Возвращает 1, если переставив элементы массива a размера size, можно
// получить геометрическую прогрессию (для целочисленных)
int isGeomProgression(int *a, size_t const size) {
  int count = countNegativeElement(a, size);
  if (size < 2 || (abs(2 * count - (int) size) > 1 && count != 0))
    return 0;
  absForEach(a, size);
  selectionSort(a, size);
  return isGeomProgression_(a, size);
}

int main() {
  size_t size;
  scanf("%llud", &size);
  int a[size];
  inputArray(a, size);

  if (isGeomProgression(a, size))
    printf("Yes");
  else
    printf("No");

  return 0;
}