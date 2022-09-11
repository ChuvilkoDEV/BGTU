#include <stdio.h>
#include <ctype.h>

int countDigit() {
  char a = getchar();
  if (a == '\n')
    return 0;
  return isdigit(a) + countDigit();
}

int main() {
  printf("%d", countDigit());
  return 0;
}