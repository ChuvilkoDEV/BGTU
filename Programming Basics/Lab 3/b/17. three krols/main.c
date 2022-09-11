#include <stdio.h>

int max2(int a, int b) {
    return a >= b ? a : b;
}

int main() {
    int amountOfDataEntered, timeNumber, maxPleasure, tmpTime;
    scanf("%d %d %d %d", &amountOfDataEntered, &timeNumber, &maxPleasure, &tmpTime);

    if (tmpTime > timeNumber)
        maxPleasure -= tmpTime - timeNumber;
    for (int dataIndex = 1; dataIndex < amountOfDataEntered; dataIndex++){
        int pleasureInTheRestaurant, timeToEat;
        scanf("%d %d", &pleasureInTheRestaurant, &timeToEat);

        if (timeToEat > timeNumber)
            pleasureInTheRestaurant -= timeToEat - timeNumber;
        maxPleasure = max2(maxPleasure, pleasureInTheRestaurant);
    }

    printf("%d", maxPleasure);

    return 0;
}