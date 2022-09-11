#include <iostream>
#include <numeric>

using namespace std;

int main() {
  int pow1, pow2;
  cin >> pow1 >> pow2;

  if (pow1 < pow2) {
    cout << "0/1";
    return 0;
  }
  int numenator, denominator, trash;

  cin >> numenator;
  for (int i = 0; i < pow1; i++)
    cin >> trash;
  cin >> denominator;
  for (int i = 0; i < pow2; i++)
    cin >> trash;
  int g = gcd(numenator, denominator);

  if (pow1 > pow2) {
    if (numenator * denominator > 0)
      cout << "Infinity";
    else
      cout << "-Infinity";
  } else {
    if (numenator * denominator > 0)
      cout << abs(numenator) / g << '/' << abs(denominator) / g;
    else
      cout << "-" << abs(numenator) / g << '/' << abs(denominator) / g;
  }

  return 0;
}
