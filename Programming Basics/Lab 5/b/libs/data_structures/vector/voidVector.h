#ifndef LAB_5B_VOIDVECTOR_H
#define LAB_5B_VOIDVECTOR_H

#include <stdbool.h>
# include <limits.h>

typedef struct vectorVoid {
  void *data; // указатель на нулевой элемент вектора

  size_t size; // размер вектора
  size_t capacity; // вместимость вектора
  size_t baseTypeSize; // размер базового типа:
  // например, если вектор хранит int -
  // то поле baseTypeSize = sizeof(int)
  // если вектор хранит float -
  // то поле baseTypeSize = sizeof(float)
} vectorVoid;


// возвращает структуру-дескриптор вектор из n значений.
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

// изменяет количество памяти, выделенное под хранение элементов вектора.
void reserveV(vectorVoid *v, size_t newCapacity);

// Обнуляет размер вектора
void clearV(vectorVoid *v);

// освобождает память, выделенную под неиспользуемые элементы
void shrinkToFitV(vectorVoid *v);

// Освобождает память, выделенную вектору
void deleteVectorV(vectorVoid *v);

// Возвращает true, если вектор пустой. False в ином случае.
bool isEmptyV(vectorVoid *v);

// Возвращает true, если вектор полный. False в ином случае.
bool isFullV(vectorVoid *v);

// записывает по адресу destination index-ый элемент вектора v.
void getVectorValueV(vectorVoid *v, size_t index, void *destination);

// записывает на index-ый элемент вектора v значение, расположенное по
// адресу source
void setVectorValueV(vectorVoid *v, size_t index, void *source);

// Удаляет последний элемент из вектора. Функция ’выкидывает’ в поток
// ошибок сообщение, если вектор пуст и заканчивает выполнение с кодом 1.
void popBackV(vectorVoid *v);

// Добавляет элемент x в конец вектора v. Если вектор заполнен,
// увеличивает количество выделенной ему памяти в 2 раза, используя reserve.
void pushBackV(vectorVoid *v, void *source);

#endif //LAB_5B_VOIDVECTOR_H
