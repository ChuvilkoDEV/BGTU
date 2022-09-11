#include <stdio.h>

int main() {
    long long input;
    scanf("%lld", &input);

    long long s = 1;
    while (input > 0) {
        int n = input % 10;

        if (n != 0)
            s *= n;

        input /= 10;
    }

    printf("%lld", s);

    return 0;
}