#include "Tree.h"

// Связывает все элементы массива в список свободных элементов
void InitMem(Tree *T) {
    for (int i = 0; i < Size; i++)
        MemTree[i].RSon = i + 1;
}

// Инициализация БД
void InitTree(Tree *T, unsigned size) {
    MemTree[0].RSon = 1;
    Size = size;
    InitMem(T);
}

// Возвращает 1, если в массиве нет свободных элементов,
// 0 — в противном случае
int EmptyMem(Tree *T) {
    return MemTree[0].RSon == Size;
}

// Возвращает номер свободного элемента и исключает его из ССЭ
unsigned int NewMem(Tree *T) {
    if (EmptyMem(T)) {
        TreeError = TreeNotMem;
        exit(TreeNotMem);
    }

    unsigned freeElementIndex = MemTree[0].RSon;
    MemTree[0].RSon = MemTree[freeElementIndex].RSon;
    return freeElementIndex;
}

// Создает корень дереву T, со значением x
void CreateRoot(Tree *T, BaseType x) {
    unsigned index = NewMem(T);
    element el = MemTree[index];
    el.data = x;
    el.RSon = 0;
    el.LSon = 0;
}

// Возвращает 1, если у элемента под номером index есть левый сын.
// 0 - в ином случае
int IsLSon(Tree *T, unsigned index) {
    return MemTree[index].LSon != 0;
}

// Возвращает 1, если у элемента под номером index есть правый сын.
// 0 - в ином случае
int IsRSon(Tree *T, unsigned index) {
    return MemTree[index].RSon != 0;
}

// Возвращает 1, если БД пустое. 0 - в ином случае
int IsEmptyTree(Tree *T) {
    return MemTree[0].RSon == 1;
}

// Записывает элемент x, в дерево Tree
void WriteDataTree(Tree *T, BaseType x) {
    if (IsEmptyTree(T)) {
        CreateRoot(T, x);
    } else if (MemTree[1].data < x) {
        if (IsLSon(T, 1)) {
            WriteDataTree_(T, x, MemTree[1].LSon);
        } else {
            MemTree[1].LSon = MemTree[0].RSon;
            CreateRoot(T, x);
        }
    } else {
        if (IsRSon(T, 1)) {
            WriteDataTree_(T, x, MemTree[1].RSon);
        } else {
            MemTree[1].RSon = MemTree[0].RSon;
            CreateRoot(T, x);
        }
    }
}

// Рекурсивно погружется для записи элемента x
void WriteDataTree_(Tree *T, BaseType x, unsigned index) {
    if (MemTree[index].data < x) {
        if (IsLSon(T, index)) {
            WriteDataTree_(T, x, MemTree[index].LSon);
        } else {
            MemTree[index].LSon = MemTree[0].RSon;
            CreateRoot(T, x);
            return;
        }
    } else {
        if (IsRSon(T, index)) {
            WriteDataTree_(T, x, MemTree[index].RSon);
        } else {
            MemTree[index].RSon = MemTree[0].RSon;
            CreateRoot(T, x);
            return;
        }
    }
}

// перейти к левому сыну, где T —адрес ячейки, содержащей адрес текущей
// вершины, TS — адрес ячейки, содержащей адрес корня левого
// поддерева(левого сына)
void MoveToLSon(Tree *T, Tree *TS) {
    **TS = MemTree[**T].LSon;
}

// Удаляет дерево
void DelTree(Tree *T) {
    Size = 0;
}

// делает n-й элемент массива свободным и включает его в ССЭ
void DisposeMem(unsigned n) {
    MemTree[n].RSon = MemTree[0].RSon;
    MemTree[0].RSon = n;
}