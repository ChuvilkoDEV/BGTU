#include <iostream>
#include <vector>
#include "algorithm"

#include "BinaryRelations/BinaryRelations.h"

using namespace std;

binaryRelation
getRelationFromPoints(const vector<pair<int, int>> &points) {
    auto dimension = points.size();
    binaryRelation res(dimension, binaryRelationMatrixRow(dimension, false));
    for (int a = 1; a < dimension; ++a) {
        for (int b = 1; b < dimension; ++b) {
            if (points[a].first < points[b].first &&
                points[a].second <= points[b].second) {
                res[a][b] = true;
            }
        }
    }
    return res;
}

binaryRelation
binaryRelation_getDominanceRelation(const binaryRelation &relation) {
    auto dimension = relation.size();
    auto res = relation;
    for (int i = 1; i < dimension; ++i)
        res[i][i] = false;
    for (int z = 1; z < dimension; ++z)
        for (int x = 1; x < dimension; ++x)
            for (int y = 1; y < dimension; ++y)
                if (res[x][z] && res[z][y])
                    res[x][y] = false;
    return res;
}



vector<vector<int>>
binaryRelation_topologicalSort(const binaryRelation &relation) {
    binaryRelation dominanceRelation =
            binaryRelation_getDominanceRelation(relation);
    auto dimension = relation.size();

    vector<int> W(dimension, 0);
    for (int a = 1; a < dimension; ++a)
        for (int b = 1; b < dimension; ++b)
            W[a] += dominanceRelation[b][a];
    std::vector<std::vector<int>> levels;
    while (std::find_if(W.begin() + 1, W.end(),
                        [&](const auto &item) {
                            return item >= 0;
                        }) != W.end()) {
        levels.emplace_back();
        for (int i = 1; i < dimension; ++i) {
            if (!W[i]) {
                levels.back().push_back(i);
                W[i] = -1;
            }
        }
        for (const auto &a: levels.back())
            for (int b = 1; b < dimension; ++b)
                W[b] -= dominanceRelation[a][b];
    }
    return levels;
}

void outputVector(vector<pair<int, int>> m, vector<vector<int>> &a) {
    for (auto & i : a) {
        for (int j : i) {
            cout << "(" << m[j].first << "; " << m[j].second << ") ";
        }
        cout << '\n';
    }
}

int main() {
    vector<pair<int, int>> M1 = {{INT32_MIN, INT32_MIN},
                                 {-1, -1}, {-1, 0}, {-1, 1},
                                 {0,  -1}, {0,  0}, {0,  1},
                                 {1,  -1}, {1,  0}, {1,  1}};
    vector<pair<int, int>> M2 = {{INT32_MIN, INT32_MIN},
                                 {-2, 0},
                                 {-1, -1}, {-1, 0},
                                 {-1, 1}, {0,  -2}, {0,  -1}, {0,  0}, {0,  1}, {0,  2},
                                 {1,  -1}, {1,  0}, {1,  1},
                                 {2,  0}};

    auto relationOnM1 = getRelationFromPoints(M1);
    auto relationOnM2 = getRelationFromPoints(M2);

    auto M1Levels = binaryRelation_topologicalSort(relationOnM1);
    auto M2Levels = binaryRelation_topologicalSort(relationOnM2);

    cout << "Relation On M1 Topological Sort:\n";
    outputVector(M1, M1Levels);
    cout << "\nRelation On M2 Topological Sort:\n";
    outputVector(M2, M2Levels);

    return 0;
}