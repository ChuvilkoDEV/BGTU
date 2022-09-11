#ifndef LAB_1_1_ORDEREDSET_H
#define LAB_1_1_ORDEREDSET_H

#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#include "../../libs/array/array.h"

typedef struct orderedSet {
  int *data;        // элементы множества
  size_t size;      // количество элементов в множестве
  size_t capacity;  // максимальное количество элементов в множестве
} orderedSet;

// возвращает пустое множество, в которое можно вставить capacity элементов
orderedSet orderedSet_create(size_t capacity);

// возвращает множество, состоящее из элементов массива a размера size
orderedSet orderedSet_createFromArray(const int *a,
                                      size_t size);

// возвращает значение позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
size_t orderedSet_in(orderedSet *set, int value);

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool orderedSet_isEqual(orderedSet set1,
                        orderedSet set2);

// возвращает значение ’истина’, если subset является подмножеством set
// иначе - ’ложь’
bool orderedSet_isSubset(orderedSet subset,
                         orderedSet set);

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void orderedSet_isAbleAppend(orderedSet *set);

// добавляет элемент value в множество set
void orderedSet_insert(orderedSet *set, int value);

// удаляет элемент value из множества set
void orderedSet_deleteElement(orderedSet *set, int value);

// возвращает объединение множеств set1 и set2
orderedSet orderedSet_union(orderedSet set1,
                            orderedSet set2);

orderedSet orderedSet_intersection(
  orderedSet set1, orderedSet set2
);

orderedSet orderedSet_difference(
  orderedSet set1, orderedSet set2, orderedSet set3
);

orderedSet orderedSet_symmetricDifference(
  orderedSet set1, orderedSet set2
);

orderedSet orderedSet_complement(
  orderedSet universumSet, orderedSet set
);

void orderedSet_delete(orderedSet set);

// вывод множества set
void orderedSet_output(orderedSet set);

#endif //LAB_1_1_ORDEREDSET_H
