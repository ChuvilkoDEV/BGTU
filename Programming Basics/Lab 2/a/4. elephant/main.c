#include <stdio.h>

// 4. Слоник (617A)

int main() {
    int x;
    scanf("%d", &x);

    // Слону всегда выгоднее идти на 5 шагов
    int step = x / 5;

    // Если количество шагов кратно 5, то просто завершаем процесс. Если нет, добавляем 1 к количеству.
    if (step * 5 == x) {
        printf("%d", step);
    } else {
        printf("%d", ++step);
    }

    return 0;
}
