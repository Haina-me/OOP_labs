#include "firstWindow.h"
#include "secondWindow.h"
#include "mainwindow.h"
#include <QPushButton>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800, 600);
//перша кнопка
    button = new QPushButton("Ввід тексту", this);
    button->setGeometry(100, 250, 200, 50);
    connect(button, &QPushButton::clicked, this, &MainWindow::openDialog);
//друга кнопка
    button2 = new QPushButton("Ввід номеру", this);
    button2->setGeometry(500, 250, 200, 50);
    connect(button2, &QPushButton::clicked, this, &MainWindow::openDialog2);

    //вікно виводу
    resultLabel = new QLabel("Тут з'явиться текст", this);
    resultLabel->setGeometry(400, 320, 300, 30);
}

void MainWindow::openDialog() //відкриття першого вікна
{
    FirstWindow dlg(this);
    connect(&dlg, &FirstWindow::textConfirmed, this, &MainWindow::onTextReceived);
    dlg.exec();
}

void MainWindow::openDialog2() // відкриття другого вікна
{
    SecondWindow dlg(this);
    connect(&dlg, &SecondWindow::valueConfirmed, this, &MainWindow::onValueReceived);
    dlg.exec();
}

void MainWindow::onTextReceived(const QString &text)
{
    resultLabel->setText(text);

}

void MainWindow::onValueReceived(int value)
{
    resultLabel->setText(QString::number(value));
}

MainWindow::~MainWindow()
{
}