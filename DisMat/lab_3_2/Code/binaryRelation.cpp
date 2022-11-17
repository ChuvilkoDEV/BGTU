#include <iostream>
#include <vector>
#include <set>

using binaryRelationMatrixRow = std::vector<bool>;
using binaryRelation = std::vector<binaryRelationMatrixRow>;

bool binaryRelation_equality(const binaryRelation &A,
                             const binaryRelation &B) {
  auto dimension = A.size();
  if (dimension != B.size())
    return false;
  for (int i = 1; i < dimension; ++i)
    for (int j = 1; j < dimension; ++j)
      if (A[i][j] != B[i][j])
        return false;
  return true;
}

bool binaryRelation_inclusion(const binaryRelation &A,
                              const binaryRelation &B) {
  auto dimension = A.size();
  if (dimension != B.size())
    return false;
  for (int i = 1; i < dimension; ++i)
    for (int j = 1; j < dimension; ++j)
      if (A[i][j] > B[i][j])
        return false;
  return true;
}

binaryRelation binaryRelation_union(const binaryRelation &A,
                                    const binaryRelation &B) {
  auto dimension = A.size();
  if (dimension != B.size())
    throw std::runtime_error("Different relations' dimensions are forbidden");
  auto C = binaryRelation(dimension,
                          binaryRelationMatrixRow(dimension));
  for (int i = 1; i < dimension; ++i)
    for (int j = 1; j < dimension; ++j)
      C[i][j] = A[i][j] || B[i][j];
  return C;
}

binaryRelation binaryRelation_intersection(const binaryRelation &A,
                                           const binaryRelation &B) {
  auto dimension = A.size();
  if (dimension != B.size())
    throw std::runtime_error("Different relations' dimensions are forbidden");
  auto C = binaryRelation(dimension,
                          binaryRelationMatrixRow(dimension));
  for (int i = 1; i < dimension; ++i)
    for (int j = 1; j < dimension; ++j)
      C[i][j] = A[i][j] && B[i][j];
  return C;
}

binaryRelation binaryRelation_difference(const binaryRelation &A,
                                         const binaryRelation &B) {
  auto dimension = A.size();
  if (dimension != B.size())
    throw std::runtime_error("Different relations' dimensions are forbidden");
  auto C = binaryRelation(dimension,
                          binaryRelationMatrixRow(dimension));
  for (int i = 1; i < dimension; ++i)
    for (int j = 1; j < dimension; ++j)
      C[i][j] = A[i][j] > B[i][j];
  return C;
}

binaryRelation binaryRelation_symmetricDifference(const binaryRelation &A,
                                                  const binaryRelation &B) {
  auto dimension = A.size();
  if (dimension != B.size())
    throw std::runtime_error("Different relations' dimensions are forbidden");
  auto C = binaryRelation(dimension,
                          binaryRelationMatrixRow(dimension));
  for (int i = 1; i < dimension; ++i)
    for (int j = 1; j < dimension; ++j)
      C[i][j] = A[i][j] != B[i][j];
  return C;
}

binaryRelation binaryRelation_complement(const binaryRelation &A) {
  auto dimension = A.size();
  auto C = binaryRelation(dimension,
                          binaryRelationMatrixRow(dimension));
  for (int i = 1; i < dimension; ++i)
    for (int j = 1; j < dimension; ++j)
      C[i][j] = !A[i][j];
  return C;
}

binaryRelation binaryRelation_converse(const binaryRelation &A) {
  auto dimension = A.size();
  auto C = binaryRelation(dimension,
                          binaryRelationMatrixRow(dimension));
  for (int i = 1; i < dimension; ++i)
    for (int j = 1; j < dimension; ++j)
      C[i][j] = A[j][i];
  return C;
}

binaryRelation binaryRelation_composition(const binaryRelation &A,
                                          const binaryRelation &B) {
  auto dimension = A.size();
  if (dimension != B.size())
    throw std::runtime_error("Different relations' dimensions are forbidden");
  auto C = binaryRelation(dimension,
                          binaryRelationMatrixRow(dimension, false));
  for (int i = 1; i < dimension; ++i)
    for (int j = 1; j < dimension; ++j) {
      int k = 1;
      while (k++ < dimension && !C[i][j])
        C[i][j] = C[i][j] || A[i][k] && B[k][j];
    }
  return C;
}
