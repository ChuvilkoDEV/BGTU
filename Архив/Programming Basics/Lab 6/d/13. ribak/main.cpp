#include <iostream>
#include <vector>

using namespace std;

int main() {
  int countKids, k;
  cin >> countKids >> k;

  int leader = 0;
  vector<int> pubg(countKids);
  for (int i = 0; i < countKids; i++) {
    pubg[i] = i + 1;
  }

  for (int i = 0; i < k; i++) {
    int a;
    cin >> a;

    leader = (leader + a) % countKids;
    cout << pubg[leader] << ' ';
    pubg.erase(pubg.cbegin() + leader);
    countKids--;
  }

  return 0;
}
