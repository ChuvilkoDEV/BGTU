#include <iostream>
#include <vector>
#include <string>
#include <cassert>

#define DEBUG

using namespace std;

void outputVector(vector<int> &v) {
  for (auto &i: v)
    cout << i << ' ';
}

// Преобразовывает массив представленный в виде двоичных кодов, используя
// байтовое представление цепочек
void squeeze(string &s, vector<int> &byteSet) {
  bool isUnit = true;
  int counter = 0;
  for (auto &i: s) {
    if (isUnit == (i == '1')) {
      counter++;
    } else {
      isUnit = !isUnit;
      byteSet.push_back(counter);
      counter = 1;
    }
  }
  byteSet.push_back(counter);
}

void test_default() {
  string s = "111110010011100101010";
  vector<int> shakal{};
  vector<int> res = {5, 2, 1, 2, 3, 2, 1, 1, 1, 1, 1, 1};

  squeeze(s, shakal);

  assert(shakal == res);
}

void test_onlyUnit() {
  string s = "1111111111";
  vector<int> shakal{};
  vector<int> res = {10};

  squeeze(s, shakal);

  assert(shakal == res);
}

void test_onlyZero() {
  string s = "0000000000";
  vector<int> shakal{};
  vector<int> res = {0, 10};

  squeeze(s, shakal);

  assert(shakal == res);
}

void tests() {
  test_default();
  test_onlyUnit();
  test_onlyZero();
}

int main() {
#ifndef DEBUG
  tests();
#endif
#ifdef DEBUG
  string s;
  cin >> s;

  // первый нечетные элементы - 1; Остальные - 0
  vector<int> shakalSet;

  squeeze(s, shakalSet);

  outputVector(shakalSet);
#endif
  return 0;
}
