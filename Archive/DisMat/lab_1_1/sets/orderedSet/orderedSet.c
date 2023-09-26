#include "orderedSet.h"

// возвращает пустое множество, в которое можно вставить capacity элементов
orderedSet orderedSet_create(size_t capacity) {
  orderedSet s;
  s.data = (int *) calloc(capacity, sizeof(int));
  s.size = 0;
  s.capacity = capacity;
  return s;
}

// возвращает множество, состоящее из элементов массива a размера size
orderedSet orderedSet_createFromArray(const int *a,
                                      size_t size) {
  orderedSet s = orderedSet_create(size);
  for (size_t i = 0; i < size; i++)
    s.data[i] = a[i];
  s.size = size;
  s.capacity = size;
  return s;
}

// возвращает значение позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
size_t orderedSet_in(orderedSet *set, int value) {
  return binarySearch(set->data, set->size, value);
}

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool orderedSet_isEqual(orderedSet set1,
                        orderedSet set2) {
  if (set1.size != set2.size)
    return false;
  for (size_t i = 0; i < set1.size; i++)
    if (set1.data[i] != set2.data[i])
      return false;
  return true;
}

// возвращает значение ’истина’, если subset является подмножеством set
// иначе - ’ложь’
bool orderedSet_isSubset(orderedSet subset,
                         orderedSet set) {
  for (size_t i = 0; i < subset.size; i++)
    if (orderedSet_in(&set, subset.data[i]) == set.size)
      return false;
  return true;
}

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void orderedSet_isAbleAppend(orderedSet *set) {
  if (set->size == set->capacity) {
    set->data = realloc(set->data, sizeof(int) * (set->size + 1));
    set->capacity++;
  }
}

// добавляет элемент value в множество set
void orderedSet_insert(orderedSet *set, int value) {
  if (isUniqueNumber(set->data, set->size, value)) {
    size_t index = binarySearchMoreOrEqual(set->data, set->size, value);
    orderedSet_isAbleAppend(set);
    insert(set->data, &set->size, index, value);
  }
}

void orderedSet_deleteElement(orderedSet *set, int value) {
  if (set->size == 0)
    return;
  size_t index = binarySearch(set->data, set->size, value);
  if (index < set->size)
    deleteByPosSaveOrder_(set->data, &set->size, index - 1);
}

orderedSet orderedSet_union(orderedSet set1,
                            orderedSet set2) {
  orderedSet set3 =
    orderedSet_create(set1.size + set2.size);
  for (size_t i = 0; i < set1.size; i++)
    set3.data[i] = set1.data[i];
  set3.size = set1.size;
  for (size_t i = 0; i < set2.size; i++)
    orderedSet_insert(&set3, set2.data[i]);
  return set3;
}

orderedSet orderedSet_intersection(
  orderedSet set1, orderedSet set2
) {
  orderedSet set3 =
    orderedSet_create(set1.size);
  for (size_t i = 0; i < set1.size; i++)
    if (orderedSet_in(&set2, set1.data[i]) != set2.size)
      orderedSet_insert(&set3, set1.data[i]);
  return set3;
}

orderedSet orderedSet_difference(
  orderedSet set1, orderedSet set2, orderedSet set3
) {
  for (size_t i = 0; i < set1.size; i++)
    if (orderedSet_in(&set2, set1.data[i]) == set2.size)
      orderedSet_insert(&set3, set1.data[i]);
  return set3;
}

orderedSet orderedSet_symmetricDifference(
  orderedSet set1, orderedSet set2
) {
  orderedSet set3 = orderedSet_difference(set1, set2);
  set3.capacity++;
  for (size_t i = 0; i < set2.size; i++)
    if (orderedSet_in(&set1, set2.data[i]) == set1.size) {
      orderedSet_insert(&set3, set2.data[i]);
    }
  return set3;
}

orderedSet orderedSet_complement(
  orderedSet universumSet, orderedSet set
) {
  return (orderedSet)
    orderedSet_difference(universumSet, set);
}

// освобождает память, занимаемую множеством set
void orderedSet_delete(orderedSet set) {
  free(set.data);
  set.size = 0;
  set.capacity = 0;
}

// вывод множества set
void orderedSet_output(orderedSet set) {
  printf("[");
  if (set.size == 0) {
    printf("]");
    return;
  }
  for (size_t i = 0; i < set.size; i++)
    printf("%d, ", set.data[i]);
  printf("\b\b]\n");
}