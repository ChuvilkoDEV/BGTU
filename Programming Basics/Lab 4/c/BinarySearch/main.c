#include <stdio.h>

// Ввод массива a размера size
void inputArray(int *const a, size_t const size) {
  for (size_t i = 0; i < size; i++)
    scanf("%d", &a[i]);
}

int binarySearch_(int const *const a, int const x, int const minIndex, int const maxIndex) {
  int deltaIndex = (maxIndex - minIndex);
  int middleIndex = minIndex + deltaIndex / 2;
  if (deltaIndex == 1 && a[middleIndex] != x)
    return -1;
  if (a[middleIndex] == x)
    return middleIndex;
  if (a[middleIndex] < x)
    return binarySearch_(a, x, middleIndex + 1, maxIndex);
  else
    return binarySearch_(a, x, minIndex, middleIndex - 1);
}

// Возвращает индекс, под которым находится значение x, если такого значения в
// массиве a размера size не найдено, то возвращается значение -1.
int binarySearch(int const *a, int const x, int size) {
  size--;
  if (a[0] > x || a[size] < x)
    return -1;
  if (a[size] == x)
    return size;
  return binarySearch_(a, x, 0, size);
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int a[n], b[k];
  inputArray(a, n);
  inputArray(b, k);

  for (int i = 0; i < k; i++) {
    if (binarySearch(a, b[i], n) == -1)
      printf("NO\n");
    else
      printf("YES\n");
  }

  return 0;
}