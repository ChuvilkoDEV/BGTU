#include "11_printWordBeforeFirstWordWithA.h"

int wordHasA(WordDescriptor w) {
  while (w.begin < w.end) {
    if (*w.begin == 'a' || *w.begin == 'A')
      return 1;
    w.begin++;
  }
  return 0;
}

WordBeforeFirstWordWithAReturnCode printWordBeforeFirstWithA(char *s) {
  getBagOfWords(&_bag, s);
  if (_bag.size == 0) {
    return EMPTY_STRING;
  } else if (_bag.size == 1) {
    return FIRST_WORD_WITH_A;
  }

  for (int i = 0; i < _bag.size; i++) {
    if (wordHasA(_bag.words[i])) {
      if (i == 0)
        return FIRST_WORD_WITH_A;
      outputWord(_bag.words[i - 1]);
      return WORD_FOUND;
    }
  }
  return NOT_FOUND_A_WORD_WITH_A;
}

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s,
                                                           char **beginWord,
                                                           char **endWord) {
  getBagOfWords(&_bag, s);
  if (_bag.size == 0) {
    return EMPTY_STRING;
  } else if (_bag.size == 1) {
    return FIRST_WORD_WITH_A;
  }

  for (int i = 0; i < _bag.size; i++) {
    if (wordHasA(_bag.words[i])) {
      if (i == 0)
        return FIRST_WORD_WITH_A;
      *beginWord = _bag.words[i - 1].begin;
      *endWord = _bag.words[i - 1].end;
      return WORD_FOUND;
    }
  }
  return NOT_FOUND_A_WORD_WITH_A;
}

void testAll_getWordBeforeFirstWordWithA() {
  char *beginWord, *endWord;

  char s1[] = "";
  assert (
    getWordBeforeFirstWordWithA(s1, &beginWord, &endWord)
    == EMPTY_STRING
  );

  char s2[] = " ABC";
  assert (
    getWordBeforeFirstWordWithA(s2, &beginWord, &endWord)
    == FIRST_WORD_WITH_A
  );

  char s3[] = "BC A";
  assert (
    getWordBeforeFirstWordWithA(s3, &beginWord, &endWord)
    == WORD_FOUND
  );
  char got[MAX_WORD_SIZE];
  copy(beginWord, endWord, got);
  got[endWord - beginWord] = '\0';
  ASSERT_STRING ("BC", got);

  char s4[] = "B Q WE YR OW IUWR ";
  assert (getWordBeforeFirstWordWithA(s4, &beginWord, &endWord) ==
          NOT_FOUND_A_WORD_WITH_A);
}