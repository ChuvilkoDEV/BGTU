#ifndef INC_6E_LIST_H
#define INC_6E_LIST_H

#include <iostream>

class list {
  private:
  struct element {
    int value;
    element *next;
    element *prev;
  };

  int size = 0;
  element *head = nullptr;
  element *tail = nullptr;

  public:
  // Возвращает (true), если список пуст. Иначе (false)
  [[nodiscard]] bool empty() const {
    return size == 0;
  }

  // Проталкивает значение (value) в конец списка
  void push_back(int value) {
    if (empty()) {
      head = new (element) {value, nullptr, nullptr};
      tail = head;
      size++;
    } else {
      tail = new (element) {value, nullptr, (element *) tail};
    }
    size++;
  }

  // Проталкивает значение (value) в конец списка
  void push_front(int value) {
    if (empty()) {
      head = new (element) {value, nullptr, nullptr};
      tail = head;
      size++;
    } else {
      head = new (element) {value, (element *) head, nullptr};
    }
    size++;
  }

  // Проталкивает значение (value) на позицию (pos)
  void push(int value, size_t pos) {
    if (empty()) {
      head = new (element) {value, nullptr, nullptr};
      tail = head;
      size++;
      return;
    }

    if (pos == 0) {
      push_front(value);
    } else if (pos == size) {
      push_back(value);
    } else {
      std::pair<element *, element *> p = {nullptr, head};
      for (int i = 1; i < pos; i++)
        p = {p.second, p.second->next};

      auto *tmp = new (element){value, p.first, p.second};
      p.first->next = tmp;
      p.second->prev = tmp;
    }
    size++;
  }
};

#endif //INC_6E_LIST_H
