#ifndef UNTITLED_OLS_H
#define UNTITLED_OLS_H

#include "stdbool.h"
#include "stdio.h"

#define ListOk  0
#define ListNotMem  1
#define ListUnder  2
#define ListEnd  3
#define  SizeList 1000

typedef int BaseType;

typedef struct ListElement *ptrel;

typedef struct ListElement {
    BaseType data;
    ptrel next; /*flag=1 если элемент принадлежит ОЛС*/
    int isUsing; //flag=0 если свободен
} ListElement;

typedef struct List {
    ptrel Start;
    ptrel ptr;
    unsigned int N;
} List;

static ListElement MemList[SizeList];

static short ListError;

void InitList(List *L);

void PutList(List *L, BaseType E);

void GetList(List *L, BaseType *E);

void ReadList(List *L, BaseType *E);

bool IsListFull(List *L);

bool EndList(List *L);

unsigned int Count(List *L);

void BeginPtr(List *L);

void EndPtr(List *L);

void MovePtr(List *L);

void MoveTo(List *L, unsigned int n);

void DoneList(List *L);

void CopyList(List *L1, List *L2);

void InitMem();/*присваивает Flag каждoго элемента в 0*/
int EmptyMemList(); /*возвращает 1, если в массиве нет свободных
элементов*/
unsigned NewMem();//возвращает номер свободного элемента
void DisposeMem(unsigned n);/*делает n-й элемент масcива cвободным*/

#endif //UNTITLED_OLS_H
