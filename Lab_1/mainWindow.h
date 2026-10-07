#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openDialog();
    void openDialog2();
    void onTextReceived(const QString &text);
    void onValueReceived(int value);

private:
    QPushButton *button;
    QPushButton *button2;
    QLabel *resultLabel;
};

#endif // MAINWINDOW_H