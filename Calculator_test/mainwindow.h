#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void digitPressed();
    void operatorPressed();
    void equalPressed();
    void clearPressed();

private:
    Ui::MainWindow *ui;

    double firstNumber = 0.0;
    QString currentOperator = "";
    bool waitingForSecondNumber = false;
};

#endif // MAINWINDOW_H