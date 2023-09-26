#include "array.h"

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

void deleteByPosSaveOrder_(int *a, size_t *n, const size_t pos) {
  for (size_t i = pos + 1; i < *n; i++)
    a[i] = a[i + 1];
  (*n)--;
}

// Возвращает позицию элемента со значением x. Поиск осуществляется в массиве a
// размера size, начиная с первого элемента. После нахождения первого
// подходящего элемента — поиск прекращается.
int linearSearch(int const *a, size_t const size, int const x) {
  for (int i = 0; i < size; i++)
    if (a[i] == x)
      return i;
  return -1;
}

int binarySearch(const int *a, const int n, const int x) {
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

size_t binarySearchMoreOrEqual(const int *a, size_t n, int x) {
  if (a[0] >= x)
    return 0;
  size_t left = 0;
  size_t right = n;
  while (right - left > 1) {
    size_t middle = left + (right - left) / 2;
    if (a[middle] < x)
      left = middle;
    else
      right = middle;
  }
  return right;
}
#define SIZE_MAX 100
void insert(int *const a, size_t *const n, const size_t pos,
             const int value) {
  assert(pos <= *n);
  if (*n != 0) {
    size_t lowBound = (pos == 0) ? SIZE_MAX : pos;
    (*n)++;
    for (size_t i = *n; i != lowBound; i--)
      a[i] = a[i - 1];
    a[pos] = value;
  } else {
    (*n)++;
    a[pos] = value;
  }
}

// Возвращает индекс минимального элемента в массиве a размера size
size_t minIndex(int const *a, size_t const size) {
  size_t minIndex = 0;
  for (size_t i = 0; i < size; i++)
    if (a[i] < a[minIndex])
      minIndex = i;
  return minIndex;
}

// Возвращает увеличенный массив a рамера size, с добавленным элементом x,
// который встанет на позицию pos. При том сохраняется относительная
// последовательность других элементов.
void addElement(int *a, size_t *size, int const x, int const pos) {
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
void append(int *a, size_t *size, int x) {
  a[*size] = x;
  (*size)++;
}

// Применяет функцию f() к элементам массива a размера size
void forEach(int *a, size_t size, int (*f)(int)) {
  for (size_t i = 0; i < size; i++)
    a[i] = f(a[i]);
}

// Возвращает значение 1 (Истина), если хотя бы один элемент массива a размера
// size удовлетворяет функции-предикату f, иначе 0 (Ложь).
int any(int const *a, size_t const size, int (*f)(int)) {
  for (size_t i = 0; i < size; i++)
    if (f(a[i]))
      return 1;
  return 0;
}

// Возвращает значение 1 (Истина), если хотя бы один элемент массива a размера
// size удовлетворяет функции-предикату f, иначе 0 (Ложь).
int all(int const *a, size_t const size, int (*f)(int)) {
  for (size_t i = 0; i < size; i++)
    if (f(a[i]) == 0)
      return 0;
  return 1;
}

// Возвращает 1 (Истина), если число x не встречается в массиве a,
// под индексами [firstIndex; lastIndex), в ином случае 0 (Ложь).
bool isUniqueNumber(int *const a, int const x, int const n) {
  for (size_t i = 0; i < n; i++)
    if (a[i] == x)
      return false;
  return true;
}

// Возвращает 1 (Истина), если все значения в массиве а размера size -
// уникальны, в ином случае 0 (Ложь)
bool isUniqueNumbers(int *const a, int const size) {
  for (size_t i = 0; i < size - 1; i++)
    if (isUniqueNumber(a + i + 1, a[i], size - 1) == 0)
      return false;
  return true;
}

void forEach_(const int *source, int *dest, const size_t n, const int (*
predicate )(int)) {
  for (size_t i = 0; i < n; i++)
    dest[i] = predicate(source[i]);
}

bool isOrdered(const int *a, int n) {
  for (int i = 1; i < n; i++)
    if (a[i - 1] > a[i])
      return false;
  return true;
}

void getMinMax(const int *a, size_t size, int *min, int *max) {
  *min = a[0];
  *max = a[0];
  for (int i = 1; i < size; i++) {
    if (a[i] < *min)
      *min = a[i];
    else if (a[i] > *max)
      *max = a[i];
  }
}
