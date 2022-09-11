#include <iostream>
#include <vector>
#include <cassert>

#define DEBUG

using namespace std;

void inputVector(const vector<int> &v) {
  for (auto &i: v)
    cin >> (int &) i;
}

void outputVector(const vector<int> &v) {
  for (auto &i: v)
    cout << i << ' ';
}

void reverseNumbers(vector<int> &v) {
  for (auto &i: v) {
    int res = 0;
    while (i > 0) {
      res *= 10;
      res += i % 10;
      i /= 10;
    }
    i = res;
  }
}

bool isEqual(vector<int> &v1, vector<int> &v2) {
  if (v1.size() != v2.size())
    return false;
  for (int i = 0; i < v1.size(); i++)
    if (v1[i] != v2[i])
      return false;
  return true;
}

void test() {
  vector<int> v = {123, 3, 12345678, 0};
  vector<int> res = {321, 3, 87654321, 0};

  reverseNumbers(v);

  assert(isEqual(v, res));
}

int main() {
#ifndef DEBUG
  test();
#endif
#ifdef DEBUG
  int n;
  cin >> n;

  vector<int> v(n);
  inputVector(v);

  reverseNumbers(v);

  outputVector(v);
#endif

  return 0;
}