#include <iostream>
#include <vector>
#include <set>
#include "algorithm"

#include "BinaryRelations/BinaryRelations.h"

using namespace std;

set<int> binaryRelation_getEquivalenceClass(const int &x,
                                            const binaryRelation &R) {
    auto dimension = R.size();
    if (x < 1 || x >= dimension)
        throw runtime_error("Value is not included into binary relation\n");
    set<int> res;
    for (int y = 1; y < dimension; ++y)
        if (R[y][x])
            res.insert(y);
    return res;
}

set<set<int>> binaryRelation_factorize(const binaryRelation &R) {
    auto dimension = R.size();
    set<int> A;
    for (int x = 1; x < dimension; ++x)
        A.insert(x);
    set<set<int>> S;
    while (!A.empty()) {
        auto eqClass = binaryRelation_getEquivalenceClass(*A.begin(), R);
        S.insert(eqClass);
        set<int> tmp;
        set_difference(A.begin(), A.end(),
                       eqClass.begin(), eqClass.end(),
                       std::inserter(tmp, tmp.begin()));
        A = tmp;
    }
    return S;
}

binaryRelation getRelation() {
    binaryRelation res(11, binaryRelationMatrixRow(11, false));
    for (int x = 1; x < 11; ++x)
        for (int y = 1; y < 11; ++y)
            if (abs(x - y) % 4 == 0 || x == y)
                res[x][y] = true;

    return res;
}

int main() {
    auto A = getRelation();
    auto factorset = binaryRelation_factorize(A);
    cout << "\nClasses of equivalence:\n";
    for (const auto &set: factorset) {
        cout << "{ ";
        for (const auto &element: set) {
            cout << element << ' ';
        }
        cout << "}\n";
    }
    return 0;
}