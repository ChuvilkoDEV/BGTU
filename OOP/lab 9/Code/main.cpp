#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int getPriority(char operation) {
  if (operation == '+' || operation == '-')
    return 1;
  else if (operation == '*' || operation == '/')
    return 2;
  else
    return 0;
}

template<typename T>
int Calculate(T op1, T op2, T op) {
  if (op == '+')
    return op1 + op2;
  else if (op == '-')
    return op1 - op2;
  else if (op == '*')
    return op1 * op2;
  else if (op == '/')
    return op1 / op2;
  else
    return 0;
}

string getReversePolish(string infixInputString) {
  stack<char> operatorStack;
  string postfix = "";
  for (int i = 0; i < infixInputString.length(); i++) {
    char current = infixInputString[i];
    if (isdigit(current)) {
      postfix += current;
    } else if (current == '(') {
      operatorStack.push(current);
    } else if (current == ')') {
      while (!operatorStack.empty() && operatorStack.top() != '(') {
        postfix += operatorStack.top();
        operatorStack.pop();
      }
      if (!operatorStack.empty() && operatorStack.top() == '(') {
        operatorStack.pop();
      }
    } else {
      while (!operatorStack.empty() && getPriority(current) <=
                                       getPriority(operatorStack.top())) {
        postfix += operatorStack.top();
        operatorStack.pop();
      }
      operatorStack.push(current);
    }
  }
  while (!operatorStack.empty()) {
    postfix += operatorStack.top();
    operatorStack.pop();
  }
  return postfix;
}

int EvaluatePostfixExpression(string postfix) {
  stack<int> operandStack;
  for (int i = 0; i < postfix.length(); i++) {
    char current = postfix[i];
    if (isdigit(current)) {
      operandStack.push(current - '0');
    } else {
      int op2 = operandStack.top();
      operandStack.pop();
      int op1 = operandStack.top();
      operandStack.pop();
      int result = Calculate(op1, op2, current);
      operandStack.push(result);
    }
  }
  return operandStack.top();
}

int getSolution(string &infix) {
  cout << "normal exp: " << infix << endl;
  string postfix = getReversePolish(infix);
  cout << "reverse polish exp: " << postfix << endl;
  int result = EvaluatePostfixExpression(postfix);
  cout << "result: " << result << endl;
}

int main() {
  string infix = "1+2*3-4";
  getSolution(infix);
  infix = "(5+6)*8/2";
  getSolution(infix);
  infix = "2+2*2";
  getSolution(infix);
  return 0;
}