#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->doubleSpinBox->setMaximum(10.00);
    ui->spinBox->setMaximum(10);
    ui->spinBox_2->setMaximum(10);
    ui->spinBox_3->setMaximum(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_add_clicked()
{
    int row = ui->table->rowCount();
    ui->table->insertRow(row);

    QTableWidgetItem *itm = new QTableWidgetItem(ui->lineEdit->text() +" "+ ui->lineEdit_2->text() +" "+ ui->lineEdit_3->text());
    ui->table->setItem(row,0,itm);

    QTableWidgetItem *itm1 = new QTableWidgetItem(ui->comboBox->currentText());
    ui->table->setItem(row,1,itm1);

    QTableWidgetItem *itm2 = new QTableWidgetItem(QString::number(ui->doubleSpinBox->value()));
    ui->table->setItem(row,2,itm2);

    QTableWidgetItem *itm3 = new QTableWidgetItem(QString::number(ui->spinBox->value()));
    ui->table->setItem(row,3,itm3);

    QTableWidgetItem *itm4 = new QTableWidgetItem(QString::number(ui->spinBox_2->value()));
    ui->table->setItem(row,4,itm4);

    QTableWidgetItem *itm5 = new QTableWidgetItem(QString::number(ui->spinBox_3->value()));
    ui->table->setItem(row,5,itm5);
}

