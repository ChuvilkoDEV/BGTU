#include <stdio.h>

// "Codeforces, с блэкджеком и другими развлекательными мероприятиями"

int main() {
    int n;
    scanf("%d", &n);

    if ((11 <= n && n <= 19) || n == 21) {
        printf("4");
    } else if (n == 20) {
        printf("15");
    } else {
        printf("0");
    }

    return 0;
}
