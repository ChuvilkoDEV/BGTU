#include "18_padTheSmallerString.h"


void additionalString(int n, char *s) {

}

void padTheSmallerString(char *s1, int n1, char *s2, int n2) {
  getBagOfWords(&_bag, s1);
  getBagOfWords(&_bag2, s2);

  if (n1 > n2) {
    additionalString(n2 - n1, s2);
  }
}