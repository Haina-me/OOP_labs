#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QActionGroup>
#include "shape.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    Shape* pcshape[120];
    int shapeCount = 0;

    enum ShapeType { PointType, LineType, RectType, EllipseType };
    ShapeType currentType = PointType;

    bool isDrawing = false;
    QPoint startPoint;
    QPoint endPoint;

    void setupMenu();
};

#endif // MAINWINDOW_H