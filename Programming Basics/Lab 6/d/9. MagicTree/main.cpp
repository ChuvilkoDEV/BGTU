#include <iostream>
#include <vector>

using namespace std;

int main() {
  int nTrees, delta;
  cin >> nTrees >> delta;

  vector<int> trees(nTrees);
  for (auto &i: trees)
    cin >> i;

  // Первый элемент - Минимальное количество действий над деревом
  // Второй элемент - Высота первого дерева
  pair<int, int> minDelta(1001, 1001);
  for (int i = 1; i <= 1000; i++) {
    int countPruning = 0;
    int height = i;
    for (auto &j: trees) {
      if (height != j)
        countPruning++;
      height += delta;
    }
    if (countPruning < minDelta.first) {
      minDelta.first = countPruning;
      minDelta.second = i;
    }
  }

  if (minDelta.first == 1001 && minDelta.second == 1001) {
    cout << 0;
    return 0;
  }

  cout << minDelta.first << '\n';
  int height = minDelta.second;
  for (int i = 0; i < trees.size(); i++) {
    if (trees[i] < height)
      cout << "+ " << i + 1 << ' ' << height - trees[i] << '\n';
    else if (trees[i] > height)
      cout << "- " << i + 1 << ' ' << trees[i] - height << '\n';
    height += delta;
  }

  return 0;
}
