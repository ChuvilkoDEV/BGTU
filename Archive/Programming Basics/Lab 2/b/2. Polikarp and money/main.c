#include <stdio.h>

int main() {
    int f;
    scanf("%d", &f);

    for (int i = 0; i < f; i++) {
        int n; // Нужно заплатить n бурлей.
        scanf("%d", &n);

        // Количество отданных монет номиналом 1
        int cnt_m_1 = n / 3;
        // Количество отданных монет номиналом 2
        int cnt_m_2 = n / 3;
        if (n % 3 == 1)
            cnt_m_1 += 1;
        else if (n % 3 == 2)
            cnt_m_2 += 1;

        printf("%d %d\n", cnt_m_1, cnt_m_2);
    }

    return 0;
}