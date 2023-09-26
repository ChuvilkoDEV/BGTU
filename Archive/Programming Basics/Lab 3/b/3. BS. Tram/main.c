#include <stdio.h>

int main() {
    int number;
    scanf("%d", &number);

    int minCapacity = 0; // Минимальная необходимая вместимость
    int capacity = 0; // Количество пассажиров, которые находятся в автобусе в конкретный момент времени
    for (int index = 0; index < number; index++) {
        int passengersGotOff, passengersGotOn;
        scanf("%d %d", &passengersGotOff, &passengersGotOn);

        capacity += passengersGotOn - passengersGotOff;
        if (capacity > minCapacity)
            minCapacity = capacity;
    }

    printf("%d", minCapacity);

    return 0;
}