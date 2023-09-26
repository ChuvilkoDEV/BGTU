#ifndef INC_1_MATRIX_H
#define INC_1_MATRIX_H

#include "vector"
#include "iostream"
#include <iomanip>

#define EPS 0.00001

using namespace std;

bool fcmp(float f1, float f2);

class Matrix {
private:
    vector<vector<float>> data;
    int rows;
    int columns;
public:
    bool isSquare();

    int getRows();

    int getColumns();

    Matrix(int rows, int columns);

    Matrix();

    void setData(int row, int column, float value);

    float getData(int row, int column);

    Matrix multiply(Matrix m2);

    Matrix multiply(float multiplier);

    Matrix add(Matrix m2);

    Matrix subtract(Matrix m2);

    Matrix transpose();

    vector<float> multiply(vector<float> v);

    void inputMatrix();

    void inputMatrix(int rows, int columns,
                     vector<vector<float>> newData);

    void outputMatrix();

    void swapRows(int r1, int r2);

    Matrix gaussForward(int &numSwaps);

    void copy(Matrix m);

    bool isZeroRow(int row);

    bool isBadRow(int row);

    vector<float> gaussBackward(bool &hasSolution);

    void pushBackColumn(vector<float> v);

    Matrix gaussForwardManyFreeTermColumns();

    Matrix gaussBackwardManyFreeTermColumns();

    float getDeterminer();

    Matrix getInverseMatrix();

    Matrix jordanGaussForward(bool &hasSolution);

    void divideRowByNum(int row, float num);

    void subtractMultipliedRow(int from, int which, float multiplier);

    void deleteRow(int row);

    vector<vector<float>> getBasicSolutions();

    void substitution(int row, int column);

    bool checkIfBasicColumn(int column, int &oneRow);

    vector<float> getBasicSolutionFromMatrix();

    void recursiveSearchOfSolution(int row, vector<vector<float>> &solutions);

    void addNewRow(vector<float> newRow);

    vector<float> getRow(int row);

    void pushBackZeroColumn();

    void multiplyRowBy(int row, float multiplier);

    void deleteColumn(int column);

    bool isUnitColumn(int column);

    int unitPosition(int column);
};

#endif //INC_1_MATRIX_H
