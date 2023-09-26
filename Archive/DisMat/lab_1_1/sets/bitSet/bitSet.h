#ifndef LAB_1_1_BITSET_H
#define LAB_1_1_BITSET_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

struct bitset {
  uint32_t value;
  uint32_t maxValue;
};


typedef struct bitset bitset;

void bitset_output(bitset set);

bitset bitset_create(unsigned maxValue);

bool bitset_in(bitset set, unsigned int value);

bool bitset_isEqual(bitset set1, bitset set2);

bool bitset_isSubset(bitset subset, bitset set);

void bitset_insert(bitset *set, unsigned int value);

void bitset_deleteElement(bitset *set, unsigned int value);

void bitset_union(
  bool *set1, size_t size1,
  bool *set2, size_t size2,
  bool *set3, size_t size3
);

bitset bitset_intersection(bitset set1, bitset set2);

bitset bitset_difference(bitset set1, bitset set2);

bitset bitset_symmetricDifference(bitset set1, bitset set2);

// возвращает дополнение до универсума множества set
bitset bitset_complement(bitset set);


#endif //LAB_1_1_BITSET_H
