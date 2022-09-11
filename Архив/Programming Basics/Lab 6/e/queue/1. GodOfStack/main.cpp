#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Snack {
  int size;
  int day;
};

int main() {
  int countOfDays;
  cin >> countOfDays;

  auto compFunc = [](Snack &s1, Snack &s2) {
    return s1.size < s2.size;
  };

  priority_queue<Snack, vector<Snack>, decltype(compFunc)> snacks(compFunc);
  for (int i = 0; i < countOfDays; ++i) {
    Snack iSnack = {0, i};
    cin >> iSnack.size;

    snacks.push(iSnack);
  }

  for (int i = 0; i < countOfDays; ++i) {
    if (snacks.top().day == i) {
      cout << snacks.top().size << ' ';
      snacks.pop();

      while (!snacks.empty() && snacks.top().day < i) {
        cout << snacks.top().size << ' ';
        snacks.pop();
      }
    }
    cout << '\n';
  }

  return 0;
}