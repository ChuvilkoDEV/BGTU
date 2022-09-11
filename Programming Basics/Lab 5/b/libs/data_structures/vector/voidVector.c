#include "voidVector.h"
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// возвращает структуру-дескриптор вектор из n значений.
vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
  vectorVoid v;
  v.data = (void *) malloc(n * baseTypeSize);
  if (v.data == 0) {
    fprintf(stderr, "bad alloc ");
    exit(1);
  }
  v.size = 0;
  v.capacity = n;
  v.baseTypeSize = baseTypeSize;
  return v;
}

// изменяет количество памяти, выделенное под хранение элементов вектора.
void reserveV(vectorVoid *v, size_t newCapacity) {
  if (newCapacity == 0) {
    v->data = NULL;
    v->size = 0;
  } else {
    if (newCapacity < v->size)
      v->size = newCapacity;
    v->data = (void *) realloc(v->data, newCapacity * v->baseTypeSize);
  }
  v->capacity = newCapacity;
}

// Обнуляет размер вектора
void clearV(vectorVoid *v) {
  v->size = 0;
}

// освобождает память, выделенную под неиспользуемые элементы
void shrinkToFitV(vectorVoid *v) {
  v->data = (void *) realloc(v->data, v->size * v->baseTypeSize);
  v->capacity = v->size;
}

// Освобождает память, выделенную вектору
void deleteVectorV(vectorVoid *v) {
  free(v->data);
  v->size = 0;
  v->capacity = 0;
  v->baseTypeSize = 0;
}

// Возвращает true, если вектор пустой. False в ином случае.
bool isEmptyV(vectorVoid *v) {
  return v->size == 0 ? true : false;
}

// Возвращает true, если вектор полный. False в ином случае.
bool isFullV(vectorVoid *v) {
  return v->size == v->capacity ? true : false;
}

// записывает по адресу destination index-ый элемент вектора v.
void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
  if (index >= v->capacity)
    fprintf(stderr, "index > capacity :'( ");
  char *source = (char *) v->data + index * v->baseTypeSize;
  memcpy(destination, source, v->baseTypeSize);
}

// записывает на index-ый элемент вектора v значение, расположенное по
// адресу source
void setVectorValueV(vectorVoid *v, size_t index, void *source) {
  if (index >= v->capacity)
    fprintf(stderr, "index > capacity :'( ");
  char *destination = (char *) v->data + index * v->baseTypeSize;
  memcpy(destination, source, v->baseTypeSize);
}

void popBackV(vectorVoid *v) {
  if (isEmptyV(v)) {
    fprintf(stderr, "vector is empty");
    exit(1);
  }
  (v->size)--;
}

void pushBackV(vectorVoid *v, void *source) {
  if (isFullV(v))
    reserveV(v, v->capacity == 0 ? v->capacity + 1 : v->capacity * 2);
  setVectorValueV(v, v->size++, source);
}