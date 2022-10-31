#include <stdio.h>
#include "stdbool.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>


int min(const int x, const int y) {
  return x < y ? x : y;
}

long long max(const long long x, const long long y) {
  return x > y ? x : y;
}
bool linearSearch(const int *a, const int n, const int x, long long *nComps) {
  int i = 0;
  while ((*nComps += 2) && i < n && a[i] != x)
    i++;
  return a[i] == x;
}

bool linearSearchFast(int *a, const int n, const int x, long long *nComps) {
  int i = 0;
  int t = a[n];
  a[n] = x;
  while (++*(nComps) && a[i] != x)
    i++;
  a[n] = t;
  return a[i] == x;
}

bool linearSearchOrdered(int *a, const int n, const int x, long long *nComps) {
  int i = 0;
  int t = a[n];
  a[n] = x;
  while (++*(nComps) && a[i] < x)
    i++;
  a[n] = t;
  return i < n;
}

bool binarySearch(const int *a, const int n, const int x, long long *nComps) {
  int left = -1;
  int right = n;
  while (right - left > 1) {
    int middle = left + (right - left) / 2;
    if (++*(nComps) && a[middle] < x)
      left = middle;
    else
      right = middle;
  }
  return a[right] == x;
}

bool blockSearch(int *a, const int n, const int x, long long *nComps) {
  const int blockSize = ceil(sqrt(n));
  const int nBlocks = ceil(n / blockSize);
  for (int beginningOfBlock = blockSize * (nBlocks - 1);
       beginningOfBlock >= 0; beginningOfBlock -= blockSize)
    if (++*(nComps) && a[beginningOfBlock] <= x)
      return linearSearchOrdered(a + beginningOfBlock,
                                 min(blockSize, n - beginningOfBlock), x,
                                 nComps);
  return false;
}

// __________Generators__________
void generateOrderedArray(int *a, int n) {
  for (int i = 0; i < n; i++)
    a[i] = i;
}

void generateRandomArray(int *a, int n) {
  srand(time(0));
  for (int i = 0; i < n; i++)
    a[i] = rand();
}


void checkComps(bool (*searchFunc)(int *, int, int, long long *),
                void (*generateFunc)(int *, int), int size,
                char *experimentName) {
  static size_t runCounter = 1;
  static int innerBuffer[500];
  generateFunc(innerBuffer, size);
  printf("Run #%zu| ", runCounter++);
  printf("Name: %s\n", experimentName);
  long long maxComps = 0;
  long long allComps = 0;
  for (int i = 0; i < size; ++i) {
    long long nComps = 0;
    searchFunc(innerBuffer, size, innerBuffer[i], &nComps);
    allComps += nComps;
    maxComps = max(maxComps, nComps);
  }
  long long averageComps = allComps / size;
  printf("OK! Max comparisons: %lld, average comparisons: %lld\n",
         maxComps, averageComps);
  // запись в файл
  char filename[256];
  sprintf(filename, "./data/%s.csv", experimentName);
  FILE *f = fopen(filename, "a");
  if (f == NULL) {
    printf("FileOpenError %s", filename);
    exit(1);
  }
  fprintf(f, "%d; %lld %lld\n", size, maxComps, averageComps);
  fclose(f);
}

void compsExperiment() {
// описание функций поиска
  SearchFunc unorderedSearch[] = {
    {linearSearch,     "linearSearch"},
    {linearSearchFast, "linearSearchFast"}
  };
  SearchFunc orderedSearch[] = {
    {linearSearchOrdered, "linearSearchOrdered"},
    {binarySearch,        "binarySearch"},
    {blockSearch,         "blockSearch"}
  };
  const unsigned UNORDERED_SEARCHES_N = ARRAY_SIZE(unorderedSearch);
  const unsigned ORDERED_SEARCHES_N = ARRAY_SIZE(orderedSearch);
  // запись статистики в файл
  for (int size = 50; size <= 450; size += 50) {
    printf("------------------------------\n");
    printf("Size: %d\n", size);
    static char filename[128];
    for (int i = 0; i < UNORDERED_SEARCHES_N; i++) {
      // генерация имени файла
      sprintf(filename, "%s_%s",
              unorderedSearch[i].name, "random");
      checkComps(unorderedSearch[i].search,
                 generateRandomArray,
                 size, filename);
    }
    for (int i = 0; i < ORDERED_SEARCHES_N; i++) {
      // генерация имени файла
      sprintf(filename, "%s_%s",
              orderedSearch[i].name, "ordered");
      checkComps(orderedSearch[i].search,
                 generateOrderedArray,
                 size, filename);
    }
    printf("\n");
  }
}