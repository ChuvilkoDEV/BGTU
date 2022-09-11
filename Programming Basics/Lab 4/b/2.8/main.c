#include <stdio.h>
#include <windows.h>

// Ввод массива a размера size
void inputArray(int *a, size_t const size) {
  for (size_t i = 0; i < size; i++)
    scanf("%d", &a[i]);
}

// Возвращает позицию элемента со значением x. Поиск осуществляется в массиве a
// размера size, начиная с первого элемента. После нахождения первого
// подходящего элемента — поиск прекращается.
int linearSearch(const int *const a, const size_t size, int x) {
  for (int i = 0; i < size; i++)
    if (a[i] == x)
      return i;
  return -1;
}

// Определяет индексы элементов массива a размера size, значения которых
// наиболее близки к значению x. Где minIndex - индекс элемента, значение
// которого меньше x. maxIndex - индекс элемента, значение которого больше x.
// В случае, когда x < минимального значения массива a - minIndex принимает
// значение -1, а когда x > максимального значения массива а - maxIndex
// остается без изменений.
void closestToX(int const *const a, size_t const size, int const x,
                int *minIndex, int *maxIndex) {
  for (int i = 0; i < size; i++) {
    if (*minIndex == -1 && a[i] < x ||
        *minIndex != -1 && a[i] < x && a[i] > a[*minIndex])
      *minIndex = i;
    else if (*maxIndex == -2 && a[i] > x ||
             *maxIndex != -2 && a[i] > x && a[i] < a[*maxIndex])
      *maxIndex = i;
  }
}

// Выводит: "-inf", если х равен -1, "+inf, если х равен -2 и x-овый элемента
// массива a в остальных случаях.
void printIf(int const *const a, int const x) {
  if (x == -1)
    printf("-inf ");
  else if (x == -2)
    printf("+inf ");
  else
    printf("%d ", a[x]);
}

int main() {
  SetConsoleOutputCP(CP_UTF8);
  int x;
  size_t n;
  scanf("%d %llud", &x, &n);
  int a[n];
  inputArray(a, n);

  if (linearSearch(a, n, x) != -1)
    printf("x - Элемент последовательности");
  else {
    int minIndex = -1, maxIndex = -2;
    closestToX(a, n, x, &minIndex, &maxIndex);
    printIf(a, minIndex);
    printIf(a, maxIndex);
  }

  return 0;
}