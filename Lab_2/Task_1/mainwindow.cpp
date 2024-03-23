#include "mainwindow.h"
#include "ui_mainwindow.h"

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


Date ss = *new Date;

void MainWindow::on_addDate_clicked()
{
    int row = ui->table->rowCount();
    ui->table->insertRow(row);
    QDate date = ui->DateAddText->date();
    ss = Date(date.year(),date.month(),date.day());

    QTableWidgetItem *itm = new QTableWidgetItem(date.toString("dd.MM.yyyy"));
    ui->table->setItem(row,0,itm);

    QTableWidgetItem *itm1 = new QTableWidgetItem(ss.nextDay().str());
    ui->table->setItem(row,1,itm1);

    QTableWidgetItem *itm2 = new QTableWidgetItem(ss.previousDay().str());
    ui->table->setItem(row,2,itm2);

    QTableWidgetItem *itm3 = new QTableWidgetItem(ss.boolToString(ss.isLeap()));
    ui->table->setItem(row,3,itm3);

    QTableWidgetItem *itm4 = new QTableWidgetItem(ss.shortToString(ss.weekNumber()));
    ui->table->setItem(row,4,itm4);

    QTableWidgetItem *itm5 = new QTableWidgetItem(ss.intToString(ss.duration(ss)));
    ui->table->setItem(row,5,itm5);
}

void MainWindow::on_DateBirthdayText_userDateChanged(const QDate &date)
{
    Date birthdaydate = Date(date.year(),date.month(),date.day());
    QDate today = today.currentDate();
    Date td = Date(today.year(),today.month(),today.day());
    ui->lcdNumber->display(td.daysTillYourBithday(birthdaydate));
}

void MainWindow::on_changeDate_clicked()
{
    QDate d = ui->DateChangeText->date();
    ss = Date(d.year(), d.month(), d.day());
    int row = ui->lineEdit->text().toInt() - 1;

    if(row < 0 || row >= ui->table->rowCount())
    {
        QMessageBox::critical(0,tr("Ошибка"),tr("Введите правильный номер даты для изменения"),QMessageBox::Ok|QMessageBox::NoButton);
        return;
    }

    QTableWidgetItem *itm = new QTableWidgetItem(d.toString("dd.MM.yyyy"));
    ui->table->setItem(row,0,itm);

    QTableWidgetItem *itm1 = new QTableWidgetItem(ss.nextDay().str());
    ui->table->setItem(row,1,itm1);

    QTableWidgetItem *itm2 = new QTableWidgetItem(ss.previousDay().str());
    ui->table->setItem(row,2,itm2);

    QTableWidgetItem *itm3 = new QTableWidgetItem(ss.boolToString(ss.isLeap()));
    ui->table->setItem(row,3,itm3);

    QTableWidgetItem *itm4 = new QTableWidgetItem(ss.shortToString(ss.weekNumber()));
    ui->table->setItem(row,4,itm4);

    QTableWidgetItem *itm5 = new QTableWidgetItem(ss.intToString(ss.duration(ss)));
    ui->table->setItem(row,5,itm5);
}
