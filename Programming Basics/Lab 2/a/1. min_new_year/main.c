#include <stdio.h>

// Минуты до Нового года

int main() {
    int len;
    scanf("%d", &len);

    int h, m;
    for (int i = 0; i < len; i++) {
        scanf("%d %d", &h, &m);

        // Вычисляем количество оставшихся минут до НГ
        h = 24 - h;
        m = h * 60 - m;
        printf("%d\n", m);
    }

    return 0;
}
