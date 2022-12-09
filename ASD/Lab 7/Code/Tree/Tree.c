#include "Tree.h"

// Инициализация БД
void InitTree(Tree *T, unsigned size) {
    T->Size = size;
    T->MemTree[0].RSon = 1;
}

// Добавляет лист дереву T
void AddLeaf(Tree *T, BaseType x, unsigned index) {
    if (index > T->Size) {
        TreeError = TreeNotMem;
        return;
    }

    T->MemTree[index].data = x;
    T->MemTree[index].RSon = 0;
    T->MemTree[index].LSon = 0;
    TreeError = TreeOk;
}

// Возвращает 1, если в массиве нет свободных элементов,
// 0 — в противном случае
int EmptyMem(Tree *T) {
    return T->MemTree[0].RSon >= T->Size;
}

// Возвращает номер свободного элемента и исключает его из ССЭ
unsigned int NewMem(Tree *T) {
    if (EmptyMem(T)) {
        TreeError = TreeNotMem;
        exit(TreeNotMem);
    }
    return (T->MemTree[0].RSon)++;
}

// Создает корень дереву T, со значением x
void CreateRoot(Tree *T, BaseType x) {
    AddLeaf(T, x, NewMem(T));
}

// Возвращает 1, если у элемента под номером index есть левый сын.
// 0 - в ином случае
int IsLSon(Tree *T, unsigned index) {
    return T->MemTree[index].LSon != 0;
}

// Возвращает 1, если у элемента под номером index есть правый сын.
// 0 - в ином случае
int IsRSon(Tree *T, unsigned index) {
    return T->MemTree[index].RSon != 0;
}

// Возвращает 1, если БД пустое. 0 - в ином случае
int IsEmptyTree(Tree *T) {
    return T->MemTree[0].RSon == 1;
}

// Записывает элемент x, в дерево Tree
void WriteDataTree(Tree *T, BaseType x) {
    if (IsEmptyTree(T)) {
        CreateRoot(T, x);
    } else if (T->MemTree[1].data < x) {
        if (IsLSon(T, 1)) {
            WriteDataTree_(T, x, T->MemTree[1].LSon);
        } else {
            T->MemTree[1].LSon = NewMem(T);
            AddLeaf(T, x, T->MemTree[1].LSon);
        }
    } else {
        if (IsRSon(T, 1)) {
            WriteDataTree_(T, x, T->MemTree[1].RSon);
        } else {
            T->MemTree[1].RSon = NewMem(T);
            AddLeaf(T, x, T->MemTree[1].RSon);
        }
    }
}

// Рекурсивно погружется для записи элемента x
void WriteDataTree_(Tree *T, BaseType x, unsigned index) {
    if (T->MemTree[index].data < x) {
        if (IsLSon(T, index)) {
            WriteDataTree_(T, x, T->MemTree[index].LSon);
        } else {
            T->MemTree[index].LSon = NewMem(T);
            AddLeaf(T, x, T->MemTree[index].LSon);
            return;
        }
    } else {
        if (IsRSon(T, index)) {
            WriteDataTree_(T, x, T->MemTree[index].RSon);
        } else {
            T->MemTree[index].RSon = NewMem(T);
            AddLeaf(T, x, T->MemTree[index].RSon);
            return;
        }
    }
}

// перейти к левому сыну, где T —адрес ячейки, содержащей адрес текущей
// вершины, TS — адрес ячейки, содержащей адрес корня левого
// поддерева(левого сына)
void MoveToLSon(Tree *T, Tree *TS) {
    InitMem(TS);
    unsigned sonIndex = T->MemTree[1].LSon;
    CreateRoot(TS, T->MemTree[sonIndex].data);

}





// Связывает все элементы массива в список свободных элементов
void InitMem(Tree *T) {
    T->MemTree[0].RSon = 1;
}

// Удаляет дерево
void DelTree(Tree *T) {
    T->Size = 0;
}