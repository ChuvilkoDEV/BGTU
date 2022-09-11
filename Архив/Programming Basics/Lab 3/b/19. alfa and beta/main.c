#include <stdio.h>

#define MAX_TRANSFER 8

int main() {
    int amountOfDataEntered, needCandy;
    scanf("%d %d", &amountOfDataEntered, &needCandy);

    int storageCandy = 0, minDays = 0;
    for (int i = 0; i < amountOfDataEntered; i++) {
        int addCandy;
        scanf("%d", &addCandy);

        if (needCandy <= 0)
            continue;
        else if (addCandy > MAX_TRANSFER) {
            needCandy -= MAX_TRANSFER;
            storageCandy += addCandy - MAX_TRANSFER;
            minDays++;
        } else if (storageCandy == 0) {
            needCandy -= addCandy;
            minDays++;
        } else if (storageCandy + addCandy <= MAX_TRANSFER) {
            needCandy -= storageCandy + addCandy;
            storageCandy = 0;
            minDays++;
        } else {
            storageCandy -= MAX_TRANSFER - addCandy;
            needCandy -= MAX_TRANSFER;
            minDays++;
        }
    }

    if (needCandy > 0)
        printf("-1");
    else
        printf("%d", minDays);

    return 0;
}