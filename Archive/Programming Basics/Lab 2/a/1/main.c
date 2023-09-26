#include <stdio.h>

// Настя и камни

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int step;
    if (n / 2 >= k) {
        step = k - 1;
    } else {
        step = n - k;
    }

    printf("%d", step);
    return 0;
}
