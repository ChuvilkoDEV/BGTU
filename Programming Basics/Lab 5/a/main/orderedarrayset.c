#include <malloc.h>
#include "orderedarrayset.h"
#include "array.h"

// возвращает пустое множество, в которое можно вставить capacity элементов
ordered_array_set ordered_array_set_create(size_t capacity) {
  ordered_array_set s;
  s.data = (int *) calloc(capacity, sizeof(int));
  s.size = 0;
  s.capacity = capacity;
  return s;
}

// возвращает множество, состоящее из элементов массива a размера size
ordered_array_set ordered_array_set_create_from_array(const int *a,
                                                      size_t size) {
  ordered_array_set s = ordered_array_set_create(size);
  for (size_t i = 0; i < size; i++)
    s.data[i] = a[i];
  s.size = size;
  s.capacity = size;
  return s;
}

// возвращает значение позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
size_t ordered_array_set_in(ordered_array_set *set, int value) {
  return binarySearch_(set->data, set->size, value);
}

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool ordered_array_set_isEqual(ordered_array_set set1,
                               ordered_array_set set2) {
  if (set1.size != set2.size)
    return false;
  for (size_t i = 0; i < set1.size; i++)
    if (set1.data[i] != set2.data[i])
      return false;
  return true;
}

// возвращает значение ’истина’, если subset является подмножеством set
// иначе - ’ложь’
bool ordered_array_set_isSubset(ordered_array_set subset,
                                ordered_array_set set) {
  for (size_t i = 0; i < subset.size; i++)
    if (ordered_array_set_in(&set, subset.data[i]) == set.size)
      return false;
  return true;
}

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void ordered_array_set_isAbleAppend(ordered_array_set *set) {
  if (set->size == set->capacity) {
    set->data = realloc(set->data, sizeof(int) * (set->size + 1));
    set->capacity++;
  }
}

// добавляет элемент value в множество set
void ordered_array_set_insert(ordered_array_set *set, int value) {
  if (isUniqueNumber(set->data, set->size, value)) {
    size_t index = binarySearchMoreOrEqual_(set->data, set->size, value);
    ordered_array_set_isAbleAppend(set);
    insert_(set->data, &set->size, index, value);
  }
}

void ordered_array_set_deleteElement(ordered_array_set *set, int value) {
  if (set->size == 0)
    return;
  size_t index = binarySearch_(set->data, set->size, value);
  if (index < set->size)
    deleteByPosSaveOrder_(set->data, &set->size, index - 1);
}

ordered_array_set ordered_array_set_union(ordered_array_set set1,
                                          ordered_array_set set2) {
  ordered_array_set set3 =
    ordered_array_set_create(set1.size + set2.size);
  for (size_t i = 0; i < set1.size; i++)
    set3.data[i] = set1.data[i];
  set3.size = set1.size;
  for (size_t i = 0; i < set2.size; i++)
    ordered_array_set_insert(&set3, set2.data[i]);
  return set3;
}

ordered_array_set ordered_array_set_intersection(
  ordered_array_set set1, ordered_array_set set2
) {
  ordered_array_set set3 =
    ordered_array_set_create(set1.size);
  for (size_t i = 0; i < set1.size; i++)
    if (ordered_array_set_in(&set2, set1.data[i]) != set2.size)
      ordered_array_set_insert(&set3, set1.data[i]);
  return set3;
}

ordered_array_set ordered_array_set_difference(
  ordered_array_set set1, ordered_array_set set2
) {
  ordered_array_set set3 =
    ordered_array_set_create(set1.size);
  for (size_t i = 0; i < set1.size; i++)
    if (ordered_array_set_in(&set2, set1.data[i]) == set2.size)
      ordered_array_set_insert(&set3, set1.data[i]);
  return set3;
}

ordered_array_set ordered_array_set_symmetricDifference(
  ordered_array_set set1, ordered_array_set set2
) {
  ordered_array_set set3 = ordered_array_set_difference(set1, set2);
  for (size_t i = 0; i < set2.size; i++)
    if (ordered_array_set_in(&set1, set2.data[i]) == set1.size)
      ordered_array_set_insert(&set3, set2.data[i]);
  return set3;
}

ordered_array_set ordered_array_set_complement(
  ordered_array_set universumSet, ordered_array_set set
) {
  return (ordered_array_set)
    ordered_array_set_difference(universumSet, set);
}

// освобождает память, занимаемую множеством set
void ordered_array_set_delete(ordered_array_set set) {
  free(set.data);
  set.size = 0;
  set.capacity = 0;
}

// вывод множества set
void ordered_array_set_print(ordered_array_set set) {
  printf("[");
  if (set.size == 0) {
    printf("]");
    return;
  }
  for (size_t i = 0; i < set.size; i++)
    printf("%d, ", set.data[i]);
  printf("\b\b]\n");
}