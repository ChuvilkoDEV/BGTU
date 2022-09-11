#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

#define K_MAX_ELEMENTS 2

using namespace std;

struct Friend {
  int height;
  int width;
};

template<typename T>
vector<int> getNMaxInSequence(const vector<T> &a, size_t k) {
  assert(k <= a.size());

  // создание приоритетной очереди, в которой
  // выталкивается элемент с наименьшим значением
  priority_queue<int, vector<int>, greater<> > q;

  // заталкиваем первые k элементов вектора
  for (int i = 0; i < K_MAX_ELEMENTS; ++i)
    q.push(a[i].height);

  // для всех i ∈ {k, k + 1, ..., n - 2, n - 1}
  // - сравнить наименьший элемент кучи с a[i]
  // - если a[i] окажется больше, ’вытащить’
  // наименьший элемент кучи и вставить текущее a[i]
  for (int i = K_MAX_ELEMENTS; i < k; ++i)
    if (a[i].height > q.top()) {
      q.pop();
      q.push(a[i].height);
    }

  // пока куча не пуста
  // - вытолкнуть все элементы из кучи в вектор
  vector<int> kMaxElements;
  while (!q.empty()) {
    kMaxElements.push_back(q.top());
    q.pop();
  }

  return kMaxElements;
}

int main() {
  int countOfFriends;
  cin >> countOfFriends;

  long long sumWidth = 0;
  vector<Friend> friends(countOfFriends);
  for (auto &i: friends) {
    cin >> i.width >> i.height;
    sumWidth += i.width;
  }

  vector<int> maxHeights = getNMaxInSequence(friends, countOfFriends);

  for (auto i: friends) {
    long long pixelSize;
    if (i.height == maxHeights[K_MAX_ELEMENTS - 1])
      pixelSize = maxHeights[K_MAX_ELEMENTS - 2] * (sumWidth - i.width);
    else
      pixelSize = maxHeights[K_MAX_ELEMENTS - 1] * (sumWidth - i.width);

    cout << pixelSize << ' ';
  }

  return 0;
};