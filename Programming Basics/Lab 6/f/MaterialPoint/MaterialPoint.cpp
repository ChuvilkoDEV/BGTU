#include "MaterialPoint.h"

// Конструктор материальной точки
MaterialPoint::MaterialPoint(double speed, double acceleration) {
  _speed = speed;
  _acceleration = acceleration;
}

// Сеттер скорости
void MaterialPoint::setSpeed(double speed) {
  _speed = speed;
}

// Сеттер ускорения
void MaterialPoint::setAcceleration(double acceleration) {
  _acceleration = acceleration;
}

// Геттер позиции
double MaterialPoint::getPosition() const {
  return _position;
}

// Геттер скорости
double MaterialPoint::getSpeed() const {
  return _speed;
}

double MaterialPoint::getAcceleration() const {
  return _acceleration;
}

// Двигает материальную точку по числовой прямой на протяжении duration секунд
void MaterialPoint::move(int duration) {
  _position += duration * _speed + _acceleration * pow(duration, 2) / 2;
  _speed += duration * _acceleration;
}

void tests_MaterialPoint_constructor1() {
  MaterialPoint m;

  assert(m.getPosition() == 0);
  assert(m.getSpeed() == 0);
  assert(m.getAcceleration() == 0);
}

void tests_MaterialPoint_constructor2() {
  MaterialPoint m(1);

  assert(m.getPosition() == 0);
  assert(m.getSpeed() == 1);
  assert(m.getAcceleration() == 0);
}

void tests_MaterialPoint_constructor3() {
  MaterialPoint m(1, 2);

  assert(m.getPosition() == 0);
  assert(m.getSpeed() == 1);
  assert(m.getAcceleration() == 2);
}

void tests_MaterialPoint_constructor() {
  tests_MaterialPoint_constructor1();
  tests_MaterialPoint_constructor2();
  tests_MaterialPoint_constructor3();
}

void tests_MaterialPoint() {
  tests_MaterialPoint_constructor();
}