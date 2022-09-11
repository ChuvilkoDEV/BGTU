#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    char flag = 0;
    int even = 0;   // Количество четных
    int uneven = 0; // Количество нечетных

    while (flag == 0) {
        long long x;
        scanf("%lld", &x);

        if (x == 0)
            flag = 1;
        else if (x % 2)
            uneven += 1;
        else
            even += 1;
    }

    if (even == 0 && uneven == 0)
        printf("Пустая последовательность");
    else
        printf("%d %d", even, uneven);

    return 0;
}