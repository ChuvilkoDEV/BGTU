#include <stdio.h>

int main() {
    long long h;    // Высота, на которую лиллия возвышается над водой
    long long l;    // Расстояние, на которое отплыла Инесса с лиллией
    scanf("%lld %lld", &h, &l);

    double hl = (double)(l * l - h * h) / (2 * h);
    printf("%.15f", hl);

    return 0;
}