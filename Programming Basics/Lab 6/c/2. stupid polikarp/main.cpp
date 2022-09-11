#include <iostream>

using namespace  std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n1, n2;
    cin >> n1 >> n2;
    if (n1 == 0) {
      cout << 1 << '\n';
      continue;
    }
    cout << n1 + n2 * 2 + 1 << '\n';
  }

  return 0;
}
