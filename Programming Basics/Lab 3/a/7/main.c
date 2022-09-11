#include <stdio.h>

int main() {
    char flag = 0;
    long long s = 0;

    while (flag == 0) {
        long long x;
        scanf("%lld", &x);

        if (x == 0)
            flag = 1;
        else if (x % 2 == 0)
            s += x;
    }

    printf("%lld", s);

    return 0;
}