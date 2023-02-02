#include <iostream>
#include <vector>
#include <set>
#include <ctime>
#include "binaryRelation.h"


using binaryRelationMatrixRow = std::vector<bool>;
using binaryRelation = std::vector<binaryRelationMatrixRow>;


binaryRelation binaryRelation_transitiveClosure_PowerUnion(
        const binaryRelation &A) {
    auto C = A;
    auto A_pow = binaryRelation_composition(A, A);
    for (int i = 2; i < A.size(); ++i) {
        C = binaryRelation_union(C, A_pow);
        A_pow = binaryRelation_composition(A_pow, A);
    }
    return C;
}

binaryRelation binaryRelation_transitiveClosure_Warshall(
        const binaryRelation &A) {
    size_t dimension = A.size();
    auto C = A;
    for (int z = 1; z < dimension; ++z)
        for (int x = 1; x < dimension; ++x)
            for (int y = 1; y < dimension; ++y)
                C[x][y] = C[x][y] || C[x][z] && C[z][y];
    return C;
}

////////////////////////////////////////

binaryRelation generateBinaryRelation(const size_t &start_x,
                                      const size_t &start_y,
                                      const size_t &nPairs,
                                      const size_t &setSize) {
    binaryRelation res(setSize + 1,
                       binaryRelationMatrixRow(setSize + 1, false));
    for (int i = 0; i < nPairs; ++i)
        res[(start_x + i / setSize)
            % setSize + 1][(start_y + i % setSize) % setSize + 1] = true;
    return res;
}

std::vector<binaryRelation> getGeneratedBR(const size_t &nPairs,
                                           const size_t &setSize,
                                           const size_t &nRelations = 10) {
    std::vector<binaryRelation> res;
    srand(time(nullptr));
    for (int i = 0; i < nRelations; ++i) {
        size_t x = rand() % setSize + 1;
        size_t y = rand() % setSize + 1;
        res.push_back(generateBinaryRelation(
                x, y, nPairs, setSize));
    }
    return res;
}

///////////////////////////////

#include <float.h>
#include <fstream>

#define TIME_TEST(testCode, time) { \
 clock_t start_time = clock(); \
 testCode \
 clock_t end_time = clock(); \
 clock_t sort_time = end_time - start_time; \
 time = sort_time * 1000.0 / CLOCKS_PER_SEC; \
}

void testTransitiveClosureAlgorithms(const size_t &setSize,
                                     std::ostream &out) {
    std::pair<binaryRelation (*)(const binaryRelation &),
            std::string> funcs[] = {
            {binaryRelation_transitiveClosure_PowerUnion, "Power Union"},
            {binaryRelation_transitiveClosure_Warshall,   "Warshall"}
    };
    std::vector<binaryRelation>
            relations[] = {
            getGeneratedBR(1, setSize),
            getGeneratedBR(setSize * setSize / 4, setSize),
            getGeneratedBR(setSize * setSize / 2, setSize),
            getGeneratedBR(setSize * setSize * 2 / 3, setSize),
            getGeneratedBR(setSize * setSize, setSize)};
    std::cout << "Relations generated" << '\n' << std::endl;
    for (const auto &func: funcs) {
        //out << func.second << ';';
        std::cout << "Testing: " << func.second << std::endl;
        for (const auto &rel_vector: relations) {
            double minTime = DBL_MAX;
            double maxTime = 0;
            for (const auto &rel: rel_vector) {
                double currTime;
                TIME_TEST(func.first(rel);, currTime)
                if (currTime > maxTime)
                    maxTime = currTime;
                else if (currTime < minTime)
                    minTime = currTime;
            }

            std::cout << "\n" << minTime << " " << maxTime << "\n\n";
            //out << minTime << " ms;" << maxTime << " ms;";
            std::cout << "Pair test passed" << std::endl;
        }
        // out << '\n';
        std::cout << std::endl;
    }
}

int main() {
    std::ofstream file("output.csv");
    for (int i = 50; i <= 150; i += 50) {
        testTransitiveClosureAlgorithms(i, file);
        std::cout << "\n\n\n" <<i<< "\n\n\n";
    }
    file.close();
    return 0;
}