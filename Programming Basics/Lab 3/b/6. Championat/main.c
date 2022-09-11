#include <stdio.h>

#define MAX_PARTICIPATION 5
#define PARTICIPANTS 3

int main() {
    int boysNumber, k;
    scanf("%d %d", &boysNumber, &k);
    
    int participantCount = 0;
    for (int i = 0; i < boysNumber; i++) {
        int participationCount;
        scanf("%d", &participationCount);

        if (MAX_PARTICIPATION - participationCount >= k)
            participantCount++;
    }

    printf("%d", participantCount / PARTICIPANTS);

    return 0;
}