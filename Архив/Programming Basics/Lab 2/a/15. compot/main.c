#include <stdio.h>

int main() {
    int lemons, apple, pear;
    scanf("%d %d %d", &lemons, &apple, &pear);

    apple /= 2;
    pear /= 4;

    int min = lemons;
    if (apple < min)
        min = apple;
    if (pear < min)
        min = pear;

    printf("%d", min*7);
    return 0;
}
