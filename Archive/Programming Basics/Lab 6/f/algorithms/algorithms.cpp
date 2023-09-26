#include "algorithms.h"

void swap(int &a, int &b) {
  int t = a;
  a = b;
  b = t;
}

void sort2(int &a, int &b) {
  if (a > b)
    swap(a, b);
}

// Возвращает наибольший общий делитель чисел a и b
int gcd(int a, int b) {
  sort2(a, b);
  if (b % a == 0)
    return a;
  int gcd = 1;
  for (int i = 2; i <= (int) sqrt(b); i++)
    if (a % i == 0 && b % i == 0)
      gcd = i;
  return gcd;
}

// Возвращает наименьшее общее кратное чисел a и b
int lcm(int a, int b) {
  sort2(a, b);
  int d = gcd(a, b);
  if (d == 1)
    return a * b;
  else if (d == a)
    return b;
  return b * a / d;
}