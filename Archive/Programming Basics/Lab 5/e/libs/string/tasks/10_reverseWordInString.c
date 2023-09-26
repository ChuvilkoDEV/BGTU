#include "10_reverseWordInString.h"

char *reverseWriteWord(char *rBegin, WordDescriptor w) {
  while (w.begin < w.end)
    *(--rBegin) = *(--w.end);
  return rBegin;
}

void reverseWordInString(char *s) {
  char *end = getEndOfString(s);
  copy(s, end + 1, _stringBuffer);
  WordDescriptor word;
  word.begin = _stringBuffer;


  while (getWord(word.begin, &word)) {
    end = reverseWriteWord(end, word);
    if (end > s)
      *(--end) = ' ';
    word.begin = word.end;
  }
}

void test_reverseWordInString_oneWord() {
  char c[] = "abc";
  reverseWordInString(c);
  ASSERT_STRING("abc", c);
}

void test_reverseWordInString_moreWord() {
  char c[] = "abc def";
  reverseWordInString(c);
  ASSERT_STRING("def abc", c);
}

void test_reverseWordInString() {
  test_reverseWordInString_oneWord();
  test_reverseWordInString_moreWord();
}