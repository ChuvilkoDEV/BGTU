#ifndef F_MATERIALPOINT_H
#define F_MATERIALPOINT_H

#include <iostream>
#include <cmath>
#include <cassert>

class MaterialPoint {
private:
  double _position = 0;       // Положение материальной точки
  double _speed = 0;         // Скорость материальной точки
  double _acceleration = 0;  // Ускорение материальной точки

public:
  // Конструктор материальной точки
  explicit MaterialPoint(double speed = 0, double acceleration = 0);

  // Сеттер скорости
  void setSpeed(double speed);

  // Сеттер ускорения
  void setAcceleration(double acceleration);

  // Геттер позиции
  double getPosition() const;

  // Геттер скорости
  double getSpeed() const;

  double getAcceleration() const;

  // Двигает материальную точку по числовой прямой на протяжении duration секунд
  void move(int duration);
};

void tests_MaterialPoint();

#endif //F_MATERIALPOINT_H
