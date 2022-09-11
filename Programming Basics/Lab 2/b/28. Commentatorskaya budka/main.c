#include <stdio.h>

int main() {
    long long n;  // Количество построенных кабинок
    long long m;  // Количество делигаций
    long long a;  // Стоимость постройки 1 кабинки
    long long b;  // Стоимость сноса 1 кабинки
    scanf("%lld %lld %lld %lld", &n, &m, &a, &b);

    // Количество кабинок, которое необходимо снести, чтобы получить кратное число
    long long rc = n % m;
    // Стоимость сноса
    long long destroy = rc * b;
    // Стоимость постройки
    long long build = (m - rc) * a;

    long long out;
    if (destroy < build)
        out = destroy;
    else
        out = build;
    printf("%lld", out);

    return 0;
}