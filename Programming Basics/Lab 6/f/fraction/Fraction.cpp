#include "Fraction.h"

using namespace std;

// Конструктор для Fraction
Fraction::Fraction(int n, int d) {
  numerator = n;
  denumerator = d;
  bringingToNormal();
}

// Конструктор для Fraction
Fraction::Fraction(Fraction &f) {
  numerator = f.numerator;
  denumerator = f.denumerator;
  bringingToNormal();
}

// Возвращает true, если дробь положительна
bool Fraction::isPositive() const {
  return (numerator >= 0) == (denumerator >= 0);
}

// Приводит Fraction к нормальному виду
void Fraction::bringingToNormal() {
  if (numerator == 0) {
    denumerator = 1;
    return;
  }
  simpleFraction();
  if (isPositive())
    numerator = abs(numerator);
  else
    numerator = -abs(numerator);
  denumerator = abs(denumerator);
}

// Осуществляет ввод структуры Fraction
void Fraction::inputFraction() {
  cin >> numerator >> denumerator;
}

// Выводит структуру Fraction
void Fraction::outputFraction() const {
  cout << numerator << '/' << denumerator;
}

// Возвращает упрощенную дробь f структуры Fraction
void Fraction::simpleFraction() {
  assert(denumerator != 0);
  int d = gcd(numerator, denumerator);
  numerator /= d;
  denumerator /= d;
}

// Возвращает дробь, которая является результатом произведения дроби f1 и f2
Fraction Fraction::operator*(Fraction &other) const {
  Fraction res(this->numerator * other.numerator,
               this->denumerator * other.denumerator);
  res.bringingToNormal();
  return res;
}

// Возвращает дробь, которая является результатом делением дроби f1 на f2
Fraction Fraction::operator/(Fraction &other) const {
  Fraction tmp1(other.denumerator, other.numerator);
  Fraction tmp2((Fraction &) *this);
  Fraction res;
  res = tmp2 * tmp1;
  return res;
}

// Возвращает дробь, которая является суммой f1 и f2
Fraction Fraction::operator+(Fraction &f) const {
  int d = lcm(this->denumerator, f.denumerator);
  Fraction res(this->numerator * (d / this->denumerator) +
               f.numerator * (d / f.denumerator),
               d);
  res.bringingToNormal();
  return res;
}

// Возвращает дробь, которая является разницей f1 и f2
Fraction Fraction::operator-(Fraction &f) {
  Fraction temp(-f.numerator, f.denumerator);
  Fraction res;
  res = temp + *this;
  return res;
}

void test_Fraction_constructor1() {
  Fraction f{};

  assert(f.numerator == 0);
  assert(f.denumerator == 1);
}

void test_Fraction_constructor2() {
  Fraction f1{1, 2};
  Fraction f2{f1};

  assert(f1.numerator == 1);
  assert(f1.denumerator == 2);
  assert(f1.numerator == f2.numerator);
  assert(f1.denumerator == f2.denumerator);
}

void test_Fraction_constructor3() {
  Fraction f1{2, 4};

  assert(f1.numerator == 1);
  assert(f1.denumerator == 2);
}

void test_Fraction_constructor4() {
  Fraction f1{0, 4};

  assert(f1.numerator == 0);
  assert(f1.denumerator == 1);
}

void test_Fraction_constructor5() {
  Fraction f1{-1, -2};

  assert(f1.numerator == 1);
  assert(f1.denumerator == 2);
}

void test_Fraction_constructor6() {
  Fraction f1{1, -2};

  assert(f1.numerator == -1);
  assert(f1.denumerator == 2);
}

void test_Fraction_constructor() {
  test_Fraction_constructor1();
  test_Fraction_constructor2();
  test_Fraction_constructor3();
  test_Fraction_constructor4();
  test_Fraction_constructor5();
  test_Fraction_constructor6();
}

void test_Fraction_mul() {
  Fraction f1(2, 5);
  Fraction f2(10, 8);

  Fraction res{};
  res = f1 * f2;

  assert(res.numerator == 1);
  assert(res.denumerator == 2);
}

void test_Fraction_div() {
  Fraction f1(5, 2);
  Fraction f2(10, 8);

  Fraction res{};
  res = f1 / f2;

  assert(res.numerator == 2);
  assert(res.denumerator == 1);
}

void test_Fraction_plus() {
  Fraction f1(5, 2);
  Fraction f2(10, 8);

  Fraction res{};
  res = f1 + f2;

  assert(res.numerator == 15);
  assert(res.denumerator == 4);
}

void test_Fraction_minus() {
  Fraction f1(5, 2);
  Fraction f2(10, 8);

  Fraction res{};
  res = f1 - f2;

  assert(res.numerator == 5);
  assert(res.denumerator == 4);
}

void tests_Fraction() {
  test_Fraction_constructor();
  test_Fraction_mul();
  test_Fraction_div();
  test_Fraction_plus();
  test_Fraction_minus();
}