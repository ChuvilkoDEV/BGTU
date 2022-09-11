#include <stdio.h>

int main() {
    int amountOfDataEntered;
    scanf("%d", &amountOfDataEntered);

    for (int DataIndex = 0; DataIndex < amountOfDataEntered; DataIndex++) {
        int money;
        scanf("%d", &money);

        int tmpMoney = money;
        while (tmpMoney > 9) {
            int change = tmpMoney / 10;
            money += change;
            tmpMoney = tmpMoney % 10 + change;
        }

        printf("%d\n", money);
    }

    return 0;
}