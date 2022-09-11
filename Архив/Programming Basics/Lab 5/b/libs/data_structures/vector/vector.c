#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

// Возвращает структуру-дескриптор вектор из n значений.
vector createVector(size_t n) {
  vector v;
  v.data = (int *) malloc(n * sizeof(int));
  if (v.data == 0) {
    fprintf(stderr, "bad alloc ");
    exit(1);
  }
  v.size = 0;
  v.capacity = n;
  return v;
}

void outputVector(vector v) {
  printf("data = (");
  for (int i = 0; i < v.size; i++)
    printf("%d, ", v.data[i]);
  printf("\b\b)\n");
  printf("size = %zu\ncapacity = %zu\n", v.size, v.capacity);
}

// Изменяет количество памяти, выделенное под хранение элементов вектора.
void reserve(vector *v, size_t newCapacity) {
  if (newCapacity == 0) {
    v->data = NULL;
    v->size = 0;
  } else {
    if (newCapacity < v->size)
      v->size = newCapacity;
    v->data = (int *) realloc(v->data, newCapacity * sizeof(int));
    if (v->data == 0) {
      fprintf(stderr, "bad alloc ");
      exit(1);
    }
  }
  v->capacity = newCapacity;
}

// Удаляет элементы из контейнера, но не освобождает выделенную память.
void clear(vector *v) {
  v->size = 0;
}

// Освобождает память, выделенную под неиспользуемые элементы
void shrinkToFit(vector *v) {
  v->data = (int *) realloc(v->data, v->size * sizeof(int));
  v->capacity = v->size;
}

// Освобождает память, выделенную вектору
void deleteVector(vector *v) {
  free(v->data);
}

// Возвращает true, если вектор пустой. Иначе false.
bool isEmpty(vector *v) {
  return v->size == 0 ? true : false;
}

// Возвращает true, если вектор полный. Иначе false.
bool isFull(vector *v) {
  return v->size == v->capacity ? true : false;
}

// Возвращает i-ый элемент вектора v. Тело функции – одна строка кода.
int getVectorValue(vector *v, size_t i) {
  return v->data[i];
}

// Добавляет элемент x в конец вектора v. Если вектор заполнен,
// увеличивает количество выделенной ему памяти в 2 раза, используя reserve.
void pushBack(vector *v, int x) {
  if (isFull(v))
    reserve(v, v->capacity == 0 ? 1 : v->capacity * 2);
  v->data[v->size++] = x;
}

// Удаляет последний элемент из вектора. Функция ’выкидывает’ в поток
// ошибок сообщение, если вектор пуст и заканчивает выполнение с кодом 1.
void popBack(vector *v) {
  if (isEmpty(v)) {
    fprintf(stderr, "vector is empty");
    exit(1);
  }
  v->size--;
}

// Возвращает указатель на index-ый элемент вектора. Если осуществляется
// попытка получить доступ вне пределов используемых элементов вектора,
// в поток ошибок выводится ошибка: "IndexError: a[index] is not exists",
// где в качестве index указывается позиция элемента, к которому пытались
// осуществить доступ.
int* atVector(vector *v, size_t index) {
  if (index > v->size)
    fprintf(stderr, "a[%zu] is not exist", index);
  return &v->data[index];
}

// Возвращает указатель на последний элемент вектора
int* back(vector *v) {
  if (isEmpty(v))
    fprintf(stderr, "vector is empty");
  return &v->data[v->size - 1];
}

// Возвращает указатель на первый элемент вектора
int* front(vector *v) {
  if (isEmpty(v))
    fprintf(stderr, "vector is empty");
  return &v->data[0];
}