#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>

class Shape {
public:
    virtual void draw(QPainter *painter) = 0;
    virtual ~Shape() {}
};

//клас крапка
class PointShape : public Shape {
    int x, y;
public:
    PointShape(int x, int y) : x(x), y(y) {}
    void draw(QPainter *painter)  {
        painter->setPen(QPen(Qt::black, 2));
        painter->drawPoint(x, y);
    }
};

//клас лінія
class LineShape : public Shape {
    int x1, y1, x2, y2;
public:
    LineShape(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
    void draw(QPainter *painter)  {
        painter->setPen(QPen(Qt::black, 2, Qt::SolidLine));
        painter->drawLine(x1, y1, x2, y2);
    }
};

//клас прямокутник
class RectShape : public Shape {
    int x1, y1, x2, y2;
public:
    RectShape(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
    void draw(QPainter *painter)  {
        painter->setPen(QPen(Qt::black, 2, Qt::SolidLine));
        painter->setBrush(QBrush(Qt::white));
        painter->drawRect(QRect(QPoint(x1, y1), QPoint(x2, y2)));
    }
};

//клас еліпс
class EllipseShape : public Shape {
    int cx, cy, rx, ry;
public:
    EllipseShape(int cx, int cy, int rx, int ry) : cx(cx), cy(cy), rx(rx), ry(ry) {}
    void draw(QPainter *painter)  {
        painter->setPen(QPen(Qt::black, 2, Qt::SolidLine));
        painter->setBrush(Qt::NoBrush); // Без заповнення за варіантом
        painter->drawEllipse(QPoint(cx, cy), rx, ry);
    }
};

#endif // SHAPE_H