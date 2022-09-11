#include <iostream>
#include <fstream> // для работы с файлами
#include <ctime>
#include <vector>
#include <cmath>

#include "Codeforces/Codeforces.h"
#include "thread/thread.h"

#define TIME_TEST(testCode, message) { \
  clock_t start_time = clock(); \
  testCode \
  clock_t end_time = clock();\
  clock_t sort_time = end_time - start_time; \
  std::clog << message << ": " \
          << static_cast<double>(sort_time) / CLOCKS_PER_SEC << std::endl; \
 }

void swap(int &a, int &b) {
  int t = a;
  a = b;
  b = t;
}

struct Product {
  std::string name;
  int price;
  size_t quantity;
};

void inputProduct(Product &p) {
  std::cout << "Enter product name: ";
  std::cin >> p.name;
  std::cout << "Enter price: ";
  std::cin >> p.price;
  std::cout << "Enter quantity product in stock: ";
  std::cin >> p.quantity;
}

void outputProduct(Product &p) {
  std::cout << "Product name: " << p.name;
  std::cout << "\nEnter price: " << p.price;
  std::cout << "\nEnter quantity product in stock: " << p.quantity;
}

void sort2(int &a, int &b) {
  if (a > b) {
    int t = a;
    a = b;
    b = t;
  }
}

void inputVector(std::vector<int> &v) {
  for (size_t i = 0; i < v.size(); i++)
    std::cin >> v.data()[i];
}

void outputVector(std::vector<int> &v) {
  for (size_t i = 0; i < v.size(); i++) {
    std::cout << v.data()[i] << ' ';
  }
}

int getMinInVector(std::vector<int> &v) {
  int min = v.data()[0];
  for (size_t i = 1; i < v.size(); i++)
   if (min > v.data()[i])
     min = v.data()[i];
  return min;
}

void inputFromKeyboard(std::vector<int>(&v)) {
  while (true) {
    int x;
    std::cin >> x;
    if (x == 0)
      return;
    v.push_back(x);
  }
}

void reverseVector(std::vector<int>(&v)) {
  for (int i = 0; i < v.size() / 2; ++i)
    swap(v[i], v[v.size() - i - 1]);
}

void getRoots(int a, int b, int c, double *x1, double *x2) {
  double d = sqrt(pow(b, 2) - 4 * a * c);
  *x1 = (-b + d) / (2 * a);
  *x2 = (-b - d) / (2 * a);
}

void getRoots(int a, int b, int c, double &x1, double &x2) {
  double d = sqrt(pow(b, 2) - 4 * a * c);
  x1 = (-b + d) / (2 * a);
  x2 = (-b - d) / (2 * a);
}

void getDistance() {

}

int main() {
  std::vector<int> v(1);

  inputFromKeyboard(v);
  reverseVector(v);
  outputVector(v);

  return 0;
}