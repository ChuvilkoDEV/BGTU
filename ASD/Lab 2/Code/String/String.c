#include "String.h"

// Выделение динамической памяти под строку str, содержащую от 0 до n символов.
void InitStr(string1 str, unsigned n) {
  str->max = n;
  str->N = 0;
  str->s = malloc(sizeof(char) * n);
}

// Запись данных в строку dest из строки source.
void WriteToStr(string1 dest, const char *source) {
  int i = 0;
  while (source[i++] != '\0')
    continue;

  if (dest->max < i)
    STRING_ERROR = STRING_INPUT_ERROR;
  else
    memcpy(dest->s, source, i);
}

// Запись данных в строку dest из строки source.
void WriteFromStr(char *dest, string1 source) {
  memcpy(dest, source->s, source->N);
}

//Ввод строки s с клавиатуры
void InputStr(string1 str) {
  char k = getchar();
  unsigned short i = 0;

  while (k != '\n' && i < str->max) {
    str->s[i] = k;
    ++i;
    k = getchar();
  }

  str->N = i;
  str->s[i++] = '\0';

  if (k != '\n' && i == str->max) {
    STRING_ERROR = STRING_INPUT_ERROR;
    assert (STRING_ERROR == -1);
  } else
    STRING_ERROR = STR_SUCCESSFUL;
}

//Вывод строки s на экран монитора
void OutputStr(string1 str) {
  for (int i = 0; i < str->N; i++)
    putchar(str->s[i]);
}

//Сравнивает строки s1 и s2 возвращает 0 если
//s1 == s2; 1 если s1 > s2; -1 если s1 < s2
int Comp(string1 s1, string1 s2) {
  if (s1->N > s2->N)
    return 1;
  else if (s1->N < s2->N)
    return -1;

  for (int i = 0; i < s1->N; i++) {
    if (s1->s[i] > s2->s[i])
      return 1;
    else if (s1->s[i] < s2->s[i])
      return -1;
  }
  return 0;
}

//Удаляет count символов из строки s начиная с позиции index
void Delete(string1 str, unsigned index, unsigned count) {
  if (index + count >= str->N)
    STRING_ERROR = STRING_DELETE_ERROR;
  else {
    unsigned ptr = index;
    for (unsigned i = index + count; i < str->N; i++)
      str->s[ptr++] = str->s[i];
    str->N -= count;
  }
}

//Вставляет подстроку subS в строку str, начиная с позиции index
void Insert(string1 subS, string1 str, unsigned index) {
  if (index > str->N)
    STRING_ERROR = STRING_NO_PLACE;
  else if (subS->N + str->N > str->max)
    STRING_ERROR = STRING_INSERT_ERROR;
  else {
    unsigned i = str->N + 1;

    while (i >= index) {
      str->s[i + subS->N] = str->s[i];
      --i;
    }

    i = index;
    unsigned j = 0;

    while (j < subS->N) {
      str->s[i] = subS->s[j];
      ++i;
      ++j;
    }

    str->N = str->N + subS->N;
  }

  assert (STRING_ERROR == (-3 || -2));
}

//Выполняет конкатенацию строк s1 и s2 результат помещает в sRez
void Concat(string1 s1, string1 s2, string1 sRez) {
  if (s1->N + s2->N > sRez->N)
    STRING_ERROR = STRING_CONCAT_ERROR;

  //Скопируем в sRez первую строку
  for (int i = 0; i < s1->N; i++) {
    sRez->s[i] = s1->s[i];
  }

  unsigned i = s1->N;

  //Соединим sRez со второй строкой
  for (int j = 0; j < s2->N; j++) {
    sRez->s[j + i] = s2->s[j];
  }

  sRez->N = s1->N + s2->N;
  sRez->s[sRez->N] = '\0';

  assert (STRING_ERROR == -4);
}

//Записывает count символов в строку subS из строки s
//начиная с позиции index
void Copy(string1 s, unsigned index, unsigned count, string1 subS) {
  if (index + count > s->N || count > s->max)
    STRING_ERROR = STRING_NO_PLACE;
  else {
    unsigned i = 0;
    unsigned rBord = index + count;

    while (index < rBord) {
      subS->s[i] = s->s[index];
      ++i;
      ++index;
    }
    subS->N = i;
  }
  assert (STRING_ERROR == -3);
}

//Возвращает текущую длинну строки s
unsigned Length(string1 s) {
  return s->N;
}

void reverse(string1 s) {
  unsigned length = strlen(s->s);
  char c;
  int i, j;

  for (i = 0, j = length - 1; i < j; i++, j--) {
    c = s->s[i];
    s->s[i] = s->s[j];
    s->s[j] = c;
  }
}

// Возвращает позицию начиная с которой в строке s
// располагается строка subS
unsigned Pos(string1 subS, string1 s) {
  unsigned short j;
  unsigned short lens = s->N;
  unsigned short lensubS = subS->N;
  unsigned short len = lens - lensubS;

  if (lens < lensubS) {
    STRING_ERROR = STRING_POS_ERROR;
    assert (STRING_ERROR == -5);
  }

  for (unsigned short i = 0; i <= len; ++i) {
    j = 0;
    while ((j < lensubS) && (s->s[i + j] == subS->s[j]))
      ++j;
    if (j == subS->N)
      return i + 1;
  }

  return 0;
}

// Удаляет строку s из динамической памяти.
void DoneStr(string1 s) {
  free(s->s);
  s->N = 0;
  s->max = 0;
}

// сравнение строк(с игнорированием множественных пробелов)
int WordCmp(string1 s1, string1 s2) {
  int s1Ptr = 0;
  int s2Ptr = 0;
  while (s1->s[s1Ptr] != '\0' && s2->s[s2Ptr] != '\0') {
    while (s1->s[s1Ptr] == ' ')
      s1Ptr++;
    while (s2->s[s2Ptr] == ' ')
      s2Ptr++;
    if (s1->s[s1Ptr] != s2->s[s2Ptr])
      return 0;
    s1Ptr++;
    s2Ptr++;
  }
  return 1;
}

