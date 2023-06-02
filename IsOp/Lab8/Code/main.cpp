#include <locale>
#include <iostream>
#include <vector>
#include <cmath>
#include "windows.h"
#define SIZE 5
using namespace std;

struct NumInd {
  float a;
  int i;
};

void ReadMatr(vector<vector<float>>& matr) {
  for (int i = 0; i < matr.size(); i++)
    for (int j = 0; j < matr[i].size(); j++)
      cin >> matr[i][j];
}
void WriteMatr(vector<vector<float>> matr) {
  for (int i = 0; i < matr.size(); i++) {
    for (int j = 0; j < matr[i].size(); j++)
      cout << matr[i][j] << ' ';
    cout << '\n';
  }
  cout << endl;
}


void BasicVariables(vector<vector<float>> matr, vector<int>& number) {
  number.resize(matr.size());
  for (int i = 0; i < matr.size(); i++) {
    for (int j = 0; j < matr[i].size() - 1; j++) {
      if (matr[i][j] == 1) {
        int k;
        for (k = 0; k < matr.size(); k++)
          if (k != i && matr[k][j] != 0)
            break;
        if (k == matr.size())
          number[i] = j + 1;
      }
    }
  }
}

int NegativeNumbers(vector<float> vec) {
  int count = 0;
  for (int i = 1; i < vec.size(); i++)
    if (vec[i] < 0)
      count++;

  return count;
}



void Sort(vector<NumInd>& numberNegative) {
  for (int i = 0; i < numberNegative.size(); i++)
    for (int j = numberNegative.size() - 1; j >= i + 1; j--)
      if (numberNegative[j].a < numberNegative[j - 1].a) {
        NumInd tmp = numberNegative[j];
        numberNegative[j] = numberNegative[j - 1];
        numberNegative[j - 1] = tmp;
      }
}
void IndexMinNumber(vector<float> vec, vector<NumInd>& numberNegative) {
  for (int i = 1; i < vec.size(); i++)
    if (vec[i] < 0)
      numberNegative.push_back({ vec[i], i });
  Sort(numberNegative);
}
int SimplexMethod(vector<vector<float>>& tabl, vector<int>& basicVar) {
  vector<NumInd> numberNegative;
  vector<NumInd> numPositive;
  while (NegativeNumbers(tabl[tabl.size() - 1])) {
    IndexMinNumber(tabl[tabl.size() - 1], numberNegative);
    int i;
    for (i = 0; i < numberNegative.size(); i++) {
      for (int j = 0; j < tabl.size() - 1; j++)
        if (tabl[j][numberNegative[i].i] > 0)
          numPositive.push_back({ tabl[j][numberNegative[i].i], j });
      if (numPositive.size() != 0)
        break;
    }




    if (numPositive.size()) {
      float min = tabl[numPositive[0].i][0] / numPositive[0].a;
      int iMin = 0;
      for (int j = 1; j < numPositive.size(); j++)
        if (min > tabl[numPositive[j].i][0] / numPositive[j].a) {
          min = tabl[numPositive[j].i][0] / numPositive[j].a;
          iMin = j;
        }
      basicVar[numPositive[iMin].i] = numberNegative[i].i;
      for (int j = 0; j < tabl[0].size(); j++)
        tabl[numPositive[iMin].i][j] /= numPositive[iMin].a;

      for (int j = 0; j < tabl.size(); j++)
        if (numPositive[iMin].i != j) {
          float p = tabl[j][numberNegative[i].i];
          for (int k = 0; k < tabl[0].size(); k++) {
            tabl[j][k] += (-tabl[numPositive[iMin].i][k] * p);
            if (abs(tabl[j][k]) <= 0.0001)
              tabl[j][k] = 0;
          }
        }
      WriteMatr(tabl);
      numberNegative.clear();
      numPositive.clear();
    }
    else {
      cout << "Система имеет неограниченное решение";
      return 1;
    }
  }

  return 0;
}

int CheckArtificialBasis(vector<int> basicVar, int m) {
  for (int i = 0; i < basicVar.size(); i++)
    if (basicVar[i] - m >= 0)
      return 1;
  return 0;
}
bool CheckIsBasic(vector<int> basic, int a) {
  for (int i = 0; i < basic.size(); i++)
    if (basic[i] == a)
      return true;
  return false;
}
void ArtBaseMethod(vector<vector<float>> tabl, vector<int> basicVar, vector<int> function, int m) {
  cout << "\nИсходная таблица:\n";
  WriteMatr(tabl);
  if (!SimplexMethod(tabl, basicVar)) {
    if (!CheckArtificialBasis(basicVar, m)) {
      cout << "Полученная таблица:\n";
      WriteMatr(tabl);
      vector<vector<float>> tablbas;
      tablbas.resize(tabl.size());
      for (int i = 0; i < tablbas.size(); i++)
        tablbas[i].resize(m);
      for (int i = 0; i < tablbas.size() - 1; i++)
        for (int j = 0; j < tablbas[i].size(); j++)
          tablbas[i][j] = tabl[i][j];
      tablbas[tablbas.size() - 1][0] = function[function.size() - 2];
      for (int j = 0; j < tabl.size() - 1; j++)
        tablbas[tablbas.size() - 1][0] += tablbas[j][0] * function[basicVar[j] - 1];
      for (int i = 1; i < tablbas[0].size(); i++) {



        if (!CheckIsBasic(basicVar, i)) {
          tablbas[tablbas.size() - 1][i] = 0;
          for (int j = 0; j < tabl.size() - 1; j++)
            tablbas[tablbas.size() - 1][i] += tablbas[j][i] * function[basicVar[j] - 1];
          tablbas[tablbas.size() - 1][i] -= function[i - 1];
        }
      }

      cout << "\n";
      WriteMatr(tablbas);
      vector<float> function;
      function.resize(SIZE + 2);
      if (!SimplexMethod(tablbas, basicVar)) {
        cout << "\n";
        WriteMatr(tablbas);
        cout << "\nЗначение функции: " << tablbas[tablbas.size() - 1][0] << endl;
        for (int i = 0; i <= SIZE; i++)
          function[i] = 0;
        for (int i = 0; i < basicVar.size(); i++)
          function[basicVar[i]] = tablbas[i][0];
        for (int i = 0; i <= SIZE; i++)
          function[i] /= function[SIZE + 1];
        for (int i = 1; i <= SIZE; i++)
          cout << "x" << i << " = " << function[i] << endl;
      }
      else
        cout << "Система уравнений не ограничена";
    }
  }
}



int SearchMulti(vector<vector<float>> matr) {
  int max = matr[0][matr[0].size() - 1];
  for (int i = 1; i < matr.size(); i++)
    if (max < matr[i][matr[0].size() - 1])
      max = matr[i][matr[0].size() - 1];
  int t = 10;
  while (max > t)
    t *= 10;
  t *= 10;
  return t;
}

void MMethod(vector<vector<float>> tabl, vector<int> basicVar) {
  vector<float> function;
  function.resize(SIZE + 2);
  cout << "\nИсходная таблица:\n";
  WriteMatr(tabl);
  if (!SimplexMethod(tabl, basicVar)) {
    WriteMatr(tabl);
    cout << "\nИскомое значение функции: " << tabl[tabl.size() - 1][0] << endl;
    for (int i = 0; i <= SIZE; i++)
      function[i] = 0;
    for (int i = 0; i < basicVar.size(); i++)
      function[basicVar[i]] = tabl[i][0];
    for (int i = 0; i <= SIZE; i++)
      function[i] /= function[SIZE + 1];
    for (int i = 1; i <= SIZE; i++)
      cout << "x" << i << " = " << function[i] << endl;
  }
}


int main() {
  SetConsoleOutputCP(CP_UTF8);

  int n, m;
  cout << "Введите размеры матрицы: ";
  cin >> n >> m;

  vector<vector<float>> matr;
  matr.resize(n);
  for (int i = 0; i < n; i++)
    matr[i].resize(m);

  cout << "Введите расширенную матрицу ограничений:\n";
  ReadMatr(matr);

  for (int i = 0; i < matr.size(); i++)
    if (matr[i][matr[0].size() - 1] < 0)
      for (int j = 0; j < matr[i].size(); j++)
        matr[i][j] *= -1;
  vector<vector<float>> matr2;
  matr2.resize(n + 1);
  for (int i = 0; i <= n; i++)
    matr2[i].resize(m + 1);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      matr2[i][j] = matr[i][j];
  for (int i = 0; i < n; i++)
    matr2[i][m - 1] *= -1;
  for (int i = 0; i < n; i++)
    matr2[i][m] = 0;




  vector<int> function;
  function.resize(m + 2);
  for (int i = 0; i <= m; i++)
    cin >> function[i];
  for (int i = 0; i < m; i++)
    cin >> matr2[n][i];
  matr2[n][m] = 1;
  cout << "Введите 1 если функция стремится к максимуму, 0 если к минимуму: ";
  cin >> function[m + 1];

  if (function[m + 1] == 0)
    for (int i = 0; i < function.size() - 1; i++)
      function[i] *= -1;
  WriteMatr(matr2);
  m++;
  n++;

  vector<int> basicVar;
  BasicVariables(matr2, basicVar);
  int k = 0;
  for (int i = 0; i < basicVar.size(); i++)
    if (basicVar[i] == 0) {
      basicVar[i] = m + k;
      k++;
    }
  vector<vector<float>> tabl;
  tabl.resize(n + 1);
  for (int i = 0; i < tabl.size(); i++)
    tabl[i].resize(m + k);
  for (int i = 0; i < tabl.size() - 1; i++)
    tabl[i][0] = matr2[i][m - 1];


  for (int i = 0; i < matr2.size(); i++)
    for (int j = 0; j < matr2[i].size() - 1; j++)
      tabl[i][j + 1] = matr2[i][j];

  for (int i = 0; i < basicVar.size(); i++)
    if (basicVar[i] - m >= 0) {
      tabl[i][basicVar[i]] = 1;
      for (int j = 0; j < tabl.size(); j++)
        if (j != i)
          tabl[j][basicVar[i]] = 0;
    }

  tabl[tabl.size() - 1][0] = 0;
  for (int i = 0; i < basicVar.size(); i++)
    if (basicVar[i] - m >= 0)
      tabl[tabl.size() - 1][0] += matr2[i][matr2[i].size() - 1];

  for (int i = 1; i < matr2[0].size(); i++) {
    tabl[tabl.size() - 1][i] = 0;
    for (int j = 0; j < basicVar.size(); j++)
      if (basicVar[j] - m >= 0)
        tabl[tabl.size() - 1][i] += matr2[j][i - 1];
  }

  for (int i = 0; i < tabl[0].size(); i++)
    tabl[tabl.size() - 1][i] *= -1;
  cout << "Метод искусственного базиса\n";
  ArtBaseMethod(tabl, basicVar, function, m);
  int M = SearchMulti(matr2);

  tabl[tabl.size() - 1][0] = function[function.size() - 2];
  float sum = 0;


  for (int i = 0; i < basicVar.size(); i++)
    if (basicVar[i] - m >= 0)
      sum += tabl[i][0];

  tabl[tabl.size() - 1][0] -= (M * sum);
  for (int j = 1; j < matr2[0].size(); j++) {
    tabl[tabl.size() - 1][j] = function[j - 1];
    sum = 0;
    for (int i = 0; i < basicVar.size(); i++)
      if (basicVar[i] - m >= 0)
        sum += tabl[i][j];
    tabl[tabl.size() - 1][j] += (M * sum);
    tabl[tabl.size() - 1][j] *= -1;
  }
  cout << "		Метод больших штрафов\n";
  MMethod(tabl, basicVar);
}