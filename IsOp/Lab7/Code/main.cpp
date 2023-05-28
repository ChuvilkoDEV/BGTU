#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <numeric>

#define DBL_EPSILON_IN_MY_CASE 7.7e-10
using SimplexTable = std::vector<std::pair<std::string,
        std::vector<double>>>;

void outputSimplexTable(const SimplexTable &simplexTable) {
  std::cout << "BV\tFV\t";
  for (size_t i{1}; i < simplexTable.at(0).second.size(); ++i) {
    std::cout << "x" << i << '\t';
  }
  std::cout << '\n';
  for (size_t i{}; i < simplexTable.size(); ++i) {
    std::cout << simplexTable.at(i).first << '\t';
    for (size_t j{}; j < simplexTable.at(i).second.size();
         ++j) {
      std::cout << simplexTable.at(i).second.at(j) << '\t';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

void derivationOfTheOptimumPoint(const SimplexTable
                                 &simplexTable, const std::vector<std::string> integralVar) {
  std::cout << "Optimum point : (";
  for (size_t i{}; i < integralVar.size(); ++i) {
    bool findVar{false};
    for (size_t j{}; j < simplexTable.size() - 1; ++j) {
      if (simplexTable.at(j).first == integralVar.at(i)) {
        findVar = true;
        if (simplexTable.at(j).second.at(0) <=
            DBL_EPSILON_IN_MY_CASE) {
          std::cout << 0 << ';';
        } else {
          std::cout << simplexTable.at(j).second.at(0)
                    << ';';
        }
      }
    }
    if (!findVar) {
      std::cout << 0 << ';';
    }
  }
  std::cout << "\b)\n";
}

bool objFunctionHasNegative(const SimplexTable &simplexTable,
                            size_t &minNegativeIndex) {
  size_t rowIndex{simplexTable.size() - 1};
  size_t minIndex{};
  bool findNegative{false};
  for (size_t i{1}; i < simplexTable.at(0).second.size(); ++i) {
    if (simplexTable.at(rowIndex).second.at(i) < (-
            DBL_EPSILON_IN_MY_CASE)) {
      findNegative = true;
      if (simplexTable.at(rowIndex).second.at(i) <
          simplexTable.at(rowIndex).second.at(minIndex)) {
        minIndex = i;
      }
    }
  }
  minNegativeIndex = minIndex;
  return findNegative;
}

bool exHasPositiveCoeff(const SimplexTable &simplexTable, const
size_t &colIndex, size_t &minCoeffIndex) {
  size_t minCoeffIn{};
  double minCoeff{std::numeric_limits<double>::max()};
  bool findPositive{false};
  for (size_t i{}; i < simplexTable.size() - 1; ++i) {
    if (simplexTable.at(i).second.at(0) /
        simplexTable.at(i).second.at(colIndex) > DBL_EPSILON_IN_MY_CASE) {
      findPositive = true;
      const double coeff{simplexTable.at(i).second.at(0) /
                         simplexTable.at(i).second.at(colIndex)};
      if (coeff < minCoeff) {
        minCoeff = coeff;
        minCoeffIn = i;
      }
    }
  }
  minCoeffIndex = minCoeffIn;
  return findPositive;
}

void maxValueOfTheObjFunctionWithTableDisplay(SimplexTable
                                              &simplexTable) {
  size_t minIndex{};
  size_t minCoeffIndex{};
  while (objFunctionHasNegative(simplexTable, minIndex)) {
    std::cout << "Simplex table :\n";
    outputSimplexTable(simplexTable);
    if (exHasPositiveCoeff(simplexTable, minIndex,
                           minCoeffIndex)) {
      const double
              divider{simplexTable.at(minCoeffIndex).second.at(minIndex)};
      for (size_t i{}; i <
                       simplexTable.at(minCoeffIndex).second.size(); ++i) {
        simplexTable.at(minCoeffIndex).second.at(i) /=
                divider;
      }
      for (size_t i{}; i < simplexTable.size(); ++i) {
        if (i != minCoeffIndex) {
          const double divide{-
                                      simplexTable.at(i).second.at(minIndex) /
                              simplexTable.at(minCoeffIndex).second.at(minIndex)};
          for (size_t j{}; j <
                           simplexTable.at(i).second.size(); ++j) {
            simplexTable.at(i).second.at(j) +=
                    (divide * simplexTable.at(minCoeffIndex).second.at(j));
          }
        }
      }
      simplexTable.at(minCoeffIndex).first = "x" +
                                             std::to_string(minIndex);
    } else {
      std::cout << "The problem does not have solution(The objective "
                   "function is unbounded on the range of admissible "
                   "values of solutions)";
      std::exit(1);
    }
  }
  std::cout << "Simplex table :\n";
  outputSimplexTable(simplexTable);
}

bool hasNegativeFree(const SimplexTable &simplexTable, size_t
&minFreeIndex) {
  size_t minFreeIn{};
  double minFree{std::numeric_limits<double>::max()};
  bool findNegative{false};
  for (size_t i{}; i < simplexTable.size() - 1; ++i) {
    if (simplexTable.at(i).second.at(0) < (-
            DBL_EPSILON_IN_MY_CASE)) {
      findNegative = true;
      if (simplexTable.at(i).second.at(0) < minFree) {
        minFree = simplexTable.at(i).second.at(0);
        minFreeIn = i;
      }
    }
  }
  minFreeIndex = minFreeIn;
  return findNegative;
}

bool hasNegativeCoeff(const SimplexTable &simplexTable, const
size_t &rowIndex, size_t &minColIndex) {
  bool hasNegative{false};
  double minimum{std::numeric_limits<double>::max()};
  size_t minIndex{0};
  for (size_t i{1}; i <
                    simplexTable.at(rowIndex).second.size(); ++i) {
    if (simplexTable.at(rowIndex).second.at(i) < (-
            DBL_EPSILON_IN_MY_CASE)) {
      hasNegative = true;
      const double coeff{-
                                 simplexTable.at(simplexTable.size() - 1).second.at(i) /
                         simplexTable.at(rowIndex).second.at(i)};
      if (coeff < minimum) {
        minimum = coeff;
        minIndex = i;
      }
    }
  }
  minColIndex = minIndex;
  return hasNegative;
}

double generalizedSimplexMethod(SimplexTable &simplexTable) {
  maxValueOfTheObjFunctionWithTableDisplay(simplexTable);
  size_t minFreeIndex{};
  while (hasNegativeFree(simplexTable, minFreeIndex)) {
    size_t minColIndex{};
    if (hasNegativeCoeff(simplexTable, minFreeIndex,
                         minColIndex)) {
      const double
              divide{simplexTable.at(minFreeIndex).second.at(minColIndex)};
      for (size_t i{}; i <
                       simplexTable.at(minFreeIndex).second.size(); ++i) {
        simplexTable.at(minFreeIndex).second.at(i) /=
                divide;
      }
      for (size_t i{}; i < simplexTable.size(); ++i) {
        if (i != minFreeIndex) {
          const double divider{-
                                       simplexTable.at(i).second.at(minColIndex) /
                               simplexTable.at(minFreeIndex).second.at(minColIndex)};
          for (size_t j{}; j <
                           simplexTable.at(i).second.size(); ++j) {
            simplexTable.at(i).second.at(j) +=
                    (divider * simplexTable.at(minFreeIndex).second.at(j));
          }
        }
      }
      simplexTable.at(minFreeIndex).first = "x" +
                                            std::to_string(minColIndex);
    } else {
      std::cout << "The problem has no solution due to the absence "
                   "of admissible solutions to the system of constraints\n";
      std::exit(1);
    }
    std::cout << "Simplex table :\n";
    outputSimplexTable(simplexTable);
  }
  return simplexTable.at(simplexTable.size() - 1).second.at(0);
}

double fractionPart(const double &value) {
  if (std::fabs(value) <= DBL_EPSILON_IN_MY_CASE) {
    return 0;
  }
  return value - std::floor(value);
}

bool isInteger(const double &value) {
  return (fractionPart(value) <= DBL_EPSILON_IN_MY_CASE);
}

bool resultIsInteger(const SimplexTable &simplexTable, const
std::vector<std::string> &integerVar) {
  for (size_t i{}; i < integerVar.size(); ++i) {
    for (size_t j{}; j < simplexTable.size() - 1; ++j) {
      if (simplexTable.at(j).first == integerVar.at(i) &&
          !isInteger(simplexTable.at(j).second.at(0))) {
        return false;
      }
    }
  }
  return true;
}

size_t rowIndexOfMaxFraction(const SimplexTable &simplexTable) {
  size_t maxIndex{};
  double maxValue{std::numeric_limits<double>::min()};
  for (size_t i{}; i < simplexTable.size() - 1; ++i) {
    double
            fracPart{fractionPart(simplexTable.at(i).second.at(0))};
    if (fracPart - maxValue > DBL_EPSILON_IN_MY_CASE) {
      maxValue = fracPart;
      maxIndex = i;
    }
  }
  return maxIndex;
}

double GomorysFirstAlgorithm(SimplexTable &simplexTable, const
std::vector<std::string> &integerVar) {
  double result{};
  while (true) {
    result = generalizedSimplexMethod(simplexTable);
    if (resultIsInteger(simplexTable, integerVar)) {
      return result;
    }
//* build Section of Gomory
    size_t maxRow{rowIndexOfMaxFraction(simplexTable)};
    simplexTable.push_back(std::make_pair(std::string("x" +
                                                      std::to_string(simplexTable.at(0).second.size())),
                                          std::vector<double>{}));
    for (size_t i{}; i <
                     simplexTable.at(maxRow).second.size(); ++i) {
      simplexTable.at(simplexTable.size() -
                      1).second.push_back(-
                                                  fractionPart(simplexTable.at(maxRow).second.at(i)));
    }
    for (size_t i{}; i < simplexTable.size(); ++i) {
      if (i != simplexTable.size() - 1) {
        simplexTable.at(i).second.push_back(0);
      } else {
        simplexTable.at(i).second.push_back(1);
      }
    }
    std::swap(simplexTable.at(simplexTable.size() - 1),
              simplexTable.at(simplexTable.size() - 2));
  }
}

int main(int argc, char **argv) {
  size_t numberOfIntegerVar{};
  std::cout << "Number of integer variables = ";
  std::cin >> numberOfIntegerVar;
  std::cout << "Enter variables that are integers (In ascending "
               "order of indices) : ";
  std::vector<std::string>
          integerVariables(numberOfIntegerVar);
  for (size_t i{}; i < numberOfIntegerVar; ++i) {
    std::cin >> integerVariables.at(i);
  }
  size_t numberOfRows{};
  size_t numberOfCols{};
  std::cout << "Number of rows in simplex table = ";
  std::cin >> numberOfRows;
  std::cout << "Number of cols in simplex table = ";
  std::cin >> numberOfCols;
  std::cout << "Enter simplex table(with the names of basic "
               "variables) : \n";
  SimplexTable simplexTable(numberOfRows);
  for (size_t i{}; i < numberOfRows; ++i) {
    std::string basisVarName{};
    std::cin >> basisVarName;
    simplexTable.at(i).first = basisVarName;
    for (size_t j{}; j < numberOfCols; ++j) {
      double value{};
      std::cin >> value;
      simplexTable.at(i).second.push_back(value);
    }
  }
  std::cout << std::setprecision(3);
  double maxFunctValue{GomorysFirstAlgorithm(simplexTable,
                                             integerVariables)};
  std::cout << "Max function value = " << maxFunctValue <<
            ",\t";
  derivationOfTheOptimumPoint(simplexTable, integerVariables);
/*
std::boolalpha(std::cout);
std::cout << resultIsInteger(simplexTable, integerVariables);
*/
  return 0;
}
