#include "4_replaceNumberDigitsBySpace.h"


// Задание 4

// Преобразовать строку, заменяя каждую цифру соответствующим ей числом
// пробелов
void replaceNumberDigitBySpace(char *c) {
  char newString[MAX_STRING_SIZE];
  char *beginNewString = newString;
  char *begin = c;
  while (*begin != '\0') {
    if (isdigit(*begin))
      for (int i = 0; i < *begin - '0'; i++)
        *(beginNewString++) = ' ';
    else
      *(beginNewString++) = *begin;
    begin++;
  }
  memcpy(c, newString, strlen_(newString));
}

// Тесты

void test_replaceNumberDigitBySpace_oneWord() {
  char c[] = "a1b2c3d4";
  replaceNumberDigitBySpace(c);
  ASSERT_STRING("a b  c   d    ", c);
}

void test_replaceNumberDigitBySpace_anyWord() {
  char c[] = "a1, b1, c1, d1";
  replaceNumberDigitBySpace(c);
  ASSERT_STRING("a , b , c , d ", c);
}

void test_replaceNumberDigitBySpace() {
  test_replaceNumberDigitBySpace_oneWord();
  test_replaceNumberDigitBySpace_anyWord();
}