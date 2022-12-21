#ifndef CODE_TREE_H
#define CODE_TREE_H

#include "stdio.h"
#include "stdlib.h"

#define capacity 1000

typedef int BaseType;

static const int TreeOk = 0;
static const int TreeNotMem = 1;
static const int TreeUnder = 2;
static int TreeError;

typedef unsigned int PtrEl;

struct element {
    BaseType data;
    PtrEl LSon;
    PtrEl RSon;
} typedef element;

typedef PtrEl *Tree;
static unsigned Size;
static element MemTree[capacity];


// инициализация дерева
void InitTree(Tree *T, unsigned size);

// Создание корня
void CreateRoot(Tree *T, BaseType x);

// Возвращает 1, если у элемента под номером index есть левый сын.
// 0 - в ином случае
int IsLSon(Tree *T, unsigned index);

// Возвращает 1, если у элемента под номером index есть правый сын.
// 0 - в ином случае
int IsRSon(Tree *T, unsigned index);

// Возвращает 1, если БД пустое. 0 - в ином случае
int IsEmptyTree(Tree *T);

// Возвращает 1, если в массиве нет свободных элементов,
// 0 — в противном случае
int EmptyMem(Tree *T);

// возвращает номер свободного элемента и исключает его из ССЭ
unsigned int NewMem(Tree *T);

//запись данных
void WriteDataTree(Tree *T, BaseType x);

void WriteDataTree_(Tree *T, BaseType x, unsigned index);

// Чтение
void ReadDataTree(Tree *T, BaseType *E);

// перейти к левому сыну, где T —адрес ячейки, содержащей адрес текущей
// вершины, TS — адрес ячейки, содержащей адрес корня левого
// поддерева(левого сына)
void MoveToLSon(Tree *T, Tree *TS);

//перейти к правому сыну
void MoveToRSon(Tree *T, Tree *TS);

// связывает все элементы массива в список свободных элементов
void InitMem(Tree *T);

//удаление листа
void DelTree(Tree *T);

// делает n-й элемент массива свободным и включает его в ССЭ
void DisposeMem(unsigned n);

#endif //CODE_TREE_H
