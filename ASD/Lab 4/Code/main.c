#include <stdio.h>
#include "stdbool.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>

unsigned numCompares = 0;

bool linearSearch(int *a, const int n, const int x) {
  int *ptr = a;
  for (int i = 0; i < n; i++) {
    numCompares++;
    if (*ptr == x)
      return true;
  }
  return false;
}

bool linearSearchFast(int *a, const int n, const int x) {
  int i = 0;
  int t = a[n];
  a[n] = x;
  while (a[i] != x) {
    numCompares++;
    i++;
  }
  a[n] = t;
  return a[i] == x;
}

bool linearSearchOrdered(int *a, const int n, const int x) {
  int i = 0;
  int t = a[n];
  a[n] = x;
  while (a[i] < x) {
    numCompares++;
    i++;
  }
  a[n] = t;
  return i < n;
}

bool binarySearch(int *a, const int n, const int x) {
  int left = -1;
  int right = n;
  while (right - left > 1) {
    numCompares++;
    int middle = left + (right - left) / 2;

    numCompares++;
    if (a[middle] < x)
      left = middle;
    else
      right = middle;
  }
  return a[right] == x;
}

int min(const int x, const int y) {
  return x < y ? x : y;
}
 
bool blockSearch(int *a, const int n, const int x) {
  const int blockSize = ceil(sqrt(n));
  const int nBlocks = ceil(n / blockSize);
  for (int beginningOfBlock = blockSize * (nBlocks - 1);
       beginningOfBlock >= 0; beginningOfBlock -= blockSize)
    if (++numCompares && a[beginningOfBlock] <= x)
      return linearSearchOrdered(a + beginningOfBlock,
                                 min(blockSize, n - beginningOfBlock), x);
  return false;
}


void getSortedArray(int *a, int n) {
  for (int i = 0; i < n; i++) {
    a[i] = i;
  }
}

void getReversedArray(int *a, int n) {
  for (int i = 0; i < n; i++) {
    a[i] = n - 1 - i;
  }
}

void getRandomArray(int *a, int n) {
  for (int i = 0; i < n; i++) {
    a[i] = rand() % n;
  }
}

#define SIZE_ARRAY 50
#define ACCURACY 1000

void getTimesForOrdered(bool (*SearchFunc)(int*, int, int)) {
  int array[SIZE_ARRAY];

  for (int size = 5; size <= SIZE_ARRAY; size += 5) {
    getSortedArray(array, size);

    unsigned sum = 0;
    for (int i = 0; i < ACCURACY; i++) {
      numCompares = 0;
      SearchFunc(array, size, rand() % size);
      sum += numCompares;
    }

    printf("%d ", (int)ceil((float)sum / (float)ACCURACY));
  }
  printf("\n");
}

void getTimesForUnordered(bool (*SearchFunc)(int*, int, int)) {
  int array[100];

  getTimesForOrdered(SearchFunc);

  for (int size = 5; size <= SIZE_ARRAY; size += 5) {
    getReversedArray(array, size);

    unsigned sum = 0;
    for (int j = 0; j < ACCURACY; j++) {
      numCompares = 0;
      SearchFunc(array, size, rand() % size);
      sum += numCompares;
    }

    printf("%d ", sum / ACCURACY);
  }
  printf("\n");

  for (int size = 5; size <= SIZE_ARRAY; size += 5) {
    getRandomArray(array, size);

    unsigned sum = 0;
    for (int i = 0; i < ACCURACY; i++) {
      numCompares = 0;
      SearchFunc(array, size, rand() % size);
      sum += numCompares;
    }

    printf("%d ", sum / ACCURACY);
  }
  printf("\n");
}

int main() {
  printf("linearSearch:\n");
  getTimesForUnordered(&linearSearch);

  printf("\nlinearSearchFast:\n");
  getTimesForUnordered(&linearSearchFast);

  printf("\nlinearSearchOrdered:\n");
  getTimesForOrdered(&linearSearchOrdered);

  printf("\nbinarySearch:\n");
  getTimesForOrdered(&binarySearch);

  printf("\nblockSearch:\n");
  getTimesForOrdered(&blockSearch);
}