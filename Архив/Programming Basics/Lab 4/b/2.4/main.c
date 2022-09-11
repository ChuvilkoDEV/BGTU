#include <stdio.h>
#include <math.h>
#include <windows.h>

// Ввод массива a размера size
void inputArray(int *a, const size_t size) {
  for (size_t i = 0; i < size; i++)
    scanf("%d", &a[i]);
}

// Возвращает 1 ('Истина'), если члены массива a размера size упорядочены по
// невозрастанию или по неубыванию, в ином случае возвращает 0 ('Ложь').
int isRegularSequence(int const *const a, size_t const size) {
  int status;
  if (a[0] < a[1])
    status = 1; // Неубывание
  else if (a[0] > a[1])
    status = 2; // Невозрастание
  else
    status = 3;
  for (int i = 1; i < size - 1; i++) {
    if ((status == 1 && a[i] > a[i + 1]) || (status == 2 && a[i] < a[i + 1]))
      return 0;
    else if (status == 3 && a[i] < a[i + 1])
      status = 1;
    else if (status == 3 && a[i] > a[i + 1])
      status = 2;
  }
  return 1;
}

// Возвращает среднее геометрическое положительных элементов массива a размера
// size, если массив не упорядочен по невозрастанию или по неубыванию. В ином
// случае возвращает -1 ('Последовательность упорядочена')
double geometricAverage(int const *const a, size_t const size) {
  int p = 1, n = 0;
  for (size_t i = 0; i < size; i++)
    if (a[i] > 0) {
      p *= a[i];
      n++;
    }
  if (n == 0)
    return 0;
  double sqrtN = 1.0 / n;
  return pow(p, sqrtN);
}

int main() {
  SetConsoleOutputCP(CP_UTF8);
  size_t n;
  scanf("%llud", &n);
  int a[n];
  inputArray(a, n);

  if (isRegularSequence(a, n))
    printf("Последовательность упорядочена");
  else
    printf("%lf", geometricAverage(a, n));

  return 0;
}