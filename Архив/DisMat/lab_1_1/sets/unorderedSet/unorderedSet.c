#include "unorderedSet.h"

// возвращает пустое множество для capacity элементов
unorderedSet unorderedSet_create(size_t capacity) {
  unorderedSet s;
  s.data = (int *) calloc(capacity, sizeof(int));
  s.size = 0;
  s.capacity = capacity;
  return s;
}

// возвращает множество, состоящее из элементов массива a размера size
unorderedSet unorderedSet_createFromArray(
  const int *a, size_t size) {
  unorderedSet s = unorderedSet_create(size);
  for (size_t i = 0; i < size; i++)
    s.data[i] = a[i];
  s.size = size;
  s.capacity = size;
  return s;
}

// возвращает позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
size_t unorderedSet_in(unorderedSet *set, int value) {
  for (size_t i = 0; i < set->size; i++)
    if (set->data[i] == value)
      return i;
  return set->size;
}

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool unorderedSet_isEqual(
  unorderedSet set1, unorderedSet set2
) {
  return set1.size == set2.size && unorderedSet_isSubset(set1, set2);
}

// возвращает значение ’истина’ если множество subset
// является подмножеством множества set, иначе - ’ложь’.
bool unorderedSet_isSubset(
  unorderedSet subset, unorderedSet set
) {
  for (size_t i = 0; i < subset.size; i++)
    if (unorderedSet_in(&set, subset.data[i]) == set.size)
      return false;
  return true;
}

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void unorderedSet_isAbleAppend(unorderedSet *set) {
  if (set->size == set->capacity) {
    set->data = realloc(set->data, sizeof(int) * (set->size + 1));
    set->capacity++;
  }
}

// добавляет элемент value в множество set
void unorderedSet_insert(
  unorderedSet *set, int value
) {
  unorderedSet_isAbleAppend(set);
  if (isUniqueNumber(set->data, set->size, value))
    set->data[set->size++] = value;
}

// удаляет элемент value из множества set
void unorderedSet_deleteElement(
  unorderedSet *set, int value
) {
  assert(set->size > 0);
  size_t index = unorderedSet_in(set, value);
  if (index != set->size)
    set->data[index] = set->data[--set->size];
}

// возвращает объединение множеств set1 и set2
unorderedSet unorderedSet_union(
  unorderedSet set1, unorderedSet set2
) {
  unorderedSet set3 =
    unorderedSet_create(set1.size + set2.size);
  for (size_t i = 0; i < set1.size; i++)
    unorderedSet_insert(&set3, set1.data[i]);
  for (size_t i = 0; i < set2.size; i++)
    unorderedSet_insert(&set3, set2.data[i]);
  return set3;
}

// возвращает пересечение множеств set1 и set2
unorderedSet unorderedSet_intersection(
  unorderedSet set1, unorderedSet set2
) {
  unorderedSet set3 = unorderedSet_create(set1.capacity);
  for (size_t i = 0; i < set1.size; i++)
    if (unorderedSet_in(&set2, set1.data[i]) != set2.size)
      unorderedSet_insert(&set3, set1.data[i]);
  return set3;
}

// возвращает разность множеств set1 и set2
unorderedSet unorderedSet_difference(
  unorderedSet set1, unorderedSet set2
) {
  unorderedSet set3 = unorderedSet_create(set1.capacity);
  for (size_t i = 0; i < set1.size; i++) {
    if (unorderedSet_in(&set2, set1.data[i]) == set2.size)
      unorderedSet_insert(&set3, set1.data[i]);
  }
  return set3;
}

// возвращает симметрическую разность множеств set1 и set2
unorderedSet unorderedSet_symmetricDifference(
  unorderedSet set1, unorderedSet set2
) {
  unorderedSet set3 = unorderedSet_difference(set1, set2);
  for (size_t i = 0; i < set2.size; i++)
    if (unorderedSet_in(&set1, set2.data[i]) == set1.size)
      unorderedSet_insert(&set3, set2.data[i]);
  return set3;
}

// освобождает память, занимаемую множеством set
void unorderedSet_delete(unorderedSet set) {
  free(set.data);
  set.size = 0;
  set.capacity = 0;
}

// вывод множества set
void unorderedSet_output(unorderedSet set) {
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
unorderedSet unorderedSet_complement(
  unorderedSet universumSet, unorderedSet set
) {
  return (unorderedSet)
    unorderedSet_difference(universumSet, set);
}