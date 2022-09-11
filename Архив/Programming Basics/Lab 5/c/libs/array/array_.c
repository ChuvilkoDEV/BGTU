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
    if (isUniqueNumber(a, a[i], i + 1, size) == 0)
      return false;
  return true;
}

void forEach_(const int *source, int *dest, const size_t n, const int (*
predicate )(int)) {
  for (size_t i = 0; i < n; i++)
    dest[i] = predicate(source[i]);
}

bool isOrdered_(const int *a, int n) {
  for (int i = 1; i < n; i++)
    if (a[i - 1] > a[i])
      return false;
  return true;
}

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

void generateRandomArray(int *a, size_t n) {
  srand(time(0));
  for (int i = 0; i < n; ++i)
    a[i] = rand() % 100000;
}

void generateOrderedArray(int *a, size_t n) {
  for (int i = 0; i < n; ++i)
    a[i] = i;
}

void generateOrderedBackwards(int *a, size_t n) {
  for (int i = 0; i < n; ++i)
    a[i] = n - i;
}