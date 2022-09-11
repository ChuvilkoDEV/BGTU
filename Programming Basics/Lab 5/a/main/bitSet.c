#include "bitSet.h"

// Выводит значения множества set
void bitset_output(bitset set) {
  printf("[");
  for (size_t i = 0; i <= set.maxValue; i++) {
    if ((set.value >> i) & 1)
      printf("%zd, ", i);
  }
  printf("\b\b]");
}

// возвращает пустое множество c универсумом 0, 1,..., maxValue
bitset bitset_create(unsigned maxValue) {
  return (bitset) {~0, maxValue};
}

// возвращает значение ’истина’, если значение value имеется в множестве set
// иначе - ’ложь’
bool bitset_in(bitset set, unsigned int value) {
  assert(set.maxValue >= value);
  return set.value >> value & 1;
}

// возвращает значение ’истина’, если множества set1 и set2 равны
// иначе - ’ложь’
bool bitset_isEqual(bitset set1, bitset set2) {
  assert(set1.maxValue == set2.maxValue);
  return (set1.value & set2.value) == set1.value;
}

// возвращает значение ’истина’ если множество subset
// является подмножеством множества set, иначе - ’ложь’.
bool bitset_isSubset(bitset subset, bitset set) {
  assert(set.maxValue == subset.maxValue);
  return (set.value & subset.value) != 0;
}

// добавляет элемент value в множество set
void bitset_insert(bitset *set, unsigned int value) {
  assert(set->maxValue >= value);
  set->value |= 1 << value;
}

// удаляет элемент value из множества set
void bitset_deleteElement(bitset *set, unsigned int value) {
  assert(set->maxValue >= value);
  set->value &= ~(1 << value);
}

// возвращает объединение множеств set1 и set2
bitset bitset_union(bitset set1, bitset set2) {
  assert(set1.maxValue == set2.maxValue);
  bitset set;
  set.value = set1.value | set2.value;
  return set;
}

// возвращает пересечение множеств set1 и set2
bitset bitset_intersection(bitset set1, bitset set2) {
  assert(set1.maxValue == set2.maxValue);
  bitset set;
  set.value = set1.value & set2.value;
  set.maxValue = set1.maxValue;
  return set;
}

// возвращает разность множеств set1 и set2
bitset bitset_difference(bitset set1, bitset set2) {
  assert(set1.maxValue == set2.maxValue);
  return (bitset) {(set1.value & ~set2.value), set1.maxValue};
}

// возвращает симметрическую разность множеств set1 и set2
bitset bitset_symmetricDifference(bitset set1, bitset set2) {
  assert(set1.maxValue == set2.maxValue);
  return (bitset) {(set1.value & ~set2.value) | (~set1.value & set2.value),
                   set1.maxValue};
}

// возвращает дополнение до универсума множества set
bitset bitset_complement(bitset set) {
  bitset u = bitset_create(set.maxValue);
  return (bitset) {u.value ^ set.value, set.maxValue};
}
