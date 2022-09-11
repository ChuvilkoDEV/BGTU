#include <stdio.h>

int main() {
    int a;  // Количество студентов, посетивших BugDonalds
    int b;  // Количество студентов, посетивших BeaverKing
    int c;  // Количество студентов, посетивших и то, и то
    int n;  // Количество студентов в группе
    scanf("%d %d %d %d", &a, &b, &c, &n);

    a -= c;
    b -= c;
    n -= (a + b + c);
    if (n >= 1 && a >= 0 && b >= 0)
        printf("%d", n);
    else
        printf("-1");

    return 0;
}