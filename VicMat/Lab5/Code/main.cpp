#include <iostream>

struct Point {
  float x;
  float y;
};
float f1(Point p) {
  return sin(2 * p.x - 0.5) - p.y + 2.5;
}
float d1x(float x) {
  return 2 * cos(2 * x - 0.5);
}
float d1y(float y) {
  return -1;
}
float f2(Point p) {
  return pow(p.x, 2) + pow(p.y, 2) - 4;
}
float d2x(float x) {
  return 2 * x;
}
float d2y(float y) {
  return 2 * y;
}

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
