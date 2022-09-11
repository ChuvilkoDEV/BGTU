#include <stdio.h>

// Возвращает наибольшее число из двух введенных целочисленных
// переменных a и b
int max2(const int a, const int b) {
  if (a >= b)
    return a;
  else
    return b;
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);

  printf("%d", max2(a, b));

  return 0;
}