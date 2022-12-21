/*
#include "Table.h"
#include <cstdio>
#include <cstdlib>

void initTable(Table *T) {
  initTree(T);
}

// возвращает "истина", если таблица пуста, иначе "ложь"
bool emptyTable(Table *T) {
  return T == NULL;
}

// запись данных
void _putTable(Table *T, BaseType E) {
  // проверка, есть ли элементы
  if (*T == NULL) {
    *T = createRoot(E);
    TableError = TreeError;
  } else { // если были элементы, нужно переназначить указатели
    if (strcmp_((*T)->data.key, E->data.key) > 0) {
      _putTable(&(*T)->leftSon, E);
    } else if (strcmp_((*T)->data.key, E->data.key) < 0) {
      _putTable(&(*T)->rightSon, E);
    } else { // если находится такой же элемент, передаётся соответствующее значение переменной ошибки
      TableError = TableNotSet;
    }
  }
}

// включает элемент таблицу, возвращает "истина", если элемент включён в таблицу, иначе "ложь"
bool putTable(Table *T, BaseType E) {
  if (emptyTable(*T)) { // если таблица пуста, сначала нужно создат корень дерева
    *T = createRoot(E);
    TableError = TreeError;
  } else { // иначе пользуемся функцией для записи в дерево
    _putTable(T, E); // внутри этой функции проверяется на универсальность
  }
  return TableError == TableOk;
}

// удаляет из дерева элемент с ключом Key
void _getTable(Tree *T, T_Key Key) {
  if (*T == NULL) {
    TreeError = TreeEnd;
  }
  if (strcmp_(Key, (*T)->data.key) < 0) { // если удаляемый элемент меньше текущего
    _getTable(&(*T)->leftSon, Key);
  } else if (strcmp_(Key, (*T)->data.key) > 0) { // если удаляемыq элемент больше текущего
    _getTable(&(*T)->rightSon, Key);
  } else if (strcmp_(Key, (*T)->data.key) == 0) { // если удаляемый элемент - текущий
    if ((*T)->leftSon == NULL) { // если левого ребёнка нет
      Tree tmp = *T;
      *T = (*T)->rightSon;
      free(tmp);
    } else if ((*T)->rightSon == NULL) { // если правого ребёнка нет
      Tree tmp = *T;
      *T = (*T)->leftSon;
      free(tmp);
    } else { // если есть оба ребёнка
      Tree tmp = (*T)->rightSon;
      Tree prev = (*T);
      while (tmp->leftSon) {
        prev = tmp;
        tmp = tmp->leftSon;
      }
      (*T)->data = tmp->data;
      if (prev != *T) {
        prev->leftSon = NULL;
      } else {
        prev->rightSon = tmp->rightSon;
      }
      TableError = TableOk;
      free(tmp);
    }
  } else { // если такого элемента нет вообще
    TableError = TableNotExistElement;
  }
}

// исключает элемент, возвращает "истина", если элемент с ключом s был в таблице, иначе "ложь"
bool getTable(Table *T, T_Key Key) {
  _getTable(T, Key);
  return TableError == TableOk;
}

// чтение данных элемента с ключом s
Tree _readDataTable(Tree T, T_Key Key) {
  if (T == NULL) {
    TableError = TableNotExistElement;
    return T;
  } else if (strcmp_(Key, (*T).data.key) == 0) {
    TableError = TableOk;
    return T;
  }
  if (strcmp_(Key, (*T).data.key) < 0) {
    // если элемент меньше текущего, уходим в левое поддерево
    return _readDataTable(T->leftSon, Key);
  } else if (strcmp_(Key, (*T).data.key) > 0) { // иначе уходим в правое поддерево
    return _readDataTable(T->rightSon, Key);
  } else { // вообще нет такого элемента
    TableError = TableNotExistElement;
    return NULL;
  }
}

// читает элемент. Возвращает "истина", если элемент с ключом s есть в таблице, иначе "ложь"
bool readTable(Table T, BaseType *E, T_Key Key) {
  *E = _readDataTable(T, Key);
  return TableError == TableOk;
}

// изменение элемента. Возвращает "истина", если элемент с ключом s есть в таблице, иначе "ложь"
bool writeTable(Table *T, BaseType E, T_Key Key) {
  BaseType tmp;
  if (readTable(T, &tmp, Key)) { // если элемент есть
    tmp = E; // перезаписываем в найденный элемент нужный
    TableError = TableOk;
  } else {
    TableError = TableNotExistElement;
  }
  return TableError == TableOk;
}

// уничтожение таблицы
void doneTable(Table *T) {
  delTree(*T);
}
 */