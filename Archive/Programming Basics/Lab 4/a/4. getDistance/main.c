#include <stdio.h>
#include <math.h>

// Возвращает расстояние между двумя точками с координатами (х1, у1) и (х2, у2)
double getDistance(const int x1, const int y1,
                   const int x2, const int y2) {
  int dx = abs(x1 - x2); // дельта x
  int dy = abs(y1 - y2); // дельта у
  return sqrt(dx * dx + dy * dy);
}

int main() {
  int x1, y1, x2, y2;
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

  printf("%lf", getDistance(x1, y1, x2, y2));

  return 0;
}
