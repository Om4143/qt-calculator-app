/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *display;
    QPushButton *btn7;
    QPushButton *btn4;
    QPushButton *btn1;
    QPushButton *btn0;
    QPushButton *btn5;
    QPushButton *btn8;
    QPushButton *btn9;
    QPushButton *btn6;
    QPushButton *btnClear;
    QPushButton *btn2;
    QPushButton *btnEqual;
    QPushButton *btn3;
    QPushButton *btnAdd;
    QPushButton *btnDiv;
    QPushButton *btnMul;
    QPushButton *btnSub;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(388, 454);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        display = new QLineEdit(centralwidget);
        display->setObjectName("display");
        display->setGeometry(QRect(50, 10, 291, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Academy Engraved LET")});
        font.setPointSize(20);
        display->setFont(font);
        display->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        btn7 = new QPushButton(centralwidget);
        btn7->setObjectName("btn7");
        btn7->setGeometry(QRect(50, 90, 41, 32));
        QFont font1;
        font1.setPointSize(20);
        btn7->setFont(font1);
        btn4 = new QPushButton(centralwidget);
        btn4->setObjectName("btn4");
        btn4->setGeometry(QRect(50, 180, 41, 32));
        btn4->setFont(font1);
        btn1 = new QPushButton(centralwidget);
        btn1->setObjectName("btn1");
        btn1->setGeometry(QRect(50, 260, 41, 32));
        btn1->setFont(font1);
        btn0 = new QPushButton(centralwidget);
        btn0->setObjectName("btn0");
        btn0->setGeometry(QRect(50, 330, 41, 32));
        btn0->setFont(font1);
        btn5 = new QPushButton(centralwidget);
        btn5->setObjectName("btn5");
        btn5->setGeometry(QRect(130, 180, 41, 32));
        btn5->setFont(font1);
        btn8 = new QPushButton(centralwidget);
        btn8->setObjectName("btn8");
        btn8->setGeometry(QRect(130, 90, 41, 32));
        btn8->setFont(font1);
        btn9 = new QPushButton(centralwidget);
        btn9->setObjectName("btn9");
        btn9->setGeometry(QRect(210, 90, 41, 32));
        btn9->setFont(font1);
        btn6 = new QPushButton(centralwidget);
        btn6->setObjectName("btn6");
        btn6->setGeometry(QRect(210, 180, 41, 32));
        btn6->setFont(font1);
        btnClear = new QPushButton(centralwidget);
        btnClear->setObjectName("btnClear");
        btnClear->setGeometry(QRect(130, 330, 41, 32));
        btnClear->setFont(font1);
        btn2 = new QPushButton(centralwidget);
        btn2->setObjectName("btn2");
        btn2->setGeometry(QRect(130, 260, 41, 32));
        btn2->setFont(font1);
        btnEqual = new QPushButton(centralwidget);
        btnEqual->setObjectName("btnEqual");
        btnEqual->setGeometry(QRect(210, 330, 41, 32));
        btnEqual->setFont(font1);
        btn3 = new QPushButton(centralwidget);
        btn3->setObjectName("btn3");
        btn3->setGeometry(QRect(210, 260, 41, 32));
        btn3->setFont(font1);
        btnAdd = new QPushButton(centralwidget);
        btnAdd->setObjectName("btnAdd");
        btnAdd->setGeometry(QRect(300, 330, 41, 32));
        btnAdd->setFont(font1);
        btnDiv = new QPushButton(centralwidget);
        btnDiv->setObjectName("btnDiv");
        btnDiv->setGeometry(QRect(300, 90, 41, 32));
        btnDiv->setFont(font1);
        btnMul = new QPushButton(centralwidget);
        btnMul->setObjectName("btnMul");
        btnMul->setGeometry(QRect(300, 180, 41, 32));
        btnMul->setFont(font1);
        btnSub = new QPushButton(centralwidget);
        btnSub->setObjectName("btnSub");
        btnSub->setGeometry(QRect(300, 260, 41, 32));
        btnSub->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 388, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btn7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        btn4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        btn1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        btn0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btn5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        btn8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        btn9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        btn6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        btnClear->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        btn2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        btnEqual->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        btn3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        btnDiv->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        btnMul->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        btnSub->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
