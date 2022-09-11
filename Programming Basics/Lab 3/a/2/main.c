#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "UTF-8");
    char flag = 0;
    long long max;
    scanf("%lld", &max);

    while (flag == 0) {
        long long x;
        scanf("%lld", &x);

        if (x == 0 || max == 0)
            flag = 1;

        if (max < x)
            max = x;
    }

    if (max == 0)
        printf("Последовательность пуста");
    else
        printf("%lld", max);

    return 0;
}