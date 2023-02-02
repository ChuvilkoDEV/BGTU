#ifndef CODE_QUEUE_H
#define CODE_QUEUE_H

#include "../OLS/OLS.h" // Смотреть лаб. раб. №5

const int FifoOk = ListOk;
const int FifoUnder = ListUnder;
const int FifoOver = ListNotMem;
int FifoError; // Переменная ошибок

typedef List Fifo;

void InitFifo(Fifo *f); // Инициализация очереди
void PutFifo(Fifo *f, BaseType E); /* Поместить элемент в очередь */
void GetFifo(Fifo *f, BaseType *E); /* Извлечь элемент из очереди */
void ReadFifo(Fifo *f, BaseType *E); // Прочитать элемент
int EmptyFifo(Fifo *f); // Проверка, пуста ли очередь?
void DoneFifo(Fifo *f); // Разрушить очередь

#endif //CODE_QUEUE_H
