#include <iostream>
#include <vector>
#include <ctime>
#include <random>

#define TIME_TEST(testCode, time) { \
  clock_t start_time = clock(); \
  testCode \
  clock_t end_time = clock();\
  clock_t sort_time = end_time - start_time; \
  time = (double)sort_time / CLOCKS_PER_SEC;\
}

using namespace std;

void _getSubArray(int i, const vector<int> &set, vector<int> arrayCur,
                  vector<vector<int>> &subArrays) {
  for (int x = 0; x <= 1; x++) {
    if (i == set.size()) {
      subArrays.push_back(arrayCur);
      return;
    } else {
      if (x)
        arrayCur.push_back(set[i]);
      _getSubArray(i + 1, set, arrayCur, subArrays);
    }
  }
}

void getSubArray(const vector<int> &set, vector<vector<int>> &subArrays) {
  vector<int> arrayCur;
  _getSubArray(0, set, arrayCur, subArrays);
}


void _generateCombinations(int n, int k, int i, int b,
                           vector<int> inputSet,
                           vector<int> generatingSet,
                           vector<vector<int>> &combinations) {
  for (int x = b; x <= n - k + i; x++) {
    vector<int> copyGeneratingSet = generatingSet;
    copyGeneratingSet.push_back(inputSet[x]);

    if (i == k) {
      combinations.push_back(generatingSet);
      return;
    } else
      _generateCombinations(n, k, i + 1, x + 1, inputSet,
                            copyGeneratingSet, combinations);
  }
}

void generateCombinations(int n, int k, vector<int> inputSet,
                          vector<vector<int>>
                          &combinations) {
  vector<int> generatingSet;
  _generateCombinations(n, k, 0, 0, inputSet, generatingSet, combinations);
}


void _getPermutations(vector<int> setAvailable, vector<int> setChosen,
                      vector<vector<int>> &permutations) {
  if (!setAvailable.empty()) {
    for (int j = 0; j < setAvailable.size(); j++) {
      vector<int> setAvailableCopy = setAvailable;
      vector<int> setChosenCopy = setChosen;

      setChosenCopy.push_back(setAvailableCopy[j]);
      setAvailableCopy.erase(setAvailableCopy.begin() + j);

      _getPermutations(setAvailableCopy, setChosenCopy,
                       permutations);
    }
  } else
    permutations.push_back(setChosen);
}

void getPermutations(vector<int> initialSet,
                     vector<vector<int>> &permutations) {
  vector<int> setChosen;
  _getPermutations(initialSet, setChosen, permutations);
}

int main() {
//#define FIRST
#ifdef FIRST
  int maxSize = 5;

  vector<int> set(maxSize);
  for (int i = 0; i < maxSize; i++)
    set[i] = i + 1;

  vector<vector<int>> subArrays;
  getSubArray(set, subArrays);

  for (auto &v: subArrays) {
    for (auto v1: v)
      cout << v1 << " ";
    cout << "\n";
  }
#endif

//#define SECOND
#ifdef SECOND
  int experimentSize = 25;

  vector<double> time(experimentSize);
  for (int maxSize = 1; maxSize <= experimentSize; maxSize++) {
    TIME_TEST({
                vector<int> set(maxSize);
                for (int i = 0; i < maxSize; i++) {
                  set[i] = i + 1;
                }

                vector<vector<int>> subArrays;
                getSubArray(set, subArrays);
              }, time[maxSize])
  }

  for (int i = 0; i < experimentSize; i++) {
    cout << i << " " << time[i] << '\n';
  }
#endif

//#define THIRD
#ifdef THIRD
  int k = 3;
  int n = 10;

  vector<vector<int>> combinations;
  vector<int> set(n);
  for (int i = 0; i < n; i++) {
    set[i] = i + 1;
  }

  generateCombinations(n, k, set, combinations);

  for (auto &v: combinations) {
    for (auto v1: v)
      cout << v1 << " ";
    cout << "\n";
  }
#endif

//#define FOURTH
#ifdef FOURTH
  int setSize = 5;

  vector<int> initialSet(setSize);
  for (int i = 0; i < setSize; i++) {
    initialSet[i] = i + 1;
  }

  vector<vector<int>> permutations;
  getPermutations(initialSet, permutations);

  for (auto &i: permutations) {
    for (auto j: i)
      cout << j << " ";
    cout << '\n';
  }
#endif

//#define FIFTH
#ifdef FIFTH
  int experimentSize = 11;

  vector<double> time(experimentSize);
  for (int setSize = 1; setSize <= experimentSize; setSize++) {
    TIME_TEST({
                vector<int> initialSet(setSize);
                for (int i = 0; i < setSize; i++) {
                  initialSet[i] = i + 1;
                }

                vector<vector<int>> permutations;
                getPermutations(initialSet, permutations);
              }, time[setSize]);
  }

  for (int i = 0; i < experimentSize; i++) {
    cout << i << " " << time[i] << "\n";
  }
#endif

  srand(47);
  cout << rand() % 120;
}