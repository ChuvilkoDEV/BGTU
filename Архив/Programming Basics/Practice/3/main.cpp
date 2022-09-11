#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  cout << "Goose\tRabbit\n";

  n >>= 1;
  for (int i = 0; i <= n / 2; i++) {
    cout << n - i * 2 << "\t" << i << '\n';
  }

  return 0;
}