#include <stdio.h>

#include "libs/array/array_.h"
#include "libs/getTime/getTime.h"
#include "libs/sorts/sorts.h"



void timeExperiment() {
  // описание функций сортировки
  SortFunc sorts[] = {
    {selectionSort, "selectionSort"},
    //{insertionSort, "insertionSort"},
    //{bubbleSort,    "bubbleSort"},
    //{combsort,      "combsort"},
    //{shellSort,     "shellSort"},
    //{digitSort,     "digitSort"},
    //{mergeSort,     "mergeSort"},
    //{heapSort,      "heapSort"}
  };
  const unsigned FUNCS_N = ARRAY_SIZE(sorts);

  // описание функций генерации
  GeneratingFunc generatingFuncs[] = {
    // генерируется случайный массив
    {generateRandomArray,      "random"},
    // генерируется массив 0, 1, 2, ..., n - 1
    {generateOrderedArray,     "ordered"},
    // генерируется массив n - 1, n - 2, ..., 0
    {generateOrderedBackwards, "orderedBackwards"}
  };
  const unsigned CASES_N = ARRAY_SIZE(generatingFuncs);

  // запись статистики в файл
  for (size_t size = 200000; size <= 300000; size += 10000) {
    printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf(" Size : %d\n", size);
    for (int i = 0; i < FUNCS_N; i++) {
      for (int j = 0; j < CASES_N; j++) {
        // генерация имени файла
        static char filename[128];
        sprintf(filename, "%s_%s_time",
                sorts[i].name, generatingFuncs[j].name);
        checkTime(sorts[i].sort,
                  generatingFuncs[j].generate,
                  size, filename);
      }
    }
    printf("\n");
  }
}

int main() {
  timeExperiment();

//    int a[] = {3, 6, 6, 135, 12, 13, 13, 143, 16, 19, 20, 150,
//               26, 27, 27, 27, 29, 159, 31, 33, 164, 165, 165,
//               39, 167, 173, 173, 175, 47, 48, 176, 178, 63, 65, 198};
//    digitSort(a, 35);
//    outputArray_(a, 35);
}