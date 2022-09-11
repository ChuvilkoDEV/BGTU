#include <stdio.h>

int main() {
    int n;
    int k;
    scanf("%d %d", &n, &k);

    int sum = 0;
    for (int i = 0; i < n; i++){
        int s;
        scanf("%d", &s);

        sum += s;
    }

    printf("%d", sum);

    return 0;
}
