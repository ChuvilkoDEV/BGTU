#include <stdio.h>
#include <stdlib.h>

void PrintByte(unsigned char a) {
  unsigned int m = 128;
  unsigned char t = a;
  for (int i = 0; i < 8; i++) {
    printf("%d", (t & m) ? 1 : 0);
    t <<= 1;
  }
  printf(" ");
}

void PrintVar(void *a, unsigned int size) {
  char i;
  unsigned char *byte = (unsigned int *) a;
  for (i = size - 1; i >= 0; i--) PrintByte(byte[i]);
  byte = NULL;
  printf("\n");
}

void main() {
  // Для целочисленных типа int
  int a = 178;
  PrintVar(&a, sizeof(int));
  int b = -7895;
  PrintVar(&b, sizeof(int));

  // Для вещественных типа long double
  long double x = 56.48;
  PrintVar(&x, sizeof(long double));
  long double y = -126.234;
  PrintVar(&y, sizeof(long double));

  int n[6] = {0, 1, 2, 3, 4, 5};
  PrintVar(&n, sizeof(enum colors));
  int m[6] = {253, 148, 1111, 777, 321, 999999};
  PrintVar(&m, sizeof(enum colors));
}