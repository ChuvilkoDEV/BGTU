#include <iostream>
#include <string>
#include <cassert>

#define DEBUG

using namespace std;

enum WorkResult {
  expectedOpeningBracket,
  expectedClosingBracket
};

// Заменяет первое вхождение скобок на фигурные скобки. Второе на квадратные.
// А все остальные оставляет без изменений
// {[(Решено без единого условия)]}
void replaceBrace(string &sOrig) {
  int levelReplace = 0;
  string s = move(sOrig);

  for (auto &i: s) {
    switch (levelReplace) {
      case 0:
        switch (i) {
          case '(':
            i = '{';
            levelReplace++;
            break;
          case ')':
            throw expectedOpeningBracket;
          default:
            continue;
        }
        break;
      case 1:
        switch (i) {
          case '(':
            i = '[';
            levelReplace++;
            break;
          case ')':
            i = '}';
            levelReplace--;
            break;
          default:
            continue;
        }
        break;
      case 2:
        switch (i) {
          case '(':
            levelReplace++;
            break;
          case ')':
            i = ']';
            levelReplace--;
            break;
          default:
            continue;
        }
        break;
      default:
        switch (i) {
          case '(':
            levelReplace++;
            break;
          case ')':
            levelReplace--;
            break;
          default:
            continue;
        }
        break;
    }
  }

  if (levelReplace != 0)
    throw expectedClosingBracket;

  sOrig = move(s);
}

void test_oneBracket() {
  string s = "a() + b() = c()";
  replaceBrace(s);
  assert(s == "a{} + b{} = c{}");
}

void test_twoBrackets() {
  string s = "a(b()) = c()";
  replaceBrace(s);
  assert(s == "a{b[]} = c{}");
}

void test_threeBrackets() {
  string s = "a(b(c())) = 0";
  replaceBrace(s);
  assert(s == "a{b[c()]} = 0");
}

void test_moreBrackets() {
  string s = "a(b(c(d(e(f))))) = 0";
  replaceBrace(s);
  assert(s == "a{b[c(d(e(f)))]} = 0");
}

void test_openingError() {
  string s = ")";
  try {
    replaceBrace(s);
    assert(true);
  } catch (WorkResult a) {
    switch (a) {
      case expectedOpeningBracket:
        // OK
        break;
      case expectedClosingBracket:
        assert(true);
        break;
    }
  }
}

void test_closingError() {
  string s = "(";
  try {
    replaceBrace(s);
    assert(true);
  } catch (WorkResult a) {
    switch (a) {
      case expectedOpeningBracket:
        assert(true);
        break;
      case expectedClosingBracket:
        // OK
        break;
    }
  }
}

void tests() {
  test_oneBracket();
  test_twoBrackets();
  test_threeBrackets();
  test_moreBrackets();
  test_openingError();
  test_closingError();
}

int main() {
#ifdef DEBUG
  tests();
#endif
#ifndef DEBUG
  string s;
  cin >> s;

  try {
    replaceBrace(s);
    cout << s;
  } catch (WorkResult a) {
    switch (a) {
      case expectedOpeningBracket:
        cout << "Expected: '('";
        break;
      case expectedClosingBracket:
        cout << "Expected: ')'";
        break;
    }
  }
#endif
  return 0;
}
