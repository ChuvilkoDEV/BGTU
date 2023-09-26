#ifndef LAB_1_1_ARRAY_H
#define LAB_1_1_ARRAY_H

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <assert.h>

#include "../algorithms/algorithms.h"


// Ввод массива a размера size
void inputArray(int *a, size_t size);

// Вывод массива a размера size
void outputArray(int *a, size_t size);

// Возвращает позицию элемента со значением x. Поиск осуществляется в массиве a
// размера size, начиная с первого элемента. После нахождения первого
// подходящего элемента — поиск прекращается.
int linearSearch(int const *a, size_t size, int x);

// возвращает позицию вхождения элемента x
// в отсортированном массиве a размера n при его наличии, иначе - SIZE_MAX
int binarySearch(const int *a, int n, int x);

// возвращает позицию первого элемента равного или большего x
// в отсортированном массиве a размера n
// при отсутствии такого элемента возвращает n
size_t binarySearchMoreOrEqual(const int *a, size_t n, int x);

// вставка элемента со значением value
// в массив data размера n на позицию pos
void insert(int *a, size_t *n, size_t pos, int value);

// добавление элемента value в конец массива data размера n
void append_(int *a, size_t *n, int value);

// удаление из массива data размера n элемента на позиции pos
// с сохранением порядка оставшихся элементов
void deleteByPosSaveOrder_(int *a, size_t *n, size_t pos);

// удаление из массива data размера n элемента на позиции pos
// без сохранения порядка оставшихся элементов
// размер массива data уменьшается на единицу
void deleteByPosUnsaveOrder_(int *a, size_t *n, size_t pos);

// Возвращает индекс минимального элемента в массиве a размера size
size_t minIndex(int const *a, size_t size);

// Возвращает увеличенный массив a рамера size, с добавленным элементом x,
// который встанет на позицию pos. При том сохраняется относительная
// последовательность других элементов.
void addElement(int *a, size_t *size, int x, int pos);

// Добавляет элемент в конец массива а размера size
void append(int *a, size_t *size, int x);

// Применяет функцию f() к элементам массива a размера size
void forEach(int *a, size_t size, int (*f)(int));

// Возвращает значение 1 (Истина), если хотя бы один элемент массива a размера
// size удовлетворяет функции-предикату f, иначе 0 (Ложь).
int any(int const *a, size_t size, int (*f)(int));

// Возвращает значение 1 (Истина), если хотя бы один элемент массива a размера
// size удовлетворяет функции-предикату f, иначе 0 (Ложь).
int all(int const *a, size_t size, int (*f)(int));

// Возвращает 1 (Истина), если число x не встречается в массиве a,
// под индексами [firstIndex; lastIndex), в ином случае 0 (Ложь).
bool isUniqueNumber(int *a, int x, int n);

// Возвращает 1 (Истина), если все значения в массиве а размера size -
// уникальны, в ином случае 0 (Ложь)
bool isUniqueNumbers(int *a, int size);

// Применяет функцию предикат для каждого элемента массива
void forEach_(const int *source, int *dest, size_t n,
              const int (*predicate)(int));

// Возвращает true, если массив отсортирован оп неубыванию, false в ином случае
bool isOrdered(const int *a, int n);

void getMinMax(const int *a, size_t size, int *min, int *max);

#endif //LAB_1_1_ARRAY_H
