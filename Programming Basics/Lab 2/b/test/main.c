#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        long long ans1 = 1;
        if (a >= c)
            ans1 = -1;
        long long ans2 = b;
        if (a * b <= c)
            ans2 = -1;
        printf("%lld %lld\n", ans1, ans2);
    }
    return 0;
}
