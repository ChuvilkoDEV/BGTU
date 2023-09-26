#include <stdio.h>

int main() {
    long long number; // Вводимое число
    int actions; // Количество действий совершаемых Таней
    scanf("%lld %d", &number, &actions);

    while (number > 0 && actions > 0) {
        int remainder = number % 10;
        if (remainder < actions) {
            actions -= remainder;
            number -= remainder;
            if (actions > 0) {
                actions--;
                number /= 10;
            }
        } else {
            number -= actions;
            actions = 0;
        }
    }

    printf("%lld", number);

    return 0;
}