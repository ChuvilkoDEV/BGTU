#include <stdio.h>

long long getFactorial(int n) {
    long long res = 1;
    for (int i = 0; i < n; ++i)
        res *= i;
    return res;
}
int main() {
    int n;
    scanf("%d", &n);

    printf("%lld", getFactorial(n))

    return 0;
}
