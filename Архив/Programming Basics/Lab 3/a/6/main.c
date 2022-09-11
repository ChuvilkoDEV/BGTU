#include <stdio.h>

int main() {
    int n;
    long long min, max;
    scanf("%d %lld", &n, &min);
    max = min;

    for (int i = 1; i < n; ++i) {
        long long x;
        scanf("%lld", &x);

        if (max < x)
            max = x;

        if (min > x)
            min = x;
    }

    printf("%lld", max - min);

    return 0;
}