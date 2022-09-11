#include <stdio.h>

#define CHANGE_WEIGHT_LITTLE_BEAR 3
#define CHANGE_WEIGHT_BIG_BEAR 2

int main() {
    int weightLittleBear, weightBigBear;
    scanf("%d %d", &weightLittleBear, &weightBigBear);

    int yearCount = 0;
    while (weightLittleBear <= weightBigBear) {
        weightLittleBear *= CHANGE_WEIGHT_LITTLE_BEAR;
        weightBigBear *= CHANGE_WEIGHT_BIG_BEAR;
        yearCount++;
    }

    printf("%d", yearCount);

    return 0;
}