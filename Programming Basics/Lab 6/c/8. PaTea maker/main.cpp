#include <iostream>
#include "vector"
#include "algorithm"

typedef struct friendsCup {
  int number;
  int size;
  int tee;
} friendsCup;


using namespace std;

int main() {
  int n, w;
  cin >> n >> w;

  vector<friendsCup> friendsCups;
  int halfOfTea = 0;
  for (int i = 0; i < n; ++i) {
    friendsCup t;
    cin >> t.size;
    t.tee = t.size / 2 + t.size % 2;
    halfOfTea += t.tee;
    t.number = i + 1;
    friendsCups.push_back(t);
  }

  w -= halfOfTea;

  if (w < 0)
    cout << -1;
  else {
    sort(begin(friendsCups), end(friendsCups), [](auto &x, auto &y) {
      return x.size > y.size;
    });

    int i = 0;
    while (w > 0) {
      friendsCups[i].tee +=
        w > (friendsCups[i].size / 2) ? friendsCups[i].size / 2 : w;
      w -= friendsCups[i].size / 2;
      i++;
    }

    sort(begin(friendsCups), end(friendsCups), [](auto &x, auto &y) {
      return x.number > y.number;
    });

    for (int j = n - 1; j >= 0; --j) {
      cout << friendsCups[j].tee << ' ';
    }
  }


  return 0;
}