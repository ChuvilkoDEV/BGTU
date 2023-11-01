#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#include <QSpinBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void NValueChanged(int value);
    void AValueChanged(int value);
private slots:
    void rotate();
private:
    Ui::MainWindow *ui;
    QTimer *timer;
    float angle;
    int n = 10;
    void paintEvent(QPaintEvent *event);
};
#endif // MAINWINDOW_H
