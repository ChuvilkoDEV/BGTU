#include <stdio.h>

int main() {
    int f;
    scanf("%d", &f);

    for (int i = 0; i < f; i++) {
        int x;  // Точка, в которой начинает первый кролик
        int y;  // Точка, в которой начинает второй кролик
        int a;  // Скорость первого кролика
        int b;  // Скорость второго кролика
        scanf("%d %d %d %d", &x, &y, &a, &b);

        // Расстояние между кроликами
        int dist = y - x;
        // Скорость сближения кроликов
        int speed = a + b;
        if (dist % speed == 0)
            printf("%d\n", dist/speed);
        else
            printf("-1\n");
    }

    return 0;
}