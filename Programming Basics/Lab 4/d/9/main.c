#include <stdio.h>

int firstElementArithmeticSequence(int n, int const d, int an) {
  n--;
  if (n == 0)
    return an;
  firstElementArithmeticSequence(n, d, an - d);
}

int main() {
  int n, d, an;
  scanf("%d %d %d", &n, &d, &an);

  printf("%d", firstElementArithmeticSequence(n, d, an));

  return 0;
}