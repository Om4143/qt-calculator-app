#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->display->setText("0");

    // Number buttons
    connect(ui->btn0, &QPushButton::clicked, this, &MainWindow::digitPressed);
    connect(ui->btn1, &QPushButton::clicked, this, &MainWindow::digitPressed);
    connect(ui->btn2, &QPushButton::clicked, this, &MainWindow::digitPressed);
    connect(ui->btn3, &QPushButton::clicked, this, &MainWindow::digitPressed);
    connect(ui->btn4, &QPushButton::clicked, this, &MainWindow::digitPressed);
    connect(ui->btn5, &QPushButton::clicked, this, &MainWindow::digitPressed);
    connect(ui->btn6, &QPushButton::clicked, this, &MainWindow::digitPressed);
    connect(ui->btn7, &QPushButton::clicked, this, &MainWindow::digitPressed);
    connect(ui->btn8, &QPushButton::clicked, this, &MainWindow::digitPressed);
    connect(ui->btn9, &QPushButton::clicked, this, &MainWindow::digitPressed);

    // Operator buttons
    connect(ui->btnAdd, &QPushButton::clicked, this, &MainWindow::operatorPressed);
    connect(ui->btnSub, &QPushButton::clicked, this, &MainWindow::operatorPressed);
    connect(ui->btnMul, &QPushButton::clicked, this, &MainWindow::operatorPressed);
    connect(ui->btnDiv, &QPushButton::clicked, this, &MainWindow::operatorPressed);

    // Equal and clear
    connect(ui->btnEqual, &QPushButton::clicked, this, &MainWindow::equalPressed);
    connect(ui->btnClear, &QPushButton::clicked, this, &MainWindow::clearPressed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitPressed()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button)
        return;

    QString buttonText = button->text();

    if (ui->display->text() == "0" || waitingForSecondNumber) {
        ui->display->setText(buttonText);
        waitingForSecondNumber = false;
    } else {
        ui->display->setText(ui->display->text() + buttonText);
    }
}

void MainWindow::operatorPressed()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button)
        return;

    firstNumber = ui->display->text().toDouble();
    currentOperator = button->text();
    waitingForSecondNumber = true;
}

void MainWindow::equalPressed()
{
    double secondNumber = ui->display->text().toDouble();
    double result = 0.0;

    if (currentOperator == "+") {
        result = firstNumber + secondNumber;
    } else if (currentOperator == "-") {
        result = firstNumber - secondNumber;
    } else if (currentOperator == "*") {
        result = firstNumber * secondNumber;
    } else if (currentOperator == "/") {
        if (secondNumber == 0) {
            ui->display->setText("Error");
            return;
        }
        result = firstNumber / secondNumber;
    }

    ui->display->setText(QString::number(result));
    currentOperator = "";
    waitingForSecondNumber = false;
}

void MainWindow::clearPressed()
{
    ui->display->setText("0");
    firstNumber = 0.0;
    currentOperator = "";
    waitingForSecondNumber = false;
}