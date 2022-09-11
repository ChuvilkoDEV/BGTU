#include "3_getWord.h"

// Задача 3

// Записывает цифры из слова word в конец слова newWord в обратном порядке
void reverseDigitBack(WordDescriptor word, WordDescriptor *newWord) {
  while (word.begin < word.end) {
    if (isdigit(*word.begin))
      *(--newWord->end) = *word.begin;
    word.begin++;
  }
}

// Записывает буквы из слова word в начало слова newWord в том же порядке
void orderedGraphFront(WordDescriptor word, WordDescriptor *newWord) {
  while (word.begin < word.end) {
    if (isgraph(*word.begin))
      *(newWord->begin++) = *word.begin;
    word.begin++;
  }
}

// Записывает в отдельном слове цифры в конец слова, а цифры в начало.
void wordOrderedDigitReversed(char *c) {
  WordDescriptor word;
  word.begin = c;
  while (getWord(word.begin, &word)) {
    int len = word.end - word.begin;
    char newC[len];
    WordDescriptor newWord = (WordDescriptor) {newC, newC + len};
    reverseDigitBack(word, &newWord);
    orderedGraphFront(word, &newWord);
    memcpy(word.begin, newWord.begin, len);
    word.begin = word.end;
  }
}


// Тесты

void test_wordOrderedDigitReversed_oneWordOnlyGraph() {
  char c[] = "abcd";
  wordOrderedDigitReversed(c);
  ASSERT_STRING("abcd", c);
}

void test_wordOrderedDigitReversed_oneWordOnlyDigit() {
  char c[] = "1234";
  wordOrderedDigitReversed(c);
  ASSERT_STRING("4321", c);
}

void test_wordOrderedDigitReversed_WordOnlyDigitAndWordOnlyDigit() {
  char c[] = "1234 abcd";
  wordOrderedDigitReversed(c);
  ASSERT_STRING("4321 abcd", c);
}

void test_wordOrderedDigitReversed_WordsDigitAndDigit() {
  char c[] = "1234abcd 1a2b3c4d";
  wordOrderedDigitReversed(c);
  ASSERT_STRING("abcd4321 abcd4321", c);
}

void test_wordOrderedDigitReversed() {
  test_wordOrderedDigitReversed_oneWordOnlyGraph();
  test_wordOrderedDigitReversed_oneWordOnlyDigit();
  test_wordOrderedDigitReversed_WordOnlyDigitAndWordOnlyDigit();
  test_wordOrderedDigitReversed_WordsDigitAndDigit();
}