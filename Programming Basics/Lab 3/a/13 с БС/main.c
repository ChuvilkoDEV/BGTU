#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    long long last, lastOut, max;
    scanf("%lld", &max);
    last = max;
    lastOut = 0;

    while (last != 0) {
        long long x;
        scanf("%lld", &x);

        if (max < x) {
            lastOut = last;
            max = x;
        }

        last = x;
    }

    if (max == 0)
        printf("Пустая последовательность");
    else if (lastOut == 0)
        printf("Максимальному элементу не предшествует никаких значений");
    else
        printf("%lld", lastOut);

    return 0;
}