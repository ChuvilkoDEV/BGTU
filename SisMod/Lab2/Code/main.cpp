#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include "Matrix.h"

using namespace std;

#define k1 20000
#define k2 10000
#define k3 40000
#define n1 1
#define n2 0.5
#define n3 0.7
#define m 10
#define g 10
#define dif 0.001

////////////////////////////////
double equationOY(double x, double y) {
  double c1 = sqrt(pow(n1 + x, 2) + y * y);
  double c2 = sqrt(pow(n2 - y, 2) + x * x);
  double c3 = sqrt(pow(n3 + y, 2) + x * x);
  return (m * g
         - k1 * (c1 - n1) * y / c1
         + k2 * (c2 - n2) * (n2 - y) / c2
         - k3 * (c3 - n3) * (n3 + y) / c3)
         / m;
}


/////////////////////////////////////////

double equationOX(double x, double y, double F) {
  double c1 = sqrt(pow(n1 + x, 2) + y * y);
  double c2 = sqrt(pow(n2 - y, 2) + x * x);
  double c3 = sqrt(pow(n3 + y, 2) + x * x);
  return (F
         - k1 * (c1 - n1) * (n1 + x) / c1
         - k2 * (c2 - n2) * x / c2
         - k3 * (c3 - n3) * x / c3)
         / m;
}

void rungeKuttStep(vector<double> &rungeKuttTable, double step) {

}

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
