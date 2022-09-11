#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int k = 0; k < t; k++) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &i: a)
      cin >> i;
    vector<int> b(n);
    for (auto &i: b)
      cin >> i;

    sort(a.begin(), a.end(), [](auto &x, auto &y) {
      return x < y;
    });
    sort(b.begin(), b.end(), [](auto &x, auto &y) {
      return x < y;
    });

    bool flag = false;
    for (int i = 0; i < n; i++) {
      if (b[i] > a[i] + 1 || b[i] < a[i]) {
        flag = true;
      }
    }

    if (flag)
      cout << "NO" << '\n';
    else
      cout << "YES" << '\n';
  }

  return 0;
}
