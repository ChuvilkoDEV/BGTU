#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    char status = 1, flag = 0;
    long long min, next = 0;
    scanf("%lld", &min);

    while (flag == 0 && min != 0) {
        long long x;
        scanf("%lld", &x);

        if (status) {
            next = x;
            status = 0;
        }

        if (x == 0)
            flag = 1;
        else if (min >= x) {
            status = 1;
            min = x;
        }
    }

    if (min == 0)
        printf("Последовательность пуста");
    else if (next == 0)
        printf("Нет решения");
    else
        printf("%lld", next);

    return 0;
}