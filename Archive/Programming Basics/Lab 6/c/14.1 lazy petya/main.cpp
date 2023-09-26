#include <iostream>
#include <vector>

using namespace std;

bool
isCorrectTime(int const *const courier, int const *const petya, int nDishes,
              long long time) {
  long long petyaTime = time;
  for (int i = 0; i < nDishes; i++) {
    if (courier[i] > time) {
      petyaTime -= petya[i];
      if (petyaTime < 0)
        return false;
    }
  }
  return true;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int nSets;
  cin >> nSets;

  for (int i = 0; i < nSets; i++) {
    int nDishes;
    cin >> nDishes;

    int courier[nDishes];
    int petya[nDishes];

    for (auto &time: courier)
      cin >> time;

    for (auto &time: petya)
      cin >> time;

    long long leftBorder = -1;
    long long rightBorder = 10000000000000;

    while (rightBorder - leftBorder > 1) {
      long long middle = leftBorder + (rightBorder - leftBorder) / 2;
      if (isCorrectTime(courier, petya, nDishes, middle))
        rightBorder = middle;
      else
        leftBorder = middle;
    }

    cout << rightBorder << '\n';
  }
}