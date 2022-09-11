#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, shakalSize, ultra4KSize;
  long long spaceOnValera;
  cin >> n >> spaceOnValera >> shakalSize >> ultra4KSize;
  vector<pair<int, int>> clients(n);;
  for (int i = 0; i < n; i++) {
    int nShakal, nUltra4K;
    cin >> nShakal >> nUltra4K;
    int r = nShakal * shakalSize + nUltra4K * ultra4KSize;
    clients[i] = {r, i};
  }

  sort(begin(clients), end(clients), [](auto &x, auto &y) {
    return x.first < y.first;
  });

  long long s = 0;
  int cnt = 0; // сокращение от count
  for (int i = 0; i < n; i++) {
    if (s + clients[i].first <= spaceOnValera) {
      s += clients[i].first;
      cnt = i + 1;
    } else {
      cnt = i;
      break;
    }
  }

  cout << cnt << '\n';
  for (int i = 0; i < cnt; i++) {
    cout << clients[i].second + 1 << ' ';
  }

  return 0;
}