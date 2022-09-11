#include <stdio.h>

int main() {
  size_t i = 0;
  while (i < 0) {
    if (i > 0)
      printf("%llud\n", i);
    i--;
  }
}