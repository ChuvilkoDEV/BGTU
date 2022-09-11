#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int out;
    if (n < 4 || n % 2 != 0)
        out = 0;
    else if (n % 4 == 0)
        out = n / 4 - 1;
    else
        out = n / 4;
    printf("%d", out);

    return 0;
}