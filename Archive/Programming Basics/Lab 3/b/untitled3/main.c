#include <stdio.h>

int main() {
    int num;
    int max;
    scanf("%d %d", &num, &max);

    int last = num <= max ? num: max;
    max = max < num ? num: max;

    while (num != 0)
        scanf("%d", &num);

    if (num != 0) {
        if (max <= num) {
            last = max;
            max = num;
        }
    }

    printf("%d", last);

    return 0;
}
