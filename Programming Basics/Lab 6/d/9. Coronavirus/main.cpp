#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int nClients, countChairs;
    cin >> nClients >> countChairs;

    vector<int> distance(nClients);
    for (auto &j: distance)
      cin >> j;

    sort(distance.begin(), distance.end(), [](auto &x, auto &y) {
      return x > y;
    });

    long long s = distance[0] - *(distance.end() - 1);
    for (auto &j: distance) {
      s += j + 1;
    }

    if (s <= countChairs)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}
