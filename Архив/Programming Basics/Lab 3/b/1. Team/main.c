#include <stdio.h>

int main() {
    int number; // Количество вводимых значений
    scanf("%d", &number);
    int flagsCount = 0;

    for (int index = 0; index < number; ++index) {
        int isPetyaSure, isVasyaSure, isTonyaSure;
        scanf("%d %d %d", &isPetyaSure, &isVasyaSure, &isTonyaSure);

        if (isVasyaSure + isPetyaSure + isTonyaSure > 1)
            flagsCount++;
    }

    printf("%d", flagsCount);

    return 0;
}