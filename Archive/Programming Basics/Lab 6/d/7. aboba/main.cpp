#include <iostream>
#include <vector>

using namespace std;

int main() {
  int countDays, countStudents;
  cin >> countDays >> countStudents;

  vector<int> graph(countDays + 1, 0);
  for (int i = 0; i < countStudents; i++) {
    int start, end;
    cin >> start >> end;

    for (int j = start; j <= end; j++)
      graph[j]++;
  }

  for (int i = 1; i <= countDays; i++)
    if (graph[i] != 1) {
      cout << i << ' ' << graph[i];
      return 0;
    }

  cout << "OK";

  return 0;
}
