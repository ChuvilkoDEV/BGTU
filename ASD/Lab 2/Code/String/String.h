#ifndef CODE_STRING_H
#define CODE_STRING_H

#include <malloc.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

#define MAX_LEN 50

//Операция прошла успешно
static const int STR_SUCCESSFUL = 0;

//Выход за границу максимально разрешенного размера строки
//при вводе в нее данных
static const int STRING_INPUT_ERROR = -1;

//Выход за границу максимально разрешенного размера строки
//при вставке данных из одной строки в другую
static const int STRING_INSERT_ERROR = -2;

//Попытка вставить элемент на место которое не существует
static const int STRING_NO_PLACE = -3;

//Выход за границу максимально разрешенного размера строки
//при склеивании в нее данных
static const int STRING_CONCAT_ERROR = -4;

//Ошибка поиска в меньшей строки большей подстроки
static const int STRING_POS_ERROR = -5;

// Ошибка выхода за пределы массива при удалении подстроки
static const int STRING_DELETE_ERROR = -6;

static int STRING_ERROR = 0;

typedef struct str {
  char *s; // Указатель на строку
  unsigned max; /* Максимальное количество символов в
                строке, определяющееся при инициализации*/
  unsigned N; // Динамическая (текущая) длина строки
} str;

typedef str *string1;

// Выделение динамической памяти под строку s, содержащую от 0 до n символов.
void InitStr(string1 s, unsigned n);

unsigned GetLenStr(const char *src);

// Запись данных в строку dst из строки src.
void WriteToStr(string1 dst, char *src);

// Запись данных в строку dest из строки source.
void WriteFromStr(char *dest, string1 source);

// Ввод строки s с клавиатуры.
void InputStr(string1 s);

//Вывод строки s на экран монитора
void OutputStr(string1 s);

//Сравнивает строки s1 и s2 возвращает 0 если
//s1 == s2; 1 если s1 > s2; -1 если s1 < s2
int Comp(string1 s1, string1 s2);

//Удаляет count символов из строки s начиная с позиции index
void Delete(string1 s, unsigned index, unsigned count);

//Вставляет подстроку subS в строку s начиная с позиции index
void Insert(string1 s, string1 subS, unsigned index);

//Выполняет конкатенацию строк s1 и s2 результат помещает в sRez
void Concat(string1 s1, string1 s2, string1 sRez);

//Записывает count символов в строку subS из строки s, начиная с позиции index
void Copy(string1 s, string1 subS, unsigned index, unsigned count);

//Возвращает текущую длинну строки s
unsigned Length(string1 s);

void reverse(string1 s);

//Возвращает позицию начиная с которой в строке s
//распологается строка subS
unsigned Pos(string1 subS, string1 s);

// Удаляет строку s из динамической памяти.
void DoneStr(string1 s);

// сравнение строк(с игнорированием множественных пробелов)
int WordCmp(string1 s1, string1 s2);

void Tests();

#endif //CODE_STRING_H
