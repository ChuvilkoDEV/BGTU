#include "5_replace.h"

// Заменяет все вхождения слова w1 на w2
void replace(char *source, char *w1, char *w2) {
  size_t w1Size = strlen_(w1);
  size_t w2Size = strlen_(w2);
  WordDescriptor word1 = {w1, w1 + w1Size};
  WordDescriptor word2 = {w2, w2 + w2Size};

  char *readPtr, *recPtr;
  if (w1Size >= w2Size) {
    readPtr = source;
    recPtr = source;
  } else {
    copy(source, getEndOfString(source), _stringBuffer);
    readPtr = _stringBuffer;
    recPtr = source;
  }

  WordDescriptor word;
  word.begin = readPtr;
  while (getWord(word.begin, &word)) {
    if (isEqualWord(word, word1)) {
      memcpy(recPtr, word2.begin, w2Size);
      recPtr += w2Size;
    } else {
      int len = wordlen(word.begin);
      memcpy(recPtr, word.begin, len);
      recPtr += len;
    }
    recPtr = recSpace(word.end, recPtr);
    word.begin = word.end;
  }
  *recPtr = '\0';
}

// Тесты

void test_replace_noMatches() {
  char c[] = "abc def";
  char w1[] = "ac";
  char w2[] = "ca";
  replace(c, w1, w2);
  ASSERT_STRING("abc def", c);
}

void test_replace_word1LessWord2() {
  char c[] = "happy";
  char w1[] = "happy";
  char w2[] = "sad";
  replace(c, w1, w2);
  ASSERT_STRING("sad", c);
}

void test_replace_word1MoreWord2() {
  char c[] = "sad";
  char w1[] = "sad";
  char w2[] = "happy";
  replace(c, w1, w2);
  ASSERT_STRING("happy", c);
}

void test_replace_words() {
  char c[] = "abc acb abc bca";
  char w1[] = "abc";
  char w2[] = "a";
  replace(c, w1, w2);
  ASSERT_STRING("a acb a bca", c);
}

void test_replace() {
  test_replace_noMatches();
  test_replace_word1LessWord2();
  test_replace_word1MoreWord2();
  test_replace_words();
}