#include <stdio.h>

// Освещение парка

int main() {
    int t;
    scanf("%d", &t);

    int m, n, s;
    for (int i = 0; i < t; ++i) {
        scanf("%d %d", &m, &n);

        s = m * n;
        if (s % 2 == 0) {
            printf("%d\n", s / 2);
        } else {
            printf("%d\n", s / 2 + 1);
        }
    }

    return 0;
}