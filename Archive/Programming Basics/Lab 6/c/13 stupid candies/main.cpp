#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> sum(n + 1);
  sum[0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum[i + 1] = a[i] + sum[i];
  }

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int l, r;
    cin >> l >> r;
    cout << (sum[r] - sum[l - 1]) / 10 << '\n';
  }

  return 0;
}
