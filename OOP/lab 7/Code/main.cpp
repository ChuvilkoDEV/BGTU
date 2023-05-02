#include <iostream>
#include <cmath>

#define EPS 0.00001

struct ODZ : std::exception {
  long long value;

  explicit ODZ(double Value) {
    value = Value;
  }
};

struct trigonometry {
  static double sin(double x) {
    return std::sin(x);
  }

  static double cos(double x) {
    return std::cos(x);
  }

  static double tg(double x) {
    if (fabs(fmodf(x, M_PI) - M_PI / 2) <= EPS)
      throw ODZ(x);
    return std::tan(x);
  }

  static double ctg(double x) {
    if (fabs(fmod(x, M_PI)) <= EPS)
      throw ODZ(x);
    return 1 / std::tan(x);
  }

  static double arcsin(double x) {
    if (x <= -1 || x >= 1)
      throw ODZ(x);
    return std::asin(x);
  }

  static double arccos(double x) {
    if (x <= -1 || x >= 1)
      throw ODZ(x);
    return std::acos(x);
  }

  static double arctg(double x) {
    return std::atan(x);
  }

  static double arcctg(double x) {
    return M_PI / 2 - std::atan(x);
  }
};

int main() {
  double x = M_PI;
  std::cout << trigonometry::ctg(x);
  return 0;
}
