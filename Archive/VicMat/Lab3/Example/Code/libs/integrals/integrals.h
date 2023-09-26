#ifndef CODE_INTEGRALS_H
#define CODE_INTEGRALS_H

#include "vector"


typedef double Function(double x);

double calculateIntegralByCentralRectangle(Function function, double lowBorder,
                                           double highBorder, int nParts);

double calculateIntegralByTrapezoid(Function function, double lowBorder,
                                    double highBorder, int nParts);

double calculateIntegralByParable(Function function, double lowBorder,
                                  double highBorder, int nParts);

double
calculateIntegralByCentralRectangleWithEps(Function function, double lowBorder,
                                           double highBorder, int nParts,
                                           double &eps);

double calculateIntegralByTrapezoidWithEps(Function function, double lowBorder,
                                           double highBorder, int nParts,
                                           double &eps);

double calculateIntegralByParableWithEps(Function function, double lowBorder,
                                         double highBorder, int nParts,
                                         double &eps);

struct gaussCoefficient {
  double t;
  double A;
};


double calculateIntegralByGauss(Function function, double lowBorder,
                                double highBorder, int nParts);

#endif //CODE_INTEGRALS_H
