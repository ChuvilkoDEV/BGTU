#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        long long k;    // Число
        long long n;    // Количество различных положительных нечетных
        scanf("%lld %lld", &k, &n);

        // Предпоследний член последовательности
        long long an = 1 + 2 * (n - 2);
        // Сумма арифметической последовательности до предпоследнего члена последновательности
        long long sn = (1 + an) * (n - 1) / 2;
        if ((sn < k) && (k - sn > an) && ((k - sn) % 2 == 1))
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}