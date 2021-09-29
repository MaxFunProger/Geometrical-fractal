#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QTextItem>
#include <QListWidgetItem>
#include <string>
#include <string.h>
#include <stack>
#include <cmath>
#include <ctype.h>
#include <algorithm>
#include <QColor>
#include <QBrush>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_verticalSlider_valueChanged(int value);

private:
    struct Rect{
        double x, y, w, h;
    };

    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    void UpdateScene();
    void DrawFractal();
    void DrawStep(int, double, double, double);
    double start_x = 0;
    double start_y = 500;
    double start_length = 100;
    QPen pen = QPen(QColor(0, 0, 0), 1);
    QPen penw = QPen(QColor(256, 256, 256), 1);
    QBrush brush = QBrush(QColor(0, 0, 0));
    QBrush brushw = QBrush(QColor(256, 256, 256));
};
#endif // MAINWINDOW_H
