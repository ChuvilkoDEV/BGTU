#include <stdio.h>

int main() {
    float f;
    char s[100];
    char c;

    scanf("%3f %8s %c", &f, s, &c);
    printf("%f %s %c", f, s, c);
    return 0;
}
