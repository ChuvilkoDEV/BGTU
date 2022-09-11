#include <stdio.h>

// Возвращает наибольшее число из двух введенных целочисленных
// переменных a и b
int max2(const int a, const int b) {
  if (a >= b)
    return a;
  else
    return b;
}

// Возвращает наибольшее значение из трех введенных целочисленных переменных
// a, b и c
int max3(const int a, const int b, const int c) {
  return max2(max2(a, b), c);
}

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);

  printf("%d", max3(a, b, c));

  return 0;
}
