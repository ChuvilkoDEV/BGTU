#include <iostream>
#include <cassert>
#include "string"

using namespace std;

const int sizeA = 100;

template<typename T>
struct Stack {
  T data[sizeA];
  unsigned ptr; // Указывает на элемент, являющийся вершиной стека

  Stack() {
    ptr = 0;
  }

  [[nodiscard]] bool EmptyStack() const {
    return ptr == 0;
  }

  void Push(T x) {
    assert(ptr <= sizeA);
    data[ptr++] = x;
  }

  void Pop() {
    assert(!EmptyStack());
    ptr--;
  }

  T Get() {
    return data[ptr - 1];
  }
};

void shredder(string &a, string *shred, int &counter) {
  string tmp;
  for (auto i: a) {
    if ((i == ' ' || i == ',') && tmp.size() > 0) {
      shred[counter++] = tmp;
      tmp = "";
    } else
      tmp.push_back(i);
  }
  if (tmp.size() > 0)
    shred[counter++] = tmp;
}

void finder(Stack<string> &vvv, string *shred, int &counter, string *dict) {
  for (int i = 0; i < counter; i++)
    for (int j = 0; j < dict->size(); j++)
      if (dict[j] == shred[i]) {
        vvv.Push(shred[i]);
        shred[i] = "";
      }
}

void sort(string &a, Stack<string> &vvv) {
  string state[] = {"Panama"};
  string noun[] = {"plan", "man", "canal"};
  int counter = 0;
  string shred[100];
  shredder(a, shred, counter);
  finder(vvv, shred, counter, state);
  finder(vvv, shred, counter, noun);
  for (int i = 0; i < counter; i++)
    if (!shred[i].empty()) {
      vvv.Push(shred[i]);
      shred[i] = "";
    }
}

int main() {
  string a = "a man, a plan a canal Panama";
  Stack<string>  vvv;
  sort(a, vvv);
  while (!vvv.EmptyStack()) {
    cout << vvv.Get() << ' ';
    vvv.Pop();
  }
  return 0;
}
