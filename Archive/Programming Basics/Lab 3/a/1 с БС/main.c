#include <stdio.h>

int main() {
    int cnt;
    long long max;
    scanf("%d %lld", &cnt, &max);

    for (int i = 2; i <= cnt; ++i) {
        long long x;
        scanf("%lld", &x);

        if (max < x)
            max = x;
    }

    printf("%lld", max);

    return 0;
}