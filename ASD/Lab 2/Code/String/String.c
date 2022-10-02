#include "String.h"

// Выделение динамической памяти под строку st, содержащую от 0 до n символов.
void InitStr(string1 st, unsigned n) {
  st->s = malloc(n);
  st->max = n;
  st->N = 0;
}

// Запись данных в строку st из строки s.
void WriteToStr(string1 st, const char *s) {
  int i = 0;
  while (s[i++] != '\0')
    continue;

  if (st->max < i)
    STRING_ERROR = STRING_INPUT_ERROR;
  else
    memcpy(st->s, s, i);
}

// Запись данных в строку s из строки st.
void WriteFromStr(char *s, string1 st) {
  memcpy(s, st->s, st->N);
}

//Ввод строки s с клавиатуры
void InputStr(string1 st) {
  char k = getchar();
  unsigned short i = 0;

  while (k != '\n' && i < st->max) {
    st->s[i] = k;
    ++i;
    k = getchar();
  }

  st->N = i;
  st->s[i++] = '\0';

  if (k != '\n' && i == st->max) {
    STRING_ERROR = STRING_INPUT_ERROR;
    assert (STRING_ERROR == -1);
  } else
    STRING_ERROR = STR_SUCCESSFUL;
}

//Вывод строки s на экран монитора
void OutputStr(string1 st) {
  for (int i = 0; i < st->N; i++)
    putchar(st->s[i]);
}

//Сравнивает строки s1 и s2 возвращает 0 если
//s1 == s2; 1 если s1 > s2; -1 если s1 < s2
int Comp(string1 s1, string1 s2) {
  if (s1->N > s2->N)
    return 1;
  else if (s1->N < s2->N)
    return -1;
  else {
    int i = 0;
    while ((s1->s[i] == s2->s[i]) && (i < s1->N)) {
      i++;
    }

    if ((i == s1->N) && (i == s2->N)) {
      STRING_ERROR = STR_SUCCESSFUL;
      return 0;
    }

    if (s1->s[i] > s2->s[i]) {
      STRING_ERROR = STR_SUCCESSFUL;
      return 1;
    }

  }
}

//Удаляет count символов из строки s
//начиная с позиции index
void Delete(string1 st, unsigned index, unsigned count) {
  for (int i = index; i < st->N; i++) {
    st->s[i] = st->s[i + count];
  }

  st->s[st->N - count] = '\0';
  st->N = st->N - count;
}

//Вставляет подстроку subS в строку st
//начиная с позиции index
void Insert(string1 subS, string1 st, unsigned index) {
  if (index > st->N)
    STRING_ERROR = STRING_NO_PLACE;
  else if (subS->N + st->N > st->max)
    STRING_ERROR = STRING_INSERT_ERROR;
  else {
    unsigned i = st->N + 1;

    while (i >= index) {
      st->s[i + subS->N] = st->s[i];
      --i;
    }

    i = index;
    unsigned j = 0;

    while (j < subS->N) {
      st->s[i] = subS->s[j];
      ++i;
      ++j;
    }

    st->N = st->N + subS->N;
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

  for (i = 0, j = length - 1; i < j; i++, j - -) {
    c = s->s[i];
    s->s[i] = s->s[j];
    s->s[j] = c;
  }
}

//Возвращает позицию начиная с которой в строке s
//распологается строка subS
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

