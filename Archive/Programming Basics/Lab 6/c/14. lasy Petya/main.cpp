#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    vector<pair<int, int>> times(n);
    for (auto &j: times)
      cin >> j.first;
    for (auto &j: times)
      cin >> j.second;

    sort(begin(times), end(times), [](auto &x, auto &y) {
      return x.first > y.first;
    });

    int lazyTime = 0;
    for (auto &j : times) {
      if (lazyTime + j.second <= j.first) {
        lazyTime += j.second;
      } else {
        lazyTime = max(lazyTime, j.first);
        break;
      }
    }

    cout <<lazyTime << '\n';
  }

  return 0;
}
