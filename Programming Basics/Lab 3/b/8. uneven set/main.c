#include <stdio.h>

int main() {
    int numberPair;
    scanf("%d", &numberPair);

    for (int index = 0; index < numberPair; index++) {
        int sequenceLen;
        scanf("%d", &sequenceLen);

        sequenceLen *= 2;
        int evenCount = 0; // Количество четных
        int unevenCount = 0; // Количество нечетных
        for (int sequenceIndex = 0; sequenceIndex < sequenceLen; sequenceIndex++) {
            int x;
            scanf("%d", &x);

            if (x % 2)
                unevenCount++;
            else
                evenCount++;
        }

        if (evenCount == unevenCount)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}