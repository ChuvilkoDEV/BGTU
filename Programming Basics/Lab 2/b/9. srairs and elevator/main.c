#include <stdio.h>

int main() {
    int x;  // Этаж, на котором живет Маша
    int y;  // Этаж, на котором живет Егор
    int z;  // Этаж, на котором находится лифт
    int t1; // Время, за которое Маша проходит 1 этаж
    int t2; // Время, за которое лифт проходит 1 этаж
    int t3; // Время, которое лифт тратит на закрытие дверей
    scanf("%d %d %d %d %d %d", &x, &y, &z, &t1, &t2, &t3);

    // Расстоянние между этажом Маши и этажом Егора
    int r1 = x - y;
    // Расстояние между лифтом и этажом Маши
    int r2 = x - z;
    if (r1 < 0)
        r1 *= -1;
    if (r2 < 0)
        r2 *= -1;

    // Время, за которое Маша поднимется по лестнице
    int stairs = r1 * t1;
    // Время, за которое Маша поднимется на лифте
    int elevator = (r2 * t2) + (3 * t3) + (r1 * t2);

    if (elevator <= stairs)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}