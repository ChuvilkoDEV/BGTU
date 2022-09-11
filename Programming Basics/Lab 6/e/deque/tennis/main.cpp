#include <iostream>

using namespace std;

int main() {
  int countPlayers;
  long long scoreForWin;
  cin >> countPlayers >> scoreForWin;

  int coolestPlayer;
  cin >> coolestPlayer;
  int scoreCounter = 0;
  for (int i = 1; i < countPlayers; i++) {
    int nextPlayer;
    cin >> nextPlayer;
    
    if (coolestPlayer < nextPlayer) {
      coolestPlayer = nextPlayer;
      scoreCounter = 1;
    } else {
      scoreCounter++;
    }

    if (scoreCounter == scoreForWin) {
      cout << coolestPlayer;
      return 0;
    }
  }

  cout << coolestPlayer;

  return 0;
}
