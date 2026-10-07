#include "firstWindow.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>

// Конструктор
FirstWindow::FirstWindow(QWidget *parent)
    : QDialog(parent)
{
    resize(300, 200);
    setWindowTitle("Введення тексту");

    lineEdit = new QLineEdit(this);
    lineEdit->setPlaceholderText("Введіть текст...");

    QPushButton *yesButton = new QPushButton("Так", this);
    QPushButton *cancelButton = new QPushButton("Відміна", this);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(yesButton);
    buttonsLayout->addWidget(cancelButton);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(lineEdit);
    layout->addLayout(buttonsLayout);

    connect(yesButton, &QPushButton::clicked, this, &FirstWindow::onYesClicked);
    connect(cancelButton, &QPushButton::clicked, this, &FirstWindow::reject);
}

void FirstWindow::onYesClicked() //відправка тексту
{
    emit textConfirmed(lineEdit->text());
    accept();
}
