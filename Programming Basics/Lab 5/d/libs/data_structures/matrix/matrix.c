#include "matrix.h"

// Реализация библиотеки

// Задание 2 (а)
// Размещает в динамической памяти матрицу размером nRows на nCols.
// Возвращает матрицу.
matrix getMemMatrix(int nRows, int nCols) {
  int **values = (int **) malloc(sizeof(int *) * nRows);
  for (int i = 0; i < nRows; i++)
    values[i] = (int *) malloc(sizeof(int) * nCols);
  return (matrix) {values, nRows, nCols};
}

// Задание 2 (b)
// Размещает в динамической памяти массив из nMatrices матриц размером
// nRows на nCols. Возвращает указатель на нулевую матрицу.
matrix *getMemArrayOfMatrices(int nMatrices,
                              int nRows, int nCols) {
  matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
  for (int i = 0; i < nMatrices; i++)
    ms[i] = getMemMatrix(nRows, nCols);
  return ms;
}

// Задание 2 (c)
// Освобождает память, выделенную под хранение матрицы m.
void freeMemMatrix(matrix m) {
  for (int i = 0; i < m.nRows; i++)
    free(m.values[i]);
  free(m.values);
}

// Задание 2 (d)
// Освобождает память, выделенную под хранение массива ms из nMatrices матриц.
void freeMemMatrices(matrix *ms, int nMatrices) {
  for (int i = 0; i < nMatrices; i++)
    freeMemMatrix(ms[i]);
  free(ms);
}

// Задание 3 (a)
// Ввод матрицы m.
void inputMatrix(matrix m) {
  for (int i = 0; i < m.nRows; i++)
    for (int j = 0; j < m.nCols; j++)
      scanf("%d ", &m.values[i][j]);
}

// Задание 3 (b)
// Ввод массива из nMatrices матриц, хранящейся по адресу ms.
void inputMatrices(matrix *ms, int nMatrices) {
  for (int i = 0; i < nMatrices; i++)
    inputMatrix(ms[i]);
}

// Задание 3 (c)
// Вывод матрицы m
void outputMatrix(matrix m) {
  if (m.nCols == 0 || m.nRows == 0) {
    printf("Empty Matrix");
    return;
  }
  printf("[");
  for (int i = 0; i < m.nRows; i++) {
    printf("[");
    for (int j = 0; j < m.nCols; j++)
      printf("%d, ", m.values[i][j]);
    printf("\b\b], ");
  }
  printf("\b\b]");
}

// Задание 3 (d)
// Вывод массива из nMatrices матриц, хранящейся по адресу ms.
void outputMatrices(matrix *ms, int nMatrices) {
  printf("[");
  for (int i = 0; i < nMatrices; i++) {
    outputMatrix(ms[i]);
    printf(", ");
  }
  printf("\b\b]");
}

// Задание 4 (a)
// Обмен строк с порядковыми номерами i1 и i2 в матрице m.
void swapRows(matrix *m, int i1, int i2) {
  int *t = m->values[i1];
  m->values[i1] = m->values[i2];
  m->values[i2] = t;
}
// Задание 4 (b)
// Обмен колонок с порядковыми номерами j1 и j2 в матрице m
void swapColumns(matrix *m, int j1, int j2) {
  for (int i = 0; i < m->nRows; i++)
    swap(&m->values[i][j1], &m->values[i][j2]);
}

// Задание 5 (a)
// выполняет сортировку вставками строк матрицы m по неубыванию значения
// функции criteria применяемой для строк
void insertionSortRowsMatrixByRowCriteria(
  matrix *m, int (*criteria)(int *, int)) {
  int rowsCriteria[m->nRows];
  for (int i = 0; i < m->nRows; i++)
    rowsCriteria[i] = criteria(m->values[i], m->nCols);

  for (int i = 1; i < m->nRows; i++)
    for (int j = i; j > 1; j--)
      if (rowsCriteria[j] < rowsCriteria[j - 1]) {
        swap(&rowsCriteria[j], &rowsCriteria[j - 1]);
        swapRows(m, j, j - 1);
      } else break;
}

// Задание 5 (b)
// выполняет сортировку выбором столбцов матрицы m по неубыванию значения
// функции criteria применяемой для столбцов
void insertionSortColsMatrixByColCriteria(matrix *m,
                                          int (*criteria)(int *, int)) {
  int colsCriteria[m->nCols];
  for (int i = 0; i < m->nCols; i++) {
    int a[m->nRows];
    for (int j = 0; j < m->nRows; j++)
      a[j] = m->values[j][i];
    colsCriteria[i] = criteria(a, m->nRows);
  }

  for (int i = 1; i < m->nCols; i++)
    for (int j = i; j > 1; j--)
      if (colsCriteria[j] > colsCriteria[j - 1]) {
        swap(&colsCriteria[j], &colsCriteria[j - 1]);
        swapColumns(m, j, j - 1);
      } else break;
}

// Задание 6 (a)
// возвращает значение ’истина’, если матрица m является квадратной, ложь –
// в противном случае
bool isSquareMatrix(matrix m) {
  return m.nRows == m.nCols;
}

// Задание 6 (b)
// возвращает значение ’истина’, если матрицы m1 и m2 равны, ложь –
// в противном случае.
bool twoMatricesEqual(matrix m1, matrix m2) {
  if (m1.nCols != m2.nCols || m1.nRows != m2.nRows)
    return false;
  for (int i = 0; i < m1.nRows; i++)
    for (int j = 0; j < m1.nCols; j++)
      if (m1.values[i][j] != m2.values[i][j])
        return false;
  return true;
}

// Задание 6 (c)
// возвращает значение ’истина’, если матрица m является единичной,
// ложь – в противном случае.
bool isEMatrix(matrix m) {
  int n = min(m.nCols, m.nRows);
  for (int i = 0; i < n; i++)
    if (m.values[i][i] != 1)
      return false;
  return true;
}

// Задание 6 (e)
// возвращает значение ’истина’, если матрица m является симметричной,
// ложь – в противном случае.
bool isSymmetricMatrix(matrix m) {
  if (!isSquareMatrix(m))
    return false;
  for (int i = 0; i < m.nRows; i++)
    for (int j = i + 1; j < m.nCols; j++)
      if (m.values[i][j] != m.values[j][i])
        return false;
  return true;
}

// Задание 7 (a)
// транспонирует квадратную матрицу m.
void transposeSquareMatrix(matrix *m) {
  if (!isSquareMatrix(*m))
    return;
  for (int i = 0; i < m->nRows; i++)
    for (int j = i + 1; j < m->nCols; j++)
      swap(&m->values[i][j], &m->values[j][i]);
}

// Задание 8 (a)
// возвращает позицию минимального элемента матрицы m.
position getMinValuePos(matrix m) {
  position min = {1, 1};
  for (int i = 0; i < m.nRows; i++)
    for (int j = 0; j < m.nCols; j++)
      if (m.values[min.rowIndex][min.colIndex] > m.values[i][j])
        min = (position) {i, j};
  return min;
}

// Задание 8 (b)
// возвращает позицию максимального элемента матрицы m.
position getMaxValuePos(matrix m) {
  position max = {1, 1};
  for (int i = 0; i < m.nRows; i++)
    for (int j = 0; j < m.nCols; j++)
      if (m.values[max.rowIndex][max.colIndex] < m.values[i][j])
        max = (position) {i, j};
  return max;
}

// Задание 9 (a)
//возвращает матрицу размера nRows на nCols, построенную из элементов массива a
matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
  matrix m = getMemMatrix(nRows, nCols);
  int k = 0;
  for (int i = 0; i < nRows; i++)
    for (int j = 0; j < nCols; j++)
      m.values[i][j] = a[k++];
  return m;
}

// Задание 9 (b)
// возвращает указатель на нулевую матрицу массива из nMatrices матриц,
// размещенных в динамической памяти, построенных из элементов массива a
matrix *createArrayOfMatrixFromArray(const int *values, int nMatrices,
                                     int nRows, int nCols) {
  matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
  int l = 0;
  for (int k = 0; k < nMatrices; k++)
    for (int i = 0; i < nRows; i++)
      for (int j = 0; j < nCols; j++)
        ms[k].values[i][j] = values[l++];
  return ms;
}

// Решение задач:


// Задание 1

// Меняет местами строки, в которых находятся минимальный и максимальный
// элементы
void exchangeMaxAndMinRow(matrix *m) {
  position min = getMinValuePos(*m);
  position max = getMaxValuePos(*m);

  swapRows(m, min.rowIndex, max.rowIndex);
}

// Задание 2

// Сортирует строки матрицы по неубыванию наибольших элементов строк
void sortRowsByMaxElement(matrix *m) {
  insertionSortRowsMatrixByRowCriteria(m, (int (*)(int *, int)) getMax);
}

// Задание 3

// Упорядочить столбцы матрицы по неубыванию минимальных элементов столбцов:
void sortColsByMinElement(matrix *m) {
  insertionSortColsMatrixByColCriteria(m, (int (*)(int *, int)) getMin);
}

// Задание 4

// Возвращает матрицу, которая является результатом произведения матрицы m1 и m2
matrix mulMatrices(matrix const m1, matrix const m2) {
  assert(m1.nCols == m2.nRows);
  matrix m3 = getMemMatrix(m1.nRows, m2.nCols);

  for (int i = 0; i < m1.nRows; i++)
    for (int j = 0; j < m2.nCols; j++) {
      int s = 0;
      for (int k = 0; k < m1.nCols; k++)
        s += m1.values[i][k] * m2.values[k][j];
      m3.values[i][j] = s;
    }
  return m3;
}

// Возвращает матрицу, которая является квадратом квадратной матрицы
void getSquareOfMatrixIfSymmetric(matrix *m) {
  if (!isSymmetricMatrix(*m))
    return;
  matrix res = mulMatrices(*m, *m);
  *m = res;
  freeMemMatrix(res);
}

// Задание 5

// Если среди сумм элементов строк матрицы нет равных, то транспонирует матрицу.
void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
  long long sumArray[m.nRows];
  for (int i = 0; i < m.nRows; i++)
    sumArray[i] = getSum(m.values[i], m.nCols);
  if (!isUnique(sumArray, m.nRows))
    return;
  transposeSquareMatrix(&m);
}

// Задание 6

// Возвращает (true), если матрицы m1 и m2 являются взаимообратными,
// (false) - в ином случае.
bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
  matrix res = mulMatrices(m1, m2);
  if (isEMatrix(res)) {
    freeMemMatrix(res);
    return true;
  }
  return false;
}

// Задание 7

// Возвращает сумму максимальных элементов псевдодиагонали.
long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
  long long s = 0;
  for (int i = 1; i < m.nRows; i++) {
    int localMax = m.values[i][0];
    for (int j = 1; j < min(m.nCols, m.nRows) - i; j++)
      localMax = max(localMax, m.values[i + j][j]);
    s += localMax;
  }
  for (int i = 1; i < m.nCols; i++) {
    int localMax = m.values[0][i];
    for (int j = 1; j < min(m.nCols, m.nRows) - i; j++)
      localMax = max(localMax, m.values[j][i + j]);
    s += localMax;
  }
  return s;
}

// Задание 8

// Возвращает минимальный элемент из выделенной области
int getMinInArea(matrix m) {
  position maxPos = getMaxValuePos(m);
  int localMin = m.values[maxPos.rowIndex][maxPos.colIndex];
  for (int i = maxPos.rowIndex - 1; i >= 0; i--) {
    int d = maxPos.rowIndex - i;
    for (int j = 0; j < 2 * d + 1; j++) {
      if (maxPos.colIndex - d + j < 0) continue;
      else if (maxPos.colIndex - d + j >= m.nCols) break;
      localMin = min(localMin, m.values[i][maxPos.colIndex - d + j]);
    }
  }
  return localMin;
}

// Задание 9

// Возвращает расстояние от точки находящейся в n-мерном пространстве, до центра
float getDistance(int *a, int n) {
  float s = 0;
  for (int i = 0; i < n; i++)
    s += pow(a[i], 2);
  return sqrt(s);
}

// Сортиурует матрицу m, по заданному критерию (criteria)
void insertionSortRowsMatrixByRowCriteriaF(
  matrix *m, float (*criteria)(int *, int)) {
  float rowsCriteria[m->nRows];
  for (int i = 0; i < m->nRows; i++)
    rowsCriteria[i] = criteria(m->values[i], m->nCols);

  for (int i = 1; i < m->nRows; i++)
    for (int j = i; j >= 1; j--)
      if (rowsCriteria[j] < rowsCriteria[j - 1]) {
        swapF(&rowsCriteria[j], &rowsCriteria[j - 1]);
        swapRows(m, j, j - 1);
      } else break;
}

// Сортирует матрицу m, по отдалению координат точки до центра
void sortByDistances(matrix *m) {
  insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

// Задание 10

// Определить количество классов эквивалентных строк данной прямоугольной
// матрицы.
int countEqClassesByRowsSum(matrix m) {
  long long a[m.nRows];
  for (int i = 0; i < m.nRows; i++)
    a[i] = sumArray(m.values[i], m.nCols);
  return countNUnique(a, m.nRows);
}

// Задание 11

// Возвращает 𝑘 – количество "особых" элементов матрицы, считая
// элемент "особым", если он больше суммы остальных элементов своего столбца.
int getNSpecialElement(matrix m) {
  int count = 0;
  for (int i = 0; i < m.nCols; i++) {
    int max = m.values[0][i];
    int sum = 0;
    for (int j = 1; j < m.nRows; j++) {
      if (m.values[j][i] > max) {
        sum += max;
        max = m.values[j][i];
      } else {
        sum += m.values[j][i];
      }
    }
    if (max > sum)
      count++;
  }
  return count;
}

// Задание 12

// Возвращает позицию левого минимального элемента
position getLeftMin(matrix m) {
  position min = {0, 0};
  for (int i = 0; i < m.nRows; i++)
    for (int j = 0; j < m.nCols; j++)
      if (m.values[i][j] < m.values[min.rowIndex][min.colIndex])
        min = (position) {i, j};
  return min;
}

// Заменяет предпоследнюю строку матрицы первым из столбцов, в котором
// находится минимальный элемент матрицы.
void swapPenultimateRow(matrix *m, int n) {
  position minPos = getLeftMin(*m);
  int a[n];
  for (int i = 0; i < n; i++)
    a[i] = m->values[i][minPos.colIndex];
  for (int i = 0; i < n; i++)
    m->values[n - 2][i] = a[i];
}

bool isNonDescendingSorted(int const *const a, int const n) {
  for (int i = 1; i < n; i++)
    if (a[i - 1] > a[i])
      return false;
  return true;
}

// Возвращает (true), если строки матрицы отсортированы по неубыванию,
// (false) - в ином случае
bool hasAllNonDescendingRows(matrix m) {
  for (int i = 0; i < m.nRows; i++)
    if (isNonDescendingSorted(m.values[i], m.nCols) == false)
      return false;
  return true;
}

// Возвращает (true), если все строки матрицы отсортированы по неубыванию,
// (false) - в ином случае
int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
  for (int i = 0; i < nMatrix; i++)
    if (hasAllNonDescendingRows(ms[i]) == false)
      return false;
  return true;
}

// Задание 14

// Возвращает количество значений value в массиве a размера n
int countValues(const int *a, int n, int value) {
  int count = 0;
  for (int i = 0; i, n; i++)
    if (a[i] == value)
      count++;
  return count;
}

// Возвращает количество нулевых строк
int countZeroRows(matrix m) {
  int count = 0;
  for (int i = 0; i < m.nRows; i++)
    if (countValues(m.values[i], m.nCols, 0) == m.nCols)
      count++;
  return count;
}

// Выводит матрицу с наибольшим количеством нулевых строк, среди массива
// матриц ms размера Matrix
void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
  matrix *msRes = getMemArrayOfMatrices(nMatrix, ms[0].nRows, ms[0].nCols);
  int count = 0;
  int max = 0;
  for (int i = 0; i < nMatrix; i++) {
    int countZero = countZeroRows(ms[i]);
    if (countZero == max) {
      msRes[count++] = ms[i];
    } else if (countZero > max) {
      count = 1;
      max = countZero;
      msRes[0] = ms[i];
    }
  }
  if (max != 0)
    outputMatrices(ms, count);
  freeMemMatrices(msRes, nMatrix);
}

// Возвращает максимум абсолютных величин матрицы m
int getNorm(matrix m) {
  int max = m.values[0][0];
  for (int i = 0; i < m.nRows; i++)
    for (int j = 0; j < m.nCols; j++)
      if (m.values[i][j] > max)
        max = m.values[i][j];
  return max;
}

// Выводит матрицу с наименьшей нормой
void minimOfNorms(matrix *ms, int nMatrix) {
  matrix *msRes = getMemArrayOfMatrices(nMatrix, ms[0].nRows, ms[0].nCols);
  int minNorm = getNorm(ms[0]);
  int count = 0;
  for (int i = 1; i < nMatrix; i++) {
    int norm = getNorm(ms[i]);
    if (minNorm > norm) {
      minNorm = norm;
      count = 0;
    } else if (minNorm == norm) {
      msRes[count++] = ms[i];
    }
  }
  outputMatrices(msRes, count);
  freeMemMatrices(msRes, nMatrix);
}