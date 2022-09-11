#include "bitSet.h"
#include "unorderedset.h"
#include "orderedarrayset.h"


void test_unordered_array_set_in1() {
  unordered_array_set set =
    unordered_array_set_create_from_array((int[]) {1, 2}, 2);
  size_t resTest = 1;
  assert(unordered_array_set_in(&set, 2) == resTest);

  unordered_array_set_delete(set);
}

void test_unordered_array_set_in2() {
  unordered_array_set set =
    unordered_array_set_create_from_array((int[]) {1, 2}, 2);
  size_t resTest = 2;
  assert(unordered_array_set_in(&set, 3) == resTest);

  unordered_array_set_delete(set);
}

void test_unordered_array_set_in() {
  test_unordered_array_set_in1();
  test_unordered_array_set_in2();
}

void test_unordered_array_set_isSubset1() {
  unordered_array_set set =
    unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
  unordered_array_set subset =
    unordered_array_set_create_from_array((int[]) {2, 3, 4}, 3);
  bool isSubset = true;
  assert(unordered_array_set_isSubset(subset, set) == isSubset);

  unordered_array_set_delete(set);
  unordered_array_set_delete(subset);
}

void test_unordered_array_set_isSubset2() {
  unordered_array_set set =
    unordered_array_set_create_from_array((int[]) {1, 2, 3, 9, 5}, 5);
  unordered_array_set subset =
    unordered_array_set_create_from_array((int[]) {2, 3, 4}, 3);
  bool isSubset = false;
  assert(unordered_array_set_isSubset(subset, set) == isSubset);

  unordered_array_set_delete(set);
  unordered_array_set_delete(subset);
}

void test_unordered_array_set_isSubset() {
  test_unordered_array_set_isSubset1();
  test_unordered_array_set_isSubset2();
}

void test_unordered_array_set_insert1() {
  unordered_array_set set =
    unordered_array_set_create(1);
  unordered_array_set_insert(&set, 4);
  unordered_array_set resSet =
    unordered_array_set_create_from_array((int[]) {4}, 1);
  assert(unordered_array_set_isEqual(set, resSet));

  unordered_array_set_delete(set);
  unordered_array_set_delete(resSet);
}

void test_unordered_array_set_insert2() {
  unordered_array_set set =
    unordered_array_set_create(5);
  unordered_array_set_insert(&set, 4);
  unordered_array_set_insert(&set, 56);
  unordered_array_set_insert(&set, 1000);
  unordered_array_set_insert(&set, -42);
  unordered_array_set_insert(&set, 42);
  unordered_array_set resSet =
    unordered_array_set_create_from_array((int[]) {42, -42, 1000, 56, 4}, 5);
  assert(unordered_array_set_isEqual(set, resSet));

  unordered_array_set_delete(set);
  unordered_array_set_delete(resSet);
}

void test_unordered_array_set_insert() {
  test_unordered_array_set_insert1();
  test_unordered_array_set_insert2();
}

void test_unordered_array_set_deleteElement1() {
  unordered_array_set set =
    unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
  unordered_array_set_deleteElement(&set, 2);
  unordered_array_set resSet =
    unordered_array_set_create_from_array((int[]) {1, 3}, 2);
  assert(unordered_array_set_isEqual(set, resSet));

  unordered_array_set_delete(set);
  unordered_array_set_delete(resSet);
}

void test_unordered_array_set_deleteElement2() {
  unordered_array_set set =
    unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
  unordered_array_set_deleteElement(&set, 2);
  unordered_array_set_deleteElement(&set, 1);
  unordered_array_set_deleteElement(&set, 4);
  unordered_array_set resSet =
    unordered_array_set_create_from_array((int[]) {3}, 1);
  assert(unordered_array_set_isEqual(set, resSet));

  unordered_array_set_delete(set);
  unordered_array_set_delete(resSet);
}

void test_unordered_array_set_deleteElement() {
  test_unordered_array_set_deleteElement1();
  test_unordered_array_set_deleteElement2();
}

void test_unordered_array_set_union1() {
  unordered_array_set set1 =
    unordered_array_set_create_from_array((int[]) {1, 2}, 2);
  unordered_array_set set2 =
    unordered_array_set_create_from_array((int[]) {2, 3}, 2);
  unordered_array_set resSet =
    unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
  unordered_array_set testSet =
    unordered_array_set_union(set1, set2);
  assert(unordered_array_set_isEqual(resSet, testSet));

  unordered_array_set_delete(set1);
  unordered_array_set_delete(set2);
  unordered_array_set_delete(resSet);
  unordered_array_set_delete(testSet);
}

void test_unordered_array_set_union2() {
  unordered_array_set set1 =
    unordered_array_set_create_from_array((int[]) {9, 2}, 2);
  unordered_array_set set2 =
    unordered_array_set_create_from_array((int[]) {7, 3}, 2);
  unordered_array_set resSet =
    unordered_array_set_create_from_array((int[]) {2, 3, 7, 9}, 4);
  unordered_array_set testSet =
    unordered_array_set_union(set1, set2);
  assert(unordered_array_set_isEqual(resSet, testSet));

  unordered_array_set_delete(set1);
  unordered_array_set_delete(set2);
  unordered_array_set_delete(resSet);
  unordered_array_set_delete(testSet);
}

void test_unordered_array_set_union3() {
  unordered_array_set set1 =
    unordered_array_set_create_from_array((int[]) {1, 2}, 2);
  unordered_array_set set2 =
    unordered_array_set_create_from_array((int[]) {1, 2}, 2);
  unordered_array_set resSet =
    unordered_array_set_create_from_array((int[]) {1, 2}, 2);
  unordered_array_set testSet =
    unordered_array_set_union(set1, set2);
  assert(unordered_array_set_isEqual(resSet, testSet));

  unordered_array_set_delete(set1);
  unordered_array_set_delete(set2);
  unordered_array_set_delete(resSet);
  unordered_array_set_delete(testSet);
}

void test_unordered_array_set_union() {
  test_unordered_array_set_union1();
  test_unordered_array_set_union2();
  test_unordered_array_set_union3();
}

void test_unordered_array_set_intersection1() {
  unordered_array_set set1 =
    unordered_array_set_create_from_array((int[]) {1, 2}, 2);
  unordered_array_set set2 =
    unordered_array_set_create_from_array((int[]) {2, 3}, 2);
  unordered_array_set resSet =
    unordered_array_set_create_from_array((int[]) {2}, 1);
  unordered_array_set testSet =
    unordered_array_set_intersection(set1, set2);
  assert(unordered_array_set_isEqual(resSet, testSet));

  unordered_array_set_delete(set1);
  unordered_array_set_delete(set2);
  unordered_array_set_delete(resSet);
  unordered_array_set_delete(testSet);
}

void test_unordered_array_set_intersection2() {
  unordered_array_set set1 =
    unordered_array_set_create_from_array((int[]) {9, 2}, 2);
  unordered_array_set set2 =
    unordered_array_set_create_from_array((int[]) {7, 3}, 2);
  unordered_array_set resSet =
    unordered_array_set_create_from_array((int[]) {}, 0);
  unordered_array_set testSet =
    unordered_array_set_intersection(set1, set2);
  assert(unordered_array_set_isEqual(resSet, testSet));

  unordered_array_set_delete(set1);
  unordered_array_set_delete(set2);
  unordered_array_set_delete(resSet);
  unordered_array_set_delete(testSet);
}

void test_unordered_array_set_intersection() {
  test_unordered_array_set_intersection1();
  test_unordered_array_set_intersection2();
}

void test_unordered_array_set_difference1() {
  unordered_array_set set1 =
    unordered_array_set_create_from_array((int[]) {1, 2}, 2);
  unordered_array_set set2 =
    unordered_array_set_create_from_array((int[]) {2, 3}, 2);
  unordered_array_set resSet =
    unordered_array_set_create_from_array((int[]) {1}, 1);
  unordered_array_set testSet =
    unordered_array_set_difference(set1, set2);
  assert(unordered_array_set_isEqual(resSet, testSet));

  unordered_array_set_delete(set1);
  unordered_array_set_delete(set2);
  unordered_array_set_delete(resSet);
  unordered_array_set_delete(testSet);
}

void test_unordered_array_set_difference2() {
  unordered_array_set set1 =
    unordered_array_set_create_from_array((int[]) {1, 2}, 2);
  unordered_array_set set2 =
    unordered_array_set_create_from_array((int[]) {2, 3}, 2);
  unordered_array_set resSet =
    unordered_array_set_create_from_array((int[]) {1}, 1);
  unordered_array_set testSet =
    unordered_array_set_difference(set1, set2);
  assert(unordered_array_set_isEqual(resSet, testSet));

  unordered_array_set_delete(set1);
  unordered_array_set_delete(set2);
  unordered_array_set_delete(resSet);
  unordered_array_set_delete(testSet);
}

void test_unordered_array_set_difference() {
  test_unordered_array_set_difference1();
  test_unordered_array_set_difference2();
}

void test_unordered_array_set_symmetricDifference1() {
  unordered_array_set set1 =
    unordered_array_set_create_from_array((int[]) {1, 2, 8}, 3);
  unordered_array_set set2 =
    unordered_array_set_create_from_array((int[]) {2, 3, 1}, 3);
  unordered_array_set resSet =
    unordered_array_set_create_from_array((int[]) {3, 8}, 2);
  unordered_array_set testSet =
    unordered_array_set_symmetricDifference(set1, set2);
  assert(unordered_array_set_isEqual(resSet, testSet));

  unordered_array_set_delete(set1);
  unordered_array_set_delete(set2);
  unordered_array_set_delete(resSet);
  unordered_array_set_delete(testSet);
}

void test_unordered_array_set_symmetricDifference2() {
  unordered_array_set set1 =
    unordered_array_set_create_from_array((int[]) {1, 42}, 2);
  unordered_array_set set2 =
    unordered_array_set_create_from_array((int[]) {5}, 1);
  unordered_array_set resSet =
    unordered_array_set_create_from_array((int[]) {1, 5, 42}, 3);
  unordered_array_set testSet =
    unordered_array_set_symmetricDifference(set1, set2);
  assert(unordered_array_set_isEqual(resSet, testSet));

  unordered_array_set_delete(set1);
  unordered_array_set_delete(set2);
  unordered_array_set_delete(resSet);
  unordered_array_set_delete(testSet);
}

void test_unordered_array_set_symmetricDifference() {
  test_unordered_array_set_symmetricDifference1();
  test_unordered_array_set_symmetricDifference2();
}

void test_unordered_array_set_complement1() {
  unordered_array_set set1 =
    unordered_array_set_create_from_array((int[]) {1}, 1);
  unordered_array_set setCompliment =
    unordered_array_set_create_from_array((int[]) {1, 42}, 2);
  unordered_array_set resSet =
    unordered_array_set_create_from_array((int[]) {42}, 1);
  unordered_array_set testSet =
    unordered_array_set_complement(setCompliment, set1);
  assert(unordered_array_set_isEqual(resSet, testSet));

  unordered_array_set_delete(set1);
  unordered_array_set_delete(setCompliment);
  unordered_array_set_delete(resSet);
  unordered_array_set_delete(testSet);
}

void test_unordered_array_set_complement2() {
  unordered_array_set set1 =
    unordered_array_set_create_from_array((int[]) {1, 53}, 2);
  unordered_array_set setCompliment =
    unordered_array_set_create_from_array((int[]) {1, 42, 53, 12}, 4);
  unordered_array_set resSet =
    unordered_array_set_create_from_array((int[]) {42, 12}, 2);
  unordered_array_set testSet =
    unordered_array_set_complement(setCompliment, set1);
  assert(unordered_array_set_isEqual(resSet, testSet));

  unordered_array_set_delete(set1);
  unordered_array_set_delete(setCompliment);
  unordered_array_set_delete(resSet);
  unordered_array_set_delete(testSet);
}

void test_unordered_array_set_complement() {
  test_unordered_array_set_complement1();
  test_unordered_array_set_complement2();
}

//////////////////////////////////////////////////////////////////

void test_ordered_array_set_in1() {
  ordered_array_set set =
    ordered_array_set_create_from_array((int[]) {1, 53}, 2);
  assert(ordered_array_set_in(&set, 5) == 2);


  ordered_array_set_delete(set);
}

void test_ordered_array_set_in2() {
  ordered_array_set set1 =
    ordered_array_set_create_from_array((int[]) {1, 53}, 2);
  assert(ordered_array_set_in(&set1, 1) == 0);

  ordered_array_set_delete(set1);
}

void test_ordered_array_set_in() {
  test_ordered_array_set_in1();
  test_ordered_array_set_in2();
}

void test_ordered_array_set_isSubset1() {
  ordered_array_set set1 =
    ordered_array_set_create_from_array((int[]) {1, 53}, 2);
  ordered_array_set set2 =
    ordered_array_set_create_from_array((int[]) {1, 12, 53, 102}, 4);
  assert(ordered_array_set_isSubset(set1, set2));

  ordered_array_set_delete(set1);
  ordered_array_set_delete(set2);
}

void test_ordered_array_set_isSubset2() {
  ordered_array_set set1 =
    ordered_array_set_create_from_array((int[]) {1, 5}, 2);
  ordered_array_set set2 =
    ordered_array_set_create_from_array((int[]) {1, 42, 53, 102}, 4);
  assert(ordered_array_set_isSubset(set1, set2) == 0);

  ordered_array_set_delete(set1);
  ordered_array_set_delete(set2);
}

void test_ordered_array_set_isSubset() {
  test_ordered_array_set_isSubset1();
  test_ordered_array_set_isSubset2();
}

void test_ordered_array_set_insert1() {
  ordered_array_set set =
    ordered_array_set_create(1);
  ordered_array_set_insert(&set, 4);
  ordered_array_set_insert(&set, 4);
  ordered_array_set resSet =
    ordered_array_set_create_from_array((int[]) {4}, 1);
  assert(ordered_array_set_isEqual(set, resSet));

  ordered_array_set_delete(set);
  ordered_array_set_delete(resSet);
}

void test_ordered_array_set_insert2() {
  ordered_array_set set =
    ordered_array_set_create(5);
  ordered_array_set_insert(&set, 4);
  ordered_array_set_insert(&set, 2);
  ordered_array_set_insert(&set, 1);
  ordered_array_set_insert(&set, 5);
  ordered_array_set_insert(&set, 3);
  ordered_array_set resSet =
    ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
  assert(ordered_array_set_isEqual(set, resSet));

  ordered_array_set_delete(set);
  ordered_array_set_delete(resSet);
}

void test_ordered_array_set_insert() {
  test_ordered_array_set_insert1();
  test_ordered_array_set_insert2();
}

void test_ordered_array_set_deleteElement1() {
  ordered_array_set set =
    ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
  ordered_array_set_deleteElement(&set, 4);
  ordered_array_set_deleteElement(&set, 2);
  ordered_array_set_deleteElement(&set, 1);
  ordered_array_set_deleteElement(&set, 5);
  ordered_array_set resSet =
    ordered_array_set_create_from_array((int[]) {3}, 1);

  assert(ordered_array_set_isEqual(set, resSet));
  ordered_array_set_delete(set);
  ordered_array_set_delete(resSet);
}

void test_ordered_array_set_deleteElement2() {
  ordered_array_set set =
    ordered_array_set_create_from_array((int[]) {}, 0);
  ordered_array_set_deleteElement(&set, 4);
  ordered_array_set_deleteElement(&set, 2);
  ordered_array_set_deleteElement(&set, 1);
  ordered_array_set_deleteElement(&set, 5);
  ordered_array_set_deleteElement(&set, 3);
  ordered_array_set resSet =
    ordered_array_set_create_from_array((int[]) {}, 0);
  assert(ordered_array_set_isEqual(set, resSet));

  ordered_array_set_delete(set);
  ordered_array_set_delete(resSet);
}

void test_ordered_array_set_deleteElement() {
  test_ordered_array_set_deleteElement1();
  test_ordered_array_set_deleteElement2();
}

void test_ordered_array_set_union1() {
  ordered_array_set set1 =
    ordered_array_set_create_from_array((int[]) {3, 4, 5, 6, 7}, 5);
  ordered_array_set set2 =
    ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
  ordered_array_set resSet =
    ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5, 6, 7}, 7);
  ordered_array_set testSet =
    ordered_array_set_union(set1, set2);
  assert(ordered_array_set_isEqual(testSet, resSet));

  ordered_array_set_delete(set1);
  ordered_array_set_delete(set2);
  ordered_array_set_delete(testSet);
  ordered_array_set_delete(resSet);
}

void test_ordered_array_set_union2() {
  ordered_array_set set1 =
    ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
  ordered_array_set set2 =
    ordered_array_set_create_from_array((int[]) {6, 7, 8, 9, 10}, 5);
  ordered_array_set resSet =
    ordered_array_set_create_from_array(
      (int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10);
  ordered_array_set testSet =
    ordered_array_set_union(set1, set2);
  assert(ordered_array_set_isEqual(testSet, resSet));

  ordered_array_set_delete(set1);
  ordered_array_set_delete(set2);
  ordered_array_set_delete(resSet);
  ordered_array_set_delete(testSet);
}

void test_ordered_array_set_union() {
  test_ordered_array_set_union1();
  test_ordered_array_set_union2();
}

void test_ordered_array_set_intersection1() {
  ordered_array_set set1 =
    ordered_array_set_create_from_array((int[]) {3, 4, 5, 6, 7}, 5);
  ordered_array_set set2 =
    ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
  ordered_array_set resSet =
    ordered_array_set_create_from_array((int[]) {3, 4, 5}, 3);
  ordered_array_set testSet =
    ordered_array_set_intersection(set1, set2);
  assert(ordered_array_set_isEqual(testSet, resSet));

  ordered_array_set_delete(set1);
  ordered_array_set_delete(set2);
  ordered_array_set_delete(testSet);
  ordered_array_set_delete(resSet);
}

void test_ordered_array_set_intersection2() {
  ordered_array_set set1 =
    ordered_array_set_create_from_array((int[]) {6, 7, 8, 9, 10}, 5);
  ordered_array_set set2 =
    ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
  ordered_array_set resSet =
    ordered_array_set_create_from_array((int[]) {}, 0);
  ordered_array_set testSet =
    ordered_array_set_intersection(set1, set2);
  assert(ordered_array_set_isEqual(testSet, resSet));

  ordered_array_set_delete(set1);
  ordered_array_set_delete(set2);
  ordered_array_set_delete(testSet);
  ordered_array_set_delete(resSet);
}

void test_ordered_array_set_intersection() {
  test_ordered_array_set_intersection1();
  test_ordered_array_set_intersection2();
}

void test_ordered_array_set_difference1() {
  ordered_array_set set1 =
    ordered_array_set_create_from_array((int[]) {3, 4, 5, 6, 7}, 5);
  ordered_array_set set2 =
    ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
  ordered_array_set resSet =
    ordered_array_set_create_from_array((int[]) {6, 7}, 2);
  ordered_array_set testSet =
    ordered_array_set_difference(set1, set2);
  assert(ordered_array_set_isEqual(testSet, resSet));

  ordered_array_set_delete(set1);
  ordered_array_set_delete(set2);
  ordered_array_set_delete(testSet);
  ordered_array_set_delete(resSet);
}

void test_ordered_array_set_difference2() {
  ordered_array_set set1 =
    ordered_array_set_create_from_array((int[]) {3, 4, 5, 6, 7}, 5);
  ordered_array_set set2 =
    ordered_array_set_create_from_array((int[]) {1, 2, 11, 12, 13}, 5);
  ordered_array_set resSet =
    ordered_array_set_create_from_array((int[]) {3, 4, 5, 6, 7}, 5);
  ordered_array_set testSet =
    ordered_array_set_difference(set1, set2);
  assert(ordered_array_set_isEqual(testSet, resSet));

  ordered_array_set_delete(set1);
  ordered_array_set_delete(set2);
  ordered_array_set_delete(testSet);
  ordered_array_set_delete(resSet);
}

void test_ordered_array_set_difference() {
  test_ordered_array_set_difference1();
  test_ordered_array_set_difference2();
}

void test_ordered_array_set_symmetricDifference1() {
  ordered_array_set set1 =
    ordered_array_set_create_from_array((int[]) {3, 4, 5, 6, 7}, 5);
  ordered_array_set set2 =
    ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
  ordered_array_set resSet =
    ordered_array_set_create_from_array((int[]) {1, 2, 6, 7}, 4);
  ordered_array_set testSet =
    ordered_array_set_symmetricDifference(set1, set2);
  assert(ordered_array_set_isEqual(testSet, resSet));

  ordered_array_set_delete(set1);
  ordered_array_set_delete(set2);
  ordered_array_set_delete(testSet);
  ordered_array_set_delete(resSet);
}

void test_ordered_array_set_symmetricDifference2() {
  ordered_array_set set1 =
    ordered_array_set_create_from_array((int[]) {6, 7, 8, 9, 10}, 5);
  ordered_array_set set2 =
    ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
  ordered_array_set resSet =
    ordered_array_set_create_from_array(
      (int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10
    );
  ordered_array_set testSet =
    ordered_array_set_symmetricDifference(set1, set2);
  assert(ordered_array_set_isEqual(testSet, resSet));

  ordered_array_set_delete(set1);
  ordered_array_set_delete(set2);
  ordered_array_set_delete(testSet);
  ordered_array_set_delete(resSet);
}

void test_ordered_array_set_symmetricDifference() {
  test_ordered_array_set_symmetricDifference1();
  test_ordered_array_set_symmetricDifference2();
}

void test_ordered_array_set_complement1() {
  ordered_array_set set1 =
    ordered_array_set_create_from_array((int[]) {3, 4, 5, 6, 7}, 5);
  ordered_array_set setComplement =
    ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
  ordered_array_set resSet =
    ordered_array_set_create_from_array((int[]) {1, 2}, 2);
  ordered_array_set testSet =
    ordered_array_set_complement(setComplement, set1);
  assert(ordered_array_set_isEqual(testSet, resSet));

  ordered_array_set_delete(set1);
  ordered_array_set_delete(setComplement);
  ordered_array_set_delete(testSet);
  ordered_array_set_delete(resSet);
}

void test_ordered_array_set_complement2() {
  ordered_array_set set1 =
    ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
  ordered_array_set setComplement =
    ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
  ordered_array_set resSet =
    ordered_array_set_create_from_array((int[]) {}, 0);
  ordered_array_set testSet =
    ordered_array_set_complement(setComplement, set1);
  assert(ordered_array_set_isEqual(testSet, resSet));

  ordered_array_set_delete(set1);
  ordered_array_set_delete(setComplement);
  ordered_array_set_delete(testSet);
  ordered_array_set_delete(resSet);
}

void test_ordered_array_set_complement() {
  test_ordered_array_set_complement1();
  test_ordered_array_set_complement2();
}

void test() {
  test_unordered_array_set_in();
  test_unordered_array_set_isSubset();
  test_unordered_array_set_insert();
  test_unordered_array_set_deleteElement();
  test_unordered_array_set_union();
  test_unordered_array_set_intersection();
  test_unordered_array_set_difference();
  test_unordered_array_set_symmetricDifference();
  test_unordered_array_set_complement();

  test_ordered_array_set_in();
  test_ordered_array_set_isSubset();
  test_ordered_array_set_insert();
  test_ordered_array_set_deleteElement();
  test_ordered_array_set_union();
  test_ordered_array_set_intersection();
  test_ordered_array_set_difference();
  test_ordered_array_set_symmetricDifference();
  test_ordered_array_set_complement();
}

int main() {
  test();

  return 0;
}
