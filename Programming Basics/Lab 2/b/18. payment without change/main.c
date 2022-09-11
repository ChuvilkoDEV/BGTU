#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        int a, n;   // а монет стоимостью n
        int b;  // b монет стоимостью 1
        int s;  // Суммарная стоимость
        scanf("%d %d %d %d", &a, &b, &n, &s);

        int min;
        if (a <= s / n)
            min = a;
        else
            min = s / n;

        if (s - (min * n) <= b)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}