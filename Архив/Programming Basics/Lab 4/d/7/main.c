#include <stdio.h>

void swap(long long *a, long long *b) {
  long long tmp = *a;
  *a = *b;
  *b = tmp;
}

int isFibonacci_(long long first, long long second,
                 long long const a, long long const b) {
  long long tmp = first + second;
  if (tmp == a + b && a == first && b == second)
    return 1;
  else if (tmp > a + b)
    return 0;
  return isFibonacci_(second, tmp, a, b);
}

int isFibonacci(long long a, long long b) {
  return isFibonacci_(1, 1, a, b);
}

int main() {
  long long a, b;
  scanf("%lld %lld", &a, &b);

  if (a > b)
    swap(&a, &b);

  if (isFibonacci(a, b))
    printf("YES");
  else
    printf("NO");

  return 0;
}