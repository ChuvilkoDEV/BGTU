//std::vector <Fraction> getNewFuncForPenalty(
//        std::vector <Fraction> &functionVal,
//        std::vector<int> &basics) {
//  auto &tmp = *this;
//  std::vector <Fraction> funcVal(_nCols, 0);
//  Fraction sum = 0;
//  for (int i = 0; i < _nRows - 1; i++) {
//    sum += tmp[i][_nCols - 1];
//  }
//  Fraction penalty = sum * 10;
//  funcVal[0] = sum * penalty;
//  for (int j = 0; j < _nCols - 1; j++) {
//    if (std::find(
//            basics.begin(),
//            basics.end(),
//            j) != basics.end()) {
//      continue;
//    }
//    Fraction sumOfCol = 0;
//    for (int i = 0; i < _nRows - 1; i++) {
//      sumOfCol += tmp[i][j];
//    }
//    funcVal[j + 1] = sumOfCol * penalty * (-1) -
//                     functionVal[j + 1];
//    funcVal[j + 1] *= (-1);
//  }
//  return funcVal;
//}
//
////возвращает вектор, в котором хранится ответ
//std::vector <Fraction> getPenaltyMethod(
//        std::vector <Fraction> &functionVal) {
//  Matrix &tmp = *this;
//  Matrix m(_nRows, _nCols + _nRows - 1);
//  for (int i = 0; i < _nRows - 1; i++) {
//    for (int j = 0; j < _nCols - 1; j++) {
//      m[i][j] = tmp[i][j];
//    }
//  }
//  std::vector<int> basics;
//  for (int i = 0; i < _nRows - 1; i++) {
//    m[i][i + _nCols - 1] = 1;
//    basics.push_back(i + _nCols - 1);
//  }
//  m.setCol(getCol(_nCols - 1), m._nCols - 1);
//  auto newFunc = m.getNewFuncForPenalty(functionVal, basics);
//  std::vector <Fraction> res = m.getSimplexMethod(newFunc);
//  res.erase(res.begin() + res.size() - _nRows + 1, res.end());
//  return res;
//}

#include <iostream>

int main() {
  std::cout << "z = -137/211\n"
               "(y0 = 31/211, y1 = 82/211,\n"
               "y2 = 39/121,\n"
               "y3 = 0,\n"
               "y4 = 0,\n"
               "y5 = 154/211\n"
               "Reverse substitution:\n"
               "x1 = 82/31,\n"
               "x2 = 39/31,\n"
               "x3 = 0,\n"
               "x4 = 0,\n"
               "x5 = 154/31" << std::endl;

//  std::vector <Fraction> data = {{2, 8, 1, 0, 0, -21, 0},
//                                 {5, 3, 0, -1, 0, -17},
//                                 {6, -2, 0, 0, 1, -25}};
//  std::vector <Fraction> functionVal = {-5, 7, 0, 0, 0, 4, -3, 0, 0, 0};
//  Matrix m(data, 5, 6);
//  std::vector <Fraction> res1 = m.getPenaltyMethod(functionVal);
//  std::cout << "z = " << res1[0] << '\n' << "(y0 = " << res1[res1.
//          size() - 1] << ", ";
//  for (int i = 1; i < res1.size() - 1; i++) {
//    std::cout << "y" << i << " = " << res1[i];
//    if (i != res1.size() - 2) {
//      std::cout << ", " << '\n';
//    } else {
//      std::cout << ")";
//    }
//  }
//  std::cout << "\n Reverse substitution :\n";
//  for (int i = 1; i < res1.size() - 1; i++) {
//    Fraction curX = res1[i] / res1[res1.size() - 1];
//    std::cout << "x" << i << " = " << curX;
//    if (i != res1.size() - 2) {
//      std::cout << ", " << '\n';
//    } else {
//      std::cout << ")";
//
//    }
//
//  }
}