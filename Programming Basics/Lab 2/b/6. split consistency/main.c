#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int s = (1 + n) * n / 2;
    if (s % 2 == 0)
        printf("0");
    else
        printf("1");

    return 0;
}