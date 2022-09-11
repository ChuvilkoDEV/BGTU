#include <iostream>
#include <vector>

using namespace std;

void outputVector(vector<vector<bool>> &field) {
  for (int i = 0; i < field.size(); i++) {
    for (int j = 0; j < field[0].size(); j++)
      cout << field[i][j];
    cout << '\n';
  }
}

// Ввод отравленных клеток
void inputDeathBox(vector<vector<bool>> &field) {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int a, b;
    cin >> a >> b;

    field[a][b] = true;
  }
}

void isReal_(int i, int j, vector<vector<bool>> &field, vector<vector<bool>> &real) {
  //real [i][j] = !field[i][j] && (
  //  (i != 0 ? real[i - 1][j] : true) || (j != 0 ? real[i][j - 1] : true));
  if (field[i][j]) {
    real[i][j] = false;
    return;
  }
  if (j == 0)
    real[i][j] = real[i - 1][j];
  else if (i == 0)
    real[i][j] = real[i][j - 1];
  else
    real[i][j] = real[i - 1][j] || real[i][j - 1];
}

bool isReal(vector<vector<bool>> &field, vector<vector<bool>> &real) {
  real[0][0] = true;
  for (int i = 0; i < field.size(); i++)
    for (int j = i + 1; j < field[0].size(); j++) {
      isReal_(i, j, field, real);
      isReal_(j, i, field, real);
    }

  isReal_(real.size() - 1, real[0].size() - 1, field, real);
  return real[real.size() - 1][real.size() - 1];
}

// Какой-то код дохуя важный

/*
void outputPath(vector<vector<bool>> &field, vector<vector<bool>> &real) {
  bool isFinal = true;
  for ()
}
*/
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> field(n, vector<bool>(m, false));
  vector<vector<bool>> real(field.size(), vector<bool>(field[0].size()));

  inputDeathBox(field);

  cout << isReal(field, real);

  return 0;
}

/*
5 5
5
2 0
1 1
3 1
2 2
2 3
 */