#include "2_removeAdjacentEqualLetters.h"

// Задача 2

// Преобразовывает строку, оставляя только один символ в каждой
// последовательности подряд идущих одинаковых символов
void removeAdjacentEqualLetters(char *s) {
  char *beginSource = s;
  while (*beginSource) {
    if (*beginSource != *s)
      *(++s) = *beginSource;
    beginSource++;
  }
  *(s + 1) = '\0';
}

// Тесты

void test_removeAdjacentEqualLetters_noRepeatingCharacters() {
  char c[] = "abcd ";
  removeAdjacentEqualLetters(c);
  ASSERT_STRING("abcd ", c);
}

void test_removeAdjacentEqualLetters_manyRepeatedCharacters() {
  char c[] = "aabbccddeeff  ";
  removeAdjacentEqualLetters(c);
  ASSERT_STRING("abcdef ", c);
}

void test_removeAdjacentEqualLetters_multipleRepeatedCharacters() {
  char c[] = "aabccdecef  \n";
  removeAdjacentEqualLetters(c);
  ASSERT_STRING("abcdecef \n", c);
}

void test_removeAdjacentEqualLetters_void() {
  char c[] = "";
  removeAdjacentEqualLetters(c);
  ASSERT_STRING("", c);
}

void test_removeAdjacentEqualLetters() {
  test_removeAdjacentEqualLetters_noRepeatingCharacters();
  test_removeAdjacentEqualLetters_manyRepeatedCharacters();
  test_removeAdjacentEqualLetters_multipleRepeatedCharacters();
  test_removeAdjacentEqualLetters_void();
}