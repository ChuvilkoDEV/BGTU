# include <stdio.h>

int isEnoughMoves(int laptopCharge, int countMoves, int withoutCharging,
                  int withCharging, int presumably) {
  if (presumably > countMoves)
    return 0;
  long long asd = (long long) presumably * (long long) withoutCharging +
                   ((long long) countMoves - (long long) presumably) *
                   (long long) withCharging;
  if (asd < laptopCharge)
    return 1;
  return 0;
}

int binMoves(int laptopCharge, int countMoves,
             int withoutCharging, int withCharging) {
  if ((long long)withCharging * (long long)countMoves >= laptopCharge)
    return -1;
  int left = 0;
  int right = countMoves + 5;
  while (left + 1 < right) {
    int middle = left + (right - left) / 2;
    int f = isEnoughMoves(laptopCharge, countMoves, withoutCharging,
                          withCharging, middle);
    if (f)
      left = middle;
    else
      right = middle;
  }
  return left;
}


int main() {
  int q;
  scanf("%d", &q);

  for (int i = 0; i < q; i++) {
    int laptopCharge, countMoves, withoutCharging, withCharging;
    scanf("%d %d %d %d", &laptopCharge, &countMoves, &withoutCharging,
          &withCharging);

    printf("%d\n",
           binMoves(laptopCharge, countMoves, withoutCharging, withCharging));
  }

  return 0;
}