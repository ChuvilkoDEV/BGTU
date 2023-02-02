#include "booleans_array.h"
#include "../../libs/algorithms/algorithms.h"

// возвращает пустое множество c универсумом 0, 1,..., до maxValue
boolean_array_set boolean_array_set_create(uint32_t maxValue) {
  boolean_array_set newSet = {malloc(sizeof(bool) * (maxValue)), 0,
                              maxValue};
  for (size_t i = 0; i < newSet.maxValue; i++)
    newSet.data[i] = false;
  return newSet;
}

// возвращает множество, полученное из массива a без повторяющихся элементов,
// для натуральных чисел
boolean_array_set boolean_array_set_createFromArray(
  int *a, uint32_t size, uint32_t maxSize
  ) {
  boolean_array_set set = boolean_array_set_create(maxSize);
  for (int i = 0; i < size; i++) {
    set.data[a[i] - 1] = true;
    set.size++;
  }
  return set;
}

//Возвращает значение ’истина’, если значение переменной value
// может принадлежать множеству set, иначе - ’ложь’
bool boolean_array_set_checkValue(boolean_array_set set, uint32_t value) {
  return (value >= 0) && (value <= set.maxValue);
}

// возвращает значение ’истина’, если значение value имеется в множестве set // иначе - ’ложь’
bool boolean_array_set_in(boolean_array_set set, uint32_t value) {
  assert((boolean_array_set_checkValue(set, value)));
  return set.data[value];
}
// возвращает значение ’истина’, если множества set1 и set2 равны
// иначе - ’ложь’
bool boolean_array_set_isEqual(boolean_array_set set1, boolean_array_set set2) {
  if (set1.size != set2.size) return false;
  size_t countEquals = 0;
  for (size_t i = 0; (i <= set1.maxValue) && (countEquals != set1.size); i++)
    if (set1.data[i] != set2.data[i]) return false;
    else
      countEquals++;
  return true;
}

// добавляет элемент value в множество set
void boolean_array_set_insert(boolean_array_set *set, uint32_t value) {
  assert(boolean_array_set_checkValue(*set, value));
  if (!boolean_array_set_in(*set, value)) {
    set->data[value] = true;
    set->size++;
  }
}

// возвращает пересечение множеств set1 и set2
boolean_array_set boolean_intersection(boolean_array_set set1,
                                       boolean_array_set set2) {
  boolean_array_set intersectionSet =
    boolean_array_set_create(set1.maxValue);
  for (size_t i = 0; i <= set1.maxValue; i++)
    if (set1.data[i] && set2.data[i]) {
      boolean_array_set_insert(&intersectionSet, i);
    }
  return intersectionSet;
}

// удаляет элемент value из множества set
void boolean_array_set_deleteElement(boolean_array_set *set, size_t value) {
  assert(boolean_array_set_checkValue(*set, value));
  if (boolean_array_set_in(*set, value)) {
    set->data[value] = false;
    set->size--;
  }
}

// возвращает объединение множеств set1 и set2
boolean_array_set boolean_array_set_union(boolean_array_set set1,
                                          boolean_array_set set2) {
  size_t sizeUnion = max2_size_t(set1.maxValue, set2.maxValue);
  boolean_array_set unionSet = boolean_array_set_create(sizeUnion);
  for (size_t i = 0; i <= sizeUnion; i++)
    if (set1.data[i] && set1.data[i] < set1.maxValue ||
        set2.data[i] && set2.data[i] < set2.maxValue) {
      boolean_array_set_insert(&unionSet, i);
    }
  return unionSet;
}

// возвращает разность множеств set1 и set2
boolean_array_set
boolean_array_set_difference(boolean_array_set set1, boolean_array_set set2) {
  boolean_array_set differenceSet =
    boolean_array_set_create(set1.maxValue);
  for (size_t i = 0; i <= set1.maxValue; i++)
    if (set1.data[i] && set1.data[i] != set2.data[i])
      boolean_array_set_insert(&differenceSet, i);
  return differenceSet;
}

// возвращает симметрическую разность множеств set1 и set2
boolean_array_set boolean_array_set_symmetricDifference(boolean_array_set set1,
                                                        boolean_array_set set2) {
  return boolean_array_set_union
    (boolean_array_set_difference(set1, set2),
     boolean_array_set_difference(set2, set1));
}

// возвращает дополнение до универсума множества set
boolean_array_set boolean_complement(boolean_array_set set,
                                     boolean_array_set universumSet) {
  return boolean_array_set_difference(universumSet, set);
}

boolean_array_set
boolean_array_set_create_from_array(bool *set, size_t maxValue,
                                    size_t size) {
  boolean_array_set newSet = boolean_array_set_create(maxValue);
  size_t countElement = size;
  for (size_t i = 0; i <= maxValue && countElement; i++)
    if (set[i]) {
      boolean_array_set_insert(&newSet, i);
      countElement--;
    }
  return newSet;
}

// вывод множества set
void boolean_array_set_print(boolean_array_set set) {
  printf("{");
  bool isEmpty = true;
  size_t countElements = set.size;
  for (int i = 0; i <= set.maxValue && countElements; i++)
    if (boolean_array_set_in(set, i)) {
      printf("%d, ", i + 1);
      isEmpty = false;
      countElements--;
    }
  if (isEmpty)
    printf("}\n");
  else
    printf("\b\b}\n");
}

boolean_array_set boolean_array_set_reverse(boolean_array_set set) {
  for (int i = 0; i < set.maxValue; i++)
    set.data[i] = !set.data[i];
  return set;
}

// освобождает память, занимаемую множеством set
void boolean_array_set_delete(boolean_array_set set) {
  free(set.data);
}
