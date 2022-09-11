#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    // сортирую все элементы в порядке возрастания
    if (a > b) {
        int t = a;
        a = b;
        b = t;
    }
    if (b > c) {
        int t = b;
        b = c;
        c = t;
    }
    if (a > b) {
        int t = a;
        a = b;
        b = t;
    }

    if (a + b > c) {
        printf("0");
    } else {
        printf("%d", c - (a + b) + 1);
    }

    return 0;
}