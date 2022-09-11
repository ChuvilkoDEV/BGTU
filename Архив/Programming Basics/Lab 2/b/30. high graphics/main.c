#include <stdio.h>

int main() {
    long long n;
    long long k;
    scanf("%lld %lld", &n, &k);

    if (k >= n)
        printf("%lld", k / n + (k % n != 0));
    else
        printf("1");

    return 0;
}