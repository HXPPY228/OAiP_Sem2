#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Даты");
    w.setMinimumSize(w.size());
    w.show();
    return a.exec();
}
