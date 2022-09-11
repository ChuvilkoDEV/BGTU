#ifndef LAB_5B_VECTOR_H
#define LAB_5B_VECTOR_H

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct vector {
  int *data; // указатель на элементы вектора
  size_t size; // размер вектора
  size_t capacity; // вместимость вектора
} vector;

// Возвращает структуру-дескриптор вектор из n значений.
vector createVector(size_t n);

// Выводит на экран вектор и информацию о нем
void outputVector(vector v);

// Изменяет количество памяти, выделенное под хранение элементов вектора.
void reserve(vector *v, size_t newCapacity);

// Удаляет элементы из контейнера, но не освобождает выделенную память.
void clear(vector *v);

// Освобождает память, выделенную под неиспользуемые элементы
void shrinkToFit(vector *v);

// Освобождает память, выделенную вектору
void deleteVector(vector *v);

// Возвращает true, если вектор пустой. Иначе false.
bool isEmpty(vector *v);

// Возвращает true, если вектор полный. Иначе false.
bool isFull(vector *v);

// Возвращает i-ый элемент вектора v. Тело функции – одна строка кода.
int getVectorValue(vector *v, size_t i);

// Добавляет элемент x в конец вектора v. Если вектор заполнен,
// увеличивает количество выделенной ему памяти в 2 раза, используя reserve.
void pushBack(vector *v, int x);

// Удаляет последний элемент из вектора. Функция ’выкидывает’ в поток
// ошибок сообщение, если вектор пуст и заканчивает выполнение с кодом 1.
void popBack(vector *v);

// Возвращает указатель на index-ый элемент вектора. Если осуществляется
// попытка получить доступ вне пределов используемых элементов вектора,
// в поток ошибок выводится ошибка: "IndexError: a[index] is not exists",
// где в качестве index указывается позиция элемента, к которому пытались
// осуществить доступ.
int* atVector(vector *v, size_t index);

// Возвращает указатель на последний элемент вектора
int* back(vector *v);

// Возвращает указатель на первый элемент вектора
int* front(vector *v);

#endif //LAB_5B_VECTOR_H
