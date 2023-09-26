#include <stdio.h>

int main() {
    int friendsCount, fenceHeight;
    scanf("%d %d", &friendsCount, &fenceHeight);

    int widthMin = 0;
    for (int boyIndex = 0; boyIndex < friendsCount; boyIndex++){
        int friendHeight;
        scanf("%d", &friendHeight);

        if (friendHeight > fenceHeight)
            widthMin++;
        widthMin++;
    }

    printf("%d", widthMin);

    return 0;
}