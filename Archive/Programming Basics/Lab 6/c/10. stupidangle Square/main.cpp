#include <iostream>
#include <cmath>

using namespace std;

int len(int n) {
  int counter = 0;
  while (n > 0) {
    n /= 10;
    counter++;
  }
  return counter;
}

int main() {
  int n;
  cin >> n;
  int lenN = len(n);

  for (int i = (int) sqrt(n); i > 0; i--) {
    int powI2 = (int) pow(i, 2);
    int lenI2 = len(powI2);
    int tmp = n;
    int counter = 0;
    while (tmp > 0) {
      if (powI2 != 0 && tmp % 10 == powI2 % 10) {
        powI2 /= 10;
        counter--;
      }
      tmp /= 10;
      counter++;
    }
    if (lenN - counter == lenI2) {
      cout << counter;
      return 0;
    }
  }

  cout << -1;

  return 0;
}
