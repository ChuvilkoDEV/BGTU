#include <stdio.h>

int main() {
    int n, d, lastX;
    scanf("%d %d %d", &n, &d, &lastX);

    int step = 0;
    for (int i = 1; i < n; i++) {
        int x;
        scanf("%d", &x);

        int tmpStep = 0;
        if (x <= lastX)
            tmpStep = (lastX - x) / d + 1;
        step += tmpStep;
        lastX = x + tmpStep * d;
    }

    printf("%d", step);

    return 0;
}