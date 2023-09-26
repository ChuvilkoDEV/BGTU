#ifndef LAB_5C_ARRAY__H
#define LAB_5C_ARRAY__H

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#include "../algorithms/algorithms.h"


// Ввод массива a размера size
void inputArray_(int *a, size_t size);

// Вывод массива a размера size
void outputArray_(int *a, size_t size);

// Возвращает позицию элемента со значением x. Поиск осуществляется в массиве a
// размера size, начиная с первого элемента. После нахождения первого
// подходящего элемента — поиск прекращается.
int linearSearch_(int const *a, size_t size, int x);

// Возвращает индекс минимального элемента в массиве a размера size
size_t minIndex_(int const *a, size_t size);

// Возвращает увеличенный массив a рамера size, с добавленным элементом x,
// который встанет на позицию pos. При том сохраняется относительная
// последовательность других элементов.
void addElement_(int *a, size_t *size, int x, int pos);

// Добавляет элемент в конец массива а размера size
void append_(int *a, size_t *size, int x);

// Применяет функцию f() к элементам массива a размера size
void forEach_(int *a, size_t size, int (*f)(int));

// Возвращает значение 1 (Истина), если хотя бы один элемент массива a размера
// size удовлетворяет функции-предикату f, иначе 0 (Ложь).
int any_(int const *a, size_t size, int (*f)(int));

// Возвращает значение 1 (Истина), если хотя бы один элемент массива a размера
// size удовлетворяет функции-предикату f, иначе 0 (Ложь).
int all_(int const *a, size_t size, int (*f)(int));

// Возвращает 1 (Истина), если число x не встречается в массиве a,
// под индексами [firstIndex; lastIndex), в ином случае 0 (Ложь).
bool isUniqueNumber_(int *a, int x, size_t firstIndex, size_t lastIndex);

// Возвращает 1 (Истина), если все значения в массиве а размера size -
// уникальны, в ином случае 0 (Ложь)
bool isUniqueNumbers_(int *a, size_t size);

// Возвращает true, если массив отсортирован оп неубыванию, false в ином случае
bool isOrdered_(const int *a, int n);

void getMinMax_(const int *a, size_t size, int *min, int *max);

void generateRandomArray(int *a, size_t n);

void generateOrderedArray(int *a, size_t n);

void generateOrderedBackwards(int *a, size_t n);

#endif //LAB_5C_ARRAY__H
