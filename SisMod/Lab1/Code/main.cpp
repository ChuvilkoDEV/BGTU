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

/////////////////////////////////////////

double equationOY(double x, double y) {
  double c1 = sqrt(pow(n1 + x, 2) + y * y);
  double c2 = sqrt(pow(n2 - y, 2) + x * x);
  double c3 = sqrt(pow(n3 + y, 2) + x * x);
  return m * g
         - k1 * (c1 - n1) * y / c1
         + k2 * (c2 - n2) * (n2 - y) / c2
         - k3 * (c3 - n3) * (n3 + y) / c3;
}

double equationOYDerivativeX(double x, double y) {
  return (equationOY(x + dif, y) - equationOY(x - dif, y)) / (2 * dif);
}


double equationOYDerivativeY(double x, double y) {
  return (equationOY(x, y + dif) - equationOY(x, y - dif)) / (2 * dif);
}

/////////////////////////////////////////

double equationOX(double x, double y, double F) {
  double c1 = sqrt(pow(n1 + x, 2) + y * y);
  double c2 = sqrt(pow(n2 - y, 2) + x * x);
  double c3 = sqrt(pow(n3 + y, 2) + x * x);
  return F
         - k1 * (c1 - n1) * (n1 + x) / c1
         - k2 * (c2 - n2) * x / c2
         - k3 * (c3 - n3) * x / c3;
}

double equationOXDerivativeX(double x, double y, double F) {
  return (equationOX(x + dif, y, F) - equationOX(x - dif, y, F)) / (2 * dif);
}


double equationOXDerivativeY(double x, double y, double F) {
  return (equationOX(x, y + dif, F) - equationOX(x, y - dif, F)) / (2 * dif);
}


int main() {
  cout << setw(3) << "F |" << setw(13) << "x |" << setw(14) << "y |\n";
  for (double F = 0; F < 100000; F += 1000) {
    // x, y
    vector<double> Values(2);
    for (int i = 0; i < 100; i++) {
      matrix w = {{equationOXDerivativeX(Values[0], Values[1], F),
                    equationOXDerivativeY(Values[0], Values[1], F)},
                  {equationOYDerivativeX(Values[0], Values[1]),
                    equationOYDerivativeY(Values[0], Values[1])}};
      Matrix W(w);
      W.inverse();

      vector<double> fVal = {equationOX(Values[0], Values[1], F),
                             equationOY(Values[0], Values[1])};
      vector<double> ffff = Matrix::Multiplication(W, fVal);
      Values[0] -= ffff[0];
      Values[1] -= ffff[1];
    }
    cout << setw(8) << F << " |" << setprecision(3) << setw(7)
         << Values[0] * 100 << " cm | " << setprecision(3)
         << setw(7) << Values[1] * 100 << " cm |\n";
  }

  return 0;
}
