#include <iostream>
#include <vector>

using namespace std;

int main() {
  int h1, h2, daySpeed, nightSpeed;
  cin >> h1 >> h2 >> daySpeed >> nightSpeed;

  int heightFirstDay = h1 + daySpeed * (12 - 4);
  if (heightFirstDay >= h2) {
    cout << 0;
    return 0;
  }
  if (daySpeed <= nightSpeed)
    cout << -1;
  else
    cout << (h2 - heightFirstDay - 1) / (daySpeed * 12 - nightSpeed * 12) + 1;

  return 0;
}
