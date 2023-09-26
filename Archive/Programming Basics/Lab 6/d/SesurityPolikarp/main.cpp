#include <iostream>
#include <vector>

using namespace std;

int main() {
  string s;
  getline(cin, s);

  int maxVisitors = 0;
  int minVisitors = 0;
  int curVisitors = 0;
  for (char &i: s) {
    if (i == '+') {
      curVisitors++;
    } else {
      curVisitors--;
    }

    minVisitors = min(minVisitors, curVisitors);
    maxVisitors = max(maxVisitors, curVisitors);
  }

  cout << maxVisitors - minVisitors;

  return 0;
}
