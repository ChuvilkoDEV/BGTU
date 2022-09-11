#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
  string s;
  cin >> s;

  queue<int> left;
  stack<int> right;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'l')
      right.push(i + 1);
    else
      left.push(i + 1);
  }

  while (left.size() > 0) {
    cout << left.front() << '\n';
    left.pop();
  }

  while (right.size() > 0) {
    cout << right.top() << '\n';
    right.pop();
  }

  return 0;
}