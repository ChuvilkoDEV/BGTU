#include <stdio.h>

int main() {
    char flag = 1;
    long long s = 0;

    while (flag) {
        char x = getchar();

        if (x == '.')
            flag = 0;
        else if (x >= '0' && x <= '9')
            s += x - '0';
    }

    printf("%lld", s);

    return 0;
}