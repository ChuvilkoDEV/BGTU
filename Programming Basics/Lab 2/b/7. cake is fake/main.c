#include <stdio.h>

int main() {
    int f;
    scanf("%d", &f);

    for (int i = 0; i < f; i++) {
        int n, m;   // Кординаты [n;m]
        int k;      // Количество монет
        scanf("%d %d %d", &n, &m, &k);

        int s = (n - 1) + (n * (m - 1));
        if (k == s)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
