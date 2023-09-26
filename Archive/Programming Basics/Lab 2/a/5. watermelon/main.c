#include <stdio.h>

// 5. Задача про арбуз (4A)

int main() {
    int w;  // Вес арбуза
    scanf("%d", &w);

    if (w % 2 == w && w > 3) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
