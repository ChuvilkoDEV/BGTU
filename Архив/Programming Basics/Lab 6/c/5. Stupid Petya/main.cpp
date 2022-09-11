#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      int m = i * j;
      int res = 0;
      for (int k = 0; m > 0; k++) {
        res += (m % n) * (int)pow(10, k);
        m /= n;
      }
      cout << res;
      if (j == n - 1)
        cout << '\n';
      else
        cout << ' ';
    }
  }

  return 0;
}
