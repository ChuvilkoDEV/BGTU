#include <iostream>
#include <stack>

using namespace std;

int main() {
  string s;
  cin >> s;

  stack<char> st;

  st.push(s[0]);
  bool isFirstWin = false;
  for (int i = 1; i < s.size(); i++) {
    if (!st.empty() && st.top() == s[i]){
      st.pop();
      isFirstWin = !isFirstWin;
    } else {
      st.push(s[i]);
    }
  }

  cout << (isFirstWin ? "YES" : "NO");


  return 0;
}
