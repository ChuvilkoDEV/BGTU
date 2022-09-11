#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int size;
    cin >> size;

    vector<int> v(size);
    for (auto &x: v)
      cin >> x;

    int max = v[0];
    bool isPossible = false;
    for (int j = 1; j < v.size() && !isPossible; j++) {
      if (v[j] < max) {
        cout << "YES" << "\n";
        isPossible = true;
      }
      if (v[j] > max)
        max = v[j];
    }
    if (!isPossible)
      cout << "NO" << "\n";
  }
}