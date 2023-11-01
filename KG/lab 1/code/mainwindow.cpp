#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <cmath>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(800, 600);
    timer = new QTimer;
    timer->setInterval(50);
    timer->start();
    connect(timer, &QTimer::timeout, this, &MainWindow::rotate);
}

void drawBG(QPainter *painter, int width, int height){
    auto oldBrush = painter->brush();
    auto oldPen = painter->pen();
    QColor white(255, 255, 255);
    painter->setBrush(white);
    painter->setPen(white);
    painter->drawRect(0, 0, width, height);
    painter->setBrush(oldBrush);
    painter->setPen(oldPen);
}

double distance(QPoint const &a, QPoint const &b){
    return std::sqrt(std::pow(a.x() - b.x(), 2) + pow(a.y() - b.y(), 2));
}

void MainWindow::paintEvent(QPaintEvent *event){
    float minSize = std::min(height(), width()) / 2.0; // Центр окна
    int a = std::min(width() / 6, height()/4) - 10;
    QPainter painter(this);

    // Создаем кисть для заливки
    QBrush blueBrush(Qt::blue);
    QBrush redBrush(Qt::red);

    // Rotate
    painter.translate(width()/2, height()/2);

    QPainterPath path;
    path.moveTo(a, 0);
    path.lineTo(-a, 0);
    path.lineTo(-a, 2*a);
    path.lineTo(a, 2*a);
    painter.fillPath(path, blueBrush);

    path = QPainterPath();
    path.moveTo(a, 0);
    path.lineTo(3*a, 0);
    path.lineTo(a, 2*a);
    painter.fillPath(path, redBrush);

    path = QPainterPath();
    path.moveTo(-a, 0);
    path.lineTo(-3*a, 0);
    path.lineTo(-a, 2*a);
    painter.fillPath(path, redBrush);

    path = QPainterPath();
    path.moveTo(0, 0);
    path.lineTo(0, -2*a);
    path.lineTo(a, 0);
    painter.fillPath(path, redBrush);

    path = QPainterPath();
    path.moveTo(0, -1.5*a);
    path.lineTo(0, -2*a);
    path.lineTo(-0.5*a, -1.75*a);
    painter.fillPath(path, blueBrush);


    QPoint wheelCenter(-2*a, a);
    painter.translate(wheelCenter);
    painter.rotate(angle);
    painter.setPen(QPen(Qt::black, 2));
    painter.drawEllipse(-a/2, -a/2, a, a);
    painter.setPen(QPen(Qt::NoPen));


    int sectorAngle = 360 / n;

    for (int i = 0; i < n; ++i) {
        double startAngle = i * sectorAngle;
        double endAngle = (i + 1) * sectorAngle;

        QColor sectorColor = QColor::fromHsv(i * sectorAngle, 255, 255);
        QBrush sectorBrush(sectorColor);
        painter.setBrush(sectorBrush);

        painter.drawPie(-a/2, -a/2, a, a, startAngle * 16, sectorAngle * 16);

        painter.setPen(QPen(Qt::black, 1));

        int deg = i * 360 / n;
        double radian = deg * M_PI / 180.0f;
        int x = a/2 * std::cos(radian);
        int y = a/2 * std::sin(radian);
        painter.drawLine(QPoint(0, 0), QPoint(x, y));
    }
}

void MainWindow::rotate() {
    angle -= 5.0f;
    this->update();
}
MainWindow::~MainWindow()
{
    delete timer;
    delete ui;
}
