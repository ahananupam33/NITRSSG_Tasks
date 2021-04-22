#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>

double CalcVal = 0.0;
bool addDetect = false;
bool subDetect = false;
bool mulDetect = false;
bool divDetect = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Displaying inputted numbers
    ui->Display->setText(QString::number(CalcVal));
    QPushButton *numButton[11];
    for(int i=0;i<11;i++){
        QString But_Name = "Button_" + QString::number(i);
        // Accessing a specific widget
        numButton[i] = MainWindow::findChild<QPushButton *>(But_Name);
        connect(numButton[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }

    connect(ui->Button_add, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->Button_subtract, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->Button_multiply, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->Button_divide, SIGNAL(released()), this, SLOT(MathButtonPressed()));

    connect(ui->Button_equal, SIGNAL(released()), this, SLOT(EqualButton()));
    connect(ui->Button_ChangeSign, SIGNAL(released()), this, SLOT(ChangeNumberSign()));
    connect(ui->Button_clear, SIGNAL(released()), this, SLOT(ClearButtonPressed()));
    connect(ui->Button_percent, SIGNAL(released()), this, SLOT(PercentButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NumPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString But_value = button->text();
    QString displayVal = ui->Display->text();
    if((displayVal.toDouble() == 0) || (displayVal.toDouble() == 0.0))
        ui->Display->setText(But_value);
    else{
        QString newVal = displayVal + But_value;
        double newVal_dbl = newVal.toDouble();
        ui->Display->setText(QString::number(newVal_dbl, 'g', 16));
    }
}

void MainWindow::MathButtonPressed(){
    addDetect = false;
    subDetect = false;
    mulDetect = false;
    divDetect = false;
    QString displayVal = ui->Display->text();
    CalcVal = displayVal.toDouble();
    QPushButton *button = (QPushButton *)sender();
    QString But_value = button->text();

    if(QString::compare(But_value, "+", Qt::CaseInsensitive) == 0)
        addDetect = true;
    else if(QString::compare(But_value, "-", Qt::CaseInsensitive) == 0)
        subDetect = true;
    else if(QString::compare(But_value, "*", Qt::CaseInsensitive) == 0)
        mulDetect = true;
    else if(QString::compare(But_value, "/", Qt::CaseInsensitive) == 0)
        divDetect = true;
    ui->Display->setText("");
}

void MainWindow::EqualButton(){
    double solution = 0.0;
    QString displayVal = ui->Display->text();
    double displayVal_dbl = displayVal.toDouble();
    if(addDetect || subDetect || mulDetect || divDetect){
        if(addDetect)
            solution = CalcVal + displayVal_dbl;
        if(subDetect)
            solution = CalcVal - displayVal_dbl;
        if(mulDetect)
            solution = CalcVal * displayVal_dbl;
        if(divDetect)
            solution = CalcVal / displayVal_dbl;
    }
    ui->Display->setText(QString::number(solution));
}

void MainWindow::ChangeNumberSign(){
    QString displayVal = ui->Display->text();
    QRegularExpression reg("[-]?[0-9.]*");
    QRegularExpressionMatch match = reg.match(displayVal);
    if(match.hasMatch()){
        double displayVal_dbl = displayVal.toDouble();
        double dblDisplayValSign = -1 * displayVal_dbl;
        ui->Display->setText(QString::number(dblDisplayValSign));
    }
}

void MainWindow::ClearButtonPressed(){
    CalcVal = 0.0;
    ui->Display->setText(QString::number(CalcVal));
}

void MainWindow::PercentButton(){
    double solution = 0.0;
    QString displayVal = ui->Display->text();
    QRegularExpression reg("[-]?[0-9.]*");
    QRegularExpressionMatch match = reg.match(displayVal);
    if(match.hasMatch()){
        double displayVal_dbl = displayVal.toDouble();
        solution = displayVal_dbl/100;
        ui->Display->setText(QString::number(solution));
    }
}
