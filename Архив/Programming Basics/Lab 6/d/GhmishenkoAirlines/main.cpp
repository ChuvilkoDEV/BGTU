#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long n = 0;
  char c;
  cin >> n >> c;
  vector<int> serviceOrder{4, 5, 6, 3, 2, 1};

  long long res =
    ((n - 1) / 4) * (4 + 6 * 2) + (n % 2 == 0) * 7 + serviceOrder[c - 'a'];

  cout << res;

  return 0;
}
