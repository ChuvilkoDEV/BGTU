#include <stdio.h>
#include <windows.h>

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

// Добавляет элемент в конец массива а размера size
void append(int *a, size_t *size, int x) {
  a[*size] = x;
  (*size)++;
}

// Возвращает количество элементов массива a размера size, равных x
int countElementX(int const *a, size_t const size, int const x) {
  int countElement = 0;
  for (size_t i = 0; i < size; i++)
    if (a[i] == x)
      countElement++;
  return countElement;
}

// Составляет массив b размера sizeB из уникальных элементов
// массива a размера sizeA
void sequenceUniqueNumbers(int const *const a, size_t const sizeA,
                           int *b, size_t *sizeB) {
  for (int i = 0; i < sizeA; i++) {
    if (countElementX(a, sizeA, a[i]) == 1)
      append(b, sizeB, a[i]);
  }
}

int main() {
  SetConsoleOutputCP(CP_UTF8);
  size_t sizeA, sizeB = 0;
  scanf("%llud", &sizeA);
  int a[sizeA], b[sizeA];
  inputArray(a, sizeA);

  sequenceUniqueNumbers(a, sizeA, b, &sizeB);

  if (sizeB > 0)
    outputArray(b, sizeB);
  else
    printf("Последовательность пуста");

  return 0;
}
