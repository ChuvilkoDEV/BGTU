#include "matrix.h"

#include <utility>

bool fcmp(float f1, float f2) {
    return (abs((f1 - f2)) < EPS);
}

Matrix::Matrix(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;

    data = vector<vector<float>>(rows);
    for (int row = 0; row < rows; row++) {
        data[row] = vector<float>(columns);
    }
}

Matrix::Matrix() {
    rows = 0;
    columns = 0;
}

bool Matrix::isSquare() {
    return rows == columns;
}

int Matrix::getRows() {
    return rows;
}

int Matrix::getColumns() {
    return columns;
}

void Matrix::setData(int row, int column, float value) {
    data[row][column] = value;
}

float Matrix::getData(int row, int column) {
    return data[row][column];
}

Matrix Matrix::multiply(Matrix m2) {
    if (this->rows != m2.columns) {
        cerr << "\nНе возможно умножить матрицу " << this->rows << "x" << this->columns
             << " на матрицу " << m2.rows << "x" << m2.columns;
        exit(0);
    }

    Matrix result(this->rows, m2.columns);

    for (int row = 0; row < this->rows; row++) {
        for (int column = 0; column < m2.columns; column++) {
            float sum = 0;
            for (int position = 0; position < this->columns; position++) {
                sum += getData(row, position) * m2.getData(position, column);
            }

            result.setData(row, column, sum);
        }
    }

    return result;
}

Matrix Matrix::multiply(float multiplier) {
    Matrix result(this->rows, this->columns);

    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            result.setData(row, column, this->getData(row, column) * multiplier);
        }
    }

    return result;
}

vector<float> Matrix::getRow(int row) {
    return data[row];
}

Matrix Matrix::add(Matrix m2) {
    if (this->rows != m2.rows || this->columns != m2.columns) {
        cerr << "\nНе возможно сложить матрицу " << this->rows << "x" << this->columns
             << " с матрицей " << m2.rows << "x" << m2.columns;
        exit(0);
    }

    Matrix result(this->rows, this->columns);

    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            float value = this->getData(row, column) + m2.getData(row, column);
            result.setData(row, column, value);
        }
    }

    return result;
}

Matrix Matrix::subtract(Matrix m2) {
    if (this->rows != m2.rows || this->columns != m2.columns) {
        cerr << "\nНе возможно вычесть из матрицы " << this->rows << "x" << this->columns
             << " матрицу " << m2.rows << "x" << m2.columns;
        exit(0);
    }

    Matrix result(this->rows, this->columns);

    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            float value = this->getData(row, column) - m2.getData(row, column);
            result.setData(row, column, value);
        }
    }

    return result;
}

Matrix Matrix::transpose() {
    Matrix result(this->columns, this->rows);

    for (int row = 0; row < this->rows; row++) {
        for (int column = 0; column < this->columns; column++) {
            result.setData(column, row, this->getData(row, column));
        }
    }

    return result;
}

vector<float> Matrix::multiply(vector<float> v) {
    if (this->rows != v.size()) {
        cerr << "\nНе возможно умножить матрицу " << this->rows << "x" << this->columns
             << " на вектор размером " << v.size();
        exit(0);
    }

    vector<float> result(this->rows);

    for (int row = 0; row < this->rows; row++) {
        float sum = 0;
        for (int position = 0; position < this->columns; position++) {
            sum += this->getData(row, position) * v[position];
        }

        result[row] = sum;
    }

    return result;
}

void Matrix::inputMatrix() {
    for (int row = 0; row < this->rows; row++) {
        for (int column = 0; column < this->columns; column++) {
            cin >> data[row][column];
        }
    }
}

void Matrix::inputMatrix(int rows, int columns, vector<vector<float>> newData) {
    this->rows = rows;
    this->columns = columns;

    data = vector<vector<float>>(rows);
    for (int i = 0; i < rows; i++) {
        data[i] = vector<float>(columns);
        for (int j = 0; j < columns; j++) {
            data[i][j] = newData[i][j];
        }
    }
}

void Matrix::outputMatrix() {
    for (int row = 0; row < this->rows; row++) {
        for (int column = 0; column < this->columns; column++) {
            if (fcmp(getData(row, column), 0) && getData(row, column) <= 0)
                setData(row, column, 0);
            cout << setw(7) << setprecision(3) << getData(row, column) << " ";
        }
        cout << "\n\n";
    }
}

void Matrix::swapRows(int r1, int r2) {
    vector<float> tmp = data[r1];
    data[r1] = data[r2];
    data[r2] = tmp;
}

void Matrix::copy(Matrix m) {
    rows = m.rows;
    columns = m.columns;
    Matrix result(m.rows, m.columns);

    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            result.setData(row, column, m.getData(row, column));
        }
    }

    this->data = result.data;
}

Matrix Matrix::gaussForward(int &numSwaps) {
    numSwaps = 0;

    Matrix result(rows, columns);
    result.copy(*this);

    for (int k = 0; k < rows; k++) {
        // Поиск максимального по модулю элемента в столбце
        float maxAbs = abs(result.getData(k, k));
        int maxAbsRow = k;
        for (int row = k + 1; row < rows; row++) {
            if (abs(result.getData(row, k)) > maxAbs) {
                maxAbs = abs(result.getData(row, k));
                maxAbsRow = row;
            }
        }

        if (k != maxAbsRow) {
            result.swapRows(k, maxAbsRow);
            numSwaps++;
        }

        if (result.getData(k, k) != 0) {
            vector<float> multipliers;
            for (int i = k + 1; i < rows; i++) {
                multipliers.push_back(-result.getData(i, k) / result.getData(k, k));
            }

            for (int row = k + 1; row < rows; row++) {
                for (int column = k; column < columns; column++) {
                    float newValue = result.getData(row, column) +
                                     multipliers[row - (k + 1)] * result.getData(k, column);
                    result.setData(row, column, newValue);
                }
            }
        }
    }

    return result;
}

bool Matrix::isZeroRow(int row) {
    for (int i = 0; i < columns; i++) {
        if (!fcmp(getData(row, i), 0))
            return false;
    }

    return true;
}

bool Matrix::isBadRow(int row) {
    for (int i = 0; i < columns - 1; i++) {
        if (!fcmp(getData(row, i), 0))
            return false;
    }

    return !fcmp(getData(row, columns - 1), 0);
}

vector<float> Matrix::gaussBackward(bool &hasSolution) {
    hasSolution = true;
    for (int row = 0; row < rows; row++) {
        if (isBadRow(row)) {
            hasSolution = false;
            return {};
        }
    }

    for (int row = 0; row < rows; row++) {
        if (isZeroRow(row))
            return {};
    }

    vector<float> vectorX(columns - 1);
    for (int k = rows - 1; k >= 0; k--) {
        float sum = getData(k, columns - 1);
        for (int i = k + 1; i < columns - 1; i++) {
            sum -= getData(k, i) * vectorX[i];
        }

        vectorX[k] = sum / getData(k, k);
    }

    return vectorX;
}

void Matrix::pushBackColumn(vector<float> v) {
    columns += 1;
    for (int row = 0; row < rows; row++) {
        data[row].push_back(v[row]);
    }
}

Matrix Matrix::gaussForwardManyFreeTermColumns() {
    Matrix result(rows, columns);
    result.copy(*this);

    for (int k = 0; k < rows; k++) {
        // Поиск максимального по модулю элемента в столбце
        float maxAbs = abs(result.getData(k, k));
        int maxAbsRow = k;
        for (int row = k + 1; row < rows; row++) {
            if (abs(result.getData(row, k)) > maxAbs) {
                maxAbs = abs(result.getData(row, k));
                maxAbsRow = row;
            }
        }

        if (k != maxAbsRow) {
            result.swapRows(k, maxAbsRow);
        }

        if (result.getData(k, k) != 0) {
            vector<float> multipliers;
            for (int i = k + 1; i < rows; i++) {
                multipliers.push_back(-result.getData(i, k) / result.getData(k, k));
            }

            for (int row = k + 1; row < rows; row++) {
                for (int column = k; column < rows; column++) {
                    float newValue = result.getData(row, column) +
                                     multipliers[row - (k + 1)] * result.getData(k, column);
                    result.setData(row, column, newValue);
                }
            }
        }
    }

    return result;
}

Matrix Matrix::gaussBackwardManyFreeTermColumns() {
    Matrix result(rows, columns - rows);

    for (int solutionColumn = 0; solutionColumn < result.getColumns(); solutionColumn++) {
        for (int k = rows - 1; k >= 0; k--) {
            float sum = getData(k, rows + solutionColumn);
            for (int i = k + 1; i < rows; i++) {
                sum -= getData(k, i) * result.getData(i, solutionColumn);
            }

            result.setData(k, solutionColumn, sum / getData(k, k));
        }
    }
    return result;
}

float Matrix::getDeterminer() {
    Matrix triangleView(rows, columns);

    int numSwaps;
    triangleView = gaussForward(numSwaps);

    float determiner = 1;
    for (int k = 0; k < triangleView.rows; k++) {
        determiner *= triangleView.getData(k, k);
    }

    if (numSwaps % 2 == 1)
        determiner *= -1;

    return determiner;
}

Matrix Matrix::getInverseMatrix() {
    Matrix result(rows, columns * 2);
    // Копирование матрицы
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result.setData(i, j, this->getData(i, j));
        }
    }

    // Создание единичной матрицы
    for (int i = 0; i < rows; i++) {
        result.setData(i, columns + i, 1);
    }

    for (int k = 0; k < rows; k++) {
        // Поиск максимального по модулю элемента в столбце
        float maxAbs = abs(result.getData(k, k));
        int maxAbsRow = k;
        for (int row = k + 1; row < rows; row++) {
            if (abs(result.getData(row, k)) > maxAbs) {
                maxAbs = abs(result.getData(row, k));
                maxAbsRow = row;
            }
        }

        if (k != maxAbsRow) {
            result.swapRows(k, maxAbsRow);
        }

        if (result.getData(k, k) != 0) {
            float t = result.getData(k, k);
            for (int column = k; column < result.columns; column++) {
                result.setData(k, column, result.getData(k, column) / t);
            }

            vector<float> multipliers(result.rows);
            for (int i = 0; i < result.rows; i++) {
                multipliers[i] = result.getData(i, k);
            }

            for (int row = 0; row < result.rows; row++) {
                if (row == k)
                    continue;

                for (int column = k; column < result.columns; column++) {
                    float newValue = result.getData(row, column) - result.getData(k, column) * multipliers[row];
                    result.setData(row, column, newValue);
                }
            }
        }
    }

    return result;
}

void Matrix::divideRowByNum(int row, float num) {
    for (int i = 0; i < columns; i++) {
        setData(row, i, getData(row, i) / num);
    }
}

void Matrix::subtractMultipliedRow(int from, int which, float multiplier) {
    for (int i = 0; i < columns; i++) {
        setData(from, i, getData(from, i) - getData(which, i) * multiplier);
    }
}

void Matrix::deleteRow(int row) {
    data.erase(data.begin() + row);

    rows--;
}

Matrix Matrix::jordanGaussForward(bool &hasSolution) {
    Matrix result(rows, columns);
    result.copy(*this);
    hasSolution = true;

    for (int handledRow = 0; handledRow < result.rows; handledRow++) {
        if (result.isZeroRow(handledRow)) {
            result.deleteRow(handledRow);
            continue;
        } else if (result.isBadRow(handledRow)) {
            hasSolution = false;
            return result;
        }

        for (int column = 0; column < result.columns - 1; column++) {
            if (!fcmp(result.getData(handledRow, column), 0)) {
                result.divideRowByNum(handledRow, result.getData(handledRow, column));

                for (int i = 0; i < result.rows; i++) {
                    if (i != handledRow)
                        result.subtractMultipliedRow(i, handledRow, result.getData(i, column));
                }

                break;
            }
        }
    }

    return result;
}

void Matrix::substitution(int row, int column) {
    divideRowByNum(row, getData(row, column));

    for (int i = 0; i < rows; i++) {
        if (i != row) {
            subtractMultipliedRow(i, row, getData(i, column));
        }
    }
}

bool Matrix::checkIfBasicColumn(int column, int &oneRow) {
    bool hasOneValue = false;

    for (int row = 0; row < rows; row++) {
        if (!fcmp(getData(row, column), 0)) {
            if (fcmp(getData(row, column), 1)) {
                if (hasOneValue)
                    return false;
                else {
                    hasOneValue = true;
                    oneRow = row;
                }
            } else {
                return false;
            }
        }
    }

    return true;
}

vector<float> Matrix::getBasicSolutionFromMatrix() {
    vector<float> basicSolution(columns - 1);
    for (int column = 0; column < columns - 1; column++) {
        int oneRow;
        bool isBasicColumn = checkIfBasicColumn(column, oneRow);

        if (isBasicColumn) {
            basicSolution[column] = getData(oneRow, columns - 1);
        } else {
            basicSolution[column] = 0;
        }
    }

    return basicSolution;
}

void Matrix::recursiveSearchOfSolution(int row, vector<vector<float>> &solutions) {
    Matrix matrixCopy(rows, columns);
    matrixCopy.copy(*this);

    for (int column = 0; column < matrixCopy.columns - 1; column++) {
        if (!fcmp(matrixCopy.getData(row, column), 0)) {
            matrixCopy.substitution(row, column);

            if (row == matrixCopy.rows - 1) {
                solutions.push_back(matrixCopy.getBasicSolutionFromMatrix());
            } else {
                matrixCopy.recursiveSearchOfSolution(row + 1, solutions);
            }
        }
    }
}

vector<vector<float>> Matrix::getBasicSolutions() {
    bool hasSolution;
    Matrix preparedMatrix = this->jordanGaussForward(hasSolution);
    if (!hasSolution)
        return {};

    vector<vector<float>> solutions;
    preparedMatrix.recursiveSearchOfSolution(0, solutions);

    return solutions;
}

void Matrix::addNewRow(vector<float> newRow) {
    rows++;
    data.push_back(newRow);
}

void Matrix::pushBackZeroColumn() {
    for (auto &raw: data)
        raw.push_back(0);

    columns++;
}

void Matrix::multiplyRowBy(int row, float multiplier) {
    for (int column = 0; column < getColumns(); column++) {
        setData(row, column, multiplier * getData(row, column));
    }
}

void Matrix::deleteColumn(int column) {
    for (int row = 0; row < getRows(); row++) {
        data[row].erase(data[row].begin() + column);
    }

    columns--;
}

bool Matrix::isUnitColumn(int column) {
    bool hasOne = false;
    for (int row = 0; row < getRows(); row++) {
        if (fcmp(getData(row, column), 1)) {
            if (hasOne)
                return false;
            hasOne = true;
        } else if (!fcmp(getData(row, column), 0))
            return false;
    }

    return hasOne;
}

int Matrix::unitPosition(int column) {
    for (int row = 0; row < getRows(); row++) {
        if (fcmp(getData(row, column), 1))
            return row;
    }

    return -1;
}
