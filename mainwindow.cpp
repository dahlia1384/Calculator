#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
   :QMainWindow(parent),
   ,ui(new Ui::MainWindow)
   ,useIsTypingSecondNum(false)
   {
    ui->setupUi(this);

    //Connect the digit buttons
    for(int i = 0; i <= 9; ++i){
        QString buttonName = "Button" + QString::number(i);
        QPushButton *button = MainWindow::findChild<QPushButton *>(buttonName);
        connect(button, SIGNAL(released()), this, SLOT(digitPressed()));
    }

    //Connect the operator buttons
    connect(ui->ButtonPlus, SIGNAL(released()), this, SLOT(operatorPressed()));
    connect(ui->ButtonMinus, SIGNAL(released()), this, SLOT(operatorPressed()));
    connect(ui->ButtonMultiply, SIGNAL(released()), this, SLOT(operatorPressed()));
    connect(ui->ButtonDivide, SIGNAL(released()), this, SLOT(operatorPressed()));

    //Connect the equals button
    connect(ui->ButtonEquals, SIGNAL(released()), this, SLOT(equalPressed()));
    connect(ui->ButtonClear, SIGNAL(released()), this, SLOT(clearPressed()));

   }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitPressed(){
    QPushButton *button = (QPushButton *)sender();
    firstNum = ui->lineEdit->text().toDouble();
    pendingOperator = button->text();
    userIsTypingSecondNum = true;
}


void MainWindow::on_equals_clicked()
{
    double secondNum = ui->lineEdit->text().toDouble();
    double result;

    if (pendingOperator == "+")
        result = firstNum + secondNum;
    else if (pendingOperator == "−")
        result = firstNum - secondNum;
    else if (pendingOperator == "×")
        result = firstNum * secondNum;
    else if (pendingOperator == "÷")
        result = (secondNum != 0) ? (firstNum / secondNum) : 0;

    ui->lineEdit->setText(QString::number(result));
}

void MainWindow::on_clear_clicked()
{
    ui->lineEdit->clear();
    userIsTypingSecondNum = false;
}