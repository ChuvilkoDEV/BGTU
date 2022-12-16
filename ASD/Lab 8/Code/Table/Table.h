#ifndef CODE_TABLE_H
#define CODE_TABLE_H

#include "list5.h" // Cмотреть лаб.раб. №5

static const TableOk = 0;
static const TableNotMem = 1;
static const TableUnder = 2;
static int TableError; // 0..2

typedef ... T_Key; // Определить тип ключа
typedef struct Table
{
    List* Buf;
    unsigned n; // Количество элементов в таблице
    unsigned SizeBuf; // Количество элементов в массиве Buf
};
void InitTable(Table *T, unsigned SizeBuf);
int EmptyTable(Table *T); // Возвращает 1 , если таблица пуста, иначе — 0
int PutTable(Table *T, BaseType E); /* Включение элемента в таблицу.
Возвращает 1 , если элемент включен в таблицу, иначе — 0 (если в таблице
уже есть элемент с заданным ключем или нехватает памяти) */
int GetTable(Table *T, BaseType *E, T_Key Key); /* Исключение элемента.
Возвращает 1 , если элемент с ключем Key был в таблице, иначе — 0 */
int ReadTable(Table *T, BaseType *E, T_Key Key); /* Чтение элемента.
Возвращает 1 , если элемент с ключем Key есть в таблице, иначе — 0 */
int WriteTable(Table *T, BaseType *E, T_Key Key); /* Изменение элемента.
Возвращает 1 , если элемент с ключем Key есть в таблице, иначе — 0 */
void DoneTable(Table *T); // Уничтожение таблицы


#endif //CODE_TABLE_H
