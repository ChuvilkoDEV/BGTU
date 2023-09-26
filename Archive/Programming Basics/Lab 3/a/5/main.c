#include <stdio.h>

int main() {
    int n, cnt = 1;
    long long min;
    scanf("%d %lld", &n, &min);

    for (int i = 2; i <= n; ++i) {
        long long x;
        scanf("%lld", &x);

        if (min == x)
            cnt++;
        else if (min > x) {
            min = x;
            cnt = 1;
        }
    }

    printf("%d", cnt);

    return 0;
}