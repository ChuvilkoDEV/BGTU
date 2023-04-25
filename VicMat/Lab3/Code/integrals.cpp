#include "integrals.h"
#include "utility"
#include "vector"
#include "stdlib.h"

typedef std::pair<double, double> GridElement;
typedef std::vector<GridElement> Grid;
double calculateIntegralByCentralRectangle(Function function, double lowBorder,
                                           double highBorder, int nParts) {
  Grid grid(nParts);
  double step = (highBorder - lowBorder) / nParts;
  double sum = 0;
  for (int i = 0; i < nParts; i++) {
    grid[i].first = lowBorder + (i + 0.5) * step;
    grid[i].second = function(grid[i].first);
    sum += grid[i].second;
  }
  return sum * step;
}
double calculateIntegralByTrapezoid(Function function, double lowBorder,
                                    double highBorder, int nParts) {
  Grid grid(nParts + 1);
  grid[0] = {lowBorder, function(lowBorder)};
  grid[grid.size() - 1] = {highBorder, function(highBorder)};
  double step = (highBorder - lowBorder) / nParts;
  double sum = (grid[0].second + grid[grid.size() - 1].second) / 2;
  for (int i = 1; i < nParts; i++) {
    grid[i].first = lowBorder + i * step;
    grid[i].second = function(grid[i].first);
    sum += grid[i].second;
  }
  return step * sum;
}
double calculateIntegralByParable(Function function, double lowBorder,
                                  double highBorder, int nParts) {
  Grid grid(nParts + 1);
  grid[0] = {lowBorder, function(lowBorder)};
  grid[grid.size() - 1] = {highBorder, function(highBorder)};
  double step = (highBorder - lowBorder) / nParts;
  double sum = grid[0].second + grid[grid.size() - 1].second;
  for (int i = 1; i < grid.size() - 1; i += 2) {
    grid[i].first = lowBorder + i * step;
    grid[i].second = function(grid[i].first);
    sum += 4 * grid[i].second;
  }
  for (int i = 2; i < grid.size() - 1; i += 2) {
    grid[i].first = lowBorder + i * step;
    grid[i].second = function(grid[i].first);
    sum += 2 * grid[i].second;
  }
  return step / 3 * sum;
}
double calculateIntegralByCentralRectangleWithEps(Function function, double lowBorder,
                                                  double highBorder, int nParts,
                                                  double &eps) {
  double integralValueNParts = calculateIntegralByCentralRectangle(function,
                                                                   lowBorder, highBorder, nParts);
  double difference = abs(integralValueNParts -
                          calculateIntegralByCentralRectangle(function, lowBorder,

                                                              highBorder, nParts / 2));
  eps = (double) 1 / 3 *difference;
  return integralValueNParts;
}
double calculateIntegralByTrapezoidWithEps(Function function, double lowBorder,
                                           double highBorder, int nParts, double &eps)
{
  double integralValueNParts = calculateIntegralByTrapezoid(function, lowBorder,
                                                            highBorder, nParts);
  double difference = abs(integralValueNParts -
                          calculateIntegralByTrapezoid(function, lowBorder,

                                                       highBorder, nParts / 2));
  eps = (double) 1 / 3 * difference;
  return integralValueNParts;
}
double calculateIntegralByParableWithEps(Function function, double lowBorder,
                                         double highBorder, int nParts, double &eps) {
  double integralValueNParts = calculateIntegralByParable(function, lowBorder,
                                                          highBorder, nParts);
  double difference = abs(integralValueNParts - calculateIntegralByParable(function,
                                                                           lowBorder,

                                                                           highBorder, nParts / 2));
  eps = (double) 1 / 15 * difference;
  return integralValueNParts;
}
