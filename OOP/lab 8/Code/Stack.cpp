#include "Stack.h"
template<typename T>
Stack<T>::Stack() {
  ptr = 0;
}

template<typename T>
int Stack<T>::EmptyStack() {
  return ptr == 0;
}

template<typename T>
void Stack<T>::Push(T x) {
  assert(ptr <= size);
  data[ptr++] = x;
}

template<typename T>
void Stack<T>::Pop() {
  assert(!EmptyStack());
  ptr--;
}

template<typename T>
T Stack<T>::Get() {
  return data[ptr];
}
