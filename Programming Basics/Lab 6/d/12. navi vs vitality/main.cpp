#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int k = 0; k < t; k++) {
    int total, red, blue;
    cin >> total >> red >> blue;

    int countRed = red / (2 * blue + 1) + 1;
    for (int i = 0; i < blue; i++) {
      cout << string(countRed, 'R') << 'B';
    }
    int redRemain = red - blue * (red / countRed);
    if (redRemain == 0)
      cout << "\b\n";
    else
      cout << string(redRemain, 'R') << '\n';
  }
  return 0;
}
