#include "13_haveSameWord.h"

int haveSameWord(char *s1, char *s2) {
  WordDescriptor w = lastCommonWords(s1, s2);
  if (w.end == w.begin)
    return 0;
  return 1;
}

void test_haveSameWord_noWord() {
  char s1[] = "aa ab ac";
  char s2[] = "cc cb ca";
  assert(haveSameWord(s1, s2) == 0);
}

void test_haveSameWord_oneWord() {
  char s1[] = "aa";
  char s2[] = "aa";
  assert(haveSameWord(s1, s2) == 1);
}

void test_haveSameWord_anyWord() {
  char s1[] = "aa bb cc";
  char s2[] = "aa bb cc";
  assert(haveSameWord(s1, s2) == 1);
}

void test_haveSameWord_sadadasd() {
  char s1[] = "aa bb cc";
  char s2[] = "asd asd asd";
  assert(haveSameWord(s1, s2) == 0);
}

void test_haveSameWord() {
  test_haveSameWord_noWord();
  test_haveSameWord_oneWord();
  test_haveSameWord_anyWord();
  test_haveSameWord_sadadasd();
}