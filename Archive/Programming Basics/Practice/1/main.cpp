#include <iostream>
#include <cmath>
#include <cassert>

#define EPS 0.01
#define DEBUG

// Сложность O(n)
double deltaPrice_kiss(int n, double p) {
  double s = 100;
  for (int i = 0; i < n; i++) {
    s += p * s / 100.0;
    s -= p * s / 100.0;
  }
  return 100 - s;
}

// Сложность O(1), если не учитывать возведение в степень
double deltaPrice_formula(int n, double p) {
  return 100 - pow(1 - pow(p, 2) / 10000, n) * 100;
}

void test_default() {
  assert(abs(deltaPrice_formula(1, 10) - 1) <= EPS);
}

void test_zeroPercent() {
  assert(abs(deltaPrice_formula(1, 0)) <= EPS);
}

void test_twoYear() {
  assert(abs(deltaPrice_formula(2, 10) - 1.99) <= EPS);
}

void test_oneHundredPercent() {
  assert(abs(deltaPrice_formula(2, 100) - 100) <= EPS);
}

void test_bigPercent() {
  assert(abs(deltaPrice_formula(3, 156) - 394.635) <= EPS);
}

void tests() {
  test_default();
  test_zeroPercent();
  test_twoYear();
  test_oneHundredPercent();
  test_bigPercent();
}

int main() {
#ifdef DEBUG
  tests();
#endif
#ifndef DEBUG
  int n;
  double p;
  std::cin >> n >> p;

  std::cout << "The price will decrease by " << deltaPrice_formula(n, p) << "%";
#endif

  return 0;
}