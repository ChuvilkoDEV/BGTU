#include <stdio.h>

int main() {
    int amountOfDataEntered;
    scanf("%d", &amountOfDataEntered);

    for (int dataIndex = 0; dataIndex < amountOfDataEntered; dataIndex++) {
        long long rangeBorder;
        scanf("%lld", &rangeBorder);

        long long sum = 0, powerOfTwo = 1;
        while (powerOfTwo <= rangeBorder) {
            powerOfTwo *= 2;
            sum -= powerOfTwo;
        }
        sum += (1 + rangeBorder) * rangeBorder / 2; // Сумма арифметической прогрессии

        printf("%lld\n", sum);
    }

    return 0;
}