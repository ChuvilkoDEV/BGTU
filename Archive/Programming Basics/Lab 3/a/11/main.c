#include <stdio.h>

int main() {
    long long x; // Вводимое число
    int digit, k, digitCnt; // digit - Цифра, которая встречается k раз
    scanf("%lld %d %d", &x, &digit, &k);

    while (x > 0) {
        int n = x % 10;
        if (n == digit)
            digitCnt += 1;

        x /= 10;
    }

    if (digitCnt == k)
        printf("YES");
    else
        printf("NO");

    return 0;
}