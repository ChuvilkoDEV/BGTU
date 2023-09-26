#include <iostream>
#include <cmath>
#include <cassert>

#define EPS 0.1

using namespace std;

class Point {
  public:
  double x;
  double y;

  // Возвращает дистанцию до точки
  [[nodiscard]] double getDistance(Point p) const {
    return sqrt(
      pow(y - p.y, 2) + pow(p.x - x, 2)
    );
  }
};

class Equation {
  public:
  double a;
  double b;
  double c;

  // Устанавливает выражение для прямой, проходящих через точки p1 и p2
  void setEquation(Point &p1, Point &p2) {
    a = p1.y - p2.y;
    b = p2.x - p1.x;
    c = p1.x * p2.y - p2.x * p1.y;
  }

  // Составляет уравнение прямой, которая является прямой для уравнения
  // n и проходящую через точку p
  void setNormalFromPoint(Equation n, Point p) {
    a = n.b;
    b = n.a;
    c = -(a * p.x + b * p.y);
  }
};

istream &operator>>(istream &in, Point &p) {
  in >> p.x >> p.y;
  return in;
}

// Хранит в себе уравнение прямой.
class Line {
  private:
  Point p1_; // Левая по х граница отрезка
  Point p2_; // Правая по х граница отрезка

  // Ax + By + C = 0
  Equation equation_;

  public:
  // Формирует уравнение прямой по двум точкам.
  void setLine(Point p1, Point p2) {
    if (p1.x < p2.x) {
      p1_ = p1;
      p2_ = p2;
    } else {
      p1_ = p2;
      p2_ = p1;
    }

    equation_.setEquation(p1, p2);
  }

  // Присваивает уравнение e
  void setEquation(Equation e) {
    equation_ = e;
  }

  // Возвращает уравнение прямой.
  Equation getEquation() {
    return equation_;
  }

  // Возвращает координаты первой точки.
  Point getPoint1() {
    return p1_;
  }

  // Возвращает координаты второй точки.
  Point getPoint2() {
    return p2_;
  }

  // Возвращает длину отрезка.
  [[nodiscard]] double len() const {
    return sqrt(
      pow(equation_.a, 2) + pow(equation_.b, 2)
    );
  }

  // Возвращает расстояние до точки.
  double getDistanceToPoint(Point &p) const {
    return abs(equation_.a * p.x + equation_.b * p.y + equation_.c) / len();
  }

  // Возвращает true, если прямая e пересекает отрезок. Иначе false.
  bool isCrossing(Equation &e) const {
    double xCrossing;
    if (e.b * equation_.a == equation_.b * e.a)
      xCrossing = p1_.x;
    else
      xCrossing =
        (equation_.b * e.c - e.b * equation_.c) /
        (e.b * equation_.a - equation_.b * e.a);

    double yCrossing;
    if (equation_.b == 0)
      yCrossing = p1_.y;
    else
      yCrossing =
        -(equation_.c + equation_.a * xCrossing) / equation_.b;

    return (xCrossing <= p2_.x == xCrossing >= p1_.x) &&
           (yCrossing <= p2_.y == yCrossing >= p1_.y);
  }

  double getMinLenToPoint(Point p) {
    Equation n{};
    n.setNormalFromPoint(equation_, p);
    if (isCrossing(n))
      return getDistanceToPoint(p);
    return min(p.getDistance(p1_), p.getDistance(p2_));
  }
};

// Возвращает минимальное значение, среди 4 переменных типа double
double min(double l1, double l2, double l3, double l4) {
  return min(l1, min(l2, min(l3, l4)));
}

// Возвращает минимальную длину, между отрезком, ограниченным точками p1 и p2 и отрезком, ограниченным точками p3, p4
double getMinLen(Line &l1, Line &l2) {
  return min(
    l1.getMinLenToPoint(l2.getPoint1()),
    l1.getMinLenToPoint(l2.getPoint2()),
    l2.getMinLenToPoint(l1.getPoint1()),
    l2.getMinLenToPoint(l1.getPoint2())
  );
}

void test_default() {
  Point p1{1, 1}, p2{2, 3}, p3{2, 2}, p4{4, 2};
  Line l1{}, l2{};
  l1.setLine(p1, p2);
  l2.setLine(p3, p4);

  assert(abs(getMinLen(l1, l2) - 0.4472) <= EPS);
}

void test_verticalLines() {
  Point p1{1, 1}, p2{1, 2}, p3{2, 1}, p4{2, 2};
  Line l1{}, l2{};
  l1.setLine(p1, p2);
  l2.setLine(p3, p4);

  assert(abs(getMinLen(l1, l2) - 1) <= EPS);
}

void test_horizontalLines() {
  Point p1{1, 1}, p2{2, 1}, p3{1, 2}, p4{2, 2};
  Line l1{}, l2{};
  l1.setLine(p1, p2);
  l2.setLine(p3, p4);

  assert(abs(getMinLen(l1, l2) - 1) <= EPS);
}

void test_crossingLines() {
  Point p1{0, 0}, p2{2, 2}, p3{-5, 5}, p4{0, 0};
  Line l1{}, l2{};
  l1.setLine(p1, p2);
  l2.setLine(p3, p4);

  assert(abs(getMinLen(l1, l2) - 0) <= EPS);
}

void tests() {
  test_default();
  test_verticalLines();
  test_horizontalLines();
  test_crossingLines();
}

#define DEBUG

int main() {
#ifdef DEBUG
  tests();
#endif
#ifndef DEBUG
  Point p1{}, p2{}, p3{}, p4{};
  cin >> p1 >> p2 >> p3 >> p4;

  Line l1{}, l2{};
  l1.setLine(p1, p2);
  l2.setLine(p3, p4);

  cout << getMinLen(l1, l2);
#endif

  return 0;
}