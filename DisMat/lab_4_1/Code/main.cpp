#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

using GraphRow = vector<bool>;
using Graph = vector<GraphRow>;

// Возвращает true, если последовательности вершин являются маршрутом
bool graphIsRoute(const Graph &g, const vector<int> &vertices) {
  for (int i = 1; i < vertices.size(); ++i)
    if (!g[vertices[i - 1] - 1][vertices[i] - 1])
      return false;
  return true;
}

// Возвращает true, если последовательности вершин являются цепью
bool graphIsChain(const Graph &m, const vector<int> &vertices) {
  if (!graphIsRoute(m, vertices))
    return false;
  map<int, int> edges;
  for (int i = 1; i < vertices.size(); ++i) {
    if (edges[vertices[i]] == vertices[i - 1])
      return false;
    edges[vertices[i - 1]] = vertices[i];
  }
  return true;
}

// Возвращает true, если последовательности вершин являются простой цепью
bool graphIsSimpleChain(const Graph &m,
                        const vector<int> &verticesSequence) {
  if (!graphIsChain(m, verticesSequence))
    return false;
  set<int> uniqueVertices;
  for (const auto &vertex: verticesSequence)
    uniqueVertices.insert(vertex);
  return uniqueVertices.size() == verticesSequence.size();
}

// Возвращает true, если последовательности вершин являются циклом
bool graphIsCycle(const Graph &m,
                  const vector<int> &verticesSequence) {
  if (!graphIsChain(m, verticesSequence))
    return false;
  return verticesSequence.front() == verticesSequence.back();
}

// Возвращает true, если последовательности вершин являются простым циклом
bool graphIsSimpleCycle(const Graph &m,
                        const vector<int> &verticesSequence) {
  if (!graphIsCycle(m, verticesSequence))
    return false;
  set<int> uniqueVertices;
  for (const auto &vertex: verticesSequence)
    uniqueVertices.insert(vertex);
  return uniqueVertices.size() + 1 == verticesSequence.size();
}

//////////////////////////////////////////////////

// Возвращает смежный граф
set<int> graphGetAdjacent(const Graph &m, const int vertex) {
  set<int> res;
  for (int i = 0; i < m.size(); ++i)
    if (m[vertex - 1][i])
      res.insert(i + 1);
  return res;
}

set<set<int>> graphGetSetsOfAdjacentVertices(const Graph &m, const set<int> &vertices) {
  set<set<int>> res;
  for (const auto &vertex: vertices)
    res.insert(graphGetAdjacent(m, vertex));
  return res;
}

void graphGetRoutes_(const size_t l, vector<int> &currRoute,
                     set<vector<int>> &routes, const Graph &m) {
  auto adjacentVertices = graphGetAdjacent(m, currRoute.back());
  for (const auto &vertex: adjacentVertices) {
    currRoute.push_back(vertex);
    if (currRoute.size() == l + 1)
      routes.insert(currRoute);
    else
      graphGetRoutes_(l, currRoute, routes, m);
    currRoute.pop_back();
  }
}

set<vector<int>> graphGetRoutes(const Graph &m, const int vertex, const size_t length) {
  if (0 >= vertex && vertex >= m.size())
    throw runtime_error("There is no such vertex in the graph");
  set<vector<int>> routes;
  vector<int> W1 = {vertex};
  graphGetRoutes_(length, W1, routes, m);
  return routes;
}

void outputRoutes(Graph &m, int length) {
  cout << "{";
  for (int i = 1; i <= m.size(); ++i) {
    auto res = graphGetRoutes(m, i, length);
    for (auto &set: res) {
      cout << "{";
      for (auto &elem: set) {
        cout << elem << ", ";
      }
      cout << "\b\b}, ";
    }
  }
  cout << "}\n\n";
}

///////////////////////////////////////////////



void graphGetRoutesAmount_(const int v, const size_t l, vector<int> &currRoute,
                           vector<vector<int>> &R, const Graph &m) {
  auto adjacentVertices = graphGetAdjacent(m, currRoute.back());
  for (const auto &vertex: adjacentVertices) {
    currRoute.push_back(vertex);
    if (currRoute.size() == l + 1)
      R[v][currRoute.back() - 1]++;
    else
      graphGetRoutesAmount_(v, l, currRoute, R, m);
    currRoute.pop_back();
  }
}

vector<vector<int>> graphGetRoutesAmount(const Graph &m, const size_t length) {
  auto size = m.size();
  vector<vector<int>> R(size, vector<int>(size, 0));
  for (int i = 0; i < size; ++i) {
    vector<int> W1 = {i + 1};
    graphGetRoutesAmount_(i, length, W1, R, m);
  }
  return R;
}

template<typename T>
vector<vector<T>> multiplyMatrices(const vector<vector<T>> &m1, const vector<vector<T>> &m2) {
  vector<vector<T>> res(m1.size(), vector<T>(m2[0].size(), 0));
  for (int i = 0; i < m1.size(); ++i)
    for (int j = 0; j < m2[0].size(); ++j)
      for (int k = 0; k < m1[0].size(); ++k)
        res[i][j] += m1[i][k] * m2[k][j];
  return res;
}

template<typename T>
vector<vector<T>> getIdenticalMatrix(const size_t size) {
  vector<vector<T>> res(size, vector<T>(size, 0));
  for (int i = 0; i < size; ++i)
    res[i][i] = 1;
  return res;
}

template<typename T>
vector<vector<T>> powMatrix(vector<vector<T>> matrix, size_t power) {
  vector<vector<T>> res = getIdenticalMatrix<T>(matrix.size());
  vector<vector<T>> currPowOf2 = matrix;
  while (power) {
    if (power & 1)
      res = multiplyMatrices(res, currPowOf2);
    currPowOf2 = multiplyMatrices(currPowOf2, currPowOf2);
    power >>= 1;
  }
  return res;
}

vector<vector<int>> graphGetRoutesAmountByAdjacencyMatrix
        (const Graph &m, const size_t length) {
  vector<vector<int>> R(m.size(), vector<int>(m.size()));
  for (int i = 0; i < m.size(); ++i)
    for (int j = 0; j < m.size(); ++j)
      R[i][j] = m[i][j];
  return powMatrix(R, length);
}


////////////////////////////////////////////////////

void graphGetRoutesBetweenVertices_(const size_t l,
                                    const int vertexEnd,
                                    vector<int> &currRoute,
                                    set<vector<int>> &routes,
                                    const Graph &m) {
  auto adjacentVertices = graphGetAdjacent(m, currRoute.back());
  for (const auto &vertex: adjacentVertices) {
    currRoute.push_back(vertex);
    if (currRoute.size() == l + 1) {
      if (currRoute.back() == vertexEnd)
        routes.insert(currRoute);
    } else
      graphGetRoutesBetweenVertices_(l, vertexEnd, currRoute, routes, m);
    currRoute.pop_back();
  }
}

set<vector<int>> graphGetRoutesBetweenVertices(const Graph &m,
                                               const int vertex1,
                                               const int vertex2,
                                               const size_t length) {
  if (0 >= vertex1 && vertex1 >= m.size() ||
      0 >= vertex2 && vertex2 >= m.size())
    throw runtime_error("There is no such vertex in the graph");
  set<vector<int>> routes;
  vector<int> W1 = {vertex1};
  graphGetRoutesBetweenVertices_(length, vertex2, W1, routes, m);
  return routes;
}

void outputRoutesBetweenVertices(Graph &m, int length, int from, int to) {
  auto res = graphGetRoutesBetweenVertices(m, from, to, length);
  for (auto &set: res) {
    cout << "{ ";
    for (auto &elem: set) {
      cout << elem << ' ';
    }
    cout << "}\n";
  }
  cout << "\n";
}

/////////////////////////////////////

void graphGetMaxSimpleChain_(vector<int> &currRoute, set<int> &V,
                             set<vector<int>> &routes, const Graph &m) {
  auto adjacentVertices = graphGetAdjacent(m, currRoute.back());
  set<int> remainingVertices;
  set_difference(adjacentVertices.begin(), adjacentVertices.end(),
                 V.begin(), V.end(),
                 inserter(remainingVertices, remainingVertices.begin()));

  for (const auto &vertex: remainingVertices) {
    currRoute.push_back(vertex);
    auto newAdjacentVertices = graphGetAdjacent(m,
                                                currRoute.back());
    if (includes(V.begin(), V.end(),
                 newAdjacentVertices.begin(),
                 newAdjacentVertices.end()))
      routes.insert(currRoute);
    else {
      V.insert(vertex);
      graphGetMaxSimpleChain_(currRoute, V, routes, m);
      V.erase(vertex);
    }
    currRoute.pop_back();
  }
}

set<vector<int>> graph_getMaxSimpleChain(const Graph &m, const int vertex) {
  if (0 >= vertex && vertex >= m.size())
    throw runtime_error("There is no such vertex in the graph");
  set<vector<int>> routes;
  vector<int> W1 = {vertex};
  set<int> V = {vertex};
  graphGetMaxSimpleChain_(W1, V, routes, m);
  return routes;
}

void outputMaxSimpleChain(Graph &m, int vertex) {
  auto res = graph_getMaxSimpleChain(m, vertex);
  for (auto &set: res) {
    cout << "{ ";
    for (auto &elem: set) {
      cout << elem << ' ';
    }
    cout << "}\n";
  }
  cout << "\n";
}


int main() {
  Graph m1 = {{0, 1, 0, 1, 0, 1, 1},
                        {1, 0, 0, 0, 1, 1, 0},
                        {0, 0, 0, 1, 0, 0, 0},
                        {1, 0, 1, 0, 0, 0, 0},
                        {1, 1, 0, 0, 0, 0, 0},
                        {1, 1, 0, 0, 0, 0, 1},
                        {1, 0, 0, 0, 0, 1, 0}};

  Graph m2 = {{0, 1, 1, 0, 0, 0, 0},
                        {1, 0, 0, 0, 0, 1, 1},
                        {1, 0, 0, 1, 1, 1, 0},
                        {0, 0, 1, 0, 1, 1, 0},
                        {0, 0, 1, 1, 0, 1, 0},
                        {0, 1, 1, 0, 1, 0, 1},
                        {0, 1, 0, 0, 0, 1, 0}};

  vector<Graph> matrices = {m1, m2};
  int vertex;
  cin >> vertex;

  cout << "G1:\n";
  outputMaxSimpleChain(m1, vertex);

  cout << "G2:\n";
  outputMaxSimpleChain(m1, vertex);

  return 0;
}