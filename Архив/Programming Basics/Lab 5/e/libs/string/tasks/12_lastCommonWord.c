#include "12_lastCommonWord.h"


WordDescriptor lastCommonWord(char *s1, char *s2) {
  getBagOfWords(&_bag, s1);
  getBagOfWords(&_bag2, s2);

  for (int i = _bag.size - 1; i >= 0; i--)
    for (int j = 0; j < _bag2.size; j++)
      if (wordCmp(_bag.words[i], _bag2.words[j]) == 0)
        return _bag.words[i];
  return (WordDescriptor){s1, s1};
}

void wordDescriptorToString(WordDescriptor word, char *destination) {
  destination = copy(word.begin, word.end, destination);
  *destination = '\0';
}

void test_lastCommonWord_noWord() {
  char s1[] = "aa ab ac";
  char s2[] = "cc cb ca";
  WordDescriptor word = lastCommonWord(s1, s2);
  char res[MAX_WORD_SIZE];
  wordDescriptorToString(word, res);
  ASSERT_STRING("", res);
}

void test_lastCommonWord_oneWord() {
  char s1[] = "aa";
  char s2[] = "aa";
  WordDescriptor word = lastCommonWord(s1, s2);
  char res[MAX_WORD_SIZE];
  wordDescriptorToString(word, res);
  ASSERT_STRING("aa", res);
}

void test_lastCommonWord_anyWord() {
  char s1[] = "aa bb cc";
  char s2[] = "aa bb cc";
  WordDescriptor word = lastCommonWord(s1, s2);
  char res[MAX_WORD_SIZE];
  wordDescriptorToString(word, res);
  ASSERT_STRING("cc", res);
}

void test_lastCommonWord_sadadasd() {
  char s1[] = "aa bb cc";
  char s2[] = "asd asd asd";
  WordDescriptor word = lastCommonWord(s1, s2);
  char res[MAX_WORD_SIZE];
  wordDescriptorToString(word, res);
  ASSERT_STRING("", res);
}

void test_lastCommonWord() {
  test_lastCommonWord_noWord();
  test_lastCommonWord_oneWord();
  test_lastCommonWord_anyWord();
  test_lastCommonWord_sadadasd();
}