#include <stdio.h>

int main() {
    long long x;
    scanf("%lld", &x);

    int max = 0;
    while (x > 0) {
        int n = x % 10;

        if (max < n)
            max = n;

        x /= 10;
    }

    printf("%d", max);

    return 0;
}