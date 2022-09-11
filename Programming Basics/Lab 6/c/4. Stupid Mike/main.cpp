#include <iostream>
#include <vector>

using namespace std;

struct square {
  pair<int, int> downLeft;
  pair<int, int> topRight;
};

int main() {
  int n, a;
  cin >> n >> a;

  int tmp = a;
  square s = {{5, 5},
              {0, 0}};
  for (int i = 1; i < n; i++) {
    int lastDigit = a % 10 - 1;
    pair<int, int> pos;
    if (lastDigit == -1)
      pos = {1, 3};
    else
      pos = {lastDigit % 3, lastDigit / 3};

    if (pos.first < s.downLeft.first || pos.second < s.downLeft.second)
      s.downLeft.first = min(pos, pos.first);
    if (pos.first > s.topRight.first || pos.second > s.topRight.second)
      s.topRight = pos;
    a /= 10
  }

  return 0;
}
