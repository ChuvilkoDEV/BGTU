#include <iostream>
#include <cmath>
#include <vector>

#define EPS 0.001
using namespace std;

struct Point {
  int x;
  double y;
};

Point MyFunc(int x) {
  Point res{x, x + log10(x)};
  return res;
}

// Проверка на равенство двух вещественных чисел с учетом погрешности
bool equal(double x1, double x2) {
  return (abs(x1 - x2) < EPS);
}

// Проверка сетки на равномерность
bool isUniform(vector<Point> &points) {
  for (int i = 1; i <= points.size() - 2; i++)
    if (!equal(points[i].x - points[i - 1].x, points[i + 1].x - points[i].x))
      return false;
  return true;
}

//Найти значение факториала
int factorial(int n) {
  int result = 1;
  for (int i = 2; i <= n; i++)
    result *= i;
  return result;
}

//Получить многочлен N степени с вычитанием
double getNPowerPolynomialNegative(int power, double value) {
  double result = 1;
  for (int i = 0; i < power; i++)
    result *= (value - i);
  return result;
}

//Получить многочлен N степени с прибавлением
double getNPowerPolynomialPositive(int power, double value) {
  double result = 1;
  for (int i = 0; i < power; i++)
    result *= (value + i);
  return result;
}


// Возвращает вектор конечных разностей
vector<vector<Point>> GetFiniteDifference(vector<Point> &points) {
  vector<vector<Point>> res(points.size());
  res[0] = points;
  for (int i = 1; i < points.size(); i++)
    for (int j = 0; j < res[i - 1].size() - 1; j++)
      res[i].push_back({res[i - 1][j].x,
                        res[i - 1][j + 1].y - res[i - 1][j].y});
  return res;
}

double FiniteDifference(vector<Point> &points, int a) {
  vector<vector<Point>> v = GetFiniteDifference(points);
  double value = 0;

  // Интерполяция вперед
  if (a >= points[0].x){
    double t = ((double)a - points[0].x) / (points[1].x - points[0].x);
    for (int i = 0; i < points.size(); i++)
      value += (v[0][i].y * getNPowerPolynomialNegative(i, t)) / factorial(i);
  } else {
    float q = ((double)a - points[points.size() - 1].x) / (points[1].x - points[0].x);
    for (int i = points.size() - 1; i >= 0; i--) {
      int j = points.size() - i - 1;
      value += v[i][j].y * getNPowerPolynomialPositive(j, q);
    }
  }
  return value;
}

// Возвращает вектор разделенных разностей
vector<vector<Point>> getDividedDifferences(vector<Point> &points) {
  vector<vector<Point>> res(points.size());
  res[0] = points;
  for (int i = 1; i < points.size(); i++)
    for (int j = 0; j < res[i - 1].size() - 1; j++)
      res[i].push_back({res[i - 1][j + 1].x,
                        (res[i - 1][j + 1].y - res[i - 1][j].y) /
                        (res[i - 1][j + 1].x - points[i].x)});
  return res;
}

double DividedDifferences(vector<Point> &points, int a) {
  vector<vector<Point>> v = GetFiniteDifference(points);
  double res = v[0][0].y;
  for (int i = 1; i < points.size()-1; i++)
    res += v[0][i].y * (a - v[i - 1][0].x);
  return res;
}


int main() {
  vector<Point> points;
  for (int i = 16; i < 20; i++)
    points.push_back(MyFunc(i));

  vector<vector<Point>> res = GetFiniteDifference(points);

  if (isUniform(points)) {
    cout << FiniteDifference(points, 15);
  } else {
    cout << DividedDifferences(points, 15);
  }


  return 0;
}
