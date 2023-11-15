#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent *event);

    void paint_image1();
    void paint_image2();

public slots:
    void onTimerTimeout();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    double angle;
    double angle1;
    double sunAngle;
    QLabel *labelStatus;
};
#endif // MAINWINDOW_H
