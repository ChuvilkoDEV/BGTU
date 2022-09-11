#include <iostream>

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::setvbuf(stdout, nullptr, _IOFBF, 2048);

  int t;
  std::cin >> t;
  for(int k = 0; k < t; k++) {
    int n;
    std::cin >> n;

    int minSum = 0;
    for (int i = 0; i < n; i++) {
      int a;
      std::cin >> a;
      minSum |= a;
    }

    std::cout << minSum << '\n';
  }
}