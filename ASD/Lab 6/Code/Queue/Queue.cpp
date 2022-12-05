#include "Queue.h"

#include <malloc.h>

void InitFifo(Fifo *f, unsigned SizeMem) {
    InitList(f, SizeMem);
}

void PutFifo(Fifo *f, BaseType E) {
    EndList(f);
    PutList(f, E);
    f->ptr++;
    FifoError = ListError;
}

void GetFifo(Fifo *f, BaseType *E) {
    EndList(f);
    GetList(f, E);
    f->ptr--;
    FifoError = ListError;
}

void ReadFifo(Fifo *f, BaseType *E) {
    *E = f->PMemList[f->ptr];
    FifoError = FifoOk;
}

int EmptyFifo(Fifo *f) {
    return f->N == 0;
}

void DoneFifo(Fifo *f) {
    DoneList(f);
}