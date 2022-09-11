#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        int n;  // Сумма, которая должна получится
        scanf("%d", &n);

        printf("%d %d\n", 1, n - 1);
    }
    return 0;
}