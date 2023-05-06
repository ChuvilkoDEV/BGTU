#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
  Stack<int> a;
  a.Push(1);
  cout << a.Get();

  return 0;
}
