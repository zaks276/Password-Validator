#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>
#include <QButtonGroup>

QRegularExpression rule1(QRegularExpression::anchoredPattern("\\S{5,}"));
QRegularExpression rule2(QRegularExpression::anchoredPattern("..[A-Za-z0-9].."));
QRegularExpression rule3(QRegularExpression::anchoredPattern("[1-9][0-9]{3,5}"));

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->checkButton, SIGNAL(clicked()), this, SLOT(checkPassword()));
    QButtonGroup* group = new QButtonGroup();
    group->addButton(ui->rule1checkBox);
    group->addButton(ui->rule2checkBox);
    group->addButton(ui->rule3checkBox);
    group->setExclusive(true);
    ui->rule1checkBox->setChecked(true);

}

void MainWindow::checkPassword()
{
    QString p = ui->passwordlineEdit->text();
    if(ui->rule1checkBox->isChecked()){
        QRegularExpressionMatch r1 = rule1.match(p);
        bool matchR1 = r1.hasMatch();
        if(matchR1)
            ui->resultlabel->setText("Rule 1 is satisfied!");
        else
            ui->resultlabel->setText("Rule 1 is not satisfied!");
    }
    if(ui->rule2checkBox->isChecked()){
        QRegularExpressionMatch r2 = rule2.match(p);
        bool matchR2 = r2.hasMatch();
        if(matchR2)
            ui->resultlabel->setText("Rule 2 is satisfied!");
        else
            ui->resultlabel->setText("Rule 2 is not satisfied!");
    }
    if(ui->rule3checkBox->isChecked()){
        QRegularExpressionMatch r3 = rule3.match(p);
        bool matchR3 = r3.hasMatch();
        if(matchR3)
            ui->resultlabel->setText("Rule 3 is satisfied!");
        else
            ui->resultlabel->setText("Rule 3 is not satisfied!");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


