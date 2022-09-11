#ifndef F_FRACTION_H
#define F_FRACTION_H

#include <cassert>
#include <iostream>

#include "../algorithms/algorithms.h"

struct Fraction {
  int numerator = 0;
  int denumerator = 1;

  // Конструктор для Fraction
  Fraction() = default;

  // Конструктор для Fraction
  Fraction(Fraction &f);

  // Конструктор для Fraction
  Fraction(int n, int d);

  // Возвращает true, если дробь положительна
  bool isPositive() const;

  // Приводит Fraction к нормальному виду
  void bringingToNormal();

  // Осуществляет ввод структуры Fraction
  void inputFraction();

  // Выводит структуру Fraction
  void outputFraction() const;

  // Возвращает упрощенную дробь f структуры Fraction
  void simpleFraction();

  // Возвращает дробь, которая является результатом произведения дроби f1 и f2
  Fraction operator*(Fraction &other) const;

  // Возвращает дробь, которая является результатом делением дроби f1 на f2
  Fraction operator/(Fraction &other) const;

  // Возвращает дробь, которая является разницей f1 и f2
  Fraction operator-(Fraction &f);

  // Возвращает дробь, которая является суммой f1 и f2
  Fraction operator+(Fraction &f) const;
};

void tests_Fraction();

#endif //F_FRACTION_H
