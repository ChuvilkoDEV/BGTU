#include <stdio.h>
#include "sets/boolean_arraySet/booleans_array.h"

void task1() {
  boolean_array_set a = boolean_array_set_createFromArray(
    (int[]){1, 2, 3, 4, 5, 6, 7},
    7, 12
    );
  boolean_array_set b = boolean_array_set_createFromArray(
    (int[]){2, 5, 6, 9, 10},
    5, 12
    );
  boolean_array_set c = boolean_array_set_createFromArray(
    (int[]){4, 7, 8, 11, 12},
    5, 12
    );

  boolean_array_set first = boolean_array_set_symmetricDifference(a, b);
  printf("first array = ");
  boolean_array_set_print(first);
  printf("\n");

  boolean_array_set second = boolean_array_set_difference(c, a);
  printf("second array = ");
  boolean_array_set_print(second);
  printf("\n");

  boolean_array_set third = boolean_array_set_difference(first, c);
  printf("third array = ");
  boolean_array_set_print(third);
  printf("\n");

  boolean_array_set d = boolean_array_set_union(third, second);
  printf("D array = ");
  boolean_array_set_print(d);
  printf("\n");
}

void task2() {
  boolean_array_set a = boolean_array_set_createFromArray(
    (int[]){2, 5, 6, 7, 9},
    5, 10
  );
  boolean_array_set b = boolean_array_set_createFromArray(
    (int[]){1, 4, 5, 9},
    4, 10
  );
  boolean_array_set c = boolean_array_set_createFromArray(
    (int[]){3, 7, 8, 10},
    4, 10
  );
  boolean_array_set d = boolean_array_set_createFromArray(
    (int[]){1, 3, 4, 8, 10},
    5, 10
  );

  boolean_array_set first = boolean_array_set_union(c, b);
  printf("first array = ");
  boolean_array_set_print(first);
  printf("\n");

  boolean_array_set res = boolean_array_set_difference(first, a);
  printf("res array = ");
  boolean_array_set_print(res);
  printf("\n");
  printf("D array = ");
  boolean_array_set_print(d);
  printf("\n");


  if (boolean_array_set_isEqual(res, d))
    printf("res = d => Program work correctly");

}

int main() {
  task1();

  printf("-----------------------------------------\n\n");

  task2();

  return 0;
}
