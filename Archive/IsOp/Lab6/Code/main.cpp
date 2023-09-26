#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

using SimplexTable = vector<pair<string,
  vector<double>>>;

void outputSimplexTable(const SimplexTable &simplexTable) {
  cout << "BV\tFV\t";
  for (size_t i{1}; i < simplexTable.at(0).second.size(); ++i) {
    cout << "y" << i << '\t';
  }
  cout << '\n';
  for (size_t i{}; i < simplexTable.size(); ++i) {
    cout << simplexTable.at(i).first << '\t';
    for (size_t j{}; j < simplexTable.at(i).second.size();
         ++j) {
      cout << simplexTable.at(i).second.at(j) << '\t';
    }
    cout << '\n';
  }
  cout << '\n';
}

void outputMixedStrategyForPlayers(const SimplexTable
                                   &simplexTable, const double &gamePrice, const
                                   vector<string> &freeVarSecPlayer) {
  cout << ",\tq = (";
  for (size_t i{}; i < freeVarSecPlayer.size(); ++i) {
    bool findVar{false};
    for (size_t j{}; !findVar && j < simplexTable.size() - 1;
         ++j) {
      if (freeVarSecPlayer.at(i) ==
          simplexTable.at(j).first) {
        findVar = true;
        cout << simplexTable.at(j).second.at(0) *
                gamePrice << ';';
      }
    }
  }
  cout << "\b),\t";
  cout << "p = (";
  for (size_t i{freeVarSecPlayer.size() + 1}; i <
                                              simplexTable.at(
                                                0).second.size(); ++i) {
    cout << simplexTable.at(simplexTable.size() -
                            1).second.at(i) * gamePrice << ';';
  }
  cout << "\b)\n";
}

bool objFunctionHasNegative(const SimplexTable &simplexTable,
                            size_t &minNegativeIndex) {
  size_t rowIndex{simplexTable.size() - 1};
  size_t minIndex{};
  bool findNegative{false};
  for (size_t i{1}; i < simplexTable.at(0).second.size(); ++i) {
    if (simplexTable.at(rowIndex).second.at(i) < 0) {
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
  double minCoeff{static_cast<double>(LONG_LONG_MAX)};
  bool findPositive{false};
  for (size_t i{}; i < simplexTable.size() - 1; ++i) {
    if (simplexTable.at(i).second.at(0) /
        simplexTable.at(i).second.at(colIndex) > 0) {
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

double maxValueOfTheObjFunctionWithTableDisplay(SimplexTable
                                                &simplexTable) {
  size_t minIndex{};
  size_t minCoeffIndex{};
  while (objFunctionHasNegative(simplexTable, minIndex)) {
    cout << "Simplex table :\n";
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
          const double divide{-simplexTable.at(i).second.at(minIndex) /
                              simplexTable.at(minCoeffIndex).second.at(
                                minIndex)};
          for (size_t j{}; j <
                           simplexTable.at(i).second.size(); ++j) {
            simplexTable.at(i).second.at(j) +=
              (divide * simplexTable.at(minCoeffIndex).second.at(j));
          }
        }
      }
      simplexTable.at(minCoeffIndex).first = "y" + to_string(minIndex);
    } else {
      cout << "The problem does not have solution(The objective function"
              " is unbounded on the range of admissible values of solutions)";
      exit(1);
    }
  }
  cout << "Simplex table :\n";
  outputSimplexTable(simplexTable);
  return simplexTable.at(simplexTable.size() - 1).second.at(0);
}

int main(int argc, char **argv) {
  size_t numberOfFreeVar{};
  cout << "Number of free variables = ";
  cin >> numberOfFreeVar;
  cout
    << "Enter variables that are free (In ascending order of indices) : ";
  vector<string> freeVar(numberOfFreeVar);
  for (size_t i{}; i < numberOfFreeVar; ++i) {
    cin >> freeVar.at(i);
  }
  size_t numberOfRows{};
  size_t numberOfCols{};
  cout << "Number of rows in simplex table = ";
  cin >> numberOfRows;
  cout << "Number of cols in simplex table = ";
  cin >> numberOfCols;
  cout << "Enter simplex table(with the names of basic variables) : \n";
  SimplexTable simplexTable(numberOfRows);
  for (size_t i{}; i < numberOfRows; ++i) {
    string basisVarName{};
    cin >> basisVarName;
    simplexTable.at(i).first = basisVarName;
    for (size_t j{}; j < numberOfCols; ++j) {
      double value{};
      cin >> value;
      simplexTable.at(i).second.push_back(value);
    }
  }
  cout << setprecision(2);
  double gamePrice{1 /
                   maxValueOfTheObjFunctionWithTableDisplay(simplexTable)};
  cout << "u = v = " << gamePrice;
  outputMixedStrategyForPlayers(simplexTable, gamePrice, freeVar);
  return 0;
}
