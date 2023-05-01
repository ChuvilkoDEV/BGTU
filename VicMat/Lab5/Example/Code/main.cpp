#include <iostream>
#include "cmath"
#include "matrix/matrix.h"

using namespace std;

struct Point {
  float x;
  float y;
};

typedef float func(Point p);

typedef float derivative(float variable);

float f1(Point p) {
  return sin(p.x) + 2.5 * p.y - 3;
}

float d1x(float x) {
  return cos(x);
}

float d1y(float y) {
  return 2.5;
}

float f2(Point p) {
  return cos(p.x - 1) + p.y - 0.9;
}

float d2x(float x) {
  return -sin(x - 1);
}

float d2y(float y) {
  return 1;
}

//Point makeNewtonMethodStep(func f1, derivative d1x, derivative d1y,
//                           func f2, derivative d2x, derivative d2y,
//                           Point start) {
//  Matrix m(2, 3);
//  m.inputMatrix(2, 3, {
//    {d1x(start.x), d1y(start.y), -f1(start)},
//    {d2x(start.x), d2y(start.y), -f2(start)}
//  });
//
//  int _;
//  m = m.gaussForward(_);
//
//  bool hasSolution;
//  vector<float> solution = m.gaussBackward(hasSolution);
//
//  Point result{start.x + solution[0], start.y + solution[1]};
//  return result;
//}
//
//bool findSolutionByNewtonMethodWithEps(func f1, derivative d1x, derivative d1y,
//                                       func f2, derivative d2x, derivative d2y,
//                                       Point &start, int maxIterations,
//                                       float eps) {
//  float precision = abs(f1(start)) + abs(f2(start));
//
//  int currentStep = 0;
//  while (precision > eps && currentStep < maxIterations) {
//    start = makeNewtonMethodStep(f1, d1x, d1y,
//                                 f2, d2x, d2y,
//                                 start);
//
//    precision = abs(f1(start)) + abs(f2(start));
//    currentStep++;
//  }
//
//  return precision < eps;
//}


int main() {
  system("chcp 65001");
  Point start = {-2, 0.5};
  bool reachedGoodPrecision = findSolutionByNewtonMethodWithEps(f1, d1x, d1y,
                                                                f2, d2x, d2y,
                                                                start, 1000,
                                                                0.001);

  if (reachedGoodPrecision) {
    cout << "Необходимая точность достигнута\n";
  } else {
    cout << "Необходимая точность не достигнута\n";
  }
  cout << "{" << start.x << " " << start.y << "}";

  cout << "\nF(x, y)= " << f1(start) << "\n";
  cout << "Ф(x, y)=" << f2(start) << "\n";
}
