#include <stdio.h>

void oct(int a) {
  if (a > 7) {
    int b = a >> 3;
    oct(b);
  }
  printf("%d", a & 7);
}

int main() {
  int a;
  scanf("%d", &a);

  oct(a);

  return 0;
}
