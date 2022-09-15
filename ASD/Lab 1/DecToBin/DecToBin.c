#include "DecToBin.h"

// Выводит представление в память одного байта по адресу a
void PrintByte(const unsigned char *a) {
  for (int i = sizeof(char) * 8 - 1; i >= 0; i--)
    printf("%d", ((1 << i) & *a) != 0 ? 1 : 0);
  printf(" ");
}

// Выводит представление в памяти переменной по адресу a, размера size
void PrintVar(void *a, int size) {
  for (int i = size - 1; i >= 0; i--)
    PrintByte((unsigned char *) a + i);
  printf("\n");
}

// Выводит на экран представление структуру по адресу a размером size.
// s - именование переменной для вывода строки
void Test_Print(void *a, int size, char *s) {
  printf("%s", s);
  PrintVar(a, size);
}

// Для целочисленных типа int
void Test_Integers() {
  int a = 178;
  Test_Print(&a, sizeof(int), "int a = ");
  int b = -7895;
  Test_Print(&b, sizeof(int), "int b = ");
}

// Для вещественных типа long double
void Test_LongDoubles() {
  long double x = 56.48;
  Test_Print(&x, sizeof(long double), "int x = ");
  long double y = -126.234;
  Test_Print(&y, sizeof(long double), "int y = ");
}

// Массив целых чисел
void Test_IntArray() {
  int n[ARRAY_SIZE] = {0, 1, 2, 3, 4, 5};
  Test_Print(n, sizeof(int) * ARRAY_SIZE, "int n[6] = ");
  int m[ARRAY_SIZE] = {0, 1, 2, 3, 4, 5};
  Test_Print(m, sizeof(int) * ARRAY_SIZE, "int m[6] = ");
}

void TestsDecToBin() {
  Test_Integers();
  Test_LongDoubles();
  Test_IntArray();
}