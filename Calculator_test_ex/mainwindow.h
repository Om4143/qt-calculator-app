#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*These two lines are called an include guard.

They prevent the same file from being included more than once by mistake.
Without this, C++ can get confused and show duplicate-definition errors.

Think of it like:
“Only load this file once.”*/
#include <QMainWindow>
/*This includes Qt’s QMainWindow class.

Your calculator window is going to be based on QMainWindow, so C++ needs to know what that is before it can use it.*/

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
/*This part is related to the UI file you designed in Qt Designer.

When Qt processes mainwindow.ui, it generates code behind the scenes. That generated code creates a class named Ui::MainWindow.

So here you are telling C++:

“There is a class called Ui::MainWindow. I will use it later.”

This is called a forward declaration.
It lets C++ know the class exists without loading everything yet.*/
class MainWindow : public QMainWindow 
                /*This defines your own class named MainWindow.

                : means inheritance.
                public QMainWindow means:

                “My MainWindow is based on Qt’s QMainWindow.”

                So your class gets all the normal window behavior from Qt:

                title bar
                resize behavior
                central widget support
                menu bar support*/
{
    Q_OBJECT
    /*This is very important in Qt.

    It enables Qt’s special features such as:

    signals
    slots
    object information at runtime

    Without this line, many Qt features related to button clicks and events would not work correctly.*/

public:
/*This means the things written below can be accessed from outside the class.*/
    MainWindow(QWidget *parent = nullptr);
    /*This is the constructor of your class.

    A constructor runs automatically when an object is created.

    So when your app creates the main window, this function runs first.

    QWidget *parent = nullptr means:

    this window can optionally have a parent widget
    if no parent is given, use nullptr meaning “no parent”

    For your calculator, that is fine.*/
    ~MainWindow();
    /*This is the destructor.

    It runs automatically when the window is destroyed, usually when the app closes.

    It is used for cleanup.*/    


private slots:
/*This section contains slots.

A slot is just a function that Qt can connect to events, like button clicks.

So when the user presses a button, Qt can call one of these functions.

private means they are used only inside this class.*/
    void digitPressed();
    /*This declares a function named digitPressed.

    void means it does not return a value.

    This function will run when one of the number buttons like 0, 1, 2 is clicked.*/
    void operatorPressed();
    /*This function will run when an operator button like +, -, *, / is clicked.*/
    void equalPressed();
    /*This function will run when = is clicked.*/
    void clearPressed();
    /*This function will run when C is clicked.*/

private:
/*This section is for internal things used only inside the class.

Other code outside the class should not directly touch these.*/
    Ui::MainWindow *ui;
    /*This is a pointer to the generated UI object.

    This is one of the most important lines for beginners to understand.

    Your .ui file is converted by Qt into C++ code.
    That generated code creates widgets like:

    line edit
    buttons
    layouts

    The pointer ui gives your C++ code access to those widgets.

    That is why you can write:
    ui->display
    ui->btn1
    ui->btnAdd
    because those widgets were created from your .ui file.*/
    double firstNumber = 0.0;
    /*This variable stores the first number in a calculation.*/
    QString currentOperator = "";
    /*This stores the operator the user selected.(+,-,* and /)*/
    bool waitingForSecondNumber = false;
    /*This is a true/false variable.

    It tells the calculator whether it is waiting for the second number.

    Example:

    User presses 5
    User presses +

    Now the app is waiting for the next number, so this becomes true.

    That helps the calculator know whether to replace the display or keep adding digits.*/
};

#endif // MAINWINDOW_H
/*This closes the include guard started at the top.*/