#include <stdio.h>

int main() {
    int s, v1, v2, t1, t2;
    scanf("%d %d %d %d %d", &s, &v1, &v2, &t1, &t2);

    int first = 2 * t1 + s * v1;
    int second = 2 * t2 + s * v2;
    if (first < second) {
        printf("First");
    } else if (first > second) {
        printf("Second");
    } else {
        printf("Friendship");
    }
    
    return 0;
}
