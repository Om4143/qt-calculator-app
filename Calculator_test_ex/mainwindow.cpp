#include "mainwindow.h" 
/*This includes your own header file.

So now this file knows the definition of the MainWindow class.*/
#include "ui_mainwindow.h"
/*This includes the code generated from your .ui file.

That generated file contains the actual widgets from Designer.

Without this line, ui->display and your buttons would not exist here.*/
#include <QPushButton>
/*This includes the QPushButton class.

You need it because later you use QPushButton *button.*/

MainWindow::MainWindow(QWidget *parent)
/*This starts the definition of the constructor you declared in .h.

MainWindow:: means:
“This function belongs to the MainWindow class.”*/
    : QMainWindow(parent)
    /*This calls the constructor of the parent class QMainWindow.

    Since your class inherits from QMainWindow, you should let the base class initialize itself first.*/
    , ui(new Ui::MainWindow)
    /*This creates the UI object and stores its address in ui.

    new Ui::MainWindow means:
    “Make a new UI object in memory.”

    Now ui points to it.*/
{
    ui->setupUi(this);
    /*This is one of the most important lines in Qt Widgets.

    It builds the interface from the .ui file and places it inside this window.

    It creates and connects all widgets designed in Qt Designer.

    Without this line, your designed buttons and display would never appear.*/

    ui->display->setText("0");
    /*This sets the text of the display widget to "0" when the program starts.

    So your calculator begins with 0 shown.*/

    // Number buttons
    connect(ui->btn0, &QPushButton::clicked, this, &MainWindow::digitPressed);
    /*This connects button btn0 to the function digitPressed.

    Read it like this:

    “When btn0 is clicked, call digitPressed() on this window.”

    connect(...) is Qt’s way of wiring events to functions.*/
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

MainWindow::~MainWindow() // destructor
{
    delete ui;
}
    /*This deletes the UI object from memory when the window closes.

    You created it with new, so you clean it up with delete.

    That avoids a memory leak.*/
void MainWindow::digitPressed()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    /*This line is very important.

    sender() means:
    “Which object sent the signal that triggered this function?”

    Since multiple digit buttons all call the same function, you need to know which one was clicked.

    qobject_cast<QPushButton *> safely converts that sender object into a QPushButton*.

    So now button points to the actual clicked button.

    If user clicked 7, then button points to the 7 button.*/
    if (!button)
        return;

    QString buttonText = button->text();
    /*This gets the text written on the clicked button.

    Examples:

    if user clicked 7, then buttonText becomes "7"
    if user clicked 2, then buttonText becomes "2"*/

    if (ui->display->text() == "0" || waitingForSecondNumber) {
        /*This checks two cases.

        Case 1:
        If display currently shows "0"
        then typing a digit should replace it.

        Case 2:
        If waitingForSecondNumber is true
        then the user just pressed an operator, and now the next digit should start a fresh number.

        So this condition means:
        “Should I replace the display instead of adding to it?”*/
        ui->display->setText(buttonText);
        /*If the condition is true, replace the display with the new digit.

        Example:

        display is 0
        user clicks 7

        Now display becomes 7

        Or:

        user pressed +
        now user clicks 3

        Display becomes 3, not 123*/
        waitingForSecondNumber = false;
        // Now the user has started entering the second number, so we are no longer waiting.
    } else {
        ui->display->setText(ui->display->text() + buttonText);
        /*This appends the new digit to the current display text.

        Example:

        display is "4"
        user clicks "5"

        New text becomes "45"

        This is how multi-digit numbers are built.*/
    }
}

void MainWindow::operatorPressed() // This runs when user clicks +, -, *, or /.
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    // Again, find which operator button was clicked.
    if (!button)
        return;

    firstNumber = ui->display->text().toDouble();
    /*Take whatever is currently shown on the display and convert it to a number.

    If display shows "25", this stores 25 in firstNumber.

    toDouble() changes text into a numeric value.*/
    currentOperator = button->text();
    /*Get the operator symbol from the button text and store it.

    Examples:

    "+"
    "-"
    "*"
    "/"

    Now the calculator knows which operation to perform later.*/
    waitingForSecondNumber = true;
    /*This tells the calculator:
    “The next digit typed should be the second number.”

    So if user now clicks 3, the display will be replaced with 3 instead of appending.*/
}

void MainWindow::equalPressed()
{
    double secondNumber = ui->display->text().toDouble();
    /*Take the number currently on the display and store it as the second number.

    Example:
    If user typed 3, then secondNumber = 3*/
    double result = 0.0;

    if (currentOperator == "+") {
        result = firstNumber + secondNumber; 
        /*If the stored operator is +, then add the two numbers.

        Example:
        2 + 3 = 5*/
    } else if (currentOperator == "-") {
        result = firstNumber - secondNumber;
        // If operator is -, subtract.
    } else if (currentOperator == "*") {
        result = firstNumber * secondNumber;
        // If operator is *, multiply.
    } else if (currentOperator == "/") {
        if (secondNumber == 0) {
            ui->display->setText("Error");
            // If second number is 0, Show "Error" on the calculator display.
            return;
        }
        result = firstNumber / secondNumber;
    }

    ui->display->setText(QString::number(result));
    /*Convert the numeric result into text and show it on the display.

    QString::number(result) turns something like 5 into "5".*/
    currentOperator = "";
    // Clear the stored operator because the calculation is done.
    waitingForSecondNumber = false;
    // Reset the flag.
}

void MainWindow::clearPressed()
{
    ui->display->setText("0");
    // ui->display->setText("0");
    firstNumber = 0.0;
    currentOperator = "";
    waitingForSecondNumber = false;
}