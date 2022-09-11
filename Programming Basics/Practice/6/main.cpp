#include <iostream>
#include <vector>
#include <cassert>

//#define DEBUG

using namespace std;

void inputVector(vector<int> &v) {
  for (auto &i: v)
    cin >> i;
}

void getMinAndMax(vector<int> &v, int &min, int &max) {
  min = v[0], max = v[0];
  for (auto &i: v) {
    if (min > i)
      min = i;
    if (max < i)
      max = i;
  }
}

int getMiddle(vector<int> &v) {
  int min, max;
  getMinAndMax(v, min, max);

  for (int i = 0; i < v.size() / 2; i++) {
    int ptrMin = max;
    for (auto &j: v)
      if (j > min && j <= max && j < ptrMin)
        ptrMin = j;
    min = ptrMin;
  }
  return min;
}

void test_default() {
  vector<int> v = {8, 1, 12, 76, 21, 34, 94};
  assert(getMiddle(v) == 21);
}

void test_increase() {
  vector<int> v = {1, 2, 3, 4, 5, 6, 7};
  assert(getMiddle(v) == 4);
}

void test_mixed() {
  vector<int> v = {6, 3, 4, 5, 1, 2, 7};
  assert(getMiddle(v) == 4);
}

void tests() {
  test_default();
  test_increase();
  test_mixed();
}

int main() {
#ifndef DEBUG
  tests();
#endif
#ifdef DEBUG
  int n;
  cin >> n;

  vector<int> v(2 * n + 1);

  inputVector(v);

  cout << getMiddle(v);
#endif
  return 0;
}
