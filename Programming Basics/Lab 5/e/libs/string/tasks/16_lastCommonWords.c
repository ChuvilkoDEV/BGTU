#include "16_lastCommonWords.h"


WordDescriptor lastCommonWords(char *s1, char *s2) {
  getBagOfWords(&_bag, s1);
  getBagOfWords(&_bag2, s2);

  for (int i = _bag.size - 1; i >= 0; i--)
    for (int j = 0; j < _bag2.size; j++)
      if (wordCmp(_bag.words[i], _bag2.words[j]) == 0)
        return _bag.words[i];
  return (WordDescriptor){s1, s1};
}

void wordsDescriptorToString(WordDescriptor word, char *destination) {
  destination = copy(word.begin, word.end, destination);
  *destination = '\0';
}

void test_lastCommonWords_noWord() {
  char s1[] = "aa ab ac";
  char s2[] = "cc cb ca";
  WordDescriptor word = lastCommonWords(s1, s2);
  char res[MAX_WORD_SIZE];
  wordDescriptorToString(word, res);
  ASSERT_STRING("", res);
}

void test_lastCommonWords_oneWord() {
  char s1[] = "aa";
  char s2[] = "aa";
  WordDescriptor word = lastCommonWords(s1, s2);
  char res[MAX_WORD_SIZE];
  wordDescriptorToString(word, res);
  ASSERT_STRING("aa", res);
}

void test_lastCommonWords_anyWord() {
  char s1[] = "aa bb cc";
  char s2[] = "aa bb cc";
  WordDescriptor word = lastCommonWords(s1, s2);
  char res[MAX_WORD_SIZE];
  wordDescriptorToString(word, res);
  ASSERT_STRING("cc", res);
}

void test_lastCommonWords_sadadasd() {
  char s1[] = "aa bb cc";
  char s2[] = "asd asd asd";
  WordDescriptor word = lastCommonWords(s1, s2);
  char res[MAX_WORD_SIZE];
  wordDescriptorToString(word, res);
  ASSERT_STRING("", res);
}

void test_lastCommonWords() {
  test_lastCommonWords_noWord();
  test_lastCommonWords_oneWord();
  test_lastCommonWords_anyWord();
  test_lastCommonWords_sadadasd();
}