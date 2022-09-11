#ifndef LAB_5E_STRING__H
#define LAB_5E_STRING__H

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)
#define ASSERT_INT(expected, got) assertInt(expected, got, \
__FILE__, __FUNCTION__, __LINE__)

char _stringBuffer[MAX_STRING_SIZE + 1];

typedef struct WordDescriptor {
  char *begin; // позиция начала слова
  char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

typedef struct BagOfWords {
  WordDescriptor words[MAX_N_WORDS_IN_STRING];
  size_t size;
} BagOfWords;

BagOfWords _bag;
BagOfWords _bag2;

// Первая реализация функции, которая возвращает размер строки
size_t strlen1(char *a);

// Вторая реализация функции, которая возвращает размер строки
size_t strlen2(char *s);

// Возвращает размер строки
size_t strlen_(const char *begin);

// Возвращает указатель на первый элемент с кодом ch, расположенным на ленте
// памяти между адресами begin и end не включая end. Если символ не найден,
// возвращается значение end.
char *find(char *begin, char *end, int ch);

//  возвращает указатель на первый пробельный символ, расположенный на ленте
//  памяти начиная с адреса begin или на первый ноль-символ.
char *findNonSpace(char *begin);

char *findSpace(char *begin);

char *findNonSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, const char *rend);

// Функция возвращает отрицательное значение, если lhs располагается до rhs
// в лексикографическом порядке (как в словаре), значение 0, если lhs и rhs
// равны, иначе – положительное значение.
int strcmp_(const char *lhs, const char *rhs);

// Записывает по адресу beginDestination фрагмент памяти, начиная с адреса
// beginSource до endSource. Возвращает указатель на следующий свободный
// фрагмент памяти в destination
char *copy(const char *beginSource, const char *endSource,
           char *beginDestination);

// Записывает по адресу beginDestination элементы из фрагмента памяти начиная с
// beginSource заканчивая endSource, удовлетворяющие функции-предикату f.
// Функция возвращает указатель на следующий свободный для записи фрагмент в
// памяти.
char *copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int));

// Записывает по адресу beginDestination элементы из фрагмента памяти начиная с
// rbeginSource заканчивая rendSource, удовлетворяющие функции-предикату f.
// Функция возвращает значение beginDestination по окончанию работы функции.
char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int));

// Возвращает адрес конца строки
char *getEndOfString(char *c);

// Возвращает адрес начала слова
char *getBeginOfWord(char *c);

// assert(), только удобнее.
void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

void assertBool(int expected, int got,
                char const *fileName, char const *funcName,
                int line);

// Возвращает значение 0, если слово не было считано, в противном
// случае будет возвращено значение 1 и в переменную word типа WordDescriptor
// будут записаны позиции начала слова, и первого символа после конца слова
int getWord(char *beginSearch, WordDescriptor *word);

// Возвращает длину слова
int wordlen(char *c);

char *recSpace(char *readPtr, char *recPtr);

int isEqualWord(WordDescriptor w1, WordDescriptor w2);

void getBagOfWords(BagOfWords *bag, char *s);

void outputWord(WordDescriptor w);

char *writeWordInString(char *s, WordDescriptor w);

int wordCmp(WordDescriptor w1, WordDescriptor w2);

void test_strlen();

void test_finds();


#endif //LAB_5E_STRING__H
