#ifndef CODE_TABLE_H
#define CODE_TABLE_H

#include "../Tree/Tree.h" // Cмотреть лаб.раб. №7

static const int TableOk = 0;
static const int TableNotMem = 1;
static const int TableUnder = 2;
static int TableError; // 0..2

typedef int T_Key; // Определить тип ключа
struct Table
{
    Tree* Buf;
    unsigned n; // Количество элементов в таблице
    unsigned SizeBuf; // Количество элементов в массиве Buf
    unsigned SizeEl; // Размер элемента таблицы
} typedef Table;

typedef int (* func)(void*, void*); /* Сравнивает ключи элементов таблицы,
адреса которых находятся в параметрах a и b. Возвращает –1, если ключ
элемента по адресу a меньше ключа элемента по адресу b, 0 — если ключи
равны и +1 — если ключ элемента по адресу a больше ключа элемента по
адресу b */

void InitTable(Table *T, unsigned SizeBuf, unsigned SizeEl);
int EmptyTable(Table *T); // Возвращает 1 , если таблица пуста, иначе — 0
int PutTable(Table *T, void *E, func f); /* Включение элемента в таблицу.
Возвращает 1 , если элемент включен в таблицу, иначе — 0 (если в таблице
уже есть элемент с заданным ключем или нехватает памяти) */
int GetTable(Table *T, void *E, T_Key Key, func f); /* Исключение
элемента. Возвращает 1 , если элемент с ключем Key был в таблице, иначе
— 0 */
int ReadTable(Table *T, void *E, T_Key Key, func f); /* Чтение элемента.
Возвращает 1 , если элемент с ключем Key есть в таблице, иначе — 0 */
int WriteTable(Table *T, void *E, T_Key Key, func f); /* Изменение
элемента. Возвращает 1 , если элемент с ключем Key есть в таблице,
иначе — 0 */
void DoneTable(Table *T); // Уничтожение таблицы
#endif //CODE_TABLE_H
