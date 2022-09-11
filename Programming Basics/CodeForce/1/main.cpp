#include <iostream>
#include "queue"
#include "vector"
#include "algorithm"
#include "stack"

struct Row {
  int number;
  int width;
};

int main() {
  int countOfRows;
  std::cin >> countOfRows;

  auto compFunc = [](Row &r1, Row &r2) {
    return r1.width > r2.width;
  };
  std::priority_queue<Row, std::vector<Row>, decltype(compFunc)> rows(compFunc);

  for (int i = 0; i < countOfRows; ++i) {
    Row newRow;
    std::cin >> newRow.width;
    newRow.number = i;

    rows.push(newRow);
  }

  std::string passList;
  std::cin >> passList;

  std::stack<int> introvertsRows;
  for (auto i: passList) {
    if (i == '0') {
      std::cout << rows.top().number + 1 << ' ';
      introvertsRows.push(rows.top().number);
      rows.pop();
    }
    else{
      std::cout << introvertsRows.top() + 1 << ' ';
      introvertsRows.pop();
    }
  }

  return 0;
}