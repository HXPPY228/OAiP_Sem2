#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QChar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->doubleSpinBox->setMaximum(10.00);
    ui->spinBox->setMaximum(100);
    ui->spinBox_2->setMaximum(100);
    ui->spinBox_3->setMaximum(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_add_clicked()
{
    int row;
    QString input = ui->lineEdit->text().trimmed();
    QString input2 = ui->lineEdit_2->text().trimmed();
    QString input3 = ui->lineEdit_3->text().trimmed();
    bool russian=true;
    for (int i =0; i< input.length();i++){
        if (input[i].script() != QChar::Script_Cyrillic) {
            russian=false;
        }
    }
    if (russian&&!input.isEmpty() && input.at(0).isUpper() && !input.contains(" ")&&!input2.isEmpty() && input2.at(0).isUpper() && !input2.contains(" ")&&!input3.isEmpty() && input3.at(0).isUpper() && !input3.contains(" ")) {
        row = ui->table->rowCount();
        ui->table->insertRow(row);
        QTableWidgetItem *itm = new QTableWidgetItem(input +" "+ input2 +" "+ input3);
        ui->table->setItem(row,0,itm);
    } else {
        QMessageBox::warning(this, "Ошибка", "Введено некорректное ФИО!");
        return;
    }
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

    QTableWidgetItem *itm6 = new QTableWidgetItem(QString::number(10*ui->doubleSpinBox->value()+ui->spinBox->value()+ui->spinBox_2->value()+ui->spinBox_3->value()));
    ui->table->setItem(row,6,itm6);
}


void MainWindow::on_pushButton_add_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открытие"), "//", tr("Текстовые документы (*.txt)"));
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        if (!CheckFile(line))
        {
            QMessageBox::critical(0,tr("Ошибка"),tr("Неверный формат данных файла"),QMessageBox::Ok|QMessageBox::NoButton);
            return;
        }

        int row = ui->table->rowCount();
        ui->table->insertRow(row);

        line=line.trimmed();
        QStringList words = line.split(' ');
        QTableWidgetItem *itm = new QTableWidgetItem(words[0] +" "+ words[1] +" "+ words[2]);
        ui->table->setItem(row,0,itm);

        QString spec;
        switch (words[3].toInt()) {
        case 0:
            spec="ИиТП";
            break;
        case 1:
            spec="КИ";
            break;
        case 2:
            spec="ПИ";
            break;
        case 3:
            spec="ПОИТ";
            break;
        }
        QTableWidgetItem *itm1 = new QTableWidgetItem(spec);
        ui->table->setItem(row,1,itm1);

        QTableWidgetItem *itm2 = new QTableWidgetItem(words[4]);
        ui->table->setItem(row,2,itm2);

        QTableWidgetItem *itm3 = new QTableWidgetItem(words[5]);
        ui->table->setItem(row,3,itm3);

        QTableWidgetItem *itm4 = new QTableWidgetItem(words[6]);
        ui->table->setItem(row,4,itm4);

        QTableWidgetItem *itm5 = new QTableWidgetItem(words[7]);
        ui->table->setItem(row,5,itm5);

        int srb = 10*words[4].toDouble();
        QTableWidgetItem *itm6 = new QTableWidgetItem(QString::number(srb+words[5].toInt()+words[6].toInt()+words[7].toInt()));
        ui->table->setItem(row,6,itm6);

        ui->table->update();
    }

    file.close();
}

bool MainWindow::CheckFile(QString line){
    line=line.trimmed();
    QStringList words = line.split(' ');
    if(words.size() != 8) {
        return false;
    }

    for(int i = 0; i < 3; i++) {
        for(QChar c : words[i]) {
            if(c.script() != QChar::Script_Cyrillic) {
                return false;
            }
        }
    }

    if (words[3]!='0'&&words[3]!='1'&&words[3]!='2'&&words[3]!='3'){
        return false;
    }

    bool ok;
    double negr = words[4].toDouble(&ok);
    if(!ok&&(negr<0||negr>10)) {
        return false;
    }

    for(int i = 5; i < 8; i++) {
        bool ok1;
        int pidoras = words[i].toInt(&ok1);
        if(!ok1&&(pidoras<0||pidoras>100)) {
            return false;
        }
    }

    return true;
}

