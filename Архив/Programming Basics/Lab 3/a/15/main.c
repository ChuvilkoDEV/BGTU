#include <stdio.h>

int main() {
    char flag = 0;
    int cnt = 0;

    while (flag == 0) {
        char x = getchar();

        if (x == 10)
            flag = 1;
        else {
            char whiteList = (x != 'a' && x != 'e' && x != 'y' && x != 'u' && x != 'i' && x != 'o' && x >= 'a' && x <= 'z');
            if (whiteList)
                cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}