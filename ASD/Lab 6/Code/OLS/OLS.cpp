#include "OLS.h"

void InitList(List *L) {
    InitMem();
    L->N = 0;
    L->Start = new ListElement;
    L->Start->next = nullptr;
    L->ptr = L->Start;

}

void InitMem() {
    for (int i = 0; i < SizeList; ++i) {
        MemList[i].data = 0;
        MemList[i].next = nullptr;
        MemList[i].isUsing = false;
    }
}

void PutList(List *L, BaseType E) {
    if (!EmptyMem())
        printf("NO MEM");
    if (!IsListFull(L) && EmptyMem()) {
        int i = NewMem();
        MemList[i].data = E;
        MemList[i].isUsing = true;
        MemList[i].next = L->ptr->next;
        L->ptr->next = &MemList[i];

        L->N++;
        ListError = ListOk;
    } else
        ListError = ListNotMem;
}

void GetList(List *L, BaseType *E) {
    if (L->Start->next != NULL) {
        *E = L->ptr->next->data;
        L->ptr->next->isUsing = false;

        L->ptr->next = L->ptr->next->next;

        L->N--;
        ListError = ListOk;
    } else
        ListError = ListUnder;
}

void ReadList(List *L, BaseType *E) {
    *E = L->ptr->next->data;
}

bool IsListFull(List *L) {
    return L->N >= SizeList;
}

bool EndList(List *L) {
    return L->ptr->next->next == nullptr;
}

bool BeginList(List *L) {
    return L->ptr == L->Start;
}

unsigned int Count(List *L) {
    return L->N;
}

void BeginPtr(List *L) {
    L->ptr = L->Start;
}

void EndPtr(List *L) {
    while (!EndList(L))
        L->ptr = L->ptr->next;
}

void MovePtr(List *L) {
    if (!EndList(L))
        L->ptr = L->ptr->next;
    else
        ListError = ListEnd;
}

void MoveTo(List *L, unsigned int n) {
    if (n < L->N) {
        BeginPtr(L);
        for (int i = 0; i < n; ++i)
            L->ptr = L->ptr->next;
    } else
        ListError = ListEnd;
}

void DoneList(List *L) {
    L->ptr = L->Start;
    while (!EndList(L)) {
        L->ptr->isUsing = false;
        MovePtr(L);
    }
    L->ptr = NULL;
    L->Start = NULL;
    L->N = 0;
}

void CopyList(List *L1, List *L2) {
    ptrel addPtr = L1->ptr;
    EndPtr(L1);
    DoneList(L2);
    int N = L1->N;
    for (int i = 0; i < N; ++i) {
        PutList(L2, L1->ptr->data);
    }
    L1->ptr = addPtr;
    BeginPtr(L2);
}

int EmptyMemList() {
    int i = 0;
    while (i < SizeList) {
        if (!MemList[i].isUsing)
            return true;
        i++;
    }
    return false;
}

unsigned NewMem() {
    int i = 0;
    while (MemList[i].isUsing) {
        i++;
    }
    return i;
}

void DisposeMem(unsigned n) {
    MemList[n].isUsing = false;
}