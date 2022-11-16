#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>

static bool **I;

bool IsVoid(int N, bool **A) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (A[i][j])
        return false;
    }
  }

  return true;
}

bool IsUniversum(int N, bool **A) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (!A[i][j])
        return false;
    }
  }

  return true;
}

bool **CreateRelation(int sizeX, int sizeY) {
  bool **A = (bool **) malloc(sizeX * sizeof(bool *));
  for (int i = 0; i < sizeX; ++i) {
    A[i] = (bool *) calloc(sizeY, sizeof(bool));
  }

  return A;
}

void FillRelation(int N, bool **A, bool a[N][N]) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      A[i][j] = a[i][j];
    }
  }
}

bool AreRelationsEquals(int N, bool **A, bool **B) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (A[i][j] != B[i][j])
        return false;
    }
  }
  return true;
}

bool IsIncluding(int N, bool **A, bool **B) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (A[i][j] == 1 && A[i][j] != B[i][j])
        return false;
    }
  }
  return true;
}

bool IsStrictIncluding(int N, bool **A, bool **B) {
  return (!AreRelationsEquals(N, A, B) && IsIncluding(N, A, B));
}

bool **NegativeRelation(int N, bool **A) {
  bool **B = CreateRelation(N, N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      B[i][j] = !A[i][j];
    }
  }
  return B;
}

bool **UnionRelations(int N, bool **A, bool **B) {
  bool **C = CreateRelation(N, N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (A[i][j] || B[i][j])
        C[i][j] = true;
    }
  }

  return C;
}

bool **IntersectionRelations(int N, bool **A, bool **B) {
  bool **C = CreateRelation(N, N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (A[i][j] && B[i][j])
        C[i][j] = true;
    }
  }

  return C;
}

bool **DifferenceRelations(int N, bool **A, bool **B) {
  bool **C = CreateRelation(N, N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (A[i][j] > B[i][j])
        C[i][j] = true;
    }
  }

  return C;
}

bool **SymmetricalDifferenceRelations(int N, bool **A, bool **B) {
  return UnionRelations(N, DifferenceRelations(N, A, B),
                        DifferenceRelations(N, B, A));
}

bool **ComplementRelations(int N, bool **A) {
  bool **C = CreateRelation(N, N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      C[i][j] = !A[i][j];
    }
  }
  return C;
}

bool **OverturnRelation(int N, bool **A) {
  bool **C = CreateRelation(N, N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (A[i][j])
        C[j][i] = true;
    }
  }

  return C;
}

bool **CompositionRelation(int N, bool **A, bool **B) {
  bool **C = CreateRelation(N, N);

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        if (A[i][k] && B[k][j])
          C[i][j] = true;
      }
    }
  }

  return C;
}

bool **PowRelation(int N, bool **A, int P) {
  if (P > 1)
    return CompositionRelation(N, A, PowRelation(N, A, P - 1));
  else
    return A;
}

bool IsReflex(int N, bool **A) {
  for (int i = 0; i < N; ++i)
    if (!A[i][i]) {
      printf("A[%d][%d] = 0 matrix is not reflex\n", i + 1, i + 1);
      return false;
    }
  return true;
}

bool IsAntiReflex(int N, bool **A) {
  for (int i = 0; i < N; ++i)
    if (A[i][i]) {
      printf("A[%d][%d] = 1 matrix is not anti reflex\n", i + 1, i + 1);
      return false;
    }
  return true;
}

bool IsSymmetric(int N, bool **A) {
  for (int i = 0; i < N; ++i)
    for (int j = i + 1; j < N; ++j)
      if (A[i][j] != A[j][i]) {
        printf("A[%d][%d] = %d A[%d][%d] = %d Matrix not symmetric\n", i + 1, j + 1, A[i][j], j + 1, i + 1,
               A[j][i]);
        return false;
      }

  return true;
}

bool IsAntiSymmetric(int N, bool **A) {
  for (int i = 0; i < N; ++i)
    for (int j = i + 1; j < N; ++j)
      if (A[i][j] && A[j][i]) {
        printf("A[%d][%d] = A[%d][%d] Matrix not antisymmetric\n", i + 1, j + 1, j + 1, i + 1);
        return false;
      }
  return true;
}

bool IsTranzitive(int N, bool **A) {
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      for (int k = 0; k < N; ++k)
        if (A[i][k] && A[k][j] && !A[i][j]) {
          printf("A[%d][%d] = 1 A[%d][%d] = 1 A[%d][%d] = 0  Matrix not tranzitive\n", i + 1, k + 1, k + 1,
                 j + 1, i + 1, j + 1);
          return false;
        }

  return true;
}

bool IsAntiTranzitive(int N, bool **A) {
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      for (int k = 0; k < N; ++k)
        if (A[i][k] && A[k][j] && A[i][j]) {
          printf("A[%d][%d] = 1 A[%d][%d] = 1 A[%d][%d] = 1  Matrix not anti tranzitive\n", i + 1, k + 1,
                 k + 1,
                 j + 1, i + 1, j + 1);
          return false;
        }

  return true;
}

bool IsFull(int N, bool **A) {
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      if (i != j) {
        if (!A[i][j])
          printf("A[%d][%d] = 0 Matrix not full\n", i + 1, j + 1);
        else if (!A[j][i])
          printf("A[%d][%d] = 0 Matrix not full\n", j + 1, i + 1);
        return false;
      }

  return true;
}

bool IsTolerant(int N, bool **A) {
  return IsReflex(N, A) && IsSymmetric(N, A);
}

bool IsEcvivalent(int N, bool **A) {
  return IsTolerant(N, A) && IsTranzitive(N, A);
}

bool IsOrder(int N, bool **A) {
  return IsAntiSymmetric(N, A) && IsTranzitive(N, A);
}

int main() {
  I = CreateRelation(10, 10);

  for (int i = 0; i < 10; ++i) {
    I[i][i] = true;
  }

  bool **A = CreateRelation(10, 10);

  for (int i = 1; i < 11; ++i) {
    for (int j = 1; j < 11; ++j) {
      A[i - 1][j - 1] = (i < j && j < 9 - i) || (9 - i < j && j < i);
    }
  }


  bool **B = CreateRelation(10, 10);

  for (int i = 1; i < 11; ++i) {
    for (int j = 1; j < 10; ++j) {
      B[i - 1][j - 1] = i % 2 == 0 && j % 2 == 1;
    }
  }


  bool **C = CreateRelation(10, 10);
  for (int i = 1; i < 11; ++i) {
    for (int j = 1; j < 11; ++j) {
      C[i - 1][j - 1] = (i * j) % 3 == 0;
    }
  }

  printf("is reflexive: %d, %d, %d\n", IsReflex(10, A), IsReflex(10, B), IsReflex(10, C));
  printf("is antireflexive: %d, %d, %d\n", IsAntiReflex(10, A), IsAntiReflex(10, B), IsAntiReflex(10, C));
  printf("is symmetric: %d, %d, %d\n", IsSymmetric(10, A), IsSymmetric(10, B), IsSymmetric(10, C));
  printf("is antisymmetric: %d, %d, %d\n", IsAntiSymmetric(10, A), IsAntiSymmetric(10, B), IsAntiSymmetric(10, C));
  printf("is transitive: %d, %d, %d\n", IsTranzitive(10, A), IsTranzitive(10, B), IsTranzitive(10, C));
  printf("is antitranzitive: %d, %d, %d\n", IsAntiTranzitive(10, A), IsAntiTranzitive(10, B),
         IsAntiTranzitive(10, C));
  printf("is full: %d, %d, %d\n", IsFull(10, A), IsFull(10, B), IsFull(10, C));
  printf("is tolerant: %d, %d, %d\n", IsTolerant(10, A), IsTolerant(10, B), IsTolerant(10, C));
  printf("is ecvivalent: %d, %d, %d\n", IsEcvivalent(10, A), IsEcvivalent(10, B), IsEcvivalent(10, C));
  printf("is order: %d, %d, %d\n", IsOrder(10, A), IsOrder(10, B), IsOrder(10, C));
}