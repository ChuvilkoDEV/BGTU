#include <stdio.h>

void inputArray(double *a, size_t const size) {
  for (size_t i = 0; i < size; i++)
    scanf("%lf", &a[i]);
}

int isExistLength(double const *const a, int const lengthRope, int const nPeace,
                  double const hypothetically) {
  int count = 0;
  for (int i = 0; i < lengthRope; ++i) {
    count += (int)(a[i] / hypothetically);
    if (count >= nPeace)
      return 1;
  }
  return 0;
}

double maxLength(double const * const a,
                 int const lengthRope, int const nPeace) {
  double left = 0;
  double right = 1e9;
  for (int i = 1; i <= 100; i++) {
    double middle = (left + right) / 2;
    if (isExistLength(a, lengthRope, nPeace, middle))
      left = middle;
    else
      right = middle;
  }
  return left;
}

int main() {
  int lengthRope, nPeace;
  scanf("%d %d", &lengthRope, &nPeace);
  double a[lengthRope];
  inputArray(a, lengthRope);

  printf("%.8f", maxLength(a, lengthRope, nPeace));

  return 0;
}