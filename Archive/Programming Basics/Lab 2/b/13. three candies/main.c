#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        long long s = (a + b + c) / 2;
        printf("%lld\n", s);
    }
    return 0;
}