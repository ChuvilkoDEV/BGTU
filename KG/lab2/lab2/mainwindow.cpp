#include "mainwindow.h"
#include <QTimer>
#include <QPainter>
#include <cmath>
#include <QVector3D>
#include <vector>
#include <random>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), angle(0)
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::rotatePoint);
    timer->start(20); // Частота обновления в миллисекундах
    resize(800, 800);
    std::random_device rd; // Используем случайное устройство для начального seed
    std::mt19937 gen(rd()); // Генератор случайных чисел Mersenne Twister
    std::uniform_int_distribution<int> distribution(0, nRows-1); // Равномерное распределение от min до max
    for (int i = 0; i < n; ++i)
        points.push_back({(int)distribution(gen), (int)distribution(gen)});
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::NoBrush);
    center = QPoint(std::min(width()/2, height()/2), std::min(width()/2, height()/2)); // Координаты центра окна

    int figureSize = center.x()/4;

    // Перемещение от центра экрана для создания 4 квадратов вокруг центра
    int offset = center.x()*3/4;

    int innerOffset = offset - figureSize/2;
    int outerOffset = offset + figureSize/2;
    painter.drawEllipse(center.x() - innerOffset, center.y() - innerOffset, 2*innerOffset, 2*innerOffset);
    painter.drawEllipse(center.x() - outerOffset, center.y() - outerOffset, 2*outerOffset, 2*outerOffset);

        int tableOffset = (innerOffset) / 1.41;
         // Количество рядов
        int rowHeight = tableOffset / nRows;
        for (int i = 0; i <= nRows; ++i) {
            int y = i * rowHeight*2;
            int x = i * rowHeight*2;
            painter.drawLine(center.x() - tableOffset, center.y() - tableOffset + y, center.x() + tableOffset, center.y() - tableOffset +y);
            painter.drawLine(center.x() - tableOffset + x, center.y() - tableOffset, center.x() - tableOffset + x, center.y() + tableOffset);
        }

        std::vector<std::vector<QPoint>> gridCoordinates(nRows, std::vector<QPoint>(nRows));
        for (int i = 1; i <= nRows; ++i)
            for (int j = 1; j <= nRows; ++j)
                gridCoordinates[i - 1][j-1] = QPoint(center.x() - tableOffset + rowHeight + i * rowHeight*2, center.y() - tableOffset + rowHeight + j * rowHeight*2);

        if (std::fmod(angle, 15.0) == 0.0) {
        std::random_device rd; // Используем случайное устройство для начального seed
        std::mt19937 gen(rd()); // Генератор случайных чисел Mersenne Twister
        std::uniform_int_distribution<int> distribution(0, 3); // Равномерное распределение от min до max
        for (auto &i: points) {
            int generation = std::rand() % 4;
            if (generation == 0) {
                if (i.first == 0)
                    i.first += 1;
                else
                    i.first -= 1;
            } else if (generation == 1) {
                if (i.first == nRows-1)
                    i.first -= 1;
                else
                    i.first += 1;
            } else if (generation == 2) {
                if (i.second == 0)
                    i.second += 1;
                else
                    i.second -= 1;
            } else if (generation == 3) {
                if (i.second == nRows-1)
                    i.second -= 1;
                else
                    i.second += 1;
            }
        }
        }

        if (std::fmod(angle, 90.0) == 0.0) {
            points.push_back({0, 0});
            points.push_back({nRows - 1, 0});
            points.push_back({0, nRows - 1});
            points.push_back({nRows - 1, nRows - 1});
        }

        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                if (points[j] == points[i]){
                    points.erase(points.begin() + j);
                }
            }
        }
        for (auto &i: points) {
            painter.drawEllipse(gridCoordinates[i.first][i.second].x() - figureSize/2.5, gridCoordinates[i.first][i.second].y()-figureSize/2.5, figureSize/5, figureSize/5);
        }


    QVector3D cursor(center.x() + offset, center.y(), 1);
    rotate(cursor, angle);
    // Вращаем и рисуем 4 фигуры
    for (int i = 0; i < 4; ++i) {
        painter.setBrush(QBrush(QColor(Qt::black)));
        rotate(cursor, 45);
        painter.drawRect(cursor.x() - figureSize /1.41/ 2, cursor.y() - figureSize /1.41/ 2, figureSize/ 1.41, figureSize/1.41);

        rotate(cursor, 45);
        drawStar(painter, cursor.x(), cursor.y(), figureSize/2);
    }


}

void MainWindow::rotatePoint()
{
    angle += 1; // Угол вращения
    update(); // Перерисовать окно
}

MainWindow::~MainWindow()
{
}

void MainWindow::rotate(QVector3D &m, float angle) {
    angle *= M_PI / 180;
    QVector3D c(center.x(), center.y(), 0);
    m -= c;

    QMatrix3x3 rotateMatrix;
    QVector3D result;
    // Установка значений элементов матрицы
    rotateMatrix(0, 0) = std::cos(angle);  // Элемент в первой строке, первом столбце
    rotateMatrix(0, 1) = -std::sin(angle);  // Элемент в первой строке, втором столбце/*
    rotateMatrix(1, 0) = std::sin(angle);  // Элемент во второй строке, первом столбце
    rotateMatrix(1, 1) = std::cos(angle);  // Элемент во второй строке, втором столбце*/
    rotateMatrix(2, 2) = 1.0;  // Элемент в третьей строке, третьем столбце
    for (int row = 0; row < 3; ++row) {
            result[row] = 0;
            for (int col = 0; col < 3; ++col) {
                result[row] += rotateMatrix(row, col) * m[col];
            }
        }
    m = result;
    m += c;
}

void MainWindow::translate(QVector3D &m, float dx, float dy) {
        QMatrix3x3 translateMatrix;
        QVector3D result;

        // Установка значений элементов матрицы для переноса
        translateMatrix.setToIdentity(); // Единичная матрица
        translateMatrix(0, 2) = dx; // Элемент в первой строке, третьем столбце
        translateMatrix(1, 2) = dy; // Элемент во второй строке, третьем столбце

        for (int row = 0; row < 3; ++row) {
            result[row] = 0;
            for (int col = 0; col < 3; ++col) {
                result[row] += translateMatrix(row, col) * m[col];
            }
        }

        m = result;
    }

void MainWindow::scale(QVector3D &m, float scaleX, float scaleY) {
        QMatrix3x3 scaleMatrix;
        QVector3D result;

        // Установка значений элементов матрицы для масштабирования
        scaleMatrix.setToIdentity(); // Единичная матрица
        scaleMatrix(0, 0) = scaleX; // Элемент в первой строке, первом столбце
        scaleMatrix(1, 1) = scaleY; // Элемент во второй строке, втором столбце

        for (int row = 0; row < 3; ++row) {
            result[row] = 0;
            for (int col = 0; col < 3; ++col) {
                result[row] += scaleMatrix(row, col) * m[col];
            }
        }

        m = result;
    }

void MainWindow::reflect(QVector3D &m, bool reflectX=false, bool reflectY=false) {
        QMatrix3x3 reflectMatrix;
        QVector3D result;

        // Установка значений элементов матрицы для отражения
        reflectMatrix.setToIdentity(); // Единичная матрица
        if (reflectX) {
            reflectMatrix(0, 0) = -1; // Отражение по горизонтали
        }
        if (reflectY) {
            reflectMatrix(1, 1) = -1; // Отражение по вертикали
        }

        for (int row = 0; row < 3; ++row) {
            result[row] = 0;
            for (int col = 0; col < 3; ++col) {
                result[row] += reflectMatrix(row, col) * m[col];
            }
        }

        m = result;
    }

void MainWindow::drawStar(QPainter &painter, int centerX, int centerY, int size) {
    QVector<QPoint> starPoints;
    for (int i = 0; i < 5; ++i) {
        float outerX = centerX + size * cos(2 * M_PI * i / 5);
        float outerY = centerY + size * sin(2 * M_PI * i / 5);
        QVector3D outer(outerX, outerY, 1);
        float innerX = centerX + (size / 2) * cos(2 * M_PI * (i + 0.5) / 5);
        float innerY = centerY + (size / 2) * sin(2 * M_PI * (i + 0.5) / 5);
        QVector3D inner(innerX, innerY, 1);

        //rotate(outer, 60*angle);
        //rotate(inner, 60*angle);

        starPoints << QPoint(outer.x(), outer.y());
        starPoints << QPoint(inner.x(), inner.y());
    }

    painter.setPen(QPen(QColor(Qt::blue)));
    painter.setBrush(QBrush(QColor(Qt::yellow)));
    painter.drawPolygon(starPoints);
}
