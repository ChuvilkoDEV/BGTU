#include "UOAS.h"

// возвращает пустое множество для capacity элементов
unordered_array_set UOAS_create(size_t capacity) {
  return (unordered_array_set) {
    static_cast<int *>(malloc(sizeof(int) * capacity)),
    0,
    capacity
  };
}

// уменьшает вместимость множества a до его размера
void UOAS_shrinkToFit(unordered_array_set *a) {
  if (a->size != a->capacity) {
    a->data = (int *) realloc(a->data, sizeof(int) * a->size);
    a->capacity = a->size;
  }
}

// возвращает позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
size_t UOAS_in(unordered_array_set *set, int value) {
  return linearSearch_(set->data, set->size, value);
}

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool UOAS_isEqual(unordered_array_set set1,
                  unordered_array_set set2) {
  if (set1.size != set2.size)
    return false;
  qsort(set1.data, set1.size, sizeof(int), compare_ints);
  qsort(set2.data, set2.size, sizeof(int), compare_ints);
  return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;
}

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void UOAS_isAbleAppend(unordered_array_set *set) {
  assert(set->size < set->capacity);
}

// добавляет элемент value в множество set
void UOAS_insert(unordered_array_set *set, int value) {
  if (UOAS_in(set, value) == set->size) {
    UOAS_isAbleAppend(set);
    append_(set->data, &set->size, value);
  }
}

// возвращает множество, состоящее из элементов массива a размера size
unordered_array_set UOAS_createFromArray(int *a, int size) {
  unordered_array_set set = UOAS_create(size);
  for (size_t i = 0; i < size; i++) {
    UOAS_insert(&set, a[i]);
  }
  return set;
}

// удаляет элемент value из множества set
void UOAS_deleteElement(unordered_array_set *set, int value) {
  size_t pos = UOAS_in(set, value);
  if (pos != set->size) {
    deleteByPosUnsaveOrder_(set->data, &set->size, pos);
  }
}

// возвращает объединение множеств set1 и set2
unordered_array_set UOAS_union(unordered_array_set set1,
                               unordered_array_set set2) {
  unordered_array_set set = UOAS_create(set1.size + set2.size);
  memcpy(set.data, set1.data, sizeof(int) * set1.size);
  set.size = set1.size;
  for (size_t i = 0; i < set2.size; i++) {
    UOAS_insert(&set, set2.data[i]);
  }
  return set;
}

// возвращает пересечение множеств set1 и set2
unordered_array_set UOAS_intersection(unordered_array_set set1,
                                      unordered_array_set set2) {
  unordered_array_set set = UOAS_create(set1.size);
  for (int i = 0; i < set1.size; i++) {
    size_t pos = linearSearch_(set2.data, set2.size, set1.data[i]);
    if (pos != set2.size)
      UOAS_insert(&set, set2.data[pos]);
  }
  return set;
}

// возвращает разность множеств set1 и set2
unordered_array_set UOAS_difference(unordered_array_set set1,
                                    unordered_array_set set2) {
  unordered_array_set set = UOAS_create(set1.size);
  for (int i = 0; i < set1.size; i++) {
    size_t pos = UOAS_in(&set2, set1.data[i]);
    if (pos == set2.size)
      UOAS_insert(&set, set1.data[i]);
  }
  return set;
}

// возвращает симметрическую разность множеств set1 и set2
unordered_array_set UOAS_symmetricDifference(unordered_array_set set1,
                                             unordered_array_set set2) {
  return UOAS_union(UOAS_difference(set1, set2),
                    UOAS_difference(set2, set1));
}

// возвращает значение "истина", если множество
// set является подмножеством subset
bool UOAS_isSubset(unordered_array_set set,
                   unordered_array_set subset) {
  for (int i = 0; i < subset.size; i++) {
    if (UOAS_in(&set, subset.data[i]) == set.size)
      return false;
  }
  return true;
}

// возвращает дополнение до универсума множества set
unordered_array_set UOAS_complement(unordered_array_set set,
                                    unordered_array_set universumSet) {
  assert(UOAS_isSubset(universumSet, set));
  return UOAS_difference(universumSet, set);
}

// вывод множества set
void UOAS_print(unordered_array_set set) {
  printf("{");
  if (set.size == 0)
    printf("}\n");
  else {
    for (int i = 0; i < set.size; i++) {
      printf("%d, ", set.data[i]);
    }
    printf("\b\b}\n");
  }
}

// освобождает память, занимаемую множеством set
void UOAS_delete(unordered_array_set set) {
  free(set.data);
}