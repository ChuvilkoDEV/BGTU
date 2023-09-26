#include "1_digitToStartTransform.h"

// Задача 1

// Удаляет пробельные символы
void removeNonLetters(char *s) {
  char *endSource = getEndOfString(s);
  char *destination = copyIf(s, endSource, s, isgraph);
  *destination = '\0';
}

// Тесты

void test_removeNonLetters_oneWord() {
  char c[] = " abacaba  ";
  removeNonLetters(c);
  ASSERT_STRING("abacaba", c);
}

void test_removeNonLetters_fewWords() {
  char c[] = "ab\ncd\tef  ";
  removeNonLetters(c);
  ASSERT_STRING("abcdef", c);
}

void test_removeNonLetters() {
  test_removeNonLetters_oneWord();
  test_removeNonLetters_fewWords();
}