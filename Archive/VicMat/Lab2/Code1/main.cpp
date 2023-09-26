#include <iostream>
#include <fstream>
#include "vector"

#define EPS 0.00001

using namespace std;

typedef pair<float, float> Point;

//Сравнение двух вещественных чисел
bool fcmp(float f1, float f2) {
  return (abs(f1 - f2) < EPS);
}

//Проверка сетки на равномерность
bool checkIfUniform(vector<Point> points) {
  for (int i = 1; i <= points.size() - 2; i++) {
    if (!fcmp(points[i].first - points[i - 1].first,
              points[i + 1].first - points[i].first))
      return false;
  }

  return true;
}

//Получить вектор конечных разностей
vector<vector<float>> getFiniteDifferences(vector<Point> points) {
  vector<vector<float>> finiteDifferences(points.size());
  for (int i = 0; i < points.size(); i++) {
    finiteDifferences[i] = vector<float>{points[i].second};
  }

  for (int column = 1; column <= points.size() - 1; column++) {
    for (int row = 0; row < points.size() - column; row++) {
      finiteDifferences[row].push_back(finiteDifferences[row + 1][column - 1] -
                                       finiteDifferences[row][column - 1]);
    }
  }

  return finiteDifferences;
}

//Получить вектор разделенных разностей
vector<vector<float>> getDividedDifferences(vector<Point> points) {
  vector<vector<float>> dividedDifferences(points.size());
  for (int i = 0; i < points.size(); i++) {
    dividedDifferences[i] = vector<float>{points[i].second};
  }

  for (int column = 1; column <= points.size() - 1; column++) {
    for (int row = 0; row < points.size() - column; row++) {
      dividedDifferences[row].push_back(
        (dividedDifferences[row + 1][column - 1] -
         dividedDifferences[row][column - 1]) /
        (points[row + 1].first - points[row].first));
    }
  }

  return dividedDifferences;
}

//Получить многочлен N степени с вычитанием
float getNPowerPolynomialNegative(int power, float value) {
  float result = 1;
  for (int i = 0; i < power; i++) {
    result *= (value - i);
  }

  return result;
}

//Получить многочлен N степени с прибавлением
float getNPowerPolynomialPositive(int power, float value) {
  float result = 1;
  for (int i = 0; i < power; i++) {
    result *= (value + i);
  }

  return result;
}

//Получить многочлен для метода разделенных разностей
float getPolynomialForDividedDifferences(int power, float value,
                                         vector<Point> points) {
  float result = 1;
  for (int i = 0; i < power; i++) {
    result *= value - points[i].first;
  }

  return result;
}

//Найти значение факториала
int factorial(int n) {
  int result = 1;
  for (int i = 2; i <= n; i++) {
    result *= i;
  }

  return result;
}
void outputDifferences(vector<vector<float>> &v) {
  for (auto &i : v) {
    for (auto j :i)
      cout << j << ' ';
    cout << '\n';
  }
}

int main(int argc, char *argv[]) {
  //Выбор способа ввода
  char source;
  cin >> source;

  float substitutedValue; // Подставляемое значение
  vector<pair<float, float>> points;

  //Считывание из терминала
  if (source == 't') {
    int numPoints;
    cin >> numPoints;

    for (int i = 0; i < numPoints; i++) {
      Point point;
      cin >> point.first >> point.second;
      points.push_back(point);
    }
    cin >> substitutedValue;

    //Считывание из файла
  } else if (source == 'f') {
    string filePath;
    cin >> filePath;

    ifstream inputFile(filePath);
    if (inputFile.is_open()) {
      int numPoints;
      inputFile >> numPoints;
      for (int i = 0; i < numPoints; i++) {
        Point point;
        inputFile >> point.first >> point.second;
        points.push_back(point);
      }
      cin >> substitutedValue;

      inputFile.close();
    } else {
      cerr << "Can't open file";
      exit(1);
    }
  } else {
    cerr << "Wrong input";
    exit(1);
  }

  if (checkIfUniform(points)) {
    vector<vector<float>> finiteDifferences = getFiniteDifferences(points);
    outputDifferences(finiteDifferences);

    float value = 0;
    if (substitutedValue >= points[0].first) {
      //Интерполяция вперед
      float t = (substitutedValue - points[0].first) /
                (points[1].first - points[0].first);

      for (int i = 0; i < finiteDifferences[0].size(); i++) {
        value += finiteDifferences[0][i] * getNPowerPolynomialNegative(i, t) /
                 factorial(i);
      }

    } else {
      //Интерполяция назад
      float q = (substitutedValue - points[points.size() - 1].first) /
                (points[1].first - points[0].first);
      for (int row = finiteDifferences.size() - 1; row >= 0; row--) {
        int column = finiteDifferences[0].size() - 1 - row;
        value += finiteDifferences[row][column] *
                 getNPowerPolynomialPositive(column, q);
      }
    }

    cout << "\nf(a) = " << value;

    //Метод разделенных разностей
  } else {
    vector<vector<float>> dividedDifferences = getDividedDifferences(points);
    outputDifferences(dividedDifferences);

    float value = 0;
    for (int column = 0; column < dividedDifferences[0].size(); column++) {
      value += dividedDifferences[0][column] *
               getPolynomialForDividedDifferences(column, substitutedValue,
                                                  points);
    }
    cout << "\nf(a) = " << value;
  }
}