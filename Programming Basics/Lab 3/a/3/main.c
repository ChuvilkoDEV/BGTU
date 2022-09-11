#include <stdio.h>

int main() {
    int n, index = 0;
    long long min;
    scanf("%d %lld", &n, &min);

    for (int i = 1; i < n; ++i) {
        long long x;
        scanf("%lld", &x);

        if (min > x) {
            index = i;
            min = x;
        }
    }

    printf("%d", index);

    return 0;
}