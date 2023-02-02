#include "implementation.h"

void inputArray_(int *const a, const int n) {
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
}

void outputArray_(const int *const a, const int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}

//Задание 1
// Условие задания:
// А – массив натуральных чисел, в котором нет одинаковых элементов;
// B – массив натуральных чисел, в котором нет одинаковых элементов.
// Получить массив С, содержащий все элементы массивов А и В без повторений.
void unordered_unionUniqueArray(int const *const a, int const sizeA,
                                int const *const b, int const sizeB,
                                int *c, int *sizeC) {
  for (int i = 0; i <= sizeA; i++)
    c[(*sizeC)++] = a[i];
  for (int i = 0; i < sizeB; i++) {
    bool flag = false;
    for (int j = 0; j < *sizeC; j++)
      if (a[i] == c[j])
        flag = true;
    if (flag == false)
      c[(*sizeC)++] = b[i];
  }
}

//

// Задание 2
// Условие задания:
// А – массив натуральных чисел, в котором нет одинаковых элементов;
// B – массив натуральных чисел, в котором нет одинаковых элементов.
// Получить массив С, содержащий все такие элементы, которые есть и
// в массиве А и в массиве В.
void unordered_intersectionArray(int const *const a, int const sizeA,
                                 int const *const b, int const sizeB,
                                 int *c, int *sizeC) {
  for (int i = 0; i < sizeA; i++)
    for (int j = 0; j < sizeB; j++)
      if (a[i] == b[j])
        c[(*sizeC)++] = a[i];
}

// Задание 3
// Условие задания:
// А – массив натуральных чисел, в котором нет одинаковых элементов;
// B – массив натуральных чисел, в котором нет одинаковых элементов.
// Получить массив С, содержащий все элементы массива А, которых нет в B.
void unordered_differenceArray(int const *const a, int const sizeA,
                               int const *const b, int const sizeB,
                               int *c, int *sizeC) {
  for (int i = 0; i < sizeA; i++) {
    bool flag = false;
    for (int j = 0; j < sizeB; j++)
      if (a[i] == b[j])
        flag = true;
    if (flag == false)
      c[(*sizeC)++] = a[i];
  }
}

// Задание 4
// Условие задания:
// А – массив натуральных чисел, в котором нет одинаковых элементов;
// B – массив натуральных чисел, в котором нет одинаковых элементов.
// Получить массив С, содержащий все элементы массива А, которых нет
// в B и все элементы массива В, которых нет в А.
void unordered_symmetricDifferenceArray(int const *const a, int const sizeA,
                                        int const *const b, int const sizeB,
                                        int *c, int *sizeC) {
  for (int i = 0; i < sizeA; i++) {
    bool flag = false;
    for (int j = 0; j < sizeB; j++)
      if (a[i] == b[j])
        flag = true;
    if (flag == false)
      c[(*sizeC)++] = a[i];
  }
  for (int i = 0; i < sizeB; i++) {
    bool flag = false;
    for (int j = 0; j < sizeA; j++)
      if (b[i] == a[j])
        flag = true;
    if (flag == false)
      c[(*sizeC)++] = a[i];
  }
}

// Задание 5
// Условие задания:
// А – массив натуральных чисел, в котором нет одинаковых элементов;
// B – массив натуральных чисел, в котором нет одинаковых элементов.
// Определить, верно ли, что массив B содержит каждый элемент массива А.
bool unordered_isEquivalent(int const *const a, int const sizeA,
                            int const *const b, int const sizeB) {
  for (int i = 0; i < sizeA; i++) {
    bool flag = false;
    for (int j = 0; j < sizeB; j++)
      if (a[i] == b[j])
        flag = true;
    if (flag == false)
      return false;
  }
  return true;
}

// Задание 6
// Условие задания:
// А – массив натуральных чисел, в котором нет одинаковых элементов;
// B – массив натуральных чисел, в котором нет одинаковых элементов.
// Определить, верно ли, что массивы А и B состоят из одинаковых элементов.
bool unordered_isEqual(int const *const a, int const sizeA,
                       int const *const b, int const sizeB) {
  if (sizeA != sizeB)
    return false;
  for (int i = 0; i < sizeA; i++) {
    bool flag = false;
    for (int j = 0; j < sizeB; j++)
      if (a[i] == b[j])
        flag = true;
    if (flag == false)
      return false;
  }
  return true;
}

// Задание 7
// Условие задания:
// А – массив натуральных чисел, в котором нет одинаковых элементов;
// B – массив натуральных чисел, в котором нет одинаковых элементов.
// Определить, верно ли, что в массивах А и B нет общих элементов.
bool unordered_isNotIntersecting(int const *const a, int const sizeA,
                                 int const *const b, int const sizeB) {
  for (int i = 0; i < sizeA; i++) {
    bool flag = false;
    for (int j = 0; j < sizeB; j++)
      if (a[i] == b[j])
        flag = true;
    if (flag == true)
      return false;
  }
  return true;
}

// Задание 8
// Условие задания:
// Даны массивы натуральных чисел А и В, упорядоченные по возрастанию.
// Получить упорядоченный по возрастанию массив С, содержащий все элементы
// массивов А и В.
void ordered_unionArrayUnique(int const *const a, int const sizeA,
                              int const *const b, int const sizeB,
                              int *c, int *sizeC) {
  int ptrA = 0, ptrB = 0, corrective = 0;
  while (ptrA + ptrB - corrective < sizeA + sizeB)
    if (a[ptrA] == b[ptrB]) {
      c[(*sizeC)++] = a[ptrA++];
      corrective++;
    } else if (a[ptrA] < b[ptrB])
      c[(*sizeC)++] = a[ptrA++];
    else
      c[(*sizeC)++] = b[ptrB++];
}

// Задание 9
// Условие задания:
// Даны массивы натуральных чисел А и В, упорядоченные по возрастанию.
// Получить упорядоченный по возрастанию массив С, содержащий все
// такие элементы, которые есть и в массиве А и в массиве В.
void ordered_unionArrayRepeat(int const *const a, int const sizeA,
                              int const *const b, int const sizeB,
                              int *c, int *sizeC) {
  int ptrA = 0, ptrB = 0;
  while (ptrA + ptrB < sizeA + sizeB)
    if (a[ptrA] == b[ptrB]) {
      c[(*sizeC)++] = a[ptrA++];
      c[(*sizeC)++] = b[ptrB++];
    } else if (a[ptrA] < b[ptrB])
      c[(*sizeC)++] = a[ptrA++];
    else
      c[(*sizeC)++] = b[ptrB++];
}

// Задание 10
// Условие задания:
// Даны массивы натуральных чисел А и В, упорядоченные по возрастанию.
// Получить упорядоченный по возрастанию массив С, содержащий все элементы
// массива А, которых нет в B.
void ordered_differenceArraySorted(int const *const a, int const sizeA,
                                   int const *const b, int const sizeB,
                                   int *c, int *sizeC) {
  int ptrA = 0, ptrB = 0;
  bool flag = false;
  while (ptrA < sizeA) {
    if (ptrB == sizeB && flag == false) {
      c[(*sizeC)++] = a[ptrA++];
      ptrB = 0;
    } else
      flag = false, ptrA++, ptrB = 0;
    if (a[ptrA] == b[ptrB])
      flag = true;
    ptrB++;
  }
}

// Задание 11
// Условие задания:
// Даны массивы натуральных чисел А и В, упорядоченные по возрастанию.
// Получить упорядоченный по возрастанию массив С, содержащий все элементы
// массива А, которых нет в B и все элементы массива В, которых нет в А.
void ordered_symmetricDifferenceArraySorted(int const *const a, int const sizeA,
                                            int const *const b, int const sizeB,
                                            int *c, int *sizeC) {
  int ptrA = 0, ptrB = 0;
  bool flag = false;
  while (ptrA < sizeA) {
    if (ptrB == sizeB && flag == false) {
      c[(*sizeC)++] = a[ptrA++];
      ptrB = 0;
    } else
      flag = false, ptrA++, ptrB = 0;
    if (a[ptrA] == b[ptrB])
      flag = true;
    ptrB++;
  }
  ptrA = 0, ptrB = 0, flag = false;
  while (ptrB < sizeB) {
    if (ptrA == sizeA && flag == false) {
      c[(*sizeC)++] = a[ptrB++];
      ptrA = 0;
    } else {
      flag = false;
      ptrB++, ptrA = 0;
    }
    if (a[ptrA] == b[ptrB])
      flag = true;
    ptrA++;
  }
}

// Задание 12
// Условие задания:
// Даны массивы натуральных чисел А и В, упорядоченные по возрастанию.
// Определить, верно ли, что массив B содержит каждый элемент массива А.
bool ordered_isEqualOrder(int const *const a, int const sizeA,
                          int const *const b, int const sizeB) {
  if (sizeA != sizeB)
    return false;
  for (int i = 0; i < sizeA; i++)
    if (a[i] != b[i])
      return false;
  return true;
}