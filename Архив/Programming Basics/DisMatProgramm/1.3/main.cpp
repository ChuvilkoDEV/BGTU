#include <iostream>
#include <stack>
#include <string>
#include <cassert>

#include "libs/UOAS/UOAS.h"

using namespace std;

// Структура, которая хранит оператор и его приоритет
struct priority {
  char operator_;
  int priority_;
};


class PolishEntry {
  private:
  string standardExpression_{};
  string polishExpression_{};
  stack<priority> operators_{};

  stack<unordered_array_set> res{};
  unordered_array_set A{};
  unordered_array_set B{};
  unordered_array_set C{};
  unordered_array_set U{};

  void setPolish() {
    for (char c: standardExpression_) {
      switch (c) {
        case '(':
          operators_.push((priority) {c, 4});
          break;
        case ')':
          while (operators_.top().operator_ != '(') {
            push(operators_.top().operator_);
          }
          operators_.pop();
          break;
        case '!':
          operators_.push((priority) {c, 1});
          break;
        case '&':
          pushLessPriority(2);
          operators_.push((priority) {c, 2});
          break;
        case 'u':
        case '^':
        case '-':
          pushLessPriority(3);
          operators_.push((priority) {c, 3});
          break;
        default:
          polishExpression_.push_back(c);
      }
    }
    while (!operators_.empty())
      push(operators_.top().operator_);
  }

  void push(char c) {
    polishExpression_.push_back(c);
    operators_.pop();
  }

  void pushLessPriority(int p) {
    while (!operators_.empty() && operators_.top().priority_ <= p)
      push(operators_.top().operator_);
  }

  void doOperator(
    unordered_array_set (*f)(unordered_array_set, unordered_array_set)) {
    assert(res.size() > 1);
    unordered_array_set tmp1 = res.top();
    res.pop();
    unordered_array_set tmp2 = res.top();
    res.pop();
    res.push(f(tmp2, tmp1));
  }

  void doComplement() {
    assert(!res.empty());
    unordered_array_set tmp1 = res.top();
    res.pop();
    res.push(UOAS_complement(tmp1, U));
  }

  void getUOAS() {
    for (char c: polishExpression_) {
      switch (c) {
        case '-':
          doOperator(UOAS_difference);
          break;
        case '&':
          doOperator(UOAS_intersection);
          break;
        case 'u':
          doOperator(UOAS_union);
          break;
        case '^':
          doOperator(UOAS_symmetricDifference);
          break;
        case '!':
          doComplement();
          break;
        case 'A':
          res.push(A);
          break;
        case 'B':
          res.push(B);
          break;
        case 'C':
          res.push(C);
          break;
        case 'X':
          res.push(U);
          break;
        default:
          cerr << "Unknown character: " << c;
          exit(1);
      }
    }
  }

  void setUOAS() {
    int a[] = {1, 3, 5, 7};
    int b[] = {2, 3, 6, 7};
    int c[] = {4, 5, 6, 7};
    int u[] = {1, 2, 3, 4, 5, 6, 7};

    A = UOAS_createFromArray(a, 4);
    B = UOAS_createFromArray(b, 4);
    C = UOAS_createFromArray(c, 4);
    U = UOAS_createFromArray(u, 7);
  }

  public:
  explicit PolishEntry(string &s) {
    setExpression(s);
    setUOAS();
    getUOAS();
  }

  PolishEntry() {
    setUOAS();
    getUOAS();
  }

  void setExpression(string &s) {
    standardExpression_ = s;
    setPolish();
  }

  string getPolish() {
    return polishExpression_;
  }

  unordered_array_set getResult() {
    return res.top();
  }
};

void test_setPolish_0() {
  string s = "A-B-CuA&B-CuC-A-B";
  PolishEntry p{s};

  assert(p.getPolish() == "AB-C-AB&C-uCA-B-u");
}

void test_setPolish_1() {
  string s = "A&!Cu!A&!B&C";
  PolishEntry p{s};

  assert(p.getPolish() == "AC!&A!B!&C&u");
}

void test_setPolish_2() {
  string s = "A-CuC-A-B";
  PolishEntry p{s};

  assert(p.getPolish() == "AC-CA-B-u");
}

void test_setPolish_3() {
  string s = "!(!(A-C)&!(C-A-B))";
  PolishEntry p{s};

  assert(p.getPolish() == "AC-!CA-B-!&!");
}

void test_setPolish_4() {
  string s = "(A-C)u(C-A-B)";
  PolishEntry p{s};

  assert(p.getPolish() == "AC-CA-B-u");
}

void tests_setPolish() {
  test_setPolish_0();
  test_setPolish_1();
  test_setPolish_2();
  test_setPolish_3();
  test_setPolish_4();
}

void test_getResult1() {
  string s1 = "A-B-CuA&B-CuC-A-B";
  PolishEntry p1{s1};
  string s2 = "A&!Cu!A&!B&C";
  PolishEntry p2{s2};

  assert(UOAS_isEqual(p1.getResult(), p2.getResult()));
}

void test_getResult2() {
  string s1 = "A-CuC-A-B";
  PolishEntry p1{s1};
  string s2 = "A&!Cu!A&!B&C";
  PolishEntry p2{s2};

  assert(UOAS_isEqual(p1.getResult(), p2.getResult()));
}

void test_getResult3() {
  string s1 = "A-CuC-A-B";
  PolishEntry p1{s1};
  string s2 = "!(!(A-C)&!(C-A-B))";
  PolishEntry p2{s2};

  assert(UOAS_isEqual(p1.getResult(), p2.getResult()));
}

void test_getResult4() {
  string s1 = "(A-C)u(C-A-B)";
  PolishEntry p1{s1};
  string s2 = "!(!(A-C)&!(C-A-B))";
  PolishEntry p2{s2};

  assert(UOAS_isEqual(p1.getResult(), p2.getResult()));
}

void tests_getResult() {
  test_getResult1();
  test_getResult2();
  test_getResult3();
  test_getResult4();
}

void tests() {
  tests_setPolish();
  tests_getResult();
}

#define DEBUG

int main() {
#ifndef DEBUG
  tests();
#endif
#ifdef DEBUG
  string s1 = "(A-(X&B)u(C&!X))^((X-A)&(X-B)-C)";
  PolishEntry p1{s1};
  string s2 = "(A-(!X&B)u(C&X))^((!X-A)&(!X-B)-C)";
  PolishEntry p2{s2};


  cout << p1.getPolish() << '\n';
  UOAS_print(p1.getResult());

  cout << p2.getPolish() << '\n';
  UOAS_print(p2.getResult());
#endif
}

// (0) A-B-CuA&B-CuC-A-B    // Ответ: AB-C-AB&C-uCA-B-u
// (1) A&!Cu!A&!B&C         // Ответ: AC!&A!B!&C&u
// (2) A-CuC-A-B            // Ответ: AC-CA-B-u
// (3) !(!(A-C)&!(C-A-B))   // Ответ: AC-!CA-B-!&!
// (4) (A-C)u(C-A-B)        // Ответ: AC-CA-B-u

// A&!BuA&CuA&B&!CuC&!AuC&B