#include <iostream>
#include <vector>

using namespace std;

vector<bool> mark(11);

int main() {
  long long n;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    mark[s[i] - '0'] = true;
  }

  bool vertical = (mark[1] || mark[2] || mark[3]) && (mark[7] || mark[9]);
  bool horizontal = (mark[1] || mark[4] || mark[7]) && (mark[3] || mark[6] || mark[9]);
  bool zero = (mark[1] || mark[2] || mark[3]) && mark[0];
  if (vertical && horizontal || zero)
    cout << "YES";
  else
    cout << "NO";

  return 0;
}