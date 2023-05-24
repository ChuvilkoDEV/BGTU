#include <iostream>
#include "cmath"

double getXByHords(double x, double t, double (*F)(double)) {
  return x - (F(x) * (t - x) / (F(t) - F(x)));
}

double getXByTangentMethod(double x, double (*F)(double), double
(*dF)(double)) {
  return x - F(x) / dF(x);
}

double GetCombSolution(double x1, double x2, double (*F)(double), double
(*dF)(double), double eps) {
  double xK, xX;
  if (F(x1) * dF(x1) > 0) {
    xK = x1;
    xX = x2;
  } else {
    xK = x2;
    xX = x1;
  }
  double t = xK;
  xK = getXByTangentMethod(xK, F, dF);
  xX = getXByHords(xX, t, F);
  while (fabs(xK - xX) > eps) {
    xK = getXByTangentMethod(xK, F, dF);
    xX = getXByHords(xK, t, F);
  }
  return (xK + xX) / 2;
}

double F(double x) {
  return pow(x, 3) - 4 * pow(x, 2) - 11 * x - 6;
}

double dF(double x) {
  return 3 * pow(x, 2) - 8 * x - 11;
}

int main() {
  double x = GetCombSolution(-4, -2, F, dF, 0.0001);
  std::cout << x << ' ' << F(x) << std::endl;
  return 0;
}
