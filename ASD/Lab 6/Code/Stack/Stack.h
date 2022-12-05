#ifndef CODE_STACK_H
#define CODE_STACK_H

#include <malloc.h>

const int StackSize = 1000;
const int StackOk = 0; // Все ОК
const int StackOver = 1; // Стек переполнен
const int StackUnder = 2; // Стек пуст
int StackError; // Переменная ошибок
typedef int BaseType; // Определить тип элемента стека

typedef struct Stack
{
    int Buf[StackSize];
    unsigned ptr; // Указывает на элемент, являющийся вершиной стека
};

void InitStack(Stack *s); // Инициализация стека
int EmptyStack(Stack *s); // Проверка: стек пуст?
void PutStack(Stack *s, BaseType E); // Поместить элемент в стек
void GetStack(Stack *s, BaseType *E); // Извлечь элемент из стека
void ReadStack(Stack *s, BaseType *E); // Прочитать элемент из вершины стека


#endif //CODE_STACK_H
