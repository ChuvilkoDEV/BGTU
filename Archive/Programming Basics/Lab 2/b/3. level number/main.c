#include <stdio.h>

int main() {
    int f;
    scanf("%d", &f);

    for (int i = 0; i < f; ++i) {
        int n;  // Номер квартиры
        int x;  // Количество квартир на одном этаже
        scanf("%d %d", &n, &x);

        // Этаж, на котором живет Петя
        int level = 1;
        if (n > 2) {
            n -= 2;
            level += (n / x) + (n % x != 0);
        }

        printf("%d\n", level);
    }

    return 0;
}