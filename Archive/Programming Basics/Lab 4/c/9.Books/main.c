# include <stdio.h>

void inputArray(int *a, size_t const size) {
  for (size_t i = 0; i < size; i++)
    scanf("%d", &a[i]);
}

int sumArray(int const *const a, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++)
    sum += a[i];
  return sum;
}

int isEnoughTime(int const *const a, int const countBooks,
                 int const freeTime, int const presumptiveLength) {
  int x = 0, y = sumArray(a, presumptiveLength);
  for (int i = 0; i < countBooks - presumptiveLength + 1; i++) {
    if (y - x <= freeTime)
      return 1;
    x += a[i];
    y += a[i + presumptiveLength];
  }
  return 0;
}

int binBooks(int const *const a, int const countBooks, int const freeTime) {
  int left = 0;
  int right = countBooks + 1;
  while (left + 1 < right) {
    int middle = left + (right - left) / 2;
    int f = isEnoughTime(a, countBooks, freeTime, middle);
    if (f)
      left = middle;
    else
      right = middle;
  }
  return left;
}


int main() {
  int countBooks, freeTime;
  scanf("%d %d", &countBooks, &freeTime);
  int a[countBooks];
  inputArray(a, countBooks);

  printf("%d\n", binBooks(a, countBooks, freeTime));

  return 0;
}