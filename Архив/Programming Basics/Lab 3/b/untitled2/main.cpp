#include <iostream>
#include <math.h>

int main() {
    double t;
    printf("Введите переменную t: ");
    scanf("%lf", &t);
    double k;
    printf("Введите переменную k: ");
    scanf("%lf", &k);
    double m;
    printf("Введите переменную m: ");
    scanf("%lf", &m);
    double n;
    printf("Введите переменную n: ");
    scanf("%lf", &n);
    double y;
    printf("Введите переменную y: ");
    scanf("%lf", &y);

    double Z = ((t - pow(k, 2))/(pow(m, 4) - n)) + sqrt(abs((sqrt(m) + y) / (12 - m) + 4));

    printf("Ответ: %lf", Z);

    return 0;
}





int a() {


}