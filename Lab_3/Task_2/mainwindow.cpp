#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int m = ui->spinBox->value();
    int n = ui->spinBox_2->value();

    if (m > 4 || (m == 4 && n) || (m == 3 && n > 10) || (m == 2 && n > 10000) || (m == 1 && n > 261114))
    {
        QMessageBox::information(this, tr("Инфо"), tr("Введёные числа получат огромное число!"), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    int output = Akkerman::Evaluate(m, n);
    ui->label->setText(QString::number(output));
}

