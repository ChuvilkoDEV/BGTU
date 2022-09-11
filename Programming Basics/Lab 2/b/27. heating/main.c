#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        long long c;    // Количество радиаторов
        long long s;    // Количество секций
        scanf("%lld %lld", &c, &s);

        long long p = s % c;  // Количество радиаторов, за которые придетяс переплатить
        long long v = s / c;  // Цена без переплаты
        long long sum = ((c - p) * v * v) + (p * (v + 1) * (v + 1));
        printf("%lld\n", sum);
    }
    return 0;
}