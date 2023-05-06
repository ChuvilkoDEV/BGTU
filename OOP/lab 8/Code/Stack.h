#ifndef CODE_STACK_H
#define CODE_STACK_H

#include <malloc.h>
#include <cassert>

const int size = 100;

template<typename T>
struct Stack {
  T* data[size];
  unsigned ptr; // Указывает на элемент, являющийся вершиной стека

  Stack();
  int EmptyStack(); // Проверка: стек пуст?
  void Push(T x); // Поместить элемент в стек
  void Pop(); // Извлечь элемент из стека
  T Get(); // Прочитать элемент из вершины стека
};



#endif //CODE_STACK_H
