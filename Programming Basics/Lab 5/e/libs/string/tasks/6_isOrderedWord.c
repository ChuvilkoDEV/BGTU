#include "6_isOrderedWord.h"

// Задание 6

int areOrderedWords(WordDescriptor w1, WordDescriptor w2) {
  while (w1.begin < w1.end && w2.begin < w2.end) {
    if (*w1.begin < *w2.begin)
      return 1;
    if (*w1.begin > *w2.begin)
      return 0;
    w1.begin++, w2.begin++;
  }
  return 1;
}

int isOrderedString(char *c) {
  WordDescriptor w1;
  if (!getWord(c, &w1))
    return 1;

  WordDescriptor w2;
  while (getWord(w1.end, &w2)) {
    if (!areOrderedWords(w1, w2))
      return 0;
    w1 = w2;
  }
  return 1;
}


// Тесты

void test_isOrderedString_oneWord() {
  char c[] = "ab";
  ASSERT_INT(1, isOrderedString(c));
}

void test_isOrderedString_orderedWords() {
  char c[] = "aa ab ac ca cb";
  ASSERT_INT(1, isOrderedString(c));
}

void test_isOrderedString_unorderedWords() {
  char c[] = "aa ab ac cz cb";
  ASSERT_INT(0, isOrderedString(c));
}

void test_isOrderedString() {
  test_isOrderedString_oneWord();
  test_isOrderedString_orderedWords();
  test_isOrderedString_unorderedWords();
}