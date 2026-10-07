#include "secondWindow.h"
#include <QLabel>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

SecondWindow::SecondWindow(QWidget *parent)
    : QDialog(parent)
{
    resize(300, 200);

    setWindowTitle("Вибір числа");

    scrollBar = new QScrollBar(Qt::Horizontal, this);
    scrollBar->setRange(1, 100);
    scrollBar->setValue(1);

    valueLabel = new QLabel("1", this);
    valueLabel->setAlignment(Qt::AlignCenter);

    QPushButton *yesButton = new QPushButton("Так", this);
    QPushButton *cancelButton = new QPushButton("Відміна", this);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(yesButton);
    buttonsLayout->addWidget(cancelButton);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(valueLabel);
    layout->addWidget(scrollBar);
    layout->addLayout(buttonsLayout);

    connect(scrollBar, &QScrollBar::valueChanged, valueLabel, qOverload<int>(&QLabel::setNum));

    connect(yesButton, &QPushButton::clicked, this, &SecondWindow::onYesClicked);
    connect(cancelButton, &QPushButton::clicked, this, &SecondWindow::reject);
}

void SecondWindow::onYesClicked()
{
    emit valueConfirmed(scrollBar->value());
    accept();
}

SecondWindow::~SecondWindow()
{
}
