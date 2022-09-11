#include <stdio.h>

int main() {
    int n, index = 0;
    long long max;
    scanf("%d %lld", &n, &max);

    for (int i = 1; i < n; ++i) {
        long long x;
        scanf("%lld", &x);

        if (max <= x) {
            max = x;
            index = i;
        }
    }

    printf("%d", index);

    return 0;
}