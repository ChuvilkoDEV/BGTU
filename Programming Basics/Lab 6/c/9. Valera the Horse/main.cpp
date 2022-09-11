#include <iostream>

using namespace std;

int main() {
  int x, y;
  cin >> x >> y;

  if (y > -x + 1 && y <= x) {
    cout << (x - 1) * 4 + 1;
  } else if (y >= -x && y > x) {
    cout << (y - 1) * 4 + 2;
  } else if (y < -x && y >= x) {
    cout << (-x - 1) * 4 + 3;
  } else {
    cout << (-y - 1) * 4 + 4;
  }

  return 0;
}
