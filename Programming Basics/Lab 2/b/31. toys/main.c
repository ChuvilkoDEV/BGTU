#include <stdio.h>

int main() {
    long long n; // Количество игрушек
    long long k; // Количество монет
    scanf("%lld %lld", &n, &k);

    long long out;
    if (n < k)
        out = n - k / 2;
    else
        out = k - (k / 2 + 1);

    out = out > 0 ? out : 0;
    printf("%lld", out);

    return 0;
}