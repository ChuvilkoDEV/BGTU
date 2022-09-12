#include <stdio.h>
#define ARRAY_SIZE 6

// Выводит представление в память одного байта по адресу a
void PrintByte(const unsigned char *a) {
  for (int i = sizeof(char) * 8 - 1; i >= 0; i--)
    printf("%d", ((1 << i) & *a) != 0 ? 1 : 0);
  printf(" ");
}

// Выводит представление в памяти переменной по адресу a, размера size
void PrintVar(void *a, int size) {
  for (int i = size - 1; i >= 0; i--)
    PrintByte((unsigned char *)a + i);
  printf("\n");
}


int main() {
  // Для целочисленных типа int
  int a = 178;
  printf("int a = ");
  PrintVar(&a, sizeof(int));
  int b = -7895;
  printf("int b = ");
  PrintVar(&b, sizeof(int));
  printf("\n");


  // Для вещественных типа long double
  long double x = 56.48;
  printf("int x = ");
  PrintVar(&x, sizeof(long double));
  long double y = -126.234;
  printf("int y = ");
  PrintVar(&y, sizeof(long double));
  printf("\n");

  // Массив целых чисел
  int n[ARRAY_SIZE] = {0, 1, 2, 3, 4, 5};
  printf("int[6] n = ");
  PrintVar(&n, sizeof(int) * ARRAY_SIZE);
  int m[ARRAY_SIZE] = {253, 148, 1111, 777, 321, 999999};
  printf("int[6] m = ");
  PrintVar(&m, sizeof(int) * ARRAY_SIZE);

  return 0;
}