#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#endif //SECONDWINDOW_H
#include <QDialog>
class QScrollBar;
class QLabel;
class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

signals:
        void valueConfirmed(int value);

private slots:
    void onYesClicked();

private:
    QScrollBar *scrollBar;
    QLabel *valueLabel;
};
