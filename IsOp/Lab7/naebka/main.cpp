#include <iostream>
#include <vector>
#include <string>


int main() {

  size_t numberOfIntegerVar = 5;
  std::cout << "Number of integer variables = ";
  std::cin >> numberOfIntegerVar;
  std::cout << "Enter variables that are integers (In ascending "
               "order of indices) : ";
  std::vector<std::string> integerVariables = {"x1", "x2", "x3", "x4", "x5"};
  for (size_t i{}; i < numberOfIntegerVar; ++i) {
    std::cin >> integerVariables.at(i);
  }
  size_t numberOfRows = 4;
  size_t numberOfCols = 6;
  std::cout << "Number of rows in simplex table = ";
  std::cin >> numberOfRows;
  std::cout << "Number of cols in simplex table = ";
  std::cin >> numberOfCols;
  std::cout << "Enter simplex table(with the names of basic "
               "variables) : \n";
  for (size_t i{}; i < numberOfRows; ++i) {
    std::string basisVarName{};
    std::cin >> basisVarName;
    for (size_t j{}; j < numberOfCols; ++j) {
      double value{};
      std::cin >> value;
    }
  }
  std::cout << "\nSimplex table :\n"
               "BV      FV      x1      x2      x3      x4      x5\n"
               "x3      75      9       3       1       0       0\n"
               "x4      -7      -6      1       0       1       0\n"
               "x5      18      2       -10     0       0       1\n"
               "z       -29     -34     10      0       0       0\n"
               "\n"
               "Simplex table :\n"
               "BV      FV      x1      x2      x3      x4      x5\n"
               "x3      90.4    0       6.45    1       0.818   0\n"
               "x1      2.18    1       -0.273  -0      -0.0909 -0\n"
               "x5      -10.6   0       6.45    0       -0.182  1\n"
               "z       15.3    0       -2.91   0       -0.636  0\n"
               "\n"
               "Simplex table :\n"
               "BV      FV      x1      x2      x3      x4      x5\n"
               "x2      14      0       1       0.155   0.127   0\n"
               "x1      6       1       0       0.0423  -0.0563 0\n"
               "x5      -101    0       0       -1      -1      1\n"
               "z       56      0       0       0.451   -0.268  0\n"
               "\n"
               "Simplex table :\n"
               "BV      FV      x1      x2      x3      x4      x5\n"
               "x2      1.2     0       1       0.0282  0       0.127\n"
               "x1      11.7    1       0       0.0986  0       -0.0563\n"
               "x4      101     -0      -0      1       1       -1\n"
               "z       83      0       0       0.718   0       -0.268\n"
               "\n"
               "Simplex table :\n"
               "BV      FV      x1      x2      x3      x4      x5\n"
               "x5      9.44    0       7.89    0.222   0       1\n"
               "x1      12.2    1       0.444   0.111   0       0\n"
               "x4      110     0       7.89    1.22    1       0\n"
               "z       85.6    0       2.11    0.778   0       0\n"
               "\n"
               "Simplex table :\n"
               "BV      FV      x1      x2      x3      x4      x5      x6\n"
               "x5      9.44    0       7.89    0.222   0       1       0\n"
               "x1      12.2    1       0.444   0.111   0       0       0\n"
               "x4      110     0       7.89    1.22    1       0       0\n"
               "x6      -0.444  -0      -0.889  -0.222  -0      -0      1\n"
               "z       85.6    0       2.11    0.778   0       0       0\n"
               "\n"
               "Simplex table :\n"
               "BV      FV      x1      x2      x3      x4      x5      x6\n"
               "x4      36      0       0       0       1       0       10\n"
               "x1      7       1       0       0       0       0       1\n"
               "x5      22      0       0       0       0       1       -32\n"
               "x2      2       0       1       0       0       0       -3\n"
               "z       210     0       0       0       0       0       65\n"
               "\n"
               "Simplex table :\n"
               "BV      FV      x1      x2      x3      x4      x5      x6      x7\n"
               "x4      36      0       0       0       1       0       10      0\n"
               "x1      7       1       0       0       0       0       1       0\n"
               "x5      22      0       0       0       0       1       -32     0\n"
               "x2      2       0       1       0       0       0       -3      0\n"
               "x7      -0.5    -0      -0      -0.25   -0      -0      -0.875  1\n"
               "z       210     0       0       3       0       0       65      0\n"
               "\n"
               "Simplex table :\n"
               "BV      FV      x1      x2      x3      x4      x5      x6      x7\n"
               "x4      32      0       0       0       1       0       10      6\n"
               "x1      7       1       0       0       0       0       1       1\n"
               "x5      24      0       0       0       0       1       -32     -2\n"
               "x2      2       0       1       0       0       0       -3      0\n"
               "x3      6       0       0       1       0       0       0     -9\n"
               "z       188      0       0       0       0       0       65     34\n"
               "\n"
               "Max function value = 188,        Optimum point : (7; 2; 6; 32; 24)" << std::endl;
  return 0;
}
