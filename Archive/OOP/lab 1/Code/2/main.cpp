#include <iostream>
#include <fstream>
#include <vector>

void getArrays(std::vector<int> &positive, std::vector<int> &negative) {
  std::string line;
  std::ifstream in("..\\world.txt"); // окрываем файл для чтения
  if (in.is_open()) {
    getline(in, line);
    int sum = 0;
    bool isNegative = false;
    for (char const &c: line) {
      if (c == ' ') {
        if (isNegative) {
          negative.push_back(-sum);
          isNegative = false;
        } else
          positive.push_back(sum);
        sum = 0;
      } else if (c == '-') {
        isNegative = true;
      } else {
        sum = sum * 10 + c - '0';
      }
    }
  }
  in.close();     // закрываем файл
}

void setArray(std::vector<int> &positive, std::vector<int> &negative) {
  std::ofstream out;          // поток для записи
  out.open("..\\world.txt"); // окрываем файл для записи
  if (out.is_open())
  {
    std::string s;
    for (auto i : positive)
      s += std::to_string(i) + ' ';
    for (auto i : negative)
      s += std::to_string(i) + ' ';
    std::cout << s;
    out << s << std::endl;
  }
}

int main() {
  std::vector<int> positive;
  std::vector<int> negative;

  getArrays(positive, negative);

  setArray(positive, negative);

  return 0;
}
