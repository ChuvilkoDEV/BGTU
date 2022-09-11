#include <stdio.h>

void outputStatusServer(int lose, int get) {
    if (get >= lose)
        printf("LIVE\n");
    else
        printf("DEAD\n");
}

int main() {
    int requestNumber;
    scanf("%d", &requestNumber);

    int firstServerLose = 0, firstServerGet = 0;
    int secondServerLose = 0, secondServerGet = 0;
    for (int i = 0; i < requestNumber; i++){
        int server;
        int packetGet;
        int packetLose;
        scanf("%d %d %d", &server, &packetGet, &packetLose);

        if (server == 1) {
            firstServerLose += packetLose;
            firstServerGet += packetGet;
        } else {
            secondServerLose += packetLose;
            secondServerGet += packetGet;
        }
    }

    outputStatusServer(firstServerLose, firstServerGet);
    outputStatusServer(secondServerLose, secondServerGet);
        
    return 0;
}