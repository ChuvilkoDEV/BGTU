#include <stdio.h>

int main() {
    int j;
    scanf("%d", &j);

    long long int n;    // Количество литров
    int a, b;           // Стоимость 1-литровой, 2-литровой
    for (int i = 0; i < j; ++i) {
        scanf("%lld %d %d", &n, &a, &b);

        // Идея программы:
        // Ищем наиболее выгодные цены в перерасчете цена/2 литра
        if (a * 2 < b) {
            b = a * 2;
        }

        if (n % 2 == 0) {
            printf("%lld\n", n / 2 * b);
        } else {
            printf("%lld\n", n / 2 * b + a);
        }
    }
    return 0;
}
