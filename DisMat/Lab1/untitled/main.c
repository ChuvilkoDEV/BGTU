#include <stdio.h>

int main() {
  int x = 0;
  for (int i = 0;  i < 6; i++) {
    x++;
    printf("%d", x);
    if (x == 5)
      x = (int const) x;
  }
  return 0;
}
