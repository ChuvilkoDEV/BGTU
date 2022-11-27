#ifndef CODE_LIST7_H
#define CODE_LIST7_H
#define capacity 1000

#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

/// переменные ошибок
// успешное завершение операции
static const short LIST_OK = 0;
// недостаток памяти
static const short LIST_NOT_MEM = 1;
// указатель в конце списка
static const short ListUnder = 2;
static const short ListEnd = 3;
static short ListError;

typedef int BaseType;
typedef unsigned ptrel;
struct List {
  BaseType *PMemList;
  ptrel ptr;
  unsigned int N; // длина списка
  unsigned int SizeMem; // размер массива
} typedef List;

void InitList(List *L, unsigned SizeMem);

void PutList(List *L, BaseType x);

void GetList(List *L, BaseType x);

void ReadList(List *L, BaseType *x);

bool FullList(List *L);

bool EndList(List *L);

unsigned int Count(List *L);

void BeginPtr(List *L);

void EndPtr(List *L);

void MovePtr(List *L);

void MoveTo(List *L, unsigned int n);

void CopyList(List *L1,List *L2);

bool isEqual(List *L1,List *L2);

void CopyFromArray(List *L, const int *a, int n);

#endif //CODE_LIST7_H
