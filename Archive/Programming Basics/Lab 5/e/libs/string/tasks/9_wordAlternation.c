#include "9_wordAlternation.h"

int max(int a, int b) {
  return a > b ? a : b;
}

char *wordAlternation(char *s1, char *s2, char *res) {
  getBagOfWords(&_bag, s1);
  getBagOfWords(&_bag2, s2);
  char *beginPtr = res;

  for (int i = 0; i < max(_bag.size, _bag2.size); i++) {
    if (i < _bag.size)
      beginPtr = writeWordInString(beginPtr, _bag.words[i]);
    if (i < _bag2.size)
      beginPtr = writeWordInString(beginPtr, _bag2.words[i]);
  }

  *(--beginPtr) = '\0';
  return res;
}

void test_wordAlternation_S1EqualS2() {
  char s1[] = "ab ef";
  char s2[] = "cd gh";
  char res[MAX_STRING_SIZE];
  ASSERT_STRING("ab cd ef gh", wordAlternation(s1, s2, res));
}

void test_wordAlternation_S1lessS2() {
  char s1[] = "ab ef";
  char s2[] = "cd gh 12";
  char res[MAX_STRING_SIZE];
  ASSERT_STRING("ab cd ef gh 12", wordAlternation(s1, s2, res));
}

void test_wordAlternation_S1moreS2() {
  char s1[] = "ab ef 34 56";
  char s2[] = "cd gh 12";
  char res[MAX_STRING_SIZE];
  ASSERT_STRING("ab cd ef gh 12 34 56", wordAlternation(s1, s2, res));
}

void test_wordAlternation() {
  test_wordAlternation_S1EqualS2();
  test_wordAlternation_S1lessS2();
  test_wordAlternation_S1moreS2();
}