#include <stdio.h>

int main() {
    int f;
    scanf("%d", &f);

    for (int i = 0; i < f; i++) {
        int a, b;   // a смотрит на b
        int c;      // На кого смотрит с
        scanf("%d %d %d", &a, &b, &c);

        // Количество людей в кругу
        int r = (a - b) * 2;
        // abs
        if (r < 0)
            r *= -1;
        // Номер участника не может быть больше, чем количество людей
        if (a <= r && b <= r && c <= r) {
            int out;
            if (c > r / 2)
                out = c - r / 2;
            else
                out = c + r / 2;

            printf("%d\n", out);
        } else
            printf("-1\n");
    }

    return 0;
}