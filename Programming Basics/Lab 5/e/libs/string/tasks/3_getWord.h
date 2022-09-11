#ifndef LAB_5E_3_GETWORD_H
#define LAB_5E_3_GETWORD_H

#include "../string_.h"

int getWord(char *beginSearch, WordDescriptor *word);

void digitToStart(WordDescriptor word);

void reverseDigitBack(WordDescriptor word, WordDescriptor *newWord);

void orderedWordFront(WordDescriptor word, char *c);

void wordOrderedDigitReversed(char *c);

void test_wordOrderedDigitReversed();

void output(char *c, int size);

#endif //LAB_5E_3_GETWORD_H
