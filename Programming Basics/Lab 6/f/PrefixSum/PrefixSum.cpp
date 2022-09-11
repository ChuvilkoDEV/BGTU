#include "PrefixSum.h"

PrefixSum::PrefixSum(const int *a, size_t n) {
  int s = 0;
  prefixSum_.push_back(s);
  for (size_t i = 0; i < n; i++) {
    s += a[i];
    prefixSum_.push_back(s);
  }
}

PrefixSum::PrefixSum(const vector<int> &a) {
  int s = 0;
  prefixSum_.push_back(s);
  for (auto &i: a) {
    s += i;
    prefixSum_.push_back(s);
  }
}

vector<int> &PrefixSum::getPrefixSum() {
  return prefixSum_;
}

long long PrefixSum::getSum(int l, int r) {
  return prefixSum_[r] - prefixSum_[l];
}

void PrefixSum::set(size_t i, int v) {
  int iElementOld = prefixSum_[i + 1] - prefixSum_[i];
  int diff = v - iElementOld;
  for (size_t j = i + 1; j < prefixSum_.size(); j++)
    prefixSum_[j] += diff;
}

void test_constructor1() {
  int a[] = {1, 2, 5, 7};
  PrefixSum s(a, 4);

  vector<int> res{0, 1, 3, 8, 15};

  assert(res == s.getPrefixSum());
}

void test_constructor2() {
  vector<int> v{1, 2, 5, 7};
  PrefixSum s(v);

  vector<int> res{0, 1, 3, 8, 15};

  assert(res == s.getPrefixSum());
}

void test_constructor() {
  test_constructor1();
  test_constructor2();
}

void test_getSum() {
  vector<int> v{1, 3, 6, 9};
  PrefixSum s(v);

  assert(s.getSum(1, 4) == 18);
}

void test_set() {
  vector<int> v{1, 3, 6, 9};
  PrefixSum s(v);

  s.set(2, 4);

  vector<int> res{0, 1, 4, 8, 17};
  assert(s.getPrefixSum() == res);
}

void tests_PrefixSum() {
  test_constructor();
  test_getSum();
  test_set();
}