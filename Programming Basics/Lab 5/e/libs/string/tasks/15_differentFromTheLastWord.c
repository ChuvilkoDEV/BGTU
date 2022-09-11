#include "15_differentFromTheLastWord.h"

void differentFromTheLastWord(char *s) {
  copy(s, getEndOfString(s) + 1, _stringBuffer);
  getBagOfWords(&_bag, _stringBuffer);

  for (int i = 0; i < _bag.size - 1; i++) {
    if (wordCmp(_bag.words[i], _bag.words[_bag.size - 1]) != 0)
      s = writeWordInString(s, _bag.words[i]);
  }
  *s = '\0';
}

void test_differentFromTheLastWord_one() {
  char c[] = "aa";
  differentFromTheLastWord(c);
  ASSERT_STRING("", c);
}

void test_differentFromTheLastWord_any() {
  char c[] = "aa bb cc aa";
  differentFromTheLastWord(c);
  ASSERT_STRING("bb cc", c);
}

void test_differentFromTheLastWord() {
  test_differentFromTheLastWord_one();
  test_differentFromTheLastWord_any();
}