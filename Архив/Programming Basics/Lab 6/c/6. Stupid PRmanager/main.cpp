#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  vector<int> a(t);
  for (auto &i: a) {
    cin >> i;
  }

  vector<int> res(t);
  int ptr = 0;
  for (int i = 0; i < t; i++)
    if (a[i] == ptr + 1)
      res[ptr++] = 2000 + i + 1;

  cout << ptr << '\n';
  for (int i = 0; i < ptr; i++)
    cout << res[i] << ' ';

  return 0;
}