#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int M[8] = {1, 2, 3, 6, 7, 8, 9, 10}; //--множество
  int w = 8; //--кол-во элементов множества

  int i, j, n;

  n = pow(2, w);
  for (i = 0; i < n; i++) //--перебор битовых маск
  {
    printf("{");
    for (j = 0; j < w; j++) //--перебор битов в маске
      if (i & (1 << j)) //--если j-й бит установлен
        printf("%d,", M[j]); //--то выводим j-й элемент множества
    printf("\b},");
  }
  return 0;
}
