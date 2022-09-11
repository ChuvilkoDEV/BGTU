#include <iostream>
#include <deque>

using namespace std;

bool isUnique(deque<int> &d, int x) {
  for (auto &j: d)
    if (j == x)
      return true;
  return false;
}

int main() {
  int nMessage, displaySize;
  cin >> nMessage >> displaySize;

  deque<int> idOnDisplay;
  for (int i = 0; i < nMessage; i++) {
    int id;
    cin >> id;

    bool isIdOnDisplay = isUnique(idOnDisplay, id);

    if (!isIdOnDisplay && idOnDisplay.size() < displaySize) {
      idOnDisplay.push_front(id);
      continue;
    }

    if (!isIdOnDisplay) {
      idOnDisplay.pop_back();
      idOnDisplay.push_front(id);
    }
  }

  cout << idOnDisplay.size() << '\n';
  for (auto &i: idOnDisplay)
    cout << i << ' ';

  return 0;
}
