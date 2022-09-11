#include <iostream>
#include <vector>
#include <cassert>
//#define DEBUG
using namespace std;

void inputVector(int n, const vector<vector<int>> &leaderboard) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i != j)
        cin >> (int &) leaderboard[i][j];
}

void outputVector(int n, const vector<vector<int>> &leaderboard) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << (int &) leaderboard[i][j] << '\t';
    cout << '\n';
  }
}

void score(int n, const vector<vector<int>> &leaderboard) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i != j)
        (int &) leaderboard[i][i] += leaderboard[j][i] - leaderboard[i][j];
}

bool isEqualDualVector(
  vector<vector<int>> &v1, vector<vector<int>> &v2, int n
) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (v1[i][j] != v2[i][j])
        return false;
  return true;
}

void inputVectorFromArray(
  int n, const vector<vector<int>> &v, int *a
) {

}

void test_5x5() {
  int n = 5;
  int a[] = {
    7, 2, 5, 1, 3,
    3, 5, 7, 4, 1,
    4, 1, 13, 6, 2,
    1, 13, 8, -5, 1,
    10, 4, 6, 7, -20
  };
  vector<vector<int>> res(n, vector<int>(n));
  inputVectorFromArray(n, res, a);

  int b[] = {
    0, 2, 5, 1, 3,
    3, 0, 7, 4, 1,
    4, 1, 0, 6, 2,
    1, 13, 8, 0, 1,
    10, 4, 6, 7, 0
  };
  vector<vector<int>> v(n, vector<int>(n));
  inputVectorFromArray(n, res, b);

  score(n, v);

  assert(isEqualDualVector(res, v, n));
}

void test_2x2_allZero() {
  int n = 2;
  int a[] = {
    0, 0,
    0, 0
  };
  vector<vector<int>> res(n, vector<int>(n));
  inputVectorFromArray(n, res, a);

  int b[] = {
    0, 0,
    0, 0
  };
  vector<vector<int>> v(n, vector<int>(n));
  inputVectorFromArray(n, res, b);

  score(n, v);

  assert(isEqualDualVector(res, v, n));
}

void tests() {
  test_5x5();
  test_2x2_allZero();
}

int main() {
#ifndef DEBUG
  tests();
#endif
#ifdef DEBUG
  int n;
  cin >> n;

  vector<vector<int>> leaderboard(n, vector<int>(n));
  inputVector(n, leaderboard);

  score(n, leaderboard);

  outputVector(n, leaderboard);
#endif
  return 0;
}

/*
5
2 5 1 3
3 7 4 1
4 1 6 2
1 13 8 1
10 4 6 7
 */