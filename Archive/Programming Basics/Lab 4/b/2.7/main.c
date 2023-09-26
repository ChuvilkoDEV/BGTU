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

// Возвращает количество отрицательных элементов в массиве а рамера size.
int countNegativeElement(const int *a, const size_t size) {
  int countNegativeElement = 0;
  for (size_t i = 0; i < size; i++)
    if (a[i] < 0)
      countNegativeElement++;
  return countNegativeElement;
}

// Обменивает значения двух переменных a и b типа int
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// Изменяет порядок элементов массива a размера size на обратный
void reverse(int *a, const size_t size) {
  for (size_t firstIndex = 0, lastIndex = size - 1; firstIndex < lastIndex;
       firstIndex++, lastIndex--)
    swap(&a[firstIndex], &a[lastIndex]);
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

// Сортирует массив a размера size таким образом, что сначала идут
// отрицательные элементы в порядке невозрастания, а потом положительные
// элементы в порядке неубывания
void sortNegativeDecreasePositiveIncrease(int *a, size_t const size) {
  selectionSort(a, size);
  size_t lastNegativeIndex = countNegativeElement(a, size);
  reverse(a, lastNegativeIndex);
}

int main() {
  size_t n;
  scanf("%llud", &n);
  int a[n];
  inputArray(a, n);

  sortNegativeDecreasePositiveIncrease(a, n);

  outputArray(a, n);

  return 0;
}
