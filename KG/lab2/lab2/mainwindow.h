#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPoint>
#include <QMatrix3x3>
#include <QVector3D>
#include <cmath>
#include <iostream>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void rotate(QVector3D &m, float angle);
    void translate(QVector3D &m, float dx, float dy);
    void scale(QVector3D &m, float scaleX, float scaleY);
    void reflect(QVector3D &m, bool reflectX, bool reflectY);
    void drawStar(QPainter &painter, int x, int y, int size);

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void rotatePoint();

private:
    double angle;
    QPoint center;
    QPoint rotatingPoint;
    int n = 10;
    int nRows = 10;
    std::vector<std::pair<int, int>> points;

};


#endif // MAINWINDOW_H
