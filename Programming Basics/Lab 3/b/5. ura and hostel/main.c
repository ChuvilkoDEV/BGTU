#include <stdio.h>

int main() {
    int numberRooms;
    scanf("%d", &numberRooms);

    int roomsCount = 0;
    for (int roomIndex = 0; roomIndex < numberRooms; roomIndex++){
        int residentsNumber, placeNumber;
        scanf("%d %d", &residentsNumber, &placeNumber);

        if (placeNumber - residentsNumber >= 2)
            roomsCount++;
    }

    printf("%d", roomsCount);

    return 0;
}