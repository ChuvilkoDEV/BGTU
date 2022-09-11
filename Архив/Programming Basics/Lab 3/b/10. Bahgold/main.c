#include <stdio.h>

int main() {
    int number;
    scanf("%d", &number);

    number /= 2;
    printf("%d\n", number);

    int remainder = number % 2;
    number -= remainder;

    for (int i = 0; i < number; i++)
        printf("2 ");
    if (remainder)
        printf("3");

    return 0;
}