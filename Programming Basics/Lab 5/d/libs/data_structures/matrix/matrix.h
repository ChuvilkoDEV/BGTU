#ifndef INC_5D_MATRIX_H
#define INC_5D_MATRIX_H

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <memory.h>
#include "../../algorithms/algorithms.h"

#define FLOAT_EPS 0.00001

typedef struct matrix {
  int **values; // элементы матрицы
  int nRows; // количество рядов
  int nCols; // количество столбцов
} matrix;

typedef struct position {
  int rowIndex;
  int colIndex;
} position;

// Реализация библиотеки

// Размещает в динамической памяти матрицу размером nRows на nCols.
// Возвращает матрицу.
matrix getMemMatrix(int nRows, int nCols);

// Размещает в динамической памяти массив из nMatrices матриц размером
// nRows на nCols. Возвращает указатель на нулевую матрицу.
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

// Освобождает память, выделенную под хранение матрицы m.
void freeMemMatrix(matrix m);

void freeMemMatrices(matrix *ms, int nMatrices);

void inputMatrix(matrix m);

void inputMatrices(matrix *ms, int nMatrices);

void outputMatrix(matrix m);

void outputMatrices(matrix *ms, int nMatrices);

void swapRows(matrix *m, int i1, int i2);

void swapColumns(matrix *m, int j1, int j2);

void insertionSortRowsMatrixByRowCriteria(
  matrix *m, int (*criteria)(int *, int));

void insertionSortColsMatrixByColCriteria(
  matrix *m, int (*criteria)(int *, int));

bool isSquareMatrix(matrix m);

bool twoMatricesEqual(matrix m1, matrix m2);

bool isEMatrix(matrix m);

bool isSymmetricMatrix(matrix m);

void transposeSquareMatrix(matrix *m);

position getMinValuePos(matrix m);

position getMaxValuePos(matrix m);

matrix createMatrixFromArray(const int *a, int nRows, int nCols);

matrix *createArrayOfMatrixFromArray(
  const int *values, int nMatrices, int nRows, int nCols);

void exchangeMaxAndMinRow(matrix *m);

void sortRowsByMaxElement(matrix *m);

void sortColsByMinElement(matrix *m);

matrix mulMatrices(matrix m1, matrix m2);

void getSquareOfMatrixIfSymmetric(matrix *m);

void transposeIfMatrixHasNotEqualSumOfRows(matrix m);

bool isMutuallyInverseMatrices(matrix m1, matrix m2);

long long findSumOfMaxesOfPseudoDiagonal(matrix m);

int getMinInArea(matrix m);

float getDistance(int *a, int n);

void sortByDistances(matrix *m);

int countEqClassesByRowsSum(matrix m);

int getNSpecialElement(matrix m);

position getLeftMin(matrix m);

void swapPenultimateRow(matrix *m, int n);

bool isNonDescendingSorted(int const *const a, int const n);

bool hasAllNonDescendingRows(matrix m);

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix);

int countValues(const int *a, int n, int value);

int countZeroRows(matrix m);

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix);

void minimOfNorms(matrix *ms, int nMatrix);

#endif //INC_5D_MATRIX_H
