#ifndef CODE_QUEUE_H
#define CODE_QUEUE_H

#include "../../../Lab 5/code/List7/List7.h" // Смотреть лаб. раб. №5

const int FifoOk = LIST_OK;
const int FifoUnder = ListUnder;
const int FifoOver = LIST_NOT_MEM;
int FifoError; // Переменная ошибок

typedef List Fifo;

void InitFifo(Fifo *f); // Инициализация очереди
void PutFifo(Fifo *f, BaseType E); /* Поместить элемент в очередь */
void GetFifo(Fifo *f, BaseType *E); /* Извлечь элемент из очереди */
void ReadFifo(Fifo *f, BaseType *E); // Прочитать элемент
int EmptyFifo(Fifo *f); // Проверка, пуста ли очередь?
void DoneFifo(Fifo *f); // Разрушить очередь

#endif //CODE_QUEUE_H
