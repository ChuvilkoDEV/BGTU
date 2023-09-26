#include <stdio.h>

int main() {
    int numberEvent;
    scanf("%d", &numberEvent);

    int cntUnsolvedCases = 0;
    int cntFreePoliceman = 0;
    for (int indexEvent = 0; indexEvent < numberEvent; indexEvent++) {
        int lastEvent;
        scanf("%d", &lastEvent);

        if (lastEvent == -1 && cntFreePoliceman == 0)
            cntUnsolvedCases++;
        else if (lastEvent == -1 && cntFreePoliceman > 0)
            cntFreePoliceman--;
        else
            cntFreePoliceman += lastEvent;
    }

    printf("%d", cntUnsolvedCases);

    return 0;
}