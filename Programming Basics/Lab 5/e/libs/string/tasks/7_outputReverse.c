#include "7_outputReverse.h"

// Выводит слова данной строки в обратном порядке
void outputReverse(char *c) {
  getBagOfWords(&_bag, c);
  for (int i = _bag.size - 1; i > 0; i--)
    outputWord(_bag.words[i]);
}