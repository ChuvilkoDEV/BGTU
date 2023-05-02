#include <iostream>
#include <thread>

using namespace std;

void vowelCount(string &s, int &count){
  string str = "aeiouAEIOU";
  for (int i = 0; i < s.size(); i++) {
    if (str.find(s[i]) != string::npos)
      count++;
    cout << "func: vowelCount. Count = " << count << endl;
  }
}

void deleteVowel(string &s) {
  string str = "aeiouAEIOU";
  const std::string empty;
  for (int i = 0; i < s.size(); i++) {
    if (str.find(s[i]) != string::npos && rand() & 1)
      s.replace(i, 1, empty);
    cout << "func: deleteVowel. string = " << s << endl;
  }
}

int main() {
  string res = "abbbabbbaaaaa";
  int count = 0;
  vowelCount(res, count);
  deleteVowel(res);
//  thread t1(vowelCount, ref(res), ref(count));
//  thread t2(deleteVowel, ref(res));
//
//  t1.join();
//  t2.join();
  cout << "End Work. count = " << count;
  return 0;
}
