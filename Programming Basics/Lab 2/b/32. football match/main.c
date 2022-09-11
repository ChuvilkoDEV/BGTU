#include <stdio.h>

int main() {
    int a;  // Вес одной секунды
    int b;  // Скорость скачивания
    int c;  // Продолжительность видело
    scanf("%d %d %d", &a, &b, &c);

    int t = (a * c / b) + (a * c % b != 0) - c;
    printf("%d", t);
    return 0;
}