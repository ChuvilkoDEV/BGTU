#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  for (int s = 0; s <= 2000; s++)
    if (s == a + b)
      cout << s;
 // ^_^
  return 0;
}
