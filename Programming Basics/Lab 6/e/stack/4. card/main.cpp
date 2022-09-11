#include <iostream>
#include <stack>
#include <list>

using namespace std;

void transform(stack<int> &res, stack<int> &tmp) {
  while (tmp.size() > 0) {
    res.push(tmp.top());
    tmp.pop();
  }
}

int main() {
  int t;
  cin >> t;

  for (int k = 0; k < t; k++) {
    int deckSize;
    cin >> deckSize;

    stack<int> tmp;
    stack<int> res;
    int maxCard = 0;
    for (int i = 0; i < deckSize; i++) {
      int iCard;
      cin >> iCard;

      if (iCard > maxCard) {
        transform(res, tmp);
        maxCard = iCard;
        tmp.push(iCard);
      } else {
        tmp.push(iCard);
      }
    }
    transform(res, tmp);

    while (res.size() > 0) {
      cout << res.top() << ' ';
      res.pop();
    }
    cout << '\n';
  }


  return 0;
}