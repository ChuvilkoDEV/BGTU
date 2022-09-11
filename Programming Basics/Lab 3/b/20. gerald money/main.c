#include <stdio.h>

int main() {
    int numberOfCoinDenomination;
    scanf("%d", &numberOfCoinDenomination);

    char isMinDenomination1 = 0;
    for (int coinIndex = 0; coinIndex < numberOfCoinDenomination; coinIndex++) {
        int coinDenomination;
        scanf("%d", &coinDenomination);

        if (coinDenomination == 1)
            isMinDenomination1 = 1;
    }

    if (isMinDenomination1)
        printf("-1");
    else
        printf("1");

    return 0;
}