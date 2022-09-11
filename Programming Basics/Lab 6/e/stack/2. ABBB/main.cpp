#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int j = 0; j < t; j++) {
    string s;
    cin >> s;

    stack<char> st;
    st.push(s[0]);

    for (int i = 1; i < s.size(); i++)
      if (!st.empty() && s[i] == 'B')
        st.pop();
      else
        st.push(s[i]);

    cout << st.size() << '\n';
  }

  return 0;
}