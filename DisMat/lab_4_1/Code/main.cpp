#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using adjacencyMatrixRow = std::vector<bool>;
using adjacencyMatrix = std::vector<adjacencyMatrixRow>;

bool graph_isRoute(const adjacencyMatrix &m,
                   const std::vector<int> &verticesSequence) {
  for (int i = 1; i < verticesSequence.size(); ++i)
    if (!m[verticesSequence[i - 1] - 1][verticesSequence[i] - 1])
      return false;
  return true;
}

bool graph_isChain(const adjacencyMatrix &m,
                   const std::vector<int> &verticesSequence) {
  if (!graph_isRoute(m, verticesSequence))
    return false;
  std::map<int, int> edges;
  for (int i = 1; i < verticesSequence.size(); ++i) {
    if (edges[verticesSequence[i]] == verticesSequence[i - 1])
      return false;
    edges[verticesSequence[i - 1]] = verticesSequence[i];
  }
  return true;
}

bool graph_isSimpleChain(const adjacencyMatrix &m,
                         const std::vector<int> &verticesSequence) {
  if (!graph_isChain(m, verticesSequence))
    return false;
  std::set<int> uniqueVertices;
  for (const auto &vertex: verticesSequence)
    uniqueVertices.insert(vertex);
  return uniqueVertices.size() == verticesSequence.size();
}

bool graph_isCycle(const adjacencyMatrix &m,
                   const std::vector<int> &verticesSequence) {
  if (!graph_isChain(m, verticesSequence))
    return false;
  return verticesSequence.front() == verticesSequence.back();
}

bool graph_isSimpleCycle(const adjacencyMatrix &m,
                         const std::vector<int> &verticesSequence) {
  if (!graph_isCycle(m, verticesSequence))
    return false;
  std::set<int> uniqueVertices;
  for (const auto &vertex: verticesSequence)
    uniqueVertices.insert(vertex);
  return uniqueVertices.size() + 1 == verticesSequence.size();
}







std::set<int> graph_getAdjacentVertices(const adjacencyMatrix &m,
                                        const int vertex) {
  std::set<int> res;
  for (int i = 0; i < m.size(); ++i)
    if (m[vertex - 1][i])
      res.insert(i + 1);
  return res;
}

std::set<std::set<int>>
graph_getSetsOfAdjacentVertices(const adjacencyMatrix &m,
                                const std::set<int> &vertices) {
  std::set<std::set<int>> res;
  for (const auto &vertex: vertices)
    res.insert(graph_getAdjacentVertices(m, vertex));
  return res;
}

void graph__getRoutes(const size_t l,
                      std::vector<int> &currRoute,
                      std::set<std::vector<int>> &routes,
                      const adjacencyMatrix &m) {
  auto adjacentVertices = graph_getAdjacentVertices(m, currRoute.back());
  for (const auto &vertex: adjacentVertices) {
    currRoute.push_back(vertex);
    if (currRoute.size() == l + 1)
      routes.insert(currRoute);
    else
      graph__getRoutes(l, currRoute, routes, m);
    currRoute.pop_back();
  }
}

std::set<std::vector<int>> graph_getRoutes(const adjacencyMatrix &m,
                                           const int vertex,
                                           const size_t length) {
  if (0 >= vertex && vertex >= m.size())
    throw std::runtime_error("There is no such vertex in the graph");
  std::set<std::vector<int>> routes;
  std::vector<int> W1 = {vertex};
  graph__getRoutes(length, W1, routes, m);
  return routes;
}

void outputRoutes(adjacencyMatrix &m, int length) {
  std::cout << "{";
  for (int i = 1; i <= m.size(); ++i) {
    auto res = graph_getRoutes(m, i, length);
    for (auto &set: res) {
      std::cout << "{";
      for (auto &elem: set) {
        std::cout << elem << ", ";
      }
      std::cout << "\b\b}, ";
    }
  }
  std::cout << "}\n\n";
}








void graph__getRoutesAmount(const int v,
                            const size_t l,
                            std::vector<int> &currRoute,
                            std::vector<std::vector<int>> &R,
                            const adjacencyMatrix &m) {
  auto adjacentVertices = graph_getAdjacentVertices(m, currRoute.back());
  for (const auto &vertex: adjacentVertices) {
    currRoute.push_back(vertex);
    if (currRoute.size() == l + 1)
      R[v][currRoute.back() - 1]++;
    else
      graph__getRoutesAmount(v, l, currRoute, R, m);
    currRoute.pop_back();
  }
}
std::vector<std::vector<int>> graph_getRoutesAmount(const adjacencyMatrix &m,
                                                    const size_t length) {
  auto size = m.size();
  std::vector<std::vector<int>> R(size,
                                  std::vector<int>(size, 0));
  for (int i = 0; i < size; ++i) {
    std::vector<int> W1 = {i + 1};
    graph__getRoutesAmount(i, length, W1, R, m);
  }
  return R;
}

template<typename T>
std::vector<std::vector<T>>
multiplyMatrices(const std::vector<std::vector<T>> &m1,
                 const std::vector<std::vector<T>> &m2) {
  std::vector<std::vector<T>> res(m1.size(),
                                  std::vector<T>(m2[0].size(), 0));
  for (int i = 0; i < m1.size(); ++i)
    for (int j = 0; j < m2[0].size(); ++j)
      for (int k = 0; k < m1[0].size(); ++k)
        res[i][j] += m1[i][k] * m2[k][j];
  return res;
}
template<typename T>
std::vector<std::vector<T>>
getIdenticalMatrix(const size_t size) {
  std::vector<std::vector<T>> res(size,
                                  std::vector<T>(size, 0));
  for (int i = 0; i < size; ++i)
    res[i][i] = 1;
  return res;
}
template<typename T>
std::vector<std::vector<T>>
powMatrix(std::vector<std::vector<T>> matrix,
          size_t power) {
  std::vector<std::vector<T>> res =
          getIdenticalMatrix<T>(matrix.size());
  std::vector<std::vector<T>> currPowOf2 = matrix;
  while (power) {
    if (power & 1)
      res = multiplyMatrices(res, currPowOf2);
    currPowOf2 = multiplyMatrices(currPowOf2, currPowOf2);
    power >>= 1;
  }
  return res;
}
std::vector<std::vector<int>>
graph_getRoutesAmountByAdjacencyMatrix(const adjacencyMatrix &m,
                                       const size_t length) {
  std::vector<std::vector<int>> R(m.size(),
                                  std::vector<int>(m.size()));
  for (int i = 0; i < m.size(); ++i)
    for (int j = 0; j < m.size(); ++j)
      R[i][j] = m[i][j];
  return powMatrix(R, length);
}








void graph__getRoutesBetweenVertices(const size_t l,
                                     const int vertexEnd,
                                     std::vector<int> &currRoute,
                                     std::set<std::vector<int>> &routes,
                                     const adjacencyMatrix &m) {
  auto adjacentVertices = graph_getAdjacentVertices(m, currRoute.back());
  for (const auto &vertex: adjacentVertices) {
    currRoute.push_back(vertex);
    if (currRoute.size() == l + 1) {
      if (currRoute.back() == vertexEnd)
        routes.insert(currRoute);
    } else
      graph__getRoutesBetweenVertices(l, vertexEnd,
                                      currRoute, routes, m);
    currRoute.pop_back();
  }
}
std::set<std::vector<int>>
graph_getRoutesBetweenVertices(const adjacencyMatrix &m,
                               const int vertex1,
                               const int vertex2,
                               const size_t length) {
  if (0 >= vertex1 && vertex1 >= m.size() ||
      0 >= vertex2 && vertex2 >= m.size())
    throw std::runtime_error("There is no such vertex in the graph");
  std::set<std::vector<int>> routes;
  std::vector<int> W1 = {vertex1};
  graph__getRoutesBetweenVertices(length, vertex2, W1, routes, m);
  return routes;
}

void outputRoutesBetweenVertices(adjacencyMatrix &m, int length, int from, int to) {
  auto res = graph_getRoutesBetweenVertices(m, from, to, length);
  for (auto &set: res) {
    std::cout << "{ ";
    for (auto &elem: set) {
      std::cout << elem << ' ';
    }
    std::cout << "}\n";
  }
  std::cout << "\n";
}










void graph__getMaxSimpleChain(std::vector<int> &currRoute,
                              std::set<int> &V,
                              std::set<std::vector<int>> &routes,
                              const adjacencyMatrix &m) {
  auto adjacentVertices = graph_getAdjacentVertices(m, currRoute.back());
  std::set<int> remainingVertices;
  std::set_difference(adjacentVertices.begin(), adjacentVertices.end(),
                      V.begin(), V.end(),
                      std::inserter(remainingVertices,
                                    remainingVertices.begin()));

  for (const auto &vertex: remainingVertices) {
    currRoute.push_back(vertex);
    auto newAdjacentVertices = graph_getAdjacentVertices(m,
                                                         currRoute.back());
    if (std::includes(V.begin(), V.end(),
                      newAdjacentVertices.begin(),
                      newAdjacentVertices.end()))
      routes.insert(currRoute);
    else {
      V.insert(vertex);
      graph__getMaxSimpleChain(currRoute, V, routes, m);
      V.erase(vertex);
    }
    currRoute.pop_back();
  }
}
std::set<std::vector<int>> graph_getMaxSimpleChain(const adjacencyMatrix &m,
                                                   const int vertex) {
  if (0 >= vertex && vertex >= m.size())
    throw std::runtime_error("There is no such vertex in the graph");
  std::set<std::vector<int>> routes;
  std::vector<int> W1 = {vertex};
  std::set<int> V = {vertex};
  graph__getMaxSimpleChain(W1, V, routes, m);
  return routes;
}

void outputMaxSimpleChain(adjacencyMatrix &m, int vertex) {
  auto res =
          graph_getMaxSimpleChain(m, vertex);
  for (auto &set: res) {
    std::cout << "{ ";
    for (auto &elem: set) {
      std::cout << elem << ' ';
    }
    std::cout << "}\n";
  }
  std::cout << "\n";
}



int main() {
  adjacencyMatrix m1 = {{0, 1, 0, 1, 0, 1, 1},
                        {1, 0, 0, 0, 1, 1, 0},
                        {0, 0, 0, 1, 0, 0, 0},
                        {1, 0, 1, 0, 0, 0, 0},
                        {1, 1, 0, 0, 0, 0, 0},
                        {1, 1, 0, 0, 0, 0, 1},
                        {1, 0, 0, 0, 0, 1, 0}};

  adjacencyMatrix m2 = {{0, 1, 1, 0, 0, 0, 0},
                        {1, 0, 0, 0, 0, 1, 1},
                        {1, 0, 0, 1, 1, 1, 0},
                        {0, 0, 1, 0, 1, 1, 0},
                        {0, 0, 1, 1, 0, 1, 0},
                        {0, 1, 1, 0, 1, 0, 1},
                        {0, 1, 0, 0, 0, 1, 0}};

  std::vector<adjacencyMatrix> matrices = {m1, m2};
  int vertex;
  std::cin >> vertex;

  std::cout << "G1:\n";
  outputMaxSimpleChain(m1, vertex);
  std::cout << "G2:\n";
  outputMaxSimpleChain(m1, vertex);

  return 0;
}