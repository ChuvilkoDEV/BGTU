#ifndef CODE_BINARYRELATION_H
#define CODE_BINARYRELATION_H

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

#endif //CODE_BINARYRELATION_H
