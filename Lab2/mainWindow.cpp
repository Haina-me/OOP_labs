#include "mainwindow.h"
#include <QMenuBar>
#include <QMessageBox>
#include <cmath>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    resize(800, 600);
    setWindowTitle("Lab 2 Графічний редактор");

    for (int i = 0; i < 120; ++i) {
        pcshape[i] = nullptr;
    }

    setupMenu();
}

MainWindow::~MainWindow() {
    for (int i = 0; i < shapeCount; ++i) {
        delete pcshape[i];
    }
}

void MainWindow::setupMenu() {
    //меню файл
    QMenu *fileMenu = menuBar()->addMenu("Файл");
    QAction *actExit = fileMenu->addAction("Вихід");
    connect(actExit, &QAction::triggered, this, &QWidget::close);
    menuBar()->setStyleSheet("QMenuBar { color: black; }");

    //меню об'єкти
    QMenu *objMenu = menuBar()->addMenu("Об'єкти");
    QActionGroup *group = new QActionGroup(this);

    QAction *actPoint = objMenu->addAction("Крапка");
    QAction *actLine = objMenu->addAction("Лінія");
    QAction *actRect = objMenu->addAction("Прямокутник");
    QAction *actEllipse = objMenu->addAction("Еліпс");

    actPoint->setCheckable(true);
    actLine->setCheckable(true);
    actRect->setCheckable(true);
    actEllipse->setCheckable(true);
    actPoint->setChecked(true);

    group->addAction(actPoint);
    group->addAction(actLine);
    group->addAction(actRect);
    group->addAction(actEllipse);

    connect(actPoint, &QAction::triggered, this, [this]() { currentType = PointType; });
    connect(actLine, &QAction::triggered, this, [this]() { currentType = LineType; });
    connect(actRect, &QAction::triggered, this, [this]() { currentType = RectType; });
    connect(actEllipse, &QAction::triggered, this, [this]() { currentType = EllipseType; });

    //меню довідка
    QMenu *helpMenu = menuBar()->addMenu("Довідка");
    QAction *actAbout = helpMenu->addAction("Про програму");
    connect(actAbout, &QAction::triggered, this, [this]() {
        QMessageBox::about(this, "Довідка", "Графічний редактор");
    });
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.fillRect(rect(), Qt::white);

    //вже ст. фіг.
    for (int i = 0; i < shapeCount; ++i) {
        if (pcshape[i]) {
            pcshape[i]->draw(&painter);
        }
    }

    //гумовий слід
    if (isDrawing && currentType != PointType) {
        painter.setPen(QPen(Qt::black, 1, Qt::SolidLine));
        painter.setBrush(Qt::NoBrush);

        if (currentType == LineType) {
            painter.drawLine(startPoint, endPoint);
        }
        else if (currentType == RectType) {
            painter.drawRect(QRect(startPoint, endPoint));
        }
        else if (currentType == EllipseType) {
            int rx = std::abs(endPoint.x() - startPoint.x());
            int ry = std::abs(endPoint.y() - startPoint.y());
            painter.drawEllipse(startPoint, rx, ry);
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (shapeCount >= 120) return;
    isDrawing = true;
    startPoint = event->pos();
    endPoint = event->pos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if (isDrawing) {
        endPoint = event->pos();
        update();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    if (!isDrawing || shapeCount >= 120) return;

    endPoint = event->pos();
    isDrawing = false;

    //зберігаємо нову фігуру в масив
    if (currentType == PointType) {
        pcshape[shapeCount] = new PointShape(startPoint.x(), startPoint.y());
    }
    else if (currentType == LineType) {
        pcshape[shapeCount] = new LineShape(startPoint.x(), startPoint.y(), endPoint.x(), endPoint.y());
    }
    else if (currentType == RectType) {
        pcshape[shapeCount] = new RectShape(startPoint.x(), startPoint.y(), endPoint.x(), endPoint.y());
    }
    else if (currentType == EllipseType) {
        int rx = std::abs(endPoint.x() - startPoint.x());
        int ry = std::abs(endPoint.y() - startPoint.y());
        pcshape[shapeCount] = new EllipseShape(startPoint.x(), startPoint.y(), rx, ry);
    }

    shapeCount++;
    update();
}