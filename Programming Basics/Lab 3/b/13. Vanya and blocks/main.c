#include <stdio.h>

int main() {
    int numberBlocks;
    scanf("%d", &numberBlocks);

    int level = 0, sumBlocks = 0, blocksLastLevel = 1, difBlocks = 2;
    while (sumBlocks + blocksLastLevel <= numberBlocks) {
        level++;
        sumBlocks += blocksLastLevel;
        blocksLastLevel += difBlocks;
        difBlocks++;
    }

    printf("%d", level);

    return 0;
}