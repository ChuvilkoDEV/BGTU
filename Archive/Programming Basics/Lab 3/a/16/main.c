#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    double last, tmp, eps = 0.00001;
    char status, flag = 0;
    scanf("%lf %lf", &tmp, &last);

    if (last < tmp)
        status = 1; // Невозрастающая
    else if (last > tmp)
        status = 2; // Неубывающая
    else
        status = 3; // Еще не определилась

    while (flag == 0) {
        double x;
        scanf("%lf", &x);

        if (x == 0)
            flag = 1;
        else {
            if (status == -1)
                continue;
            else if ((status == 1 && x + eps > last) || (status == 2 && x - eps < last))
                status = -1;
            else if (status == 3 && x + eps < last)
                status = 1;
            else if (status == 3 && x - eps > last)
                status = 2;
            else
                last = x;
        }
    }

    if (status == 1)
        printf("Невозрастающая");
    else if (status == 2)
        printf("Неубывающая");
    else if (status == 3)
        printf("Все элементы равны");
    else
        printf("Неопределенная");

    return 0;
}