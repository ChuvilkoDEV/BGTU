#include <iostream>
#include "libs/integrals/integrals.h"
#include "cmath"
#include "windows.h"

double f1(double x) {
  return 6 * pow(x, 2) - 2 * x + 3;
}

double f2(double x) {
  return sin(x) * cos(x);
}

double f3(double x) {
  return 1 + log(2 * x);
}
//
//int main() {
//    SetConsoleOutputCP(CP_UTF8);
//
//    std::cout << "Вычисление по формуле центральных прямоугольников\n" <<
//              "Интеграл 1, n = 8: " << calculateIntegralByCentralRectangle(f1, -2, 1, 8) <<
//              "\nИнтеграл 2, n = 8: " << calculateIntegralByCentralRectangle(f2, 0, M_PI / 3, 8) <<
//              "\nИнтеграл 3, n = 8: " << calculateIntegralByCentralRectangle(f3, 1, 2, 8) <<
//              "\n\nВычисление по формуле трапеций\n" <<
//              "Интеграл 1, n = 8: " << calculateIntegralByTrapezoid(f1, -2, 1, 8) <<
//              "\nИнтеграл 2, n = 8: " << calculateIntegralByTrapezoid(f2, 0, M_PI / 3, 8) <<
//              "\nИнтеграл 3, n = 8: " << calculateIntegralByTrapezoid(f3, 1, 2, 8) <<
//              "\n\nВычисление по формуле парабол\n" <<
//              "Интеграл 1, n = 8: " << calculateIntegralByParable(f1, -2, 1, 8) <<
//              "\nИнтеграл 2, n = 8: " << calculateIntegralByParable(f2, 0, M_PI / 3, 8) <<
//              "\nИнтеграл 3, n = 8: " << calculateIntegralByParable(f3, 1, 2, 8);
//}
//
//int main() {
//  SetConsoleOutputCP(CP_UTF8);
//
//  double preciseSolution = 0;
//  double centralRectanglesSolution = calculateIntegralByCentralRectangle(f2, 0,
//                                                                         M_PI /
//                                                                         3, 10);
//  double trapezoidSolution = calculateIntegralByTrapezoid(f2, 0, M_PI / 3, 10);
//  double parableSolution = calculateIntegralByParable(f2, 0, M_PI / 3, 10);
//  double gaussSolution = calculateIntegralByGauss(f2, 0, M_PI / 3, 4);
//
//  std::cout << "Интеграл 2, точное решение: " << preciseSolution <<
//            "\nИнтеграл, решение методом центральных прямоугольников: "
//            << centralRectanglesSolution <<
//            " ; Абсолютная погрешность: "
//            << abs((centralRectanglesSolution - preciseSolution)) <<
//            "\nИнтеграл, решение методом трапеций: " << trapezoidSolution <<
//            " ; Абсолютная погрешность: "
//            << abs((trapezoidSolution - preciseSolution)) <<
//            "\nИнтеграл, решение методом парабол: " << parableSolution <<
//            " ; Абсолютная погрешность: "
//            << abs((parableSolution - preciseSolution)) <<
//            "\nИнтеграл, решение методом Гаусса: " << gaussSolution <<
//            " ; Абсолютная погрешность: "
//            << abs((gaussSolution - preciseSolution));
//}

int main() {
  SetConsoleOutputCP(CP_UTF8);
  std::cout << "Вычисление интеграла по формуле Гаусса\n";
  for (int i = 1; i <= 4; i++) {
    std::cout << "Интеграл 1, n = " << i << ": " <<
              calculateIntegralByGauss(f1, -2, 1, i) << "\n";
  }
  std::cout << "Интеграл 2, n = 4: " <<
            calculateIntegralByGauss(f2, 0, M_PI / 3, 4) << "\n";
  std::cout << "Интеграл 3, n = 4: " <<
            calculateIntegralByGauss(f3, 1, 2, 4) << "\n";
}
