#include <stdio.h>

int max2(int a, int b) {
    return a >= b ? a : b;
}

int main() {
    int numberDays, taxValue, lastCourse;
    scanf("%d %d %d", &numberDays, &taxValue, &lastCourse);

    int maxProfit = 0;
    for (int dayIndex = 1; dayIndex < numberDays; dayIndex++) {
        int nowCourse;
        scanf("%d", &nowCourse);

        int profit = lastCourse - nowCourse - taxValue;
        maxProfit = max2(maxProfit, profit);
        lastCourse = nowCourse;
    }

    printf("%d", maxProfit);

    return 0;
}