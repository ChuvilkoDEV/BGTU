#include <iostream>

using namespace std;
int main() {
  int n;
  cin >> n;

  int s = 0;
  int minUneven = 100;
  for (int i = 0; i < n; i++) {
    int petals;
    cin >> petals;

    if (petals % 2 == 1)
      minUneven = min(petals, minUneven);

    s += petals;
  }

  if (s % 2 == 0 && minUneven != 100)
    s -= minUneven;
  if (s % 2 == 0) {
    cout << 0;
    return 0;
  }
  cout << s;

  return 0;
}
