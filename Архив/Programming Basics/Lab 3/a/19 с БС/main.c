#include <stdio.h>

double dabs(double a) {
    return a > 0 ? a : -a;
}

int main() {
    double d, tmp, last, eps = 0.00001 ;
    char status = 1, flag = 0;
    scanf("%lf %lf", &tmp, &last);

    d = dabs(last - tmp);

    while (flag == 0) {
        double x;
        scanf("%lf", &x);

        if (x == 0)
            flag = 1;
        else {
            double dif = dabs(last - x);
            if (status && dif + eps > d && dif - eps < d)
                last = x;
            else
                status = 0;
        }
    }

    if (status)
        printf("Yes");
    else
        printf("No");

    return 0;
}