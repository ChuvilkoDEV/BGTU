#include <iostream>
#include <vector>

using namespace std;

int findTime(int room, int cleaner, int trash) {
  if (cleaner <= trash) {
    return trash - cleaner;
  } else {
    return 2 * (room - cleaner) + cleaner - trash;
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int roomX, roomY, cleanerX, cleanerY, trashX, trashY;
    cin >> roomX >> roomY >> cleanerX >> cleanerY >> trashX >> trashY;

    cout << min(findTime(roomX, cleanerX, trashX),
                findTime(roomY, cleanerY, trashY)) << '\n';
  }
  return 0;
}
