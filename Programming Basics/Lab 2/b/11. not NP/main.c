#include <stdio.h>

int main() {
    int l, r;   // Диапозон чисел
    scanf("%d %d", &l, &r);

    // Так как наиболее частый делитель у любого диапозона чисел - 2, кроме случая, когда l и r равны
    if (l == r)
        printf("%d", l);
    else
        printf("2");

    return 0;
}