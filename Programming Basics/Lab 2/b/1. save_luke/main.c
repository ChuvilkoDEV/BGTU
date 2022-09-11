#include <stdio.h>

int main() {
    double luke;      // Ширина Люка
    double length;    // Растояние междк прессами
    double v1;        // Скорость второго пресса
    double v2;        // Скорость второго пресса
    scanf("%lf %lf %lf %lf", &luke, &length, &v1, &v2);

    double time = (length - luke) / (v1 + v2);
    printf("%f", time);

    return 0;
}