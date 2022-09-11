#include <stdio.h>

struct line {
  double a;
  double b;
  double c;
};

typedef struct line line;

void inputLine(line *line) {
  scanf("%lf %lf %lf", &line->a, &line->b, &line->c);
}

void outputLine(line line) {
  printf("%.3lfx + %.3lfy + %.3lf = 0", line.a, line.b, line.c);
}

int main() {
  line line = {1, 2, 3};

  return 0;
}
