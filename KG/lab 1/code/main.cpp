#include "mainwindow.h"
#include <QApplication>

// Функция для рисования круга
void MainWindow::paintEvent(QPaintEvent* event)
{
    QPainter painter(this); // Создаём объект-живописец

    QColor orangeRed(240, 100, 0); // Оранжево-красный цвет

    // Радиус большой окружности
    float radius;
    // Вычисляем радиус окружности
    if (width() > height()) // Если ширина окна больше высоты
     radius = (height() - 20) / 2; // Отступ от краёв - 10 пикселей
    else radius = (width() - 20) / 2;

    // Если размеры окна маленькие, ничего не выводить
    if (width() < 30 || height() < 30)
     return;

    // Координаты центра окружности
    QPointF center = QPointF(width() / 2, height() / 2);

    // Задаём область прорисовки круга
    QRectF rect = QRectF(center.x() - radius, center.y() - radius, radius*2, radius*2);

    // Рисуем большой круг красно-оранжевым цветом
    painter.setBrush( orangeRed);
    painter.setPen( orangeRed );
    painter.drawEllipse(rect);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
