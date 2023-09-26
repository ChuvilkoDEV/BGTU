#include <stdio.h>

int main() {
    int h1, m1; // Время начала контеста
    int h2, m2; // Время окончания контеста
    scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);

    int out = ((h2 + h1) * 60 + m2 + m1) / 2;
    int hh = out / 60;
    int mm = out % 60;

    printf("%02d:%02d", hh, mm);

    return 0;
}