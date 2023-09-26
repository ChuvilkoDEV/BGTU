#include <iostream>

//int main() {
//  std::cout << "0 0 0 15 6\n18 0 0 4 0\n0 0 19 0 3\n0 20 0 0 0\n";
//}



//#include "libs/matrix/matrix.h"
//#include "libs/transport/transport.h"
//
//int main() {
//  Matrix costMatrix;
//  costMatrix.inputMatrix(4, 5, {
//          {14, 27, 6,  16, 8},
//          {2,  4,  19, 4,  27},
//          {26, 23, 1,  20, 3},
//          {24, 5,  12, 30, 5}
//  });
//  vector<float> stock{21, 22, 22, 20};
//  vector<float> requests{18, 20, 19, 19, 9};
//  TransportTable transportTable(costMatrix, stock, requests);
//  transportTable.solveByDistributiveMethod();
//  for (int i = 0; i < transportTable.planTable.size(); i++) {
//    for (int j = 0; j < transportTable.planTable[0].size(); j++) {
//      std::cout << transportTable.planTable[i][j].value << " ";
//    }
//    std::cout << "\n";
//  }
//}


#include <iostream>
#include "libs/matrix/matrix.h"
#include "libs/transport/transport.h"
int main() {
  Matrix costMatrix;
  costMatrix.inputMatrix(4, 5, {
          {14, 27, 6, 16, 8},
          {2, 4, 19, 4, 27},
          {26, 23, 1, 20, 3},
          {24, 5, 12, 30, 5}
  });
  vector<float> stock{21, 22, 22, 20};
  vector<float> requests{18, 20, 19, 19, 9};
  TransportTable transportTable(costMatrix, stock, requests);
  transportTable.solveByPotentialMethod();
  for (int i = 0; i < transportTable.planTable.size(); i++) {
    for (int j = 0; j < transportTable.planTable[0].size(); j++) {
      std::cout << transportTable.planTable[i][j].value << " ";
    }
    std::cout << "\n";
  }
}
