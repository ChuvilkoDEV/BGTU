#include <stdio.h>
#include <math.h>

#define N 6

/////////////////
/// 1 Задание ///
/////////////////

// Ввод массива a размера size
void inputArray(int *a, size_t const size) {
  for (size_t i = 0; i < size; i++)
    scanf("%d", &a[i]);
}

/////////////////
/// 2 Задание ///
/////////////////

// Вывод массива a размера size
void outputArray(int *a, size_t const size) {
  for (size_t i = 0; i < size; i++)
    printf("%d ", a[i]);
}

/////////////////
/// 3 Задание ///
/////////////////

// Возвращает позицию элемента со значением x. Поиск осуществляется в массиве a
// размера size, начиная с первого элемента. После нахождения первого
// подходящего элемента — поиск прекращается.
int linearSearch(int const *a, size_t const size, int const x) {
  for (int i = 0; i < size; i++)
    if (a[i] == x)
      return i;
  return -1;
}

/////////////////
/// 4 Задание ///
/////////////////

//Возвращает позицию первого отрицательного элемента массива a размера size
int findNegativeIndex(const int *a, const size_t size) {
  for (int i = 0; i < size; i++)
    if (a[i] < 0)
      return i;
  return -1;
}

/////////////////
///*5*Задание*///
/////////////////

// Возвращает позицию элемента с начала массива a размера size
// (по функции-предикату).
int findIndexIf(const int *a, size_t const size, int (*f)(int)) {
  for (int i = 0; i < size; i++)
    if (f(a[i]))
      return i;
  return -1;
}

/////////////////
/// 6 Задание ///
/////////////////

// Возвращает позицию последнего четного элемента массива a размера size
int findLastEvenIndex(int const *a, int const size) {
  for (int i = size - 1; i >= 0; i--)
    if (a[i] % 2 == 0)
      return i;
  return -1;
}

/////////////////
///*7*Задание*///
/////////////////

// Возвращает позицию элемента с конца массива a размера size
// (по функции предикату)
int lastElementIndexIf(int const *a, int const size, int (*f)(int)) {
  for (int i = size - 1; i >= 0; i--)
    if (f(a[i]))
      return i;
  return -1;
}

/////////////////
/// 8 Задание ///
/////////////////

// Возвращает количество отрицательных элементов в массиве а рамера size.
int countNegativeElement(int const *a, size_t const size) {
  int countNegativeElement = 0;
  for (size_t i = 0; i < size; i++)
    if (a[i] < 0)
      countNegativeElement++;
  return countNegativeElement;
}

/////////////////
///*9*Задание*///
/////////////////

// Возвращает количество элементов массива a размера size,
// удовлетворяющих функции-предикату
int countElementIf(int const *a, size_t const size, int (*f)(int)) {
  int countElement = 0;
  for (size_t i = 0; i < size; i++)
    if (f(a[i]))
      countElement++;
  return countElement;
}

//////////////////
/// 10 Задание ///
//////////////////

// Обменивает значения двух переменных a и b типа int
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// Изменяет порядок элементов массива a размера size на обратный
void reverse(int *a, size_t const size) {
  for (size_t firstIndex = 0, lastIndex = size - 1; firstIndex < lastIndex;
       firstIndex++, lastIndex--)
    swap(&a[firstIndex], &a[lastIndex]);
}

//////////////////
/// 11 Задание ///
//////////////////

// Возвращает 1 (Истина), если последовательность элементов массива a размера
// size представляет собой палиндром, в ином случае 0 (Ложь)
int isPalindrome(int const *a, size_t const size) {
  for (size_t firstIndex = 0, lastIndex = size - 1; firstIndex < lastIndex;
       firstIndex++, lastIndex--)
    if (a[firstIndex] != a[lastIndex])
      return 0;
  return 1;
}

//////////////////
/// 12 Задание ///
//////////////////

// Возвращает индекс минимального элемента в массиве a размера size
size_t minIndex(int const *a, size_t const size) {
  size_t minIndex = 0;
  for (size_t i = 0; i < size; i++)
    if (a[i] < a[minIndex])
      minIndex = i;
  return minIndex;
}

// Сортирует выбором массив a размера size по неубыванию
void selectionSort(int *a, size_t const size) {
  for (size_t i = 0; i < size - 1; i++) {
    swap(&a[i], &a[i + minIndex(&a[i], size - i)]);
  }
}

//////////////////
/// 13 Задание ///
//////////////////

// Удаляет все нечетные элементы из массива а размера size
void deleteUneven(int *a, size_t *size) {
  int lastEvenIndex = 0;
  for (size_t i = 0; i < *size; i++) {
    if (a[i] % 2 == 0) {
      swap(&a[lastEvenIndex++], &a[i]);
      (*size)--;
    }
  }
}

//////////////////
/// 14 Задание ///
//////////////////

// Возвращает увеличенный массив a рамера size, с добавленным элементом x,
// который встанет на позицию pos. При том сохраняется относительная
// последовательность других элементов.
void addElement(int *a, size_t *size, int const x, int const pos) {
  int last;
  for (size_t i = 0; i <= *size; i++)
    if (i == pos) {
      last = a[i];
      a[i] = x;
    } else if (i > pos) {
      int tmp = a[i];
      a[i] = last;
      last = tmp;
    }
  (*size)++;
}

//////////////////
/// 15 Задание ///
//////////////////

// Добавляет элемент в конец массива а размера size
void append(int *a, size_t *size, int x) {
  a[*size] = x;
  (*size)++;
}

//////////////////
/// 16 Задание ///
//////////////////

// Удаляет элемент массива a размера n, находящийся на позиции pos, сохраняя
// относительную последовательность остальных элементов
void deleteElementKeeping(int *a, size_t *size, int const pos) {
  (*size)--;
  for (int i = 0; i < *size; i++) {
    if (i >= pos)
      a[i] = a[i + 1];
  }
}

//////////////////
/// 17 Задание ///
//////////////////

// Удаляет элемент массива a размера size, находящийся на позиции pos, не
// сохраняя относительную последовательность остальных элементов
void deleteElementNotKeeping(int *a, size_t *size, int const pos) {
  (*size)--;
  a[pos] = a[*size];
}

//////////////////
///*18*Задание*///
//////////////////

// Совершает циклический сдвиг влево массива а размера size на k позиций
void cyclicShift(int *a, size_t *size, size_t k) {
  if (*size < k)
    k = *size;
  for (int i = 0; i < *size - k; i++) {
    a[i] = a[i + k];
  }
  *size -= k;
}
//////////////////
///*19*Задание*///
//////////////////

// Применяет функцию f() к элементам массива a размера size
void forEach(int *a, size_t size, int (*f)(int)) {
  for (size_t i = 0; i < size; i++)
    a[i] = f(a[i]);
}

//////////////////
///*20*Задание*///
//////////////////

// Возвращает значение 1 (Истина), если хотя бы один элемент массива a размера
// size удовлетворяет функции-предикату f, иначе 0 (Ложь).
int any(int const *a, size_t const size, int (*f)(int)) {
  for (size_t i = 0; i < size; i++)
    if (f(a[i]))
      return 1;
  return 0;
}

//////////////////
///*21*Задание*///
//////////////////

// Возвращает значение 1 (Истина), если хотя бы один элемент массива a размера
// size удовлетворяет функции-предикату f, иначе 0 (Ложь).
int all(int const *a, size_t const size, int (*f)(int)) {
  for (size_t i = 0; i < size; i++)
    if (f(a[i]) == 0)
      return 0;
  return 1;
}

//////////////////
///*22*Задание*///
//////////////////

int isNegative(int a) {
  if (a < 0)
    return 1;
  return 0;
}

// Разделяет массив a размера size на элементы, удовлетворяющие
// функции-предикату f, сохраняя в массиве b, иначе - в массиве c
void arraySplit(int const *a, size_t const size, int (*f)(int), int *b,
                size_t *sizeB, int *c, size_t *sizeC) {
  for (size_t i = 0; i < size; i++) {
    if (f(a[i]))
      append(b, sizeB, a[i]);
    else
      append(c, sizeC, a[i]);
  }
}

////////////////////////////////////////////////////////////////////////////////
///                               Второй  блок                               ///
////////////////////////////////////////////////////////////////////////////////


/////////////////
/// 1 Задание ///
/////////////////

// Возвращает знаменатель геометрической последовательности. Если целочисленный
// знаменатель найти не получается - возвращает 0
int denominatorGeomProgression(int const a, const int b) {
  if (a % b == 0 && b != 0)
    return a / b;
  return 0;
}

// Возвращает 1, если элементы массива представляют собой
// геометрическую прогрессию.
int isGeomProgression_(int const *a, const size_t size) {
  int q = denominatorGeomProgression(a[0], a[1]);
  for (size_t i = 1; i < size - 1 && q != 0; i++) {
    if (q != denominatorGeomProgression(a[i], a[i + 1]))
      return 0;
  }
  return q != 0;
}

// Возвращает 1, если переставив элементы массива, можно получить
// геометрическую прогрессию (для целочисленных)
int isGeomProgression(int *a, const size_t size) {
  if (size < 2)
    return 0;
  selectionSort(a, size);
  return isGeomProgression_(a, size);
}

/////////////////
/// 2 Задание ///
/////////////////

// Возвращает 1 (Истина), если число x не встречается в массиве a,
// под индексами [firstIndex; lastIndex), в ином случае 0 (Ложь).
int isUniqueNumber(int const *const a, const int x, const size_t firstIndex,
                   const size_t lastIndex) {
  for (size_t i = firstIndex; i < lastIndex; i++)
    if (a[firstIndex] == x)
      return 0;
  return 1;
}

// Возвращает 1 (Истина), если все значения в массиве а размера size -
// уникальны, в ином случае 0 (Ложь)
int isUniqueNumbers(int *const a, const size_t size) {
  for (size_t i = 0; i < size - 1; i++)
    if (isUniqueNumber(a, a[i], i + 1, size) == 0)
      return 0;
  return 1;
}

// Упорядочивает массив a размера size по убыванию, если упорядочить по
// убыванию невозможно (есть элементы, знчаения которых равны), то оставляет
// массив без изменения
void sortDescending(int *const a, const size_t size) {
  if (isUniqueNumbers(a, size)) {
    selectionSort(a, size);
  }
}

/////////////////
/// 3 Задание ///
/////////////////

void findMinMax(int const *const a, size_t size, size_t *minIndex,
                size_t *maxIndex) {
  for (size_t i = 1; i < size; i++) {
    if (a[i] <= a[*minIndex])
      *minIndex = i;
    else if (a[i] > a[*maxIndex])
      *maxIndex = i;
  }
}

void sortDescendingBetweenMinMax(int *a, size_t size) {
  size_t minIndex = 0, maxIndex = 0;
  findMinMax(a, size, &minIndex, &maxIndex);
  if (maxIndex < minIndex) {
    selectionSort(&a[maxIndex + 1], minIndex - 1);
  }
}

/////////////////
/// 4 Задание ///
/////////////////

// Возвращает 1 - если все элементы последовательности равны, 2 - если
// последовательность неубывающая, 3 - если последовательность невозрастающая,
// 0 - если последовательность неупорядоченна
int isRegularSequence(int const *const a, size_t const size) {
  int regularSequence;
  if (a[0] == a[1])
    regularSequence = 1;
  else if (a[0] < a[1])
    regularSequence = 2; // Неубывающая
  else
    regularSequence = 3; // Невозрастающая
  for (size_t i = 1; i < size - 1; i++) {
    if ((regularSequence == 2 && a[i] > a[i + 1]) ||
        (regularSequence == 3 && a[i] < a[i + 1]))
      return 0;
  }
  return regularSequence;
}

int geometricAverage(int const *const a, size_t const size) {
  if (isRegularSequence(a, size) == 0) {
    int p = 1, n = 0;
    for (size_t i = 0; i < size; i++)
      if (a[i] > 0) {
        p *= a[i];
        n++;
      }
    if (n == 0)
      return 0;
    double sqrtN = 1.0 / n;
    return (int) pow(p, sqrtN);
  }
  printf("Последовательность упорядочена"); // Сделать через массив
}

/////////////////
/// 5 Задание ///
/////////////////

void sortAfterX(int *a, size_t size, int const x) {
  int indexX = linearSearch(a, size, x);
  if (indexX < size - 1 && indexX != -1)
    selectionSort(&a[indexX + 1], size - indexX - 1);
}

/////////////////
/// 6 Задание ///
/////////////////

void sortUniqueNumbers(int *const a, size_t const sizeA,
                       int *const b, size_t const sizeB,
                       int *c, size_t *sizeC) {
  selectionSort(a, sizeA);
  selectionSort(b, sizeB);
  for (size_t i = 0; i < sizeA; i++)
    if (isUniqueNumber(b, sizeB, 0, a[i]))
      append(c, sizeC, a[i]);
  reverse(c, *sizeC);
}

/////////////////
/// 7 Задание ///
/////////////////



int main() {
  size_t n = 6;
  int a[n];
  inputArray(a, n);

  cyclicShift(a, &n, 2);
  outputArray(a, n);

  return 0;
}
