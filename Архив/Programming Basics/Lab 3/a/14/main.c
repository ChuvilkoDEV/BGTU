#include <stdio.h>

int main() {
    char flag = 0;
    int len = 0;

    while (flag == 0) {
        if (getchar() == '\n')
            flag = 1;
        else
            len += 1;
    }

    printf("%d", len);

    return 0;
}