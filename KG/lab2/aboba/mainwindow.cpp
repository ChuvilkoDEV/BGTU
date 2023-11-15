#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "matrix.h"

#include <QLabel>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerTimeout()));
    timer->start(10);

    angle = 0;
    angle1 = -angle;
    sunAngle = 90;

    labelStatus = new QLabel(this);
    labelStatus->setText(QString::number(angle));
    labelStatus->setGeometry(QRect(10, 10, 200, 30));
}

void MainWindow::onTimerTimeout() {
    angle += 0.5;
    if (angle >= 360)
        angle -= 360;
    angle1 = 180-angle;
    if (angle1 >= 360)
        angle1 -= 360;
    if (angle1 < 0)
        angle1 += 360;
    labelStatus->setText(QString::number(angle));
    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include <QPointF>
#include <QList>
#include <cmath>

QList<QPointF> findIntersections(
    const QPointF &center, double radius,
    const QPointF &lineStart, const QPointF &lineEnd)
{
    QList<QPointF> intersections;

    // Уравнение окружности: (x - h)^2 + (y - k)^2 = r^2
    double h = center.x();
    double k = center.y();
    double r = radius;

    // Компоненты направления линии
    double dx = lineEnd.x() - lineStart.x();
    double dy = lineEnd.y() - lineStart.y();

    // Параметры уравнения квадрата (Ax^2 + Bx + C = 0)
    double A = dx * dx + dy * dy;
    double B = 2 * (dx * (lineStart.x() - h) + dy * (lineStart.y() - k));
    double C = (lineStart.x() - h) * (lineStart.x() - h) + (lineStart.y() - k) * (lineStart.y() - k) - r * r;

    // Дискриминант
    double D = B * B - 4 * A * C;

    if (D >= 0) {
        // Корни уравнения
        double t1 = (-B + std::sqrt(D)) / (2 * A);
        double t2 = (-B - std::sqrt(D)) / (2 * A);

        QPointF intersection(lineStart.x() + t1 * dx, lineStart.y() + t1 * dy);

        // Проверка углов пересечения и их добавление, если они находятся в диапазоне дуги
        double angle1 = std::atan2(intersection.y() - k, intersection.x() - h) * 180 / M_PI;

        // Нормализация углов
        if (angle1 < 0) angle1 += 360;

        intersections.push_back(intersection);

    }

    return intersections;
}

void MainWindow::paint_image1()
{
    QPainter painter(this);
    QPointF earthCenter(0, 0);

    int centerX = this->width() / 4;
    int centerY = this->height() / 2;
    Matrix translateCenterMatrix = Matrix::translate(centerX, centerY, 0);
    earthCenter = translateCenterMatrix.transformPoint(earthCenter);

    int earthRadius = qMin(this->width() / 2, this->height()) / 5; // Радиус шара

    // Рисуем светлую половину
    painter.setBrush(QColor(200, 200, 255)); // Светлый оттенок синего

    painter.drawPie(earthCenter.x() - earthRadius,
                    earthCenter.y() - earthRadius,
                    2 * earthRadius, 2 * earthRadius,
                    45 * 16,
                    180 * 16);

    // Рисуем темную половину
    painter.setBrush(QColor(0, 0, 128)); // Темный оттенок синего
    painter.drawPie(earthCenter.x() - earthRadius,
                    earthCenter.y() - earthRadius,
                    2 * earthRadius,
                    2 * earthRadius,
                    225 * 16,
                    180 * 16);

    int sunRadius = earthRadius / 2.5;
    float sunDistance = earthRadius * 2;
    QPointF sunCenter = earthCenter;
    Matrix sunTranslateMatrix = Matrix::translate(
                -sunDistance,
                -sunDistance,
                0);
    sunCenter = sunTranslateMatrix.transformPoint(sunCenter);

    painter.setBrush(Qt::yellow);
    painter.drawEllipse(sunCenter, sunRadius, sunRadius);

    int moonRadius = earthRadius / 5;
    float moonDistance = earthRadius * 1.4;
    QPointF moonCenter_1 = earthCenter;
    Matrix moonTranslateMatrix = Matrix::translate(
                -moonDistance * cos(angle / 180 * M_PI),
                -moonDistance * sin(angle / 180 * M_PI),
                0);
    moonCenter_1 = moonTranslateMatrix.transformPoint(moonCenter_1);

    QPointF sunToMoon = sunCenter - moonCenter_1;
    double sunMoonAngle = atan2(sunToMoon.y(), sunToMoon.x());
    sunMoonAngle = - sunMoonAngle * 180.0 / M_PI;

    // Рисуем светлую сторону луны, которая будет обращена к солнцу
    painter.setBrush(Qt::gray); // Цвет светлой стороны луны
    painter.drawPie(moonCenter_1.x() - moonRadius,
                    moonCenter_1.y() - moonRadius,
                    2 * moonRadius, 2 * moonRadius,
                    (sunMoonAngle - 90) * 16,
                    180 * 16);

    // Рисуем темную сторону луны
    painter.setBrush(QColor(50, 50, 50)); // Цвет темной стороны луны
    painter.drawPie(moonCenter_1.x() - moonRadius,
                    moonCenter_1.y() - moonRadius,
                    2 * moonRadius, 2 * moonRadius,
                    (sunMoonAngle + 90) * 16,
                    180 * 16);

    // Создаем QPainterPath для дуги окружности (светлой стороны земли)
    QPainterPath earthPath;
    earthPath.arcMoveTo(earthCenter.x() - earthRadius,
                        earthCenter.y() - earthRadius,
                        2 * earthRadius, 2 * earthRadius,
                        45);
    earthPath.arcTo(earthCenter.x() - earthRadius,
                    earthCenter.y() - earthRadius,
                    2 * earthRadius,
                    2 * earthRadius,
                    45, 180);


    // Нормализация вектора
    qreal length = std::sqrt(sunToMoon.x() * sunToMoon.x() + sunToMoon.y() * sunToMoon.y());
    QPointF sunToMoonNormalized(sunToMoon.x() / length, sunToMoon.y() / length);
    QPointF perpendicular(-sunToMoonNormalized.y(), sunToMoonNormalized.x());

    QPointF lineStart1 = moonCenter_1 + perpendicular * moonRadius;
    QPointF lineEnd1 = sunCenter + perpendicular * sunRadius; // и заканчивается в центре Солнца

    QPointF direction1 = lineEnd1 - lineStart1;
    double linePathlength1 = std::sqrt(direction1.x() * direction1.x() +
                                      direction1.y() * direction1.y());
    QPointF unitVector1(direction1.x() / linePathlength1, direction1.y() / linePathlength1);

    lineStart1 -= 200 * unitVector1;

    painter.setBrush(QColor(0, 0, 255));
    QList<QPointF> intersections1 = findIntersections(earthCenter, earthRadius, lineStart1, lineEnd1);

    QPointF lineStart2 = moonCenter_1 - perpendicular * moonRadius;
    QPointF lineEnd2 = sunCenter - perpendicular * sunRadius; // и заканчивается в центре Солнца

    QPointF direction2 = lineEnd1 - lineStart1;
    double linePathlength2 = std::sqrt(direction1.x() * direction1.x() +
                                      direction1.y() * direction1.y());
    QPointF unitVector2(direction1.x() / linePathlength1, direction1.y() / linePathlength1);

    lineStart1 -= 200 * unitVector1;

    painter.setBrush(QColor(255, 0, 0));
    QList<QPointF> intersections2 = findIntersections(earthCenter, earthRadius, lineStart2, lineEnd2);
    if ((angle < 120) && (!intersections1.isEmpty() || !intersections2.isEmpty())) {
        double startAngle;
        double endAngle;
        if (!intersections1.isEmpty() && !intersections2.isEmpty()) {
            QPointF intersection1 = intersections1.first(); // Первая точка пересечения
            QPointF intersection2 = intersections2.first(); // Вторая точка пересечения

            // Вычисляем углы в радианах
            double startAngleRad = std::atan2(intersection1.x() - earthCenter.x(),
                                              intersection1.y() - earthCenter.y());
            double endAngleRad = std::atan2(intersection2.x() - earthCenter.x(),
                                            intersection2.y() - earthCenter.y());
            // Преобразуем углы в градусы
            startAngle = startAngleRad * 180.0 / M_PI;
            endAngle = endAngleRad * 180.0 / M_PI;
        }

        if (!intersections1.isEmpty() && intersections2.isEmpty()) {
            QPointF intersection1 = intersections1.first(); // Вторая точка пересечения

            double endAngleRad = std::atan2(intersection1.x() - earthCenter.x(),
                                            intersection1.y() - earthCenter.y());

            // Преобразуем углы в градусы
            startAngle = -45;
            endAngle = endAngleRad * 180.0 / M_PI;
        }

        if (intersections1.isEmpty() && !intersections2.isEmpty()) {
            QPointF intersection2 = intersections2.first(); // Вторая точка пересечения

            // Вычисляем углы в радианах
            double startAngleRad = std::atan2(intersection2.x() - earthCenter.x(),
                                              intersection2.y() - earthCenter.y());

            // Преобразуем углы в градусы
            startAngle = startAngleRad * 180.0 / M_PI;
            endAngle = 135;
        }
        // Нормализуем углы
        startAngle = (startAngle < 0) ? startAngle + 360 : startAngle;
        endAngle = (endAngle < 0) ? endAngle + 360 : endAngle;

        // Если дуга должна быть рисована через 0 градусов, корректируем углы
        if (startAngle > endAngle) {
            std::swap(startAngle, endAngle);
        }

        // Вычисляем угловую длину дуги
        double sweepLength = endAngle - startAngle;
        if (sweepLength < 0) {
            sweepLength += 360;
        }

        // Переводим углы в формат, который ожидает QPainter
        int startAngle16 = static_cast<int>((-90 + startAngle) * 16);
        int endAngle16 = static_cast<int>(endAngle * 16);
        int sweepLength16 = static_cast<int>(sweepLength * 16);

        QPen pen(Qt::black, 5, Qt::SolidLine);
        painter.setPen(pen);
        QRectF earthRect(earthCenter.x() - earthRadius,  // левый верхний угол X
                         earthCenter.y() - earthRadius,  // левый верхний угол Y
                         earthRadius * 2,                // ширина
                         earthRadius * 2);               // высота
        painter.drawArc(earthRect, startAngle16, sweepLength16);
    }
}

void MainWindow::paint_image2()
{
    QPainter painter(this);
    QPointF earthCenter(0, 0);

    int centerX = this->width() * 3 / 4;
    int centerY = this->height() / 2;
    Matrix translateCenterMatrix = Matrix::translate(centerX, centerY, 0);
    earthCenter = translateCenterMatrix.transformPoint(earthCenter);

    int earthRadius = qMin(this->width() / 2, this->height()) / 5; // Радиус шара

    // Рисуем светлую половину
    painter.setBrush(QColor(200, 200, 255)); // Светлый оттенок синего

    painter.drawPie(earthCenter.x() - earthRadius,
                    earthCenter.y() - earthRadius,
                    2 * earthRadius, 2 * earthRadius,
                    -45 * 16,
                    180 * 16);

    // Рисуем темную половину
    painter.setBrush(QColor(0, 0, 128)); // Темный оттенок синего
    painter.drawPie(earthCenter.x() - earthRadius,
                    earthCenter.y() - earthRadius,
                    2 * earthRadius,
                    2 * earthRadius,
                    135 * 16,
                    180 * 16);

    int sunRadius = earthRadius / 2.5;
    float sunDistance = earthRadius * 2;
    QPointF sunCenter = earthCenter;
    Matrix sunTranslateMatrix = Matrix::translate(
                sunDistance,
                -sunDistance,
                0);
    sunCenter = sunTranslateMatrix.transformPoint(sunCenter);

    painter.setBrush(Qt::yellow);
    painter.drawEllipse(sunCenter, sunRadius, sunRadius);

    int moonRadius = earthRadius / 5;
    float moonDistance = earthRadius * 1.4;
    QPointF moonCenter_1 = earthCenter;
    Matrix moonTranslateMatrix = Matrix::translate(
                -moonDistance * cos(angle1 / 180 * M_PI),
                -moonDistance * sin(angle1 / 180 * M_PI),
                0);
    moonCenter_1 = moonTranslateMatrix.transformPoint(moonCenter_1);

    QPointF sunToMoon = sunCenter - moonCenter_1;
    double sunMoonAngle = atan2(sunToMoon.y(), sunToMoon.x());
    sunMoonAngle = - sunMoonAngle * 180.0 / M_PI;

    // Рисуем светлую сторону луны, которая будет обращена к солнцу
    painter.setBrush(Qt::gray); // Цвет светлой стороны луны
    painter.drawPie(moonCenter_1.x() - moonRadius,
                    moonCenter_1.y() - moonRadius,
                    2 * moonRadius, 2 * moonRadius,
                    (sunMoonAngle - 90) * 16,
                    180 * 16);

    // Рисуем темную сторону луны
    painter.setBrush(QColor(50, 50, 50)); // Цвет темной стороны луны
    painter.drawPie(moonCenter_1.x() - moonRadius,
                    moonCenter_1.y() - moonRadius,
                    2 * moonRadius, 2 * moonRadius,
                    (sunMoonAngle + 90) * 16,
                    180 * 16);

    // Создаем QPainterPath для дуги окружности (светлой стороны земли)
    QPainterPath earthPath;
    earthPath.arcMoveTo(earthCenter.x() - earthRadius,
                        earthCenter.y() - earthRadius,
                        2 * earthRadius, 2 * earthRadius,
                        45);
    earthPath.arcTo(earthCenter.x() - earthRadius,
                    earthCenter.y() - earthRadius,
                    2 * earthRadius,
                    2 * earthRadius,
                    45, 180);


    // Нормализация вектора
    qreal length = std::sqrt(sunToMoon.x() * sunToMoon.x() + sunToMoon.y() * sunToMoon.y());
    QPointF sunToMoonNormalized(sunToMoon.x() / length, sunToMoon.y() / length);
    QPointF perpendicular(-sunToMoonNormalized.y(), sunToMoonNormalized.x());

    QPointF lineStart1 = moonCenter_1 + perpendicular * moonRadius;
    QPointF lineEnd1 = sunCenter + perpendicular * sunRadius; // и заканчивается в центре Солнца

    QPointF direction1 = lineEnd1 - lineStart1;
    double linePathlength1 = std::sqrt(direction1.x() * direction1.x() +
                                      direction1.y() * direction1.y());
    QPointF unitVector1(direction1.x() / linePathlength1, direction1.y() / linePathlength1);

    lineStart1 -= 200 * unitVector1;

    painter.setBrush(QColor(0, 0, 255));
    QList<QPointF> intersections1 = findIntersections(earthCenter, earthRadius, lineStart1, lineEnd1);

    QPointF lineStart2 = moonCenter_1 - perpendicular * moonRadius;
    QPointF lineEnd2 = sunCenter - perpendicular * sunRadius; // и заканчивается в центре Солнца

    QPointF direction2 = lineEnd1 - lineStart1;
    double linePathlength2 = std::sqrt(direction1.x() * direction1.x() +
                                      direction1.y() * direction1.y());
    QPointF unitVector2(direction1.x() / linePathlength1, direction1.y() / linePathlength1);

    lineStart1 -= 100 * unitVector1;

    painter.setBrush(QColor(255, 0, 0));
    QList<QPointF> intersections2 = findIntersections(earthCenter, earthRadius, lineStart2, lineEnd2);
    if ((angle < 120) && (!intersections1.isEmpty() || !intersections2.isEmpty())) {
        double startAngle;
        double endAngle;
        if (!intersections1.isEmpty() && !intersections2.isEmpty()) {
            QPointF intersection1 = intersections1.first(); // Первая точка пересечения
            QPointF intersection2 = intersections2.first(); // Вторая точка пересечения

            // Вычисляем углы в радианах
            double startAngleRad = std::atan2(intersection1.x() - earthCenter.x(),
                                              intersection1.y() - earthCenter.y());
            double endAngleRad = std::atan2(intersection2.x() - earthCenter.x(),
                                            intersection2.y() - earthCenter.y());
            // Преобразуем углы в градусы
            startAngle = startAngleRad * 180.0 / M_PI;
            endAngle = endAngleRad * 180.0 / M_PI;
        }

        if (!intersections1.isEmpty() && intersections2.isEmpty()) {
            QPointF intersection1 = intersections1.first(); // Вторая точка пересечения

            double endAngleRad = std::atan2(intersection1.x() - earthCenter.x(),
                                            intersection1.y() - earthCenter.y());

            // Преобразуем углы в градусы
            startAngle = 225;
            endAngle = endAngleRad * 180.0 / M_PI;
        }

        if (intersections1.isEmpty() && !intersections2.isEmpty()) {
            QPointF intersection2 = intersections2.first(); // Вторая точка пересечения

            // Вычисляем углы в радианах
            double startAngleRad = std::atan2(intersection2.x() - earthCenter.x(),
                                              intersection2.y() - earthCenter.y());

            // Преобразуем углы в градусы
            startAngle = startAngleRad * 180.0 / M_PI;
            endAngle = 45;
        }
        // Нормализуем углы
        startAngle = (startAngle < 0) ? startAngle + 360 : startAngle;
        endAngle = (endAngle < 0) ? endAngle + 360 : endAngle;

        // Если дуга должна быть рисована через 0 градусов, корректируем углы
        if (startAngle > endAngle) {
            std::swap(startAngle, endAngle);
        }

        // Вычисляем угловую длину дуги
        double sweepLength = endAngle - startAngle;
        if (sweepLength < 0) {
            sweepLength += 360;
        }

        // Переводим углы в формат, который ожидает QPainter
        int startAngle16 = static_cast<int>((-90 + startAngle) * 16);
        int endAngle16 = static_cast<int>(endAngle * 16);
        int sweepLength16 = static_cast<int>(sweepLength * 16);

        QPen pen(Qt::black, 5, Qt::SolidLine);
        painter.setPen(pen);
        QRectF earthRect(earthCenter.x() - earthRadius,  // левый верхний угол X
                         earthCenter.y() - earthRadius,  // левый верхний угол Y
                         earthRadius * 2,                // ширина
                         earthRadius * 2);               // высота
        painter.drawArc(earthRect, startAngle16, sweepLength16);
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawLine(QPoint(this->width() / 2, 0), QPoint(this->width() / 2, this->height()));

    paint_image1();
    paint_image2();
}
