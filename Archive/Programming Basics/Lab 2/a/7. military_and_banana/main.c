#include <stdio.h>

int main() {

    int k;  // за первый банан k$
    int n;  // долларов в кошельке у солдата
    int w;  // Количество бананов
    scanf("%d %d %d", &k, &n, &w);

    // сумма членов ариф. прогрессии
    int i;
    i = (1 + w) * w / 2;

    int sum;
    sum = i * k;
    if (sum >= n) {
        printf("%d", sum - n);
    } else {
        printf("0");
    }

    return 0;
}

