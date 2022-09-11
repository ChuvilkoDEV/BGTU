#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        long long retailPrice;   // Цена пончика в розничном магазине
        long long optCnt;    // Количество пончиков в коробе в опт. маг.
        long long optPrice;  // Цена короба с пончиками в опт. маг.
        scanf("%lld %lld %lld", &retailPrice, &optCnt, &optPrice);

        // Розничная
        long long out1 = 1;
        if (retailPrice >= optPrice)
            out1 = -1;

        // Оптовая
        long long out2 = optCnt;
        if (retailPrice * optCnt <= optPrice)
            out2 = -1;

        printf("%lld %lld\n", out1, out2);
    }

    return 0;
}