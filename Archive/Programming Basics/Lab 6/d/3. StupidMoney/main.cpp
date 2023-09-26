#include <iostream>
#include <vector>

using namespace std;

typedef struct student {
  int timeToCome;
  int timeToLeave;
} student;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int countOfStudents;
    cin >> countOfStudents;

    vector<student> students(countOfStudents);
    for (auto &j: students)
      cin >> j.timeToCome >> j.timeToLeave;

    int currentTime = 0;
    for (auto j: students) {
      if (j.timeToLeave > currentTime) {
        if (currentTime + 1 >= j.timeToCome)
          currentTime++;
        else
          currentTime = j.timeToCome;

        cout << currentTime << ' ';
      } else
        cout << 0 << ' ';
    }
    cout << '\n';
  }
  return 0;
}