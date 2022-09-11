#include <ctype.h>
#include "string_.h"

# define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)

// Первая реализация функции, которая возвращает размер строки
size_t strlen1(char *a) {
  size_t i = 0;
  while (a[i] != '\0')
    i++;
  return i;
}

// Вторая реализация функции, которая возвращает размер строки
size_t strlen2(char *s) {
  int i = 0;
  while (*s != '\0') {
    i++;
    s++;
  }
  return i;
}

// Возвращает размер строки
size_t strlen_(const char *begin) {
  char const *end = begin;
  while (*end != '\0')
    end++;
  return end - begin;
}

// Возвращает указатель на первый элемент с кодом ch, расположенным на ленте
// памяти между адресами begin и end не включая end. Если символ не найден,
// возвращается значение end.
char *find(char *begin, char *end, int ch) {
  while (begin != end && *begin != ch)
    begin++;
  return begin;
}

// Возвращает указатель на первый символ, отличный от пробельных, расположенный
// на ленте памяти, начиная с begin и заканчивая ноль-символом. Если символ
// не найден, возвращается адрес первого ноль-символа.
char *findNonSpace(char *begin) {
  while (isspace(*begin))
    begin++;
  return begin;
}

// возвращает указатель на первый пробельный символ, расположенный на ленте
// памяти начиная с адреса begin или на первый ноль-символ.
char *findSpace(char *begin) {
  while (!isspace(*begin) && *begin != '\0')
    begin++;
  return begin;
}

// Возвращает указатель на первый справа символ, отличный от пробельных,
// расположенный на ленте памяти, начиная с rbegin (последний символ
// строки, за которым следует ноль-символ) и заканчивая rend
// (адрес символа перед началом строки). Если символ не найден, возвращается
// адрес rend.
char *findNonSpaceReverse(char *rbegin, const char *rend) {
  while (rbegin >= rend && isspace(*rbegin))
    rbegin--;
  return rbegin;
}

// Возвращает указатель на первый пробельный символ справа, расположенный на
// ленте памяти, начиная с rbegin и заканчивая rend. Если символ не найден,
// возвращается адрес rend.
char *findSpaceReverse(char *rbegin, const char *rend) {
  while (rbegin >= rend && !isspace(*rbegin))
    rbegin--;
  return rbegin;
}

// Функция возвращает отрицательное значение, если lhs располагается до rhs
// в лексикографическом порядке (как в словаре), значение 0, если lhs и rhs
// равны, иначе – положительное значение.
int strcmp_(const char *lhs, const char *rhs) {
  while (*lhs && *lhs == *rhs)
    lhs++, rhs++;
  return *lhs - *rhs;
}

// Записывает по адресу beginDestination фрагмент памяти, начиная с адреса
// beginSource до endSource. Возвращает указатель на следующий свободный
// фрагмент памяти в destination
char *copy(const char *beginSource, const char *endSource,
           char *beginDestination) {
  while (beginSource < endSource) {
    *beginDestination = *beginSource;
    beginSource++;
    beginDestination++;
  }
  return beginDestination;
}

// Записывает по адресу beginDestination элементы из фрагмента памяти начиная с
// beginSource заканчивая endSource, удовлетворяющие функции-предикату f.
// Функция возвращает указатель на следующий свободный для записи фрагмент в
// памяти.
char *copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int)) {
  while (beginSource < endSource) {
    if (f(*beginSource))
      *beginDestination++ = *beginSource;
    beginSource++;
  }
  return beginDestination;
}

// Записывает по адресу beginDestination элементы из фрагмента памяти начиная с
// rbeginSource заканчивая rendSource, удовлетворяющие функции-предикату f.
// Функция возвращает значение beginDestination по окончанию работы функции.
char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int)) {
  while (rbeginSource > rendSource) {
    if (f(*rbeginSource)) {
      *beginDestination = *rbeginSource;
      beginDestination++;
    }
    rbeginSource--;
  }
  return beginDestination;
}

// Возвращает адрес конца строки
char *getEndOfString(char *c) {
  return c + strlen_(c);
}

// Возвращает адрес начала слова
char *getBeginOfWord(char *c) {
  while (*c != '\0' && isspace(*c))
    c++;
  return c;
}

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
  if (strcmp_(expected, got)) {
    fprintf(stderr, "File %s\n", fileName);
    fprintf(stderr, "%s - failed on line %d\n", funcName, line);
    fprintf(stderr, "Expected : \t\"%s \"\n", expected);
    fprintf(stderr, "Got: \t\t\"%s\"\n\n", got);
  } else
    fprintf(stdout, "%s - OK\n", funcName);
}

void printErrorInt(const int expected, int got,
                   char const *fileName, char const *funcName,
                   int line) {
  fprintf(stderr, "File %s\n", fileName);
  fprintf(stderr, "%s - failed on line %d\n", funcName, line);
  fprintf(stderr, "Expected : \t\"%d\"\n", expected);
  fprintf(stderr, "Got: \t\t\"%d\"\n\n", got);
}

void assertInt(const int expected, int got,
               char const *fileName, char const *funcName,
               int line) {
  if (expected != got) {
    fprintf(stderr, "File %s\n", fileName);
    fprintf(stderr, "%s - failed on line %d\n", funcName, line);
    fprintf(stderr, "Expected : \t\"%d\"\n", expected);
    fprintf(stderr, "Got: \t\t\"%d\"\n\n", got);
  } else
    fprintf(stdout, "%s - OK\n", funcName);
}

// Возвращает значение 0, если слово не было считано, в противном
// случае будет возвращено значение 1 и в переменную word типа WordDescriptor
// будут записаны позиции начала слова, и первого символа после конца слова
int getWord(char *beginSearch, WordDescriptor *word) {
  word->begin = findNonSpace(beginSearch);

  if (*word->begin == '\0')
    return 0;

  word->end = findSpace(word->begin);

  return 1;
}

int wordlen(char *c) {
  char *end = c;
  while (!isspace(*end) && *end != '\0')
    end++;
  return end - c;
}

// Возвращает 1, если слово w1 равно w2. 0 в обратном случае.
int isEqualWord(WordDescriptor w1, WordDescriptor w2) {
  while (w1.begin < w1.end && w2.begin < w2.end) {
    if (*w1.begin != *w2.begin)
      return 0;
    w1.begin++, w2.begin++;
  }
  return 1;
}

char *recSpace(char *readPtr, char *recPtr) {
  while (*readPtr != '\0' && isspace(*readPtr))
    *(recPtr++) = *(readPtr++);
  return recPtr;
}

void getBagOfWords(BagOfWords *bag, char *s) {
  char *begin = s;
  bag->size = 0;
  while (getWord(begin, &bag->words[bag->size])) {
    begin = bag->words[bag->size].end;
    bag->size++;
  }
}

char *writeWordInString(char *s, WordDescriptor w) {
  while (w.begin < w.end)
    *(s++) = *(w.begin++);
  *(s++) = ' ';
  return s;
}

int wordCmp(WordDescriptor w1, WordDescriptor w2) {
  while (*w1.begin == *w2.begin &&
         w1.begin < w1.end - 1 && w2.begin < w2.end - 1)
    w1.begin++, w2.begin++;
  return *w1.begin - *w2.begin;
}

void outputWord(WordDescriptor word) {
  while (word.begin < word.end) {
    printf("%c", *word.begin);
    word.begin++;
  }
  printf(" ");
}

void test_strlen() {
  char a[] = "Hello world!";
  char b[100] = "Z";
  char c[] = "\tHi\t";

  assert(strlen1(a) == 12);
  assert(strlen2(b) == 1);
  assert(strlen_(c) == 4);
}

void test_finds() {
  char a[] = "  abcd";
  assert(findNonSpace(a) - a == 2);
  char b[] = "abcd  ";
  assert(findSpace(b) - b == 4);
  char c[] = "abcd    ";
  assert(&c[strlen1(c) - 1] - findNonSpaceReverse(&c[7], c) == 4);
  char d[] = "    abcd";
  assert(&d[strlen1(d) - 1] - findSpaceReverse(&d[7], d) == 4);
}