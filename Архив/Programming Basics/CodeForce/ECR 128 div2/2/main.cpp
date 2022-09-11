#include <iostream>

using namespace std;

struct coordinates {
  int x;
  int y;
};

int main() {
  int t;
  cin >> t;

  for (int k = 0; k < t; k++) {
    int n, m;
    cin >> n >> m;

    coordinates top = {n, m};
    coordinates left = {n, m};
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;

      for (int j = 0; j < m; j++)
        if (s[j] == 'R') {
          if (i < top.x)
            top = {i, j};
          if (j < left.y)
            left = {i, j};
        }
    }

    if (top.x == left.x && top.y == left.y)
      cout << "YES\n";
    else
      cout << "NO\n";
  }


  return 0;
}
