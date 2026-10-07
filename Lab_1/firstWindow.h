#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include <QDialog>
class QLineEdit;

class FirstWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FirstWindow(QWidget *parent = nullptr);

signals:
        void textConfirmed(const QString &text);

private slots:
    void onYesClicked();

private:
    QLineEdit *lineEdit;
};

#endif // FIRSTWINDOW_H