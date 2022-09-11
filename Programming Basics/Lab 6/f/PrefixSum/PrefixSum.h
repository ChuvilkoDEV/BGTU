#ifndef F_PREFIXSUM_H
#define F_PREFIXSUM_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

struct PrefixSum {
  private:
  vector<int> prefixSum_{};

  public:
  PrefixSum(const int *a, size_t n);

  PrefixSum(const vector<int> &a);

  vector<int> &getPrefixSum();

// возвращает сумму элементов от l до r не включая r.
// например, для массива 1, 3, 5
// запрос getSum(0, 2) должен возвращать 1 + 3 = 4;
  long long getSum(int l, int r);

// данный запрос должен каким-то образом,
// без хранения старого массива
// обновлять префиксный массив так, как будто мы
// заменили i-ый элемент старого массива на v
  void set(size_t i, int v);
};

void tests_PrefixSum();

#endif //F_PREFIXSUM_H
