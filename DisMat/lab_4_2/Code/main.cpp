#include "iostream"
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <ctime>
#include <random>

bool isExist(const std::vector<int> &adjacencyVector, const int &value) {
  for (auto &adjacency: adjacencyVector) {
    if (adjacency == value) {
      return true;
    }
  }
  return false;
}

void _generateGraph(Graph &graph, const size_t &verticesNumber, const size_t
&edgesNumber) {
  if (edgesNumber > (verticesNumber * (verticesNumber - 1) / 2)) {
    std::cerr << "Unable to build a graph with the specified number of
    vertices and edges\n";
    exit(1);
  }
  std::srand(std::time(0));
  std::set<int> randVertex;
  std::vector<int> initAdjacency;
  for (int i = 0; i < verticesNumber; i++) {
    int randValue = std::rand() % 1000;
    if (randVertex.find(randValue) != randVertex.end()) {
      i--;
    } else {
      randVertex.insert(randValue);
      graph.insert({randValue, initAdjacency});
    }
  }
  for (auto &value: randVertex) {
    initAdjacency.push_back(value);
  }
  for (int i = 0; i < edgesNumber; i++) {
    size_t randIndexFirstVertex = std::rand() % verticesNumber;
    size_t randIndexSecondVertex = std::rand() % verticesNumber;
    if ((randIndexFirstVertex != randIndexSecondVertex)
        && !isExist(graph.at(initAdjacency.at(randIndexFirstVertex)),
                    initAdjacency.at(randIndexSecondVertex))) {
      graph.at(initAdjacency.at(randIndexFirstVertex)).push_back(initAdjacency.at(r
      andIndexSecondVertex));
      graph.at(initAdjacency.at(randIndexSecondVertex)).push_back(initAdjacency.at(
              randIndexFirstVertex));
    } else {
      i--;
    }
  }
}

Graph generateGraph(const size_t &verticesNumber, const size_t &edgesNumber){
  Graph graph;
  _generateGraph(graph, verticesNumber, edgesNumber);
  return graph;
}

bool isEulerGraph(const Graph &graph) {
  for (auto &x: graph) {
    if (x.second.size() % 2 == 1) {
      return false;
    }
  }
  return true;
}

bool isHamiltonianGraph(const Graph &graph) {
  if (graph.size() >= 3) {
    for (auto &x: graph) {
      if (x.second.size() < (graph.size() / 2)) {
        return false;
      }
    }
  } else {
    return false;
  }
  return true;
}

void exercise(const size_t &verticesNumber) {
  size_t maxEdgesNumber = verticesNumber * (verticesNumber - 1) / 2;
  for (size_t i = verticesNumber; i <= maxEdgesNumber; i++) {
    auto untilMoment {std::chrono::high_resolution_clock::now() +
                      std::chrono::seconds(10)};
    size_t hamiltonianCounter = 0;
    size_t eulerCounter = 0;
    size_t generalCounter = 0;
    while (std::chrono::high_resolution_clock::now() < untilMoment) {
      Graph graph = generateGraph(verticesNumber, i);
      hamiltonianCounter += isHamiltonianGraph(graph);
      eulerCounter += isEulerGraph(graph);
      generalCounter++;
    }
    std::cout << "\tInformation about " << i << "-edges graph\n";
    std::cout << "-Hamiltonian: " << hamiltonianCounter
              << "; Euler: " << eulerCounter
              << "; Total: " << generalCounter << '\n';
  }
}


int main() {
  exercise(8);
  return 0;
}