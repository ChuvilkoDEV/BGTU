#include <iostream>

int main() {
  int f = -5;
  int g = 1000;
  int h = 2;
  int res = f*g + f/(1000000*h) - (g*g*g)/(h*h);

  std::cout << res;


  return 0;
}
