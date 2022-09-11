#include <stdio.h>

int main() {
    int numberAllFriends;
    scanf("%d", &numberAllFriends);

    for (int friendIndex = 0; friendIndex < numberAllFriends; friendIndex++) {
        long long w, h, numberFriend;
        scanf("%lld %lld %lld", &w, &h, &numberFriend);

        int pieceCount = 1, pieceChange = 1;
        while (pieceCount < numberFriend && (w % 2 == 0 || h % 2 == 0)) {
            if (w % 2 == 0) {
                pieceCount += pieceChange;
                pieceChange *= 2;
                w /= 2;
            } else if (h % 2 == 0) {
                pieceCount += pieceChange;
                pieceChange *= 2;
                h /= 2;
            }
        }

        if (pieceCount >= numberFriend)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}