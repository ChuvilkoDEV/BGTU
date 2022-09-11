#include <stdio.h>

int main() {
    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int r1, r2;   // Диапазон
        int d;  // Надо найти число, кратное d
        scanf("%d %d %d", &r1, &r2, &d);

        int out;
        if (r1 <= d && d <= r2)
            out = r2 + d - (r2 % d);
        else
            out = d;
        printf("%d\n", out);
    }

    return 0;
}