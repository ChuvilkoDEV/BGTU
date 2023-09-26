#include <iostream>
#include <vector>
#include <iomanip>
#include "cmath"
#include <windows.h>

using namespace std;

int length;
string message;

struct SymbolCode {
  char symbol;
  int count;
  float probability;
  string code;

  SymbolCode(char symbol) {
    this->symbol = symbol;
    this->count = 1;
    this->probability = (float) 1 / (float) length;
  }
};

void pushToTable(char c, vector<SymbolCode> &symbolCodeTable) {
  for (auto &i: symbolCodeTable)
    if (i.symbol == c) {
      i.count++;
      i.probability = (float) i.count / (float) length;
      return;
    }
  symbolCodeTable.emplace_back(c);
}

void readMessage(vector<SymbolCode> &symbolCodeTable) {
  getline(cin, message);
  length = message.size();
  for (auto c: message)
    pushToTable(c, symbolCodeTable);
}

void swap(SymbolCode *a, SymbolCode *b) {
  SymbolCode tmp = *a;
  *a = *b;
  *b = tmp;
}

void sort(vector<SymbolCode> &symbolCodeTable) {
  for (int i = 0; i < symbolCodeTable.size() - 1; i++) {
    int maxIndex = i;
    for (int j = i + 1; j < symbolCodeTable.size(); j++)
      if (symbolCodeTable[j].count > symbolCodeTable[maxIndex].count)
        maxIndex = j;
    swap(&symbolCodeTable[i], &symbolCodeTable[maxIndex]);
  }
}

void CodesForSymbolCodesTable_(vector<SymbolCode> &symbolCodeTable,
                               int leftBorder, int rightBorder) {
  if (rightBorder - leftBorder == 1)
    return;

  float totalProbabilitiesSum = 0;
  for (int i = leftBorder; i < rightBorder; i++)
    totalProbabilitiesSum += symbolCodeTable[i].probability;

  int i = leftBorder;
  float partialProbabilitiesSum = 0;
  while (i < rightBorder and
         partialProbabilitiesSum < totalProbabilitiesSum / 2) {
    partialProbabilitiesSum += symbolCodeTable[i].probability;
    i++;
  }

  for (int j = leftBorder; j < i; j++)
    symbolCodeTable[j].code += '0';
  for (int j = i; j < rightBorder; j++)
    symbolCodeTable[j].code += '1';

  CodesForSymbolCodesTable_(symbolCodeTable, leftBorder, i);
  CodesForSymbolCodesTable_(symbolCodeTable, i, rightBorder);
}

void CodesForSymbolCodesTable(vector<SymbolCode> &symbolCodeTable) {
  CodesForSymbolCodesTable_(symbolCodeTable, 0, symbolCodeTable.size());
}

void outputSymbolCodeTable(vector<SymbolCode> &symbolCodeTable) {
  for (auto &i: symbolCodeTable)
    cout << setprecision(4) << i.symbol << ' ' << i.probability << ' ' << i.code
         << endl;
}

void squeezeMessage(vector<SymbolCode> &symbolCodeTable) {
  for (auto i: message)
    for (auto &j: symbolCodeTable)
      if (j.symbol == i)
        cout << j.code << "'";
  cout << endl;
}

float compressionRatio(vector<SymbolCode> &symbolCodeTable) {
  int compressionMessageSize = 0;
  for (auto i: message)
    for (auto &j: symbolCodeTable)
      if (j.symbol == i)
        compressionMessageSize += j.code.size();
  return (float) (length * 8) / (float) compressionMessageSize;
}

double dispersion(vector<SymbolCode> &symbolCodeTable) {
  double res = 0;
  for (auto &i:symbolCodeTable)
    res += pow(log(i.probability),2) * i.probability;
  return res;
}

int main() {
  setlocale(LC_ALL,"Russian");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  vector<SymbolCode> symbolCodeTable;
  readMessage(symbolCodeTable);
  sort(symbolCodeTable);
  CodesForSymbolCodesTable(symbolCodeTable);
  outputSymbolCodeTable(symbolCodeTable);
  squeezeMessage(symbolCodeTable);
  cout << compressionRatio(symbolCodeTable) << endl;
  cout << dispersion(symbolCodeTable);

  return 0;
}
