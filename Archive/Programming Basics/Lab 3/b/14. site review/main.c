#include <stdio.h>

int main() {
    int amountOfDataEntered;
    scanf("%d", &amountOfDataEntered);

    for (int indexData = 0; indexData < amountOfDataEntered; indexData++) {
        int numberUsers;
        scanf("%d", &numberUsers);

        int maxLikes = 0;
        for (int j = 0; j < numberUsers; j++) {
            int typeReviewer;
            scanf("%d", &typeReviewer);

            if (typeReviewer != 2)
                maxLikes++;
        }

        printf("%d\n", maxLikes);
    }

    return 0;
}