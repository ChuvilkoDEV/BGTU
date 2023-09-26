#include "array_.h"

// Ввод массива a размера size
void inputArray_(int *a, size_t const size) {
  for (size_t i = 0; i < size; i++)
    scanf("%d", &a[i]);
}

// Вывод массива a размера size
void outputArray_(int *a, size_t const size) {
  for (size_t i = 0; i < size; i++)
    printf("%d ", a[i]);
}

// Возвращает позицию элемента со значением x. Поиск осуществляется в массиве a
// размера size, начиная с первого элемента. После нахождения первого
// подходящего элемента — поиск прекращается.
int linearSearch_(int const *a, size_t const size, int const x) {
  for (int i = 0; i < size; i++)
    if (a[i] == x)
      return i;
  return -1;
}

// Осуществляет бинарный поиск в массиве a размера size, элемент x
int binarySearch_(const int *a, const int n, const int x) {
  int left = -1;
  int right = n;
  while (left + 1 < right) {
    int middle = left + (right - left) / 2;
    if (a[middle] > x)
      right = middle;
    else if (a[middle] < x)
      left = middle;
    else
      return middle;
  }
  return -1;
}

// Возвращает индекс минимального элемента в массиве a размера size
size_t minIndex_(int const *a, size_t const size) {
  size_t minIndex = 0;
  for (size_t i = 0; i < size; i++)
    if (a[i] < a[minIndex])
      minIndex = i;
  return minIndex;
}

// Возвращает увеличенный массив a рамера size, с добавленным элементом x,
// который встанет на позицию pos. При том сохраняется относительная
// последовательность других элементов.
void addElement_(int *a, size_t *size, int const x, int const pos) {
  int last;
  for (size_t i = 0; i <= *size; i++)
    if (i == pos) {
      last = a[i];
      a[i] = x;
    } else if (i > pos) {
      int tmp = a[i];
      a[i] = last;
      last = tmp;
    }
  (*size)++;
}

// Добавляет элемент в конец массива а размера size
void append_(int *a, size_t *size, int x) {
  a[*size] = x;
  (*size)++;
}

// Возвращает значение 1 (Истина), если хотя бы один элемент массива a размера
// size удовлетворяет функции-предикату f, иначе 0 (Ложь).
int any_(int const *a, size_t const size, int (*f)(int)) {
  for (size_t i = 0; i < size; i++)
    if (f(a[i]))
      return 1;
  return 0;
}

// Возвращает значение 1 (Истина), если хотя бы один элемент массива a размера
// size удовлетворяет функции-предикату f, иначе 0 (Ложь).
int all_(int const *a, size_t const size, int (*f)(int)) {
  for (size_t i = 0; i < size; i++)
    if (f(a[i]) == 0)
      return 0;
  return 1;
}

// Возвращает 1 (Истина), если число x не встречается в массиве a,
// под индексами [firstIndex; lastIndex), в ином случае 0 (Ложь).
bool isUniqueNumber_(int *const a, const int x, const size_t firstIndex,
                     const size_t lastIndex) {
  for (size_t i = firstIndex; i < lastIndex; i++)
    if (a[firstIndex] == x)
      return false;
  return true;
}

// Возвращает 1 (Истина), если все значения в массиве а размера size -
// уникальны, в ином случае 0 (Ложь)
bool isUniqueNumbers_(int *const a, const size_t size) {
  for (size_t i = 0; i < size - 1; i++)
    if (isUniqueNumber_(a, a[i], i + 1, size) == 0)
      return false;
  return true;
}

// Применяет функцию предикат для каждого элемента массива
void forEach_(const int *source, int *dest, const size_t n, const int (*
predicate )(int)) {
  for (size_t i = 0; i < n; i++)
    dest[i] = predicate(source[i]);
}

// Возвращает true, если массив отсортирован оп неубыванию, false в ином случае
bool isOrdered_(const int *a, int n) {
  for (int i = 1; i < n; i++)
    if (a[i - 1] > a[i])
      return false;
  return true;
}

// Осуществляет поиск в массиве a размера size минимального и максимального
// элемента, и записывает их в переменный min и max соответственно
void getMinMax_(const int *a, size_t size, int *min, int *max) {
  *min = a[0];
  *max = a[0];
  for (int i = 1; i < size; i++) {
    if (a[i] < *min)
      *min = a[i];
    else if (a[i] > *max)
      *max = a[i];
  }
}

// Генерирует массив из случайных элементов
void generateRandomArray(int *a, size_t n) {
  srand(time(0));
  for (int i = 0; i < n; ++i)
    a[i] = rand() % 100000;
}

// Генерирует сортированный по неубыванию массив
void generateOrderedArray(int *a, size_t n) {
  for (int i = 0; i < n; ++i)
    a[i] = i;
}

// Генерирует сортированный по невозрастанию массив
void generateOrderedBackwards(int *a, size_t n) {
  for (int i = 0; i < n; ++i)
    a[i] = n - i;
}