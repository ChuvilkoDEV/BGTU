//#include <iostream>
//#include "libs/matrix/matrix.h"
//#include "libs/simplexTable/simplexTable.h"
//int main() {
//  SimplexTable simplexTable;
//  simplexTable.inputTable(2, 6,
//                          {{1, 5, -3, -4, 2, 1, 14},
//                           {2, 9, -5, -7, 4, 2, 32}
//                          },
//                          {1, -3, 4, 5, -1, 8, 0});
//  float maxFValue;
//  vector<float> solution = simplexTable.findSolutionBySimplexBigPenalty(maxFValue);
//  if (solution.empty())
//    cout << "Решений нет";
//  else {
//    cout << "{";
//    for (auto i: solution) {
//      cout << i << "; ";
//    }
//    cout << "\b\b}\n";
//    cout << "Fmax = " << maxFValue;
//  }
//}
