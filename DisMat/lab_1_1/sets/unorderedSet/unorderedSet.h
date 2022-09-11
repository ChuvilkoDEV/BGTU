#ifndef LAB_1_1_UNORDEREDSET_H
#define LAB_1_1_UNORDEREDSET_H

#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#include "../../libs/array/array.h"


typedef struct unorderedSet {
  int *data;        // элементы множества
  size_t size;      // количество элементов в множестве
  size_t capacity;  // максимальное количество элементов в множестве
} unorderedSet;

// возвращает пустое множество для capacity элементов
unorderedSet unorderedSet_create(size_t capacity);

// возвращает множество, состоящее из элементов массива a размера size
unorderedSet unorderedSet_createFromArray(
  const int *a, size_t size
);

// возвращает позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
size_t unorderedSet_in(unorderedSet *set, int value);

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool unorderedSet_isEqual(
  unorderedSet set1, unorderedSet set2
);

// возвращает значение ’истина’ если множество subset
// является подмножеством множества set, иначе - ’ложь’.
bool unorderedSet_isSubset(
  unorderedSet subset, unorderedSet set
);

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void unorderedSet_isAbleAppend(unorderedSet *set);

// добавляет элемент value в множество set
void unorderedSet_insert(
  unorderedSet *set, int value
);

// удаляет элемент value из множества set
void unorderedSet_deleteElement(
  unorderedSet *set, int value
);

// возвращает объединение множеств set1 и set2
unorderedSet unorderedSet_union(
  unorderedSet set1, unorderedSet set2
);


// возвращает пересечение множеств set1 и set2
unorderedSet unorderedSet_intersection(
  unorderedSet set1, unorderedSet set2
);

// возвращает разность множеств set1 и set2
unorderedSet unorderedSet_difference(
  unorderedSet set1, unorderedSet set2
);

// возвращает симметрическую разность множеств set1 и set2
unorderedSet unorderedSet_symmetricDifference(
  unorderedSet set1, unorderedSet set2
);

// возвращает дополнение до универсума множества set
unorderedSet unorderedSet_complement(
  unorderedSet universumSet, unorderedSet set
);

// освобождает память, занимаемую множеством set
void unorderedSet_delete(unorderedSet set);

// вывод множества set
void unorderedSet_output(unorderedSet set);

#endif //LAB_1_1_UNORDEREDSET_H
