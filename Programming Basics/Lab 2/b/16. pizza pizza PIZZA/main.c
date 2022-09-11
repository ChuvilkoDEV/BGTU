#include <stdio.h>

int main() {
    long long n;    // Количество друзей на вечеринке
    scanf("%lld", &n);

    long long out;
    if (n == 0)
        out = 0;
    else if ((n + 1) % 2 == 0)
        out = (n + 1) / 2;
    else
        out = n + 1;
    printf("%lld", out);

    return 0;
}