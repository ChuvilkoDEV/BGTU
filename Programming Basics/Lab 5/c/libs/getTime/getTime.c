#include "getTime.h"

void checkTime(void (*sortFunc )(int *, size_t),
               void (*generateFunc )(int *, size_t),
               size_t size, char *experimentName) {
  static size_t runCounter = 1;

  // генерация последовательности
  static int innerBuffer[100000];
  generateFunc(innerBuffer, size);
  printf("Run #%zu|", runCounter++);
  printf("Name: %s\n", experimentName);

  // замер времени
  double time;

  TIME_TEST({ sortFunc(innerBuffer, size); }, time);

  // результаты замера
  printf("Status: ");
  if (isOrdered(innerBuffer, size)) {
    printf("OK! Time: %.3fs.\n", time);

    // запись в файл
    char filename[256];
    sprintf(filename, "D:\\BGTU\\Programming Basics\\vor\\data\\%s.csv", experimentName);
    FILE *f = fopen(filename, "a");
    if (f == NULL) {
      printf("FileOpenError%s", filename);
      exit(1);
    }
    fprintf(f, "%zu; %.3f\n", size, time);
    fclose(f);
  } else {
    printf(" Wrong !\n");


    // вывод массива, который не смог быть отсортирован
    outputArray_(innerBuffer, size);

    exit(1);
  }
}

