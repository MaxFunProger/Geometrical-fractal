#include "mainwindow.h"
#include "ui_mainwindow.h"

int border = 7;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->gV->setScene(scene);
    ui->verticalSlider->setValue(6);
    DrawFractal();

}


void MainWindow::UpdateScene(){
    DrawFractal();

}

void MainWindow::DrawFractal(){
    scene->clear();
    scene->addLine(0, 0, 1, 1, QPen(QColor(256, 256, 256), 1));
    scene->addRect(-300, -300, 600, 600, pen, brush);
    int ind = 1;
    DrawStep(ind, -300, -300, 600);
}

void MainWindow::DrawStep(int ind, double x, double y, double len){
    if (ind >= border){
        return;
    }
    auto rect = scene->addRect(x + len / 3, y + len / 3, len / 3, len / 3);
    rect->setBrush(Qt::white);

    scene->addLine(0, 0, 1, 1, QPen(QColor(256, 256, 256), 1));

    DrawStep(ind + 1, x, y, len / 3);
    DrawStep(ind + 1, x + len / 3, y, len / 3);
    DrawStep(ind + 1, x + 2 * len / 3, y, len / 3);
    DrawStep(ind + 1, x, y + len / 3, len / 3);
    DrawStep(ind + 1, x + 2 * len / 3, y + len / 3, len / 3);
    DrawStep(ind + 1, x, y + 2 * len / 3, len / 3);
    DrawStep(ind + 1, x + len / 3, y + 2 * len / 3, len / 3);
    DrawStep(ind + 1, x + 2 * len / 3, y + 2 * len / 3, len / 3);
}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_verticalSlider_valueChanged(int value)
{
    border = value;
    std::cout << "wewretr";
    DrawFractal();
}
