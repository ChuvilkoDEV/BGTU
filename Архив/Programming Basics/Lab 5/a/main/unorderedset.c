#include <malloc.h>
#include "unorderedset.h"
#include "array.h"

// возвращает пустое множество для capacity элементов
unordered_array_set unordered_array_set_create(size_t capacity) {
  unordered_array_set s;
  s.data = (int *) calloc(capacity, sizeof(int));
  s.size = 0;
  s.capacity = capacity;
  return s;
}

// возвращает множество, состоящее из элементов массива a размера size
unordered_array_set unordered_array_set_create_from_array(
  const int *a, size_t size) {
  unordered_array_set s = unordered_array_set_create(size);
  for (size_t i = 0; i < size; i++)
    s.data[i] = a[i];
  s.size = size;
  s.capacity = size;
  return s;
}

// возвращает позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
size_t unordered_array_set_in(unordered_array_set *set, int value) {
  for (size_t i = 0; i < set->size; i++)
    if (set->data[i] == value)
      return i;
  return set->size;
}

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool unordered_array_set_isEqual(
  unordered_array_set set1, unordered_array_set set2
) {
  return set1.size == set2.size && unordered_array_set_isSubset(set1, set2);
}

// возвращает значение ’истина’ если множество subset
// является подмножеством множества set, иначе - ’ложь’.
bool unordered_array_set_isSubset(
  unordered_array_set subset, unordered_array_set set
) {
  for (size_t i = 0; i < subset.size; i++)
    if (unordered_array_set_in(&set, subset.data[i]) == set.size)
      return false;
  return true;
}

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void unordered_array_set_isAbleAppend(unordered_array_set *set) {
  if (set->size == set->capacity) {
    set->data = realloc(set->data, sizeof(int) * (set->size + 1));
    set->capacity++;
  }
}

// добавляет элемент value в множество set
void unordered_array_set_insert(
  unordered_array_set *set, int value
) {
  unordered_array_set_isAbleAppend(set);
  if (isUniqueNumber(set->data, set->size, value))
    set->data[set->size++] = value;
}

// удаляет элемент value из множества set
void unordered_array_set_deleteElement(
  unordered_array_set *set, int value
) {
  assert(set->size > 0);
  size_t index = unordered_array_set_in(set, value);
  if (index != set->size)
    set->data[index] = set->data[--set->size];
}

// возвращает объединение множеств set1 и set2
unordered_array_set unordered_array_set_union(
  unordered_array_set set1, unordered_array_set set2
) {
  unordered_array_set set3 =
    unordered_array_set_create(set1.size + set2.size);
  for (size_t i = 0; i < set1.size; i++)
    unordered_array_set_insert(&set3, set1.data[i]);
  for (size_t i = 0; i < set2.size; i++)
    unordered_array_set_insert(&set3, set2.data[i]);
  return set3;
}

// возвращает пересечение множеств set1 и set2
unordered_array_set unordered_array_set_intersection(
  unordered_array_set set1, unordered_array_set set2
) {
  unordered_array_set set3 = unordered_array_set_create(set1.capacity);
  for (size_t i = 0; i < set1.size; i++)
    if (unordered_array_set_in(&set2, set1.data[i]) != set2.size)
      unordered_array_set_insert(&set3, set1.data[i]);
  return set3;
}

// возвращает разность множеств set1 и set2
unordered_array_set unordered_array_set_difference(
  unordered_array_set set1, unordered_array_set set2
) {
  unordered_array_set set3 = unordered_array_set_create(set1.capacity);
  for (size_t i = 0; i < set1.size; i++) {
    if (unordered_array_set_in(&set2, set1.data[i]) == set2.size)
      unordered_array_set_insert(&set3, set1.data[i]);
  }
  return set3;
}

// возвращает симметрическую разность множеств set1 и set2
unordered_array_set unordered_array_set_symmetricDifference(
  unordered_array_set set1, unordered_array_set set2
) {
  unordered_array_set set3 = unordered_array_set_difference(set1, set2);
  for (size_t i = 0; i < set2.size; i++)
    if (unordered_array_set_in(&set1, set2.data[i]) == set1.size)
      unordered_array_set_insert(&set3, set2.data[i]);
  return set3;
}

// освобождает память, занимаемую множеством set
void unordered_array_set_delete(unordered_array_set set) {
  free(set.data);
  set.size = 0;
  set.capacity = 0;
}

// вывод множества set
void unordered_array_set_print(unordered_array_set set) {
  printf("[");
  if (set.size == 0)
    printf("]");
  else {
    for (size_t i = 0; i < set.size; i++)
      printf("%d, ", set.data[i]);
    printf("\b\b]\n");
  }
}

// возвращает дополнение до универсума множества set
unordered_array_set unordered_array_set_complement(
  unordered_array_set universumSet, unordered_array_set set
) {
  return (unordered_array_set)
    unordered_array_set_difference(universumSet, set);
}
