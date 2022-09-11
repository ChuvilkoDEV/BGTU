#ifndef INC_1_3_UOAS_H
#define INC_1_3_UOAS_H

#include <memory.h>
#include "../array/array.h"

typedef struct unordered_array_set {
  int *data; // элементы множества
  size_t size; // количество элементов в множестве
  size_t capacity; // максимальное количество элементов в множестве
} unordered_array_set;

unordered_array_set UOAS_create(size_t capacity);

void UOAS_shrinkToFit(unordered_array_set *a);

size_t UOAS_in(unordered_array_set *set, int value);

bool UOAS_isEqual(unordered_array_set set1,
                  unordered_array_set set2);

void UOAS_isAbleAppend(unordered_array_set *set);

void UOAS_insert(unordered_array_set *set, int value);

unordered_array_set UOAS_createFromArray(int *a, int size);

void UOAS_deleteElement(unordered_array_set *set, int value);

unordered_array_set UOAS_union(unordered_array_set set1,
                               unordered_array_set set2);

unordered_array_set UOAS_intersection(unordered_array_set set1,
                                      unordered_array_set set2);

unordered_array_set UOAS_difference(unordered_array_set set1,
                                    unordered_array_set set2);

unordered_array_set UOAS_symmetricDifference(unordered_array_set set1,
                                             unordered_array_set set2);

bool UOAS_isSubset(unordered_array_set set,
                   unordered_array_set subset);

unordered_array_set UOAS_complement(unordered_array_set set,
                                    unordered_array_set universumSet);

void UOAS_print(unordered_array_set set);

void UOAS_delete(unordered_array_set set);

#endif //INC_1_3_UOAS_H
