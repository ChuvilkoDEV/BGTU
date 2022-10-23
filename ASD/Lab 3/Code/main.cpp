#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

int N = 500;

// обмен значений двух переменных по адресам a и b
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

//сортировка включением
int insertionSort(int *a, const int size) {
  int count = 0;
  for (int i = 1; ++count && i < size; i++) {
    int t = a[i];
    int j = i;
    while (++count && j > 0 && ++count && a[j - 1] > t) {
      a[j] = a[j - 1];
      j--;
    }
    a[j] = t;
  }
  return count;
}

//сортировка выбором
int selectionSort(int *a, int size) {
  int count = 0;
  for (int i = 0; ++count && i < size - 1; i++) {
    int minPos = i;
    for (int j = i + 1; ++count && j < size; j++)
      if (++count && a[j] < a[minPos])
        minPos = j;
    swap(&a[i], &a[minPos]);
  }
  return count;
}

//сортировка обменом
int bubbleSort(int *a, int size) {
  int count = 0;
  for (size_t i = 0; ++count && i < size - 1; i++)
    for (size_t j = size - 1; ++count && j > i; j--)
      if (++count && a[j - 1] > a[j])
        swap(&a[j - 1], &a[j]);

  return count;
}

//Улучшенная обменом 1
/*После каждого прохода в сортировке обменом может быть сделана проверка,были
ли совершены перестановки в течение данного прохода.Если
перестановок не было, то это означает,что
массив упорядочен и дальнейших проходов не требуется.*/
int bubbleSort1(int *a, int size) {

  int count = 0;
  int f;
  int i = 1;
  do {
    f = 0;
    for (size_t j = size - 1; ++count && j >= i; j--) {
      if (++count && a[j - 1] >= a[j]) {
        swap(&a[j - 1], &a[j]);
        f = 1;
      }
    }
    i++;
  } while ((++count && f == 1) && (++count && i < size));
  return count;
}

/*В отличие от улучшенной сортировки обменом 1 здесь в течение
проходафиксируется
 последний элемент, участвующий в обмене.В
 очередном проходе этот элемент и все предшествующие в сравнении не участвуют,тк
 .. все элементы до этой позиции уже отсортированы.*/


int bubbleSort2(int *a, int size) { //Улучшенная обменом 2
  int count = 0;
  int i = 1;
  do {
    int k = size;
    for (size_t j = size - 1; ++count && j >= i; j--) {
      if (a[j - 1] > a[j] && ++count) {
        swap(&a[j - 1], &a[j]);
        k = j;
      }
    }
    i = k;
  } while (++count && i < size); //Если перестановок не было, выйти из алгоритма
  return count;
}
//сортировка Шелла

int shellSort(int *a, int size) {
  int count = 0;
  for (int d = size / 2; ++count && d > 0; d /= 2)
    for (int i = d; ++count && i < size; ++i)
      for (int j = i - d; (++count && j >= 0) && (++count && a[j] >
                                                             a[j + d]); j -= d)
        swap(&a[j], &a[j + d]);
  return count;
}

int QSort(int a[], int L, int R) {
  int count = 0;
  int x = a[L], i = L, j = R; // в качестве разделителя выбираем первый элемент
  while (++count && i <= j) {
    while (++count && a[i] < x)
      i++;
    while (++count && a[j] > x)
      j--;
    if (++count && i <= j) {
      swap(&a[i], &a[j]);
      i++;
      j--;
    }
  }
  if (++count && L < j)
    count += QSort(a, L, j);
  if (++count && i < R)
    count += QSort(a, i, R);
  return count;
}
//функция сортировки методом Хоара

int HoarSort(int a[], int n) {
  return QSort(a, 0, n);
}

int Sift(int a[], int L, int R) {
  int count = 0;
  int i, j, x;
  i = L;
  j = 2 * L + 1;
  x = a[L];
  if (++count && (j < R) && (++count && a[j] < a[j + 1]))
    j++;
  while (++count && (j <= R) && (++count && x < a[j])) {
    swap(&a[i], &a[j]);
    i = j;
    j = 2 * j + 1;
    if (++count && (j < R) && (++count && a[j] < a[j + 1]))
      j++;
  }
  return count;
}

//пирамидальная функция сортировки

int HeapSort(int A[], int nn) {
  int count = 0;
  int L, R, x;
  L = nn / 2;
  R = nn - 1;
  //Построение пирамиды из исходного массива
  while (++count && L > 0) {
    L = L - 1;
    count += Sift(A, L, R);
  }
  //Сортировка: пирамида => отсортированный массив
  while (++count && R > 0) {
    x = A[0];
    A[0] = A[R];
    A[R] = x;
    R--;
    count += Sift(A, L, R);
  }
  return count;
}

void output(int *a) {
  for (int i = 0; i < N; ++i) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

//Обратно упорядоченный массив


void BackSorted(int *a) {
  for (int i = 0; i < N; ++i) {
    a[i] = N - i;
  }
}

//упорядоченный массив
void Sorted(int *a) {
  for (int i = 0; i < N; ++i) {
    a[i] = i;
  }
}

//Неупорядоченный массив

void Unsorted(int *a) {
  for (int i = 0; i < N; ++i) {
    a[i] = rand() % 100;
  }
}

FILE *csvFiles[3];

typedef int (*sort_func )(int *, int);

typedef void (*gen_f )(int *);

int TIME_TEST(int *a, int n, gen_f gen, sort_func s) {
  gen(a);
  return s(a, N);
}

int isSorted(int *a) {
  for (int i = 1; i < N; i++) {
    if (a[i - 1] > a[i]) {
      return 0;
    }
  }
  return 1;
}

#define ARRAY_SIZE(array) \
sizeof(array) / sizeof(int)

const int sizes[] = {5, 10, 15, 20, 25, 30, 35, 40, 45};
const int sizes_count = ARRAY_SIZE(sizes);
typedef struct {
  char name[100];
  sort_func func;

} sort_f;

int main() {
  for (int i = 0; i < 3; i++) {
    char filename[100];
    sprintf(filename, "data%d.txt", i);
    csvFiles[i] = fopen(filename, "w");
  }
  int a[1000];
  gen_f gen_funcs[3] = {
    BackSorted,
    Sorted,
    Unsorted,
  };


  sort_f sort_funcs[8] = {
    {" insertion sort ", insertionSort},
    {" selection sort ", selectionSort},
    {" bubble sort ",    bubbleSort},
    {" bubble sort 1",   bubbleSort1},
    {" bubble sort 2",   bubbleSort2},
    {" shell sort ",     shellSort},
    {" Hoar sort ",      HoarSort},
    {" heap sort ",      HeapSort},
  };


  for (int g_f = 0; g_f < 3; g_f++) {
    fprintf(csvFiles[g_f], " Sort name ;");
    for (int i = 0; i < sizes_count; i++) {
      fprintf(csvFiles[g_f], "%d;", sizes[i]);
    }
    fprintf(csvFiles[g_f], "\n");
    for (int s_f = 0; s_f < 8; s_f++) {
      fprintf(csvFiles[g_f], "%s;", sort_funcs[s_f].name);
      for (int size = 0; size < sizes_count; size++) {
        N = sizes[size];
        int comps = TIME_TEST(a, N, gen_funcs[g_f],
                              sort_funcs[s_f].func);
        assert(isSorted(a));
        fprintf(csvFiles[g_f], "%d;", comps);
      }
      fprintf(csvFiles[g_f], "\n");
    }
  }
  for (int i = 0; i < 3; i++) {
    fclose(csvFiles[i]);
  }
  return 0;
}