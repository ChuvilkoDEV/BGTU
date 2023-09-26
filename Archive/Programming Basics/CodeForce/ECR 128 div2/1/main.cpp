#include <iostream>

using namespace std;

int getBeautifulSet(pair<int, int> min, pair<int, int> max) {
  if (min.second < max.first)
    return min.first + max.first;
  if (min.second > max.first)
    return max.first;
  return min.first;
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    pair<int, int> min;
    cin >> min.first >> min.second;
    pair<int, int> max;
    cin >> max.first >> max.second;

    if (min.first > max.first)
      swap(min, max);

    cout << getBeautifulSet(min, max) << '\n';
  }

  return 0;
}
