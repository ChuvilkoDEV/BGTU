#include <stdio.h>

int main() {
    long long n, m;
    long long a;
    scanf("%lld %lld %lld", &n, &m, &a);

    long long na = n / a + (n % a != 0);
    long long ma = m / a + (m % a != 0);
    printf("%lld", ma * na);

    return 0;
}