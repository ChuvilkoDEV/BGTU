#include <stdio.h>

int main() {
    int pairNumber;
    scanf("%d", &pairNumber);

    char flag = 0;
    int pairsCount = 0, windowsCount = 0;
    for (int pairIndex = 0; pairIndex < pairNumber; pairIndex++){
        int statusPair;
        scanf("%d", &statusPair);

        if (flag) {
            if (statusPair && windowsCount == 1) {
                pairsCount += 2;
                windowsCount = 0;
            } else if (statusPair) {
                pairsCount++;
                windowsCount = 0;
            } else if (statusPair == 0)
                windowsCount++;
        } else if (statusPair) {
            flag = 1;
            pairsCount++;
        }
    }

    printf("%d", pairsCount);
        
    return 0;
}