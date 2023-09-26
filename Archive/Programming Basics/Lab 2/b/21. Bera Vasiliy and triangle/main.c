#include <stdio.h>

long long int abs(long long x) {
    return x >= 0 ? x : -x;
}

int main() {
    long long x, y;
    scanf("%lld %lld", &x, &y);

    long long s = abs(x) + abs(y);
    long long out[4];
    if (x > 0 && y > 0) {
        out[0] = 0, out[1] = s;
        out[2] = s, out[3] = 0;
    } else if (x < 0 && y > 0) {
        out[0] = -s, out[1] = 0;
        out[2] = 0, out[3] = s;
    } else if (x > 0 && y < 0) {
        out[0] = 0, out[1] = -s;
        out[2] = s, out[3] = 0;
    } else {
        out[0] = -s, out[1] = 0;
        out[2] = 0, out[3] = -s;
    }

    printf("%lld %lld %lld %lld", out[0], out[1], out[2], out[3]);

    return 0;
}