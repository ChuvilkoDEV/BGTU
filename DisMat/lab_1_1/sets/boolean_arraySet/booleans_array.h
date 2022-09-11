#ifndef INC_BOOLEANS_ARRAY_H
#define INC_BOOLEANS_ARRAY_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct boolean_array_set {
    bool *data; // элементы множества
    size_t size; // количество элементов в массиве
    size_t maxValue; // максимальное количество элементов в множестве
} boolean_array_set;

boolean_array_set boolean_array_set_create(uint32_t maxValue);

// возвращает пустое множество c универсумом 0, 1,..., maxValue
boolean_array_set boolean_array_set_createFromArray(
  int *a, uint32_t size, uint32_t maxSize
);

//Возвращает значение ’истина’, если значение переменной value
// может принадлежать множеству set, иначе - ’ложь’
bool boolean_array_set_checkValue(boolean_array_set set, uint32_t value);

// возвращает значение ’истина’, если значение value имеется в множестве set // иначе - ’ложь’
bool boolean_array_set_in(boolean_array_set set, uint32_t value);

// возвращает значение ’истина’, если множества set1 и set2 равны
// иначе - ’ложь’
bool boolean_array_set_isEqual(boolean_array_set set1, boolean_array_set set2);

// добавляет элемент value в множество set
void boolean_array_set_insert(boolean_array_set *set, uint32_t value);

// возвращает пересечение множеств set1 и set2
boolean_array_set boolean_intersection(boolean_array_set set1,
                                       boolean_array_set set2);

// удаляет элемент value из множества set
void boolean_array_set_deleteElement(boolean_array_set *set, size_t value);

// возвращает объединение множеств set1 и set2
boolean_array_set boolean_array_set_union(boolean_array_set set1,
                                          boolean_array_set set2);

// возвращает разность множеств set1 и set2
boolean_array_set
boolean_array_set_difference(boolean_array_set set1, boolean_array_set set2);

// возвращает симметрическую разность множеств set1 и set2
boolean_array_set boolean_array_set_symmetricDifference(boolean_array_set set1,
                                                        boolean_array_set set2);

// возвращает дополнение до универсума множества set
boolean_array_set boolean_complement(boolean_array_set set,
                                     boolean_array_set universumSet);

boolean_array_set boolean_array_set_create_from_array(bool *set, size_t
maxValue, size_t size);

boolean_array_set boolean_array_set_reverse(boolean_array_set set);

// вывод множества set
void boolean_array_set_print(boolean_array_set set);

// освобождает память, занимаемую множеством set
void boolean_array_set_delete(boolean_array_set set);

#endif