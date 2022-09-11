#include <iostream>
#include <vector>
#include <cassert>

//#define DEBUG

using namespace std;

void inputVector(vector<int> &v) {
  for (auto &i: v)
    cin >> i;
}

void outputVector(vector<int> &v) {
  for (auto &i: v)
    cout << i << ' ';
}

struct List {
  List *parent;
  int value;
  int index;
};

// Возвращает длиннейшую возрастающую последовательность
void increase(vector<int> &v) {
  // Первый элемент указывает на родителя. Второй на порядковый номер
  vector<List> din(v.size());

  din[0] = (List) {nullptr, v[0], 1};
  List maxLength = din[0];
  for (int i = 1; i < v.size(); i++) {
    if (v[i] > v[i - 1]) {
      din[i] = (List) {&din[i - 1], v[i], din[i - 1].index + 1};
    } else {
      List longestSequence = (List) {nullptr, v[i], 1};
      for (int j = 0; j < i; j++)
        if (v[i] > v[j] && din[j].index >= longestSequence.index)
          longestSequence = (List) {&din[j], v[i], din[j].index + 1};
      din[i] = longestSequence;
    }
    if (din[i].index > maxLength.index)
      maxLength = din[i];
  }

  List *ptr = &maxLength;
  for (int i = maxLength.index - 1; i >= 0; i--) {
    v[i] = ptr->value;
    ptr = ptr->parent;
  }
  while (v.size() > maxLength.index)
    v.pop_back();
}

void test_default() {
  vector<int> v = {1, 12, 13, 4, 5, 6};
  vector<int> res = {1, 4, 5, 6};

  increase(v);

  assert(v == res);
}

void test_allIncrease() {
  vector<int> v = {1, 2, 3, 4, 5, 6};
  vector<int> res = {1, 2, 3, 4, 5, 6};

  increase(v);

  assert(v == res);
}

void test_allDecrease() {
  vector<int> v = {6, 5, 4, 3, 2, 1};
  vector<int> res = {6};

  increase(v);

  assert(v == res);
}

void tests() {
  test_default();
  test_allIncrease();
  test_allDecrease();
}

int main() {
#ifndef DEBUG
  tests();
#endif

#ifdef DEBUG
  int n;
  cin >> n;

  vector<int> v(n);
  inputVector(v);

  increase(v);

  outputVector(v);
#endif

  return 0;
}