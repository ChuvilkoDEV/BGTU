#include "Stack.h"

// Инициализация стека
void InitStack(Stack *s) {
    s->ptr = 0;
}

// Проверка: стек пуст?
int EmptyStack(Stack *s) {
    return s->ptr == 0;
}

void PutStack(Stack *s, int x) {
    if (s->ptr > StackSize) {
        StackError = StackOver;
        return;
    }

    s->Buf[++s->ptr] = x;
    StackError = StackOk;
}

// Извлечь элемент из стека
void GetStack(Stack *s, BaseType *E) {
    if (EmptyStack(s)) {
        StackError = StackUnder;
        return;
    }

    --s->ptr;
    StackError = StackOk;
}

// Прочитать элемент из вершины стека
void ReadStack(Stack *s, BaseType *E) {
    *E = s->Buf[--(s->ptr)];
    StackError = StackOk;
}