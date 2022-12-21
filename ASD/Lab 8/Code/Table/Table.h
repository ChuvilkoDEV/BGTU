#ifndef CODE_TABLE_H
#define CODE_TABLE_H

#include <stdbool.h>
#include "../Tree/Tree.h" // Cмотреть лаб.раб. №7


static const short TableOk = 0;
static const short TableNotSet = 1;
static const short TableNotExistElement = 2;
static const short TableEnd = 3;
short TableError;

typedef char* T_Key;
typedef Tree Table;

// инициализация таблицы
void initTable(Table *T);
// возвращает "истина", если таблица пуста, иначе "ложь"
bool emptyTable(Table *T);
// включает элемент таблицу, возвращает "истина", если элемент включён
// в таблицу, иначе "ложь"
bool putTable(Table *T, BaseType Key);
// исключает элемент, возвращает "истина", если элемент с ключом s был
// в таблице, иначе "ложь"
bool getTable(Table *T, T_Key Key);
// читает элемент. Возвращает "истина", если элемент с ключом s есть в
// таблице, иначе "ложь"
bool readTable(Table T, BaseType *E, T_Key Key);
// изменение элемента. Возвращает "истина", если элемент с ключом s
// есть в таблице, иначе "ложь"
bool writeTable(Table *T, BaseType E, T_Key Key);
// уничтожение таблицы
void doneTable(Table *T);

#endif //CODE_TABLE_H
