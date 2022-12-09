#ifndef CODE_BINARYRELATIONS_H
#define CODE_BINARYRELATIONS_H

#include <iostream>
#include <vector>
#include <set>

using binaryRelationMatrixRow = std::vector<bool>;
using binaryRelation = std::vector<binaryRelationMatrixRow>;


bool binaryRelation_equality(const binaryRelation &A,
                             const binaryRelation &B);

bool binaryRelation_inclusion(const binaryRelation &A,
                              const binaryRelation &B);

binaryRelation binaryRelation_union(const binaryRelation &A,
                                    const binaryRelation &B);

binaryRelation binaryRelation_intersection(const binaryRelation &A,
                                           const binaryRelation &B);

binaryRelation binaryRelation_difference(const binaryRelation &A,
                                         const binaryRelation &B);

binaryRelation binaryRelation_symmetricDifference(const binaryRelation &A,
                                                  const binaryRelation &B);

binaryRelation binaryRelation_complement(const binaryRelation &A);

binaryRelation binaryRelation_composition(const binaryRelation &A,
                                          const binaryRelation &B);

#endif //CODE_BINARYRELATIONS_H
