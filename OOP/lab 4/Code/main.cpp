#include <iostream>

using namespace std;

class Rectangle {
  int a;
  int b;

  public:
  Rectangle(int a, int b) {
    this->a = a;
    this->b = b;
  }

  void outputSides() const {
    cout << "a: " << a << " b: " << b << endl;
  }

  void outputPerimeter() const {
    cout << "Perimeter: " << (a + b) * 2 << endl;
  }

  int area() const {
    return a*b;
  }

  void outputArea() const {
    cout << "Area: " << area() << endl;
  }

  friend bool operator<(Rectangle &a1, Rectangle &a2) {
    return a1.area() < a2.area();
  }

  friend Rectangle operator+(Rectangle &a1, Rectangle &a2) {
    Rectangle a3(a1.a + a2.a, a1.b + a2.b);
    return a3;
  }
};

int main() {
  Rectangle r1(3,4);
  r1.outputSides();
  Rectangle r2(4, 2);
  r2.outputSides();

  r1.outputPerimeter();
  r1.outputArea();
  r2.outputPerimeter();
  r2.outputArea();

  if (r1 < r2)
    cout << "r1 < r2\n";
  else
    cout << "r1 >= r2\n";

  Rectangle r3 = r1 + r2;
  r3.outputSides();

  return 0;
}
