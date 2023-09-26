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

// Возвращает наибольшее число из двух введенных целочисленных
// переменных a и b типа size_t
size_t maxSize(size_t const a, size_t const b) {
  return a > b ? a : b;
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

// Добавляет элемент в конец массива а размера size
void append(int *a, size_t *size, int x) {
  a[*size] = x;
  (*size)++;
}

// Изменяет порядок элементов массива a размера size на обратный
void reverse(int *a, size_t const size) {
  for (size_t firstIndex = 0, lastIndex = size - 1; firstIndex < lastIndex;
       firstIndex++, lastIndex--)
    swap(&a[firstIndex], &a[lastIndex]);
}

// Возвращает 1 (Истина), если число x не встречается в массиве a размера size,
// в ином случае 0 (Ложь).
int isUniqueNumber(int const *const a, size_t const size, const int x) {
  for (size_t i = 0; i < size; i++)
    if (a[i] == x)
      return 0;
  return 1;
}

// Отбирает из массива a размера sizeA и массива b размера sizeB уникальные
// элементы, которые встречаются в массиве a, но не встречается в массиве b,
// и сохраняет их в массив c размера sizeC в порядке невозрастания
void sortUniqueNumbers(int *const a, size_t const sizeA,
                       int *const b, size_t const sizeB,
                       int *const c, size_t *sizeC) {
  selectionSort(a, sizeA);
  selectionSort(b, sizeB);
  for (size_t i = 0; i < sizeA; i++)
    if (isUniqueNumber(b, sizeB, a[i]))
      append(c, sizeC, a[i]);
  reverse(c, *sizeC);
}


int main() {
  // Ввод массива a
  size_t sizeA;
  scanf("%llud", &sizeA);
  int a[sizeA];
  inputArray(a, sizeA);
  // Ввод массива b
  size_t sizeB;
  scanf("%llud", &sizeB);
  int b[sizeB];
  inputArray(b, sizeB);
  // Выделение места под массив c
  size_t sizeC = 0;
  int c[sizeA];

  sortUniqueNumbers(a, sizeA, b, sizeB, c, &sizeC);

  outputArray(c, sizeC);

  return 0;
}