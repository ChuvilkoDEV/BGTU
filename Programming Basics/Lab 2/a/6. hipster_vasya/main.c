#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int min, max;
    if (a < b) {
        min = a;
        max = b;
    } else {
        min = b;
        max = a;
    }

    printf("%d %d", min, (max - min) / 2);

    return 0;
}