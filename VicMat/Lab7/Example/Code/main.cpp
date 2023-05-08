#include <iostream>
#include "cmath"
#include "windows.h"

using namespace std;

struct Point {
  float x1;
  float x2;
  void output() {
    cout << x1 << ' ' << x2 << '\n';
  }
};

typedef float func(Point point);

typedef Point grad(Point point);

float targetFunction(Point point) {
  return pow(point.x1, 2) + pow(point.x2, 2) + point.x1 * point.x2 - point.x1 - 2 * point.x2 + 5;
}

Point gradient(Point point) {
  return {2 * point.x1 + point.x2 - 1, 2 * point.x2 + point.x1 - 2};
}

bool findMinPoint(func targetFunction, grad gradient, Point &point, float &minValue, float eps, int maxIterations,
                  float alpha, float betta, float gamma) {
  float precision = eps * 2;
  int iteration = 0;

  while (precision > eps && iteration < maxIterations) {
    Point currentGradient = gradient(point);
    float gradientModuleSquared = pow(currentGradient.x1, 2) + pow(currentGradient.x2, 2);
    Point newPoint;

    int i = 0;
    bool equationIsValid = false;
    while (!equationIsValid) {
      i++;
      newPoint = {(float) (point.x1 - alpha * pow(gamma, i) * currentGradient.x1),
                  (float) (point.x2 - alpha * pow(gamma, i) * currentGradient.x2)};

      equationIsValid = targetFunction(newPoint) - targetFunction(point) <
                        -betta * alpha * pow(gamma, i) * gradientModuleSquared;
    }

    precision = abs(targetFunction(newPoint) - targetFunction(point));
    point = newPoint;
    point.output();
    iteration++;
  }

  minValue = targetFunction(point);
  return precision < eps;
}


int main() {
  SetConsoleOutputCP(CP_UTF8);
  Point point = {1, 1};
  float minValue;
  bool isSuccessful = findMinPoint(targetFunction, gradient, point, minValue, 0.00001, 100, 1, 0.5, 0.5);

  if (isSuccessful) {
    cout << "Необходимая точность достигнута";
  } else {
    cout << "Необходимая точность не достигнута";
  }

  cout << "\n" << minValue << "\n" << point.x1 << " " << point.x2;
}
