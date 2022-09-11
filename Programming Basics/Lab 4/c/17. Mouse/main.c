#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void *a, const void *b) {
  int arg1 = *(const int *) a;
  int arg2 = *(const int *) b;
  if (arg1 < arg2) return -1;
  if (arg1 > arg2) return 1;
  return 0;
}

void inputArrayDistance(int *const a, int const countMouse, int const distance) {
  for (int i = 0; i < countMouse; i++) {
    int tmp;
    scanf("%d", &tmp);
    a[i] = distance - tmp;
  }
}

int maxSaveMouse(int const *const a, int const distance, int const countMouse) {
  int s = 0;
  for (int i = 0; i < countMouse; i++) {
    s += a[i];
    if (s >= distance)
      return i;
  }
  return countMouse;
}

int main() {
  int t;
  scanf("%d", &t);

  for (int i = 0; i < t; i++) {
    int distance, countMouse;
    scanf("%d %d", &distance, &countMouse);
    int a[countMouse];
    inputArrayDistance(a, countMouse, distance);

    qsort(a, countMouse, sizeof(int), compare_ints);
    printf("%d\n", maxSaveMouse(a, distance, countMouse));
  }

  return 0;
}