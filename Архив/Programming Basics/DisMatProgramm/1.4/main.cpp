#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include "vector"
#include <utility>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>

using namespace std;


typedef struct unordered_array_set {
  int *data; // элементы множества
  size_t size; // количество элементов в множестве
  size_t capacity; // максимальное количество элементов в множестве
} unordered_array_set;

int compare_ints(const void *a, const void *b) {
  int arg1 = *(const int *) a;
  int arg2 = *(const int *) b;
  if (arg1 < arg2) return -1;
  if (arg1 > arg2) return 1;
  return 0;
}

void inputArray_(int *const a, const size_t n) {
  for (size_t i = 0; i < n; i++)
    scanf("%d", &a[i]);
}

void outputArray_(const int *const a, const size_t n) {
  for (size_t i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}

void append_(int *const a, size_t *const n, const int value) {
  a[*n] = value;
  (*n)++;
}

void insert_(int *const a, size_t *const n, const size_t pos,
             const int value) {
  assert(pos < *n);
  if (*n != 0) {
    size_t lowBound = (pos == 0) ? ULONG_MAX : pos;
    (*n)++;
    for (size_t i = *n; i != lowBound; i--)
      a[i] = a[i - 1];
    a[pos] = value;
  } else {
    (*n)++;
    a[pos] = value;
  }
}

void deleteByPosSaveOrder_(int *a, size_t *n, const size_t pos) {
  for (size_t i = pos + 1; i < *n; i++)
    a[i] = a[i + 1];
  (*n)--;
}

void deleteByPosUnsaveOrder_(int *a, size_t *n, size_t pos) {
  a[pos] = a[*n - 1];
  (*n)--;
}

size_t linearSearch_(const int *a, const size_t n, int x) {
  for (size_t i = 0; i < n; i++)
    if (a[i] == x)
      return i;
  return n;
}

int any_(const int *a, size_t n, int (*predicate)(int)) {
  for (size_t i = 0; i < n; i++)
    if (predicate(a[i]))
      return 1;
  return 0;
}

int all_(const int *a, size_t n, int (*predicate)(int)) {
  for (size_t i = 0; i < n; i++)
    if (!predicate(a[i]))
      return 0;
  return 1;
}

int countIf_(const int *const a, const size_t n, int (*predicate)(int)) {
  int count = 0;
  for (size_t i = 0; i < n; i++)
    count += predicate(a[i]);
  return count;
}

void deleteIf_(int *const a, size_t *const n, int (*deletePredicate)(int)) {
  size_t iRead = 0;
  while (iRead < *n && !deletePredicate(a[iRead]))
    iRead++;
  size_t iWrite = iRead;
  while (iRead < *n) {
    if (!deletePredicate(a[iRead])) {
      a[iWrite] = a[iRead];
      iWrite++;
    }
    iRead++;
  }
  *n = iWrite;
}

void forEach_(const int *source, int *dest,
              const size_t n, const int (*predicate)(int)) {
  for (size_t i = 0; i < n; i++)
    dest[i] = predicate(source[i]);
}

size_t binarySearch_(const int *a, size_t n, int x) {
  size_t left = 0;
  size_t right = n - 1;
  while (left <= right) {
    size_t middle = left + (right - left) / 2;
    if (a[middle] < x)
      left = middle + 1;
    else if (a[middle] > x)
      right = middle - 1;
    else
      return middle;
  }
  return n;
}

size_t binarySearchMoreOrEqual_(const int *a, size_t n, int x) {
  if (a[0] >= x)
    return 0;
  size_t left = 0;
  size_t right = n;
  while (right - left > 1) {
    size_t middle = left + (right - left) / 2;
    if (a[middle] < x)
      left = middle;
    else
      right = middle;
  }
  return right;
}

// возвращает пустое множество для capacity элементов
unordered_array_set UOAS_create(size_t capacity) {
  return (unordered_array_set) {
    static_cast<int *>(malloc(sizeof(int) * capacity)),
    0,
    capacity
  };
}

// уменьшает вместимость множества a до его размера
void UOAS_shrinkToFit(unordered_array_set *a) {
  if (a->size != a->capacity) {
    a->data = (int *) realloc(a->data, sizeof(int) * a->size);
    a->capacity = a->size;
  }
}

// возвращает позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
size_t UOAS_in(unordered_array_set *set, int value) {
  return linearSearch_(set->data, set->size, value);
}

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool UOAS_isEqual(unordered_array_set set1,
                  unordered_array_set set2) {
  if (set1.size != set2.size)
    return false;
  qsort(set1.data, set1.size, sizeof(int), compare_ints);
  qsort(set2.data, set2.size, sizeof(int), compare_ints);
  return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;
}

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void UOAS_isAbleAppend(unordered_array_set *set) {
  assert(set->size < set->capacity);
}

// добавляет элемент value в множество set
void UOAS_insert(unordered_array_set *set, int value) {
  if (UOAS_in(set, value) == set->size) {
    UOAS_isAbleAppend(set);
    append_(set->data, &set->size, value);
  }
}

// возвращает множество, состоящее из элементов массива a размера size
unordered_array_set UOAS_create_from_array(const int *a, size_t size) {
  unordered_array_set set = UOAS_create(size);
  for (size_t i = 0; i < size; i++) {
    UOAS_insert(&set, a[i]);
  }
  UOAS_shrinkToFit(&set);
  return set;
}

// удаляет элемент value из множества set
void UOAS_deleteElement(unordered_array_set *set, int value) {
  size_t pos = UOAS_in(set, value);
  if (pos != set->size) {
    deleteByPosUnsaveOrder_(set->data, &set->size, pos);
  }
}

// возвращает объединение множеств set1 и set2
unordered_array_set UOAS_union(unordered_array_set set1,
                               unordered_array_set set2) {
  unordered_array_set set = UOAS_create(set1.size + set2.size);
  memcpy(set.data, set1.data, sizeof(int) * set1.size);
  set.size = set1.size;
  for (size_t i = 0; i < set2.size; i++) {
    UOAS_insert(&set, set2.data[i]);
  }
  return set;
}

// возвращает пересечение множеств set1 и set2
unordered_array_set UOAS_intersection(unordered_array_set set1,
                                      unordered_array_set set2) {
  unordered_array_set set = UOAS_create(set1.size);
  for (int i = 0; i < set1.size; i++) {
    size_t pos = linearSearch_(set2.data, set2.size, set1.data[i]);
    if (pos != set2.size)
      UOAS_insert(&set, set2.data[pos]);
  }
  return set;
}

// возвращает разность множеств set1 и set2
unordered_array_set UOAS_difference(unordered_array_set set1,
                                    unordered_array_set set2) {
  unordered_array_set set = UOAS_create(set1.size);
  for (int i = 0; i < set1.size; i++) {
    size_t pos = UOAS_in(&set2, set1.data[i]);
    if (pos == set2.size)
      UOAS_insert(&set, set1.data[i]);
  }
  return set;
}

// возвращает симметрическую разность множеств set1 и set2
unordered_array_set UOAS_symmetricDifference(unordered_array_set set1,
                                             unordered_array_set set2) {
  return UOAS_union(UOAS_difference(set1, set2),
                    UOAS_difference(set2, set1));
}

// возвращает значение "истина", если множество
// set является подмножеством subset
bool UOAS_isSubset(unordered_array_set set,
                   unordered_array_set subset) {
  for (int i = 0; i < subset.size; i++) {
    if (UOAS_in(&set, subset.data[i]) == set.size)
      return false;
  }
  return true;
}

// возвращает дополнение до универсума множества set
unordered_array_set UOAS_complement(unordered_array_set set,
                                    unordered_array_set universumSet) {
  assert(UOAS_isSubset(universumSet, set));
  return UOAS_difference(universumSet, set);
}

// вывод множества set
void UOAS_print(unordered_array_set set) {
  printf("{");
  if (set.size == 0)
    printf("}\n");
  else {
    for (int i = 0; i < set.size; i++) {
      printf("%d, ", set.data[i]);
    }
    printf("\b\b}\n");
  }
}

// освобождает память, занимаемую множеством set
void UOAS_delete(unordered_array_set set) {
  free(set.data);
}


class InToPost {
  private:
  stack<char> stackOperators;
  string postfixNotation;
  string input;

  public:
  explicit InToPost(string input) :
    input(std::move(input)) {};

  void gotOper(char oper, int priorityNew) {
    while (!this->stackOperators.empty()) {
      char topOperator = this->stackOperators.top();
      if (topOperator != '(') {
        int priorityTop;
        if (topOperator == '!')
          priorityTop = 1;
        else if (topOperator == '&')
          priorityTop = 2;
        else priorityTop = 3;

        if (priorityNew >= priorityTop) {
          this->postfixNotation += topOperator;
          this->stackOperators.pop();
        } else
          break;

      } else {
        break;
      }
    }
    this->stackOperators.push(oper);
  }

  void gotParen() {
    while (!this->stackOperators.empty()) {
      char i = this->stackOperators.top();
      this->stackOperators.pop();
      if (i == u'(')
        break;
      else
        this->postfixNotation += i;
    }
  }

  void makePostfixNotation(const string &infixNotation) {
    for (auto i: infixNotation) {
      switch (i) {
        case 'u':
        case '^':
        case '-':{
          gotOper(i, 3);
          break;
        }
        case '&':{
          gotOper(i, 2);
          break;
        }
        case '!': {
          gotOper(i, 1);
          break;
        }
        case '(': {
          this->stackOperators.push(i);
          break;
        }
        case ')': {
          gotParen();
          break;
        }
        default:
          postfixNotation += i;
      }

    }
    while (!this->stackOperators.empty()) {
      this->postfixNotation += this->stackOperators.top();
      this->stackOperators.pop();
    }
  }

  string getPostfixNotation() {
    makePostfixNotation(input);
    return this->postfixNotation;
  }
};

class SolverPost {
  private:
  int countSets;
  string postExpression;
  unordered_array_set X;
  int a[3] = {2,9,10};
  int b[5] = {1,2,8,9,10};
  int c[4] = {1,3,6,7};
  int d[10] = {1,2,3,4,5,6,7,8,9,10};

  unordered_array_set universum = UOAS_create_from_array(d, 10);
  vector<unordered_array_set> sets = {
    UOAS_create_from_array(a, 3),
    UOAS_create_from_array(b, 5),
    UOAS_create_from_array(c, 4),
  };
  stack<unordered_array_set> executionStack;

  public:
  void inputX(unordered_array_set x) {
    this->X = x;
  }

  unordered_array_set getUniversum() {
    return universum;
  }

  SolverPost(int numSets, string postExpression) :
    countSets(numSets), postExpression(std::move(postExpression)) {};

  unordered_array_set fi() {
    while (!this->executionStack.empty())
      this->executionStack.pop();

    int curIndex = 0;
    while (curIndex < postExpression.size()) {
      char curSymbol = this->postExpression[curIndex];
      if ('A' <= curSymbol && curSymbol <= 'Z') {
        if (curSymbol == 'U')
          this->executionStack.push(this->universum);
        else if (curSymbol == 'X')
          this->executionStack.push(this->X);
        else
          this->executionStack.push(this->sets[curSymbol - 'A']);
      } else {
        if (curSymbol == 'u') {
          unordered_array_set set1 = this->executionStack.top();
          this->executionStack.pop();
          unordered_array_set set2 = this->executionStack.top();
          this->executionStack.pop();

          this->executionStack.push(UOAS_union(set1, set2));

        } else if (curSymbol == '&') {
          unordered_array_set set1 = this->executionStack.top();
          this->executionStack.pop();
          unordered_array_set set2 = this->executionStack.top();
          this->executionStack.pop();

          this->executionStack.push(
            UOAS_intersection(set1, set2));

        } else if (curSymbol == '^') {
          unordered_array_set set1 = this->executionStack.top();
          this->executionStack.pop();
          unordered_array_set set2 = this->executionStack.top();
          this->executionStack.pop();

          this->executionStack.push(
            UOAS_symmetricDifference(set1, set2));

        } else if (curSymbol == '-') {
          unordered_array_set set1 = this->executionStack.top();
          this->executionStack.pop();
          unordered_array_set set2 = this->executionStack.top();
          this->executionStack.pop();

          this->executionStack.push(UOAS_difference(set2, set1));

        } else if (curSymbol == '!') {
          unordered_array_set set1 = this->executionStack.top();
          this->executionStack.pop();

          this->executionStack.push(
            UOAS_complement(set1, this->universum));
        }
      }
      curIndex++;
    }

    return executionStack.top();
  }
};

void printBinValue(int i, int numDigits) {
  for (int j = numDigits - 1; j >= 0; j--) {
    cout << ((i & (1 << j)) >> j);
  }
}

//#define FIRST
#define SECOND

int main() {
#ifdef FIRST
  string input = "(A-(X&B)u(C&!X))^((X-A)&(X-B)-C)";
  InToPost translator(input);
  SolverPost solver(3, translator.getPostfixNotation());
  int a[0];
  cout << translator.getPostfixNotation() << '\n';
  solver.inputX(UOAS_create_from_array(a, 0));
  unordered_array_set set = solver.fi();

  qsort(set.data, set.size, sizeof(int), compare_ints);
  for (int i = 0; i < set.size; i++) {
    cout << set.data[i] << " ";
  }
  cout << endl;

  InToPost translator2(input);
  SolverPost solver2(3, translator2.getPostfixNotation());
  int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  solver2.inputX(UOAS_create_from_array(b, 10));
  unordered_array_set set2 = solver2.fi();
  set2 = UOAS_complement(set2, UOAS_create_from_array(b, 10));

  qsort(set2.data, set2.size, sizeof(int), compare_ints);
  for (int i = 0; i < set2.size; i++) {
    cout << set2.data[i] << " ";
  }
#endif
#ifdef SECOND
  int a[] = {1,2,3,6,7,8,9,10};
  unordered_array_set x = UOAS_create_from_array(a, 8);
  string input = "(A-(X&B)u(C&!X))^((X-A)&(X-B)-C)";
  InToPost translator(input);
  SolverPost solver(8, translator.getPostfixNotation());
  solver.inputX(x);
  unordered_array_set set = solver.fi();

  if (set.size == 0)
    cout << "Is this solution";
  else
    cout << "Is not a solution";
  cout << endl;
#endif

  return 0;
}