#include <stdio.h>

int main() {
    int k;
    scanf("%d", &k);

    for (int i = 0; i < k; ++i) {
        long long n; // Количество участников
        long long x; // Время, через которое запускают следующего участника
        long long t; // Время, которое дается на написание олимпиады
        scanf("%lld %lld %lld", &n, &x, &t);

        // Максимальное раздражение
        long long m = t / x;
        // Раздражение последних (m + 1) участников
        long long r1 = (1 + m) * m / 2;
        // Раздражение первых (n - (m + 1)) участников
        long long r2 = (n - (m + 1)) * m;
        printf("%lld\n", r1 + r2);
    }
    return 0;
}